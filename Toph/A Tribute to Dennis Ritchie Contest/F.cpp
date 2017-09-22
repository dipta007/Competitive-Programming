#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const double EPS = 1e-9;
const int INF = 1000000;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef dipta00
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

int n,timee;
int cat[24];
int req[24];
vector < pii > prob[24];
int kotoTime[24];
int dp1[24][104][10004];
int dp2[(1<<24)+4];
int pri[(1<<24)+4];

int call1(int c, int in, int baki)
{
    if(baki <= 0) return 0;
    if(in >= cat[c])
    {
        return INF;
    }

    int &ret = dp1[c][in][baki];
    if(ret!=-1) return ret;

    ret = call1(c, in+1, baki);
    ret = min(ret, prob[c][in].ff + call1(c, in+1, baki - prob[c][in].ss));
    return ret;
}

int call2(int mask)
{
    int &ret  = dp2[mask];
    if(ret!=-1) return ret;

    int bakiTime = timee;
    FOR(i,0,n-1)
    {
        if(bitCheck(mask, i)==1)
        {

            bakiTime -= dp1[i][0][req[i]];
        }
    }

//    debug(mask, bakiTime)
    ret = 0;
    FOR(i,0,n-1)
    {
        if(bitCheck(mask, i)==0 && dp1[i][0][req[i]] <= bakiTime)
        {
            int kk = 1+call2(bitOn(mask, i));
            if(kk > ret)
            {
                debug(mask)
                pri[mask] = i;
                ret = kk;
            }
        }
    }
    return ret;
}

vi res;

void dpPrint(int mask)
{
    int kk = pri[mask];
    if(kk==-1) return;
    debug(kk)

    res.PB(kk);
    dpPrint(bitOn(mask, kk));
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        res.clear();
        FOR(i,0,21) prob[i].clear();

        getII(n,timee);

        FOR(i,0,n-1)
        {
            getI(cat[i]);
        }

        FOR(i,0,n-1)
        {
            getI(req[i]);
        }

        FOR(i,0,n-1)
        {
//            debug(i, cat[i])
            FOR(j,1,cat[i])
            {
                pii p;
                getII(p.ff, p.ss);
                prob[i].PB(p);
            }
        }
//        debug("*")

        SET(dp1);
        SET(dp2);
        SET(pri);

        FOR(i,0,n-1)
        {
            call1(i, 0, req[i]);
        }

        int kk = call2(0);
        if(kk == 0) printf("Better luck next time\n");
        else
        {
            dpPrint(0);
            FOR(i,0,(int)res.size()-1)
            {
                if(i) printf(" ");
                printf("%d",res[i]+1);
            }
            printf("\n");
        }
    }

    return 0;
}



