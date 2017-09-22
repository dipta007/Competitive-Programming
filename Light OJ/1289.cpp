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

const int mx =100000000;
unsigned int pre[5761460];
int lim;
int primes[5761460];

bool Check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}

int status[(mx/32)+2];
void sieve()
{
    ll i, j, sqrtN;
    ll N = 100000000;
    sqrtN = int( sqrt( N ) );
    primes[lim++]=2;
    for( i = 3; i <= sqrtN; i += 2 )
    {
        if( Check(status[i>>5],i&31)==0)
        {
            primes[lim++]=i;
            for( j = i*i; j <= N; j += (i<<1) )
            {
                status[j>>5]=Set(status[j>>5],j & 31)   ;
            }
        }
    }
    i=sqrtN;
    if(i%2==0) i++;
    for(;i<=N;i+=2)
    {
        if( Check(status[i>>5],i&31)==0)
            primes[lim++]=i;
    }
}

int bin_src(int low,int high, int val)
{
    int res;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(primes[mid]<=val)
        {
            res=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return res;
}

int main()
{
#ifdef dipta007
    //READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    lim=0;
    sieve();
    debug(lim)
    pre[0]=0;
    pre[1]=1;
    int in=2;
    int x;
    FOR(i,2,100000000)
    {
        if((i==2 || i%2==1) && Check(status[i>>5], i&31)==0)
        {
            pre[in] = pre[in-1]*i;
            in++;
        }
        //else pre[i] = pre[i-1];
    }
    debug(x)
    FOR(ci,1,t)
    {
        int n;
        getI(n);
        int pos = bin_src(0,5761454,n);
        unsigned int res = pre[pos+2];
        debug(res,primes[pos],pos)


        int nn = sqrt(n);
        FOR(i,0,(int)lim-1)
        {
            if(primes[i]>nn) break;
            int xx = n/primes[i];
            while(primes[i]<=xx)
            {
                //debug(xx,primes[i])
                res *= primes[i];
                xx /= primes[i];
            }
        }
        printf("Case %d: %u\n",ci,res);
    }

    return 0;
}



