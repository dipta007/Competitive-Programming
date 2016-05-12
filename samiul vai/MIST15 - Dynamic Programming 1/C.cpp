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
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
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
#define    bitCheck(N,in)    ((bool)(a&(1<<(k))))
#define    bitOff(N,in)      (a&(~(1<<(k))))
#define    bitOn(N,in)       (a|(1<<(k)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
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

struct kadane //Structure for 1D-Kadane Algorithm
{
    int u,d,sum,area;
    kadane()
    {
        u=-1,d=-1,sum=0,area=0;
    }
};

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n,m,k;
        getIII(n,m,k);
        int a[n][m];
        FOR(i,0,n-1)
        {
            FOR(j,0,m-1)
            {
                getI(a[i][j]);
            }
        }
        int r=n,c=m;
        int maxSum=INF,maxL,maxR,maxU,maxD,maxArea=-INF;
        int kad[r];

        for(int left=0;left<c;left++)
        {
            CLR(kad);
            for(int right=left;right<c;right++)
            {
                for(int i=0;i<r;i++)
                {
//                    kad[i]=a[i][right];
                    kad[i]=kad[i]+a[i][right];
                }

                kadane curr,maxy;

                for(int i=0;i<r;i++) //This FOR for 1D-Kadane Algorithm
                {
                    debug(kad[i])
                    if(curr.sum+kad[i]>k)
                    {
                        curr.sum = kad[i];
                        curr.u=i;
                        curr.d=i;
                    }
                    else
                    {
                        curr.sum = curr.sum + kad[i];
                        curr.d=i;
                    }
                    curr.area = abs(right-left+1)*abs(curr.u-curr.d+1);
                    if(curr.area>maxy.area && curr.sum<=k)
                    {
                        maxy = curr;
                    }
                    else if(curr.area==maxy.area && curr.sum<maxy.sum && curr.sum<=k)
                    {
                        maxy=curr;
                    }
                }
                if(maxy.area > maxArea)
                {
                    maxArea = maxy.area;
                    maxSum=maxy.sum;
                    maxL=left;
                    maxR=right;
                    maxU=maxy.u;
                    maxD=maxy.d;
                }
                else if(maxy.area==maxArea && maxy.sum<maxSum)
                {
                    maxArea = maxy.area;
                    maxSum=maxy.sum;
                    maxL=left;
                    maxR=right;
                    maxU=maxy.u;
                    maxD=maxy.d;
                }

            }
        }
        debug(maxArea,maxSum);
//        printf("%")
    }

    return 0;
}



