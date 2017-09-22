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
#define    iseq(a,b)          (fabs(a-b)<EPS)
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

ll dp[100004][504];
ll a[100004];
int n,k;

int call(int in, int kk)
{
    debug(in,kk,n)
    if(in>=n-1)
    {
        if(in==n-1) return INF;
        if(kk==k) return 0;
        else return INF;
    }

    ll &ret = dp[in][k];
    if(ret!=-1) return ret;

    ll mini = min(a[in],a[in+1]);
    ll maxy = max(a[in], a[in+1]);
    ret = LONG_LONG_MAX;
    FOR(i,in+1,n-2)
    {
        ret = min(ret, maxy-mini + call(i+1, k+1));
        maxy = max(maxy, a[i+1]);
        mini = min(mini, a[i+1]);
    }
    return ret;
}

vector <ll> cluster[504];

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    double miny = 40000000000000;
    debug(miny);
    getI(t);
    FOR(ci,1,t)
    {
        getII(n,k);
        FOR(i,0,n-1)
        {
            getL(a[i]);
        }
        sort(a,a+n);
        vi cen;
        FOR(i,0,k-1)
        {
            cen.PB(a[i]);
        }
        FOR(i,0,500)
        {
            cluster[i].clear();
        }
        FOR(i,k,n-1)
        {
            double mini = 40000000000000;
            int in;
            FOR(j,0,k-1)
            {
                ll kk = fabs(cen[j]-(double)a[i]);
                if(kk+EPS<mini)
                {
                    mini=kk;
                    in=j;
                }
            }
            cluster[in].PB(a[i]);
            ll jog = accumulate(ALL(cluster[in]),0);
            cen[in] = (double)jog/cluster[in].size();
        }

        FOR(i,0,500)
        {
            cluster[i].clear();
        }
        FOR(i,0,n-1)
        {
            double mini = 40000000000000;
            int in;
            FOR(j,0,k-1)
            {
                double kk = fabs(cen[j]-(double)a[i]);
                if(kk+EPS<mini)
                {
                    mini=kk;
                    in=j;
                }
            }
            if(in>0 && cluster[in-1].size()<2) in--;
            cluster[in].PB(a[i]);
        }
//        FOR(i,0,k-1)
//        {
//            sort(ALL(cluster[i]));
//        }

        ll sum=0;
        int flg=0;
        FOR(i,0,k-1)
        {
            ll mini = LONG_LONG_MAX;
            ll maxy = LONG_LONG_MIN;
//            if(cluster[i].size()<2)
//            {
//                cluster[i].PB(cluster[i+1][0]);
//                flg=1
//            }
            FOR(j,0,(int)cluster[i].size()-1)
            {
                mini = min(mini, cluster[i][j]);
                maxy = max(maxy, cluster[i][j]);
                debug(cluster[i][j],i)
            }
            sum += maxy-mini;
        }
        printf("%lld\n",sum);
    }

    return 0;
}



