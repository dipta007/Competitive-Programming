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

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef dipta007
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

int n;
double a[19][19];
double dp[(1<<18)+4];
int vis[(1<<18)+4];

double call(int mask)
{
    if(__builtin_popcount(mask)==n-1) return 1.0;
    double &ret = dp[mask];
    if(vis[mask]) return ret;
    vis[mask]=1;

    int ase = n - __builtin_popcount(mask);
    double allPairs = (ase*(ase-1))/2;
    ret=0.0;
    FOR(i,0,n-1)
    {
        if(bitCheck(mask,i)==0)
        {
            FOR(j,i+1,n-1)
            {
                if(bitCheck(mask,j)==1) continue;
                if(i==j) continue;
                //if(i!=in)
                {
                    //debug(1,i,j,in)
                    ret += (a[j][i] * call(bitOn(mask, i)));
                }
                //if(j!=in)
                {
                    //debug(2,i,j,in)
                    ret += (a[i][j] * call(bitOn(mask, j)));
                }
            }
        }
    }
    //debug(in,ret,mask)
    ret /= allPairs;
    return ret;
}


int main()
{
#ifdef dipta007
    //READ("in.txt");
//        WRITE("in.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    while(~getI(n))
    {
        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                getF(a[i][j]);
            }
        }
        CLR(vis);
        FOR(i,0,(1<<n)-1)
        {
            dp[i]=0.0;
            if(__builtin_popcount(i)>=1)
            {
                FOR(j,0,n-1)
                {
                    if(bitCheck(i,j)==1) /// morse
                    {
                        int ase = n - __builtin_popcount(i) + 1;
                        double allPairs = ase * (ase-1);
                        allPairs /= 2.0;
                        FOR(k,0,n-1)
                        {
                            if(bitCheck(i,k)==0) /// marse
                            {
                                dp[i] += (a[k][j] * dp[bitOff(i,j)] ) /allPairs;
                            }
                        }
                    }
                }
            }
            else
            {
                dp[i]=1.0;
            }
        }

        double res[n];
        FOR(i,0,n-1) res[i]=0.0;
        FOR(i,0,(1<<n)-1)
        {
            if(__builtin_popcount(i)==n-1)
            {
                FOR(j,0,n-1)
                {
                    if(bitCheck(i,j)==0)
                    {
                        //debug(i,j,dp[i])
                        res[j] += dp[i];
                    }
                }
            }
        }
        FOR(i,0,n-1)
        {
            if(i) printf(" ");
            printf("%.12lf",res[i]);
        }
        printf("\n");
    }

    return 0;
}



