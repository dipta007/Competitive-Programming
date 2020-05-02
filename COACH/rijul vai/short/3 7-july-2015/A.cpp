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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    F(i,L,R)	         for (int i = L; i < R; i++)
#define    FF(i,L,R) 	     for (int i = L; i <= R; i++)
#define    FR(i,L,R) 	     for (int i = L; i > R; i--)
#define    FRF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d %d", &a, &b)
#define    getIII(a,b,c)     scanf("%d %d %d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld %lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double


template< class T > inline T _abs(T n) { return ( (n) < 0 ? -(n) : (n) ); }
template< class T > inline T _max(T a, T b) { return ( ! ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _min(T a, T b) { return ( ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _swap(T &a, T &b) { T temp=a;a=b;b=temp;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd( (b), ( (a) % (b) ) ) ; }
template< class T > inline T lcm(T a, T b) { return ( (a) / gcd( (a), (b) ) * (b) ); }


//******************DELETE****************
#define shubhashis
#ifdef shubhashis
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************

struct data
{
    int a,b,c;
}a[34];

int n;
int dp[3004][3004];

int test(int x,int y)
{
    int flg=0;
    int p1=0,p2=0,p3=0,p4=0,p5=0,p6=0,p=0;
    if(dp[x][y]!=-1) return dp[x][y];
    for(int i=0;i<n;i++)
    {
        if(a[i].a<x && a[i].b<y)
        {
            p1=a[i].c+test(a[i].a,a[i].b);
        }
        if(a[i].b<x && a[i].a<y)
        {
            p2=a[i].c+test(a[i].b,a[i].a);
        }
        if(a[i].a<x && a[i].c<y)
        {
            p3=a[i].b+test(a[i].a,a[i].c);
        }
        if(a[i].c<x && a[i].a<y)
        {
            p4=a[i].b+test(a[i].c,a[i].a);
        }
        if(a[i].b<x && a[i].c<y)
        {
            p5=a[i].a+test(a[i].b,a[i].c);
        }
        if(a[i].c<x && a[i].b<y)
        {
            p6=a[i].a+test(a[i].c,a[i].b);
        }

        p=max(p,max(p1,max(p2,max(p3,max(p4,max(p5,p6))))));
    }

    return (dp[x][y]=p);
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    while(~getI(n))
    {
        SET(dp);
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
            getIII(a[i].a,a[i].b,a[i].c);
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            int r1=a[i].c+test(a[i].a,a[i].b);
            int r2=a[i].b+test(a[i].a,a[i].c);
            int r3=a[i].a+test(a[i].b,a[i].c);
            int r4=a[i].c+test(a[i].b,a[i].a);
            int r5=a[i].b+test(a[i].c,a[i].a);
            int r6=a[i].a+test(a[i].c,a[i].b);
            int r=max(r1,max(r2,max(r3,max(r4,max(r5,r6)))));
            res=max(res,r);
        }
        printf("%d\n",res);
    }

    return 0;
}

