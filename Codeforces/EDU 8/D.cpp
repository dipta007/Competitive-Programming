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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    rep(i,n)          for(i=1;i<=n;i++)
#define    repI(i,n)         for(i=0;i<n;i++)
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
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
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

//******************DELETE****************
#define shubhashis
#ifdef shubhashis
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

int bitOn(int N,int pos)
{
    return N=N | (1<<pos);
}
int bitOff(int N,int pos)
{
    return N=N & ~(1<<pos);
}
bool bitCheck(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

const int NX = 2004 ;

int dp[2][NX][NX];
int lim, tt ;
int mod = 1000000007;
vector < int > inp ;
int dig;

int call(int pos,int isSmall)

int DP( int pos, int isSmall,int isStart)
{
    if( pos == lim ) return 1;
    debug("*")

    int &ret = dp[isSmall][isStart][pos];
    if( ret!=-1 ) return ret ;

    int ses = isSmall ? 9 : inp[pos];
    int i ;
    ret = 0 ;
    int even=0;
    if(isStart!=2001 )  // আগেই নাম্বার বসানো শুরু করে দিছি
    {
        if(isStart%2==0)
        {
            if(pos%2==1) even=1;
        }
        else
        {
            if(pos%2==0) even=1;
        }
        if(even==0)
        {
            for ( i = 0 ; i <= ses ; i++ )
            {
                if(i==dig) continue;
                ret += DP( pos + 1, isSmall | i < inp[pos],isStart);
            }
        }
        else
        {
            for ( i = dig ; i <= dig ; i++ )
            {
                ret += DP( pos + 1, isSmall | i < inp[pos],isStart);
            }
        }
    }
    else
    {
        for ( i = 1 ; i <= ses ; i++ )
        {
            ret += DP( pos + 1, isSmall | i < inp[pos],pos);
        }
        ret += DP( pos + 1, 1,2001);
    }
    return ret%mod ;
}

int Cal( string x )
{
    inp.clear();
    for(int i=0;i<x.size();i++)
    {
        inp.PB(x[i]-'0');
    }
    lim = inp.size();
    SET(dp);
    return DP( 0, 0, 2001 ) ;    // শুধু ০ টা আলাদা এড করছি
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int m,d;
    while(~getII(m,d))
    {
        getchar();
        string st1,st2;
        getline(cin,st1);
        getline(cin,st2);
        dig=d;
        int ans1 = Cal(st1);
        int ans2 = Cal(st2);
        debug(ans1,ans2,ans2-ans1)
    }

    return 0;
}


