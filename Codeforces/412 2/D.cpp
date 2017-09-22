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
const int INF = 0x7f7f7f7f;
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

#ifdef dipta007
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

struct node
{
    int p[5];
};

struct score
{
    double l,r;
    int val;
};

vector < node > v;
int submission[5];
int n;

/// vasya 0
/// patya 1

vector < score > vs;

int check(int sub)
{
    int cpySub[5];
    FOR(i,0,4)
    {
        cpySub[i] = submission[i];
    }

    int nn = n+sub;


    FOR(i,0,4)
    {
        if(v[0].p[i]>v[1].p[i])
        {
            cpySub[i]+=sub;
        }
    }

    double subRat[5],score[5];
    /// per problem loop
    FOR(i,0,4)
    {
        subRat[i] = (double)cpySub[i] / (double)nn;
        /// kon vag e pore oi ter loop
        FOR(j,0,5)
        {
            if(subRat[i] > vs[j].l+EPS && (subRat[i]+EPS < vs[j].r || fabs(subRat[i] - vs[j].r)<EPS))
            {
                score[i] = vs[j].val;
                break;
            }
        }
    }

    double vasya=0.0, patya=0.0;

    FOR(i,0,4)
    {
        if(v[0].p[i]==-1) continue;
        double pp = score[i] * (1.0 - (double)v[0].p[i] / 250.0);
        vasya += pp;
    }


    FOR(i,0,4)
    {
        if(v[1].p[i]==-1) continue;
        double pp = score[i] * (1.0 - (double)v[1].p[i] / 250.0);
        patya += pp;
    }

    if(sub<=2)
    {
        FOR(i,0,4)
        {
            debug("score",i,score[i],subRat[i]);
        }
        debug("chk",sub,vasya, patya);
    }

    if(vasya > patya + EPS) return 1;
    return 0;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    score he;
    he.l = 1.0/2.0;
    he.r = 1.0;
    he.val = 500;
    vs.PB(he);

    he.l = 1.0/4.0;
    he.r = 1.0/2.0;
    he.val = 1000;
    vs.PB(he);

    he.l = 1.0/8.0;
    he.r = 1.0/4.0;
    he.val = 1500;
    vs.PB(he);

    he.l = 1.0/16.0;
    he.r = 1.0/8.0;
    he.val = 2000;
    vs.PB(he);

    he.l = 1.0/32.0;
    he.r = 1.0/16.0;
    he.val = 2500;
    vs.PB(he);

    he.l = -1;
    he.r = 1.0/32.0;
    he.val = 3000;
    vs.PB(he);


    while(~getI(n))
    {
        v.clear();

        CLR(submission);

        FOR(i,0,n-1)
        {
            node d;
            FOR(j,0,4)
            {
                getI(d.p[j]);
                if(d.p[j]!=-1)
                {
                    submission[j]++;
                }
            }
            v.PB(d);
        }

        int low = 0, high = 1e9+7;
        int res=-1;

        while(low <= high)
        {
            int mid = (low+high)/2;

            debug(low,mid,high)
            if(check(mid))
            {
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        printf("%d\n",res);

    }

    return 0;
}



