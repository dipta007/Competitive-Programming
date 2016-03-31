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
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
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

bool isValidSolution ( ll a, ll b, ll c, ll p, ll div )
{
    ll x=( ( div - c ) / a );
    ll y=( (p-b*div) / (a*div) );
    if(x<=0 || y<=0) return 0;

    if ( ( ( div - c )% a ) != 0 ) return false; //x = (div - c) / a
    if ( ( (p-b*div) % (a*div) ) != 0 ) return false;// y = (p-b*div) /(a*div)
//    if(div-c<=0) return 0;
//    if(p-b*div<=0) return 0;

    debug(x,y,div)
    return true;
}

ll hyperbolicDiophantine ( ll a, ll b, ll c, ll d )
{
    ll p = -(d<<1) + 1;
    //debug(d,p,d<<1)
    ll res = 0;

    //For each divisor of p
    ll sqrtn = sqrt ( p ), div;
    for ( ll i = 1; i <= sqrtn; i++ )
    {
        if ( p % i == 0 )   //i is a divisor
        {

            //Check if divisors i,-i,p/i,-p/i produces valid solutions
            if ( isValidSolution(a,b,c,p,i) )res++;
            else if ( isValidSolution(a,b,c,p,-i) )res++;
            if ( p / i != i )   //Check whether p/i is different divisor than i
            {
                if ( isValidSolution(a,b,c,p,p/i) )res++;
                else if ( isValidSolution(a,b,c,p,-p/i) )res++;
            }
        }
    }

    return res;
}

#define M 50000004
bool marked[M];
vector<int> primes;   // we'll preload primes once at the beginning

void sieve(ll n)     // SIEVE caliye prime ber korbo
{
    primes.push_back(2);
    n = sqrt(n);
    for (ll i = 3; i <= n; i += 2)
    {
        if (marked[i] == 0)
        {
            primes.push_back(i);
            for (ll j = i * i; j <= n; j += i + i)
            {
                marked[j] = 1;
            }
        }
    }
}

ll NOD ( ll n )
{
    ll sqrtn = sqrt ( n );
    ll res = 1;
    for ( int i = 0; i < primes.size() && primes[i] <= sqrtn; i++ )
    {
        if ( n % primes[i] == 0 )
        {
            ll p = 0; /*Counter for power of primes*/
            while ( n % primes[i] == 0 )
            {
                n /= primes[i];
                p++;
            }
            sqrtn = sqrt ( n );
            p++;/*Increase it by one at end*/
            res *= p; /*Multiply with answer*/
        }
    }
    if ( n != 1 )
    {
        res *= 2; /*Remaining prime has power p^1. So multiply with 2*/
    }
    return res;
}


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    ll n;
    sieve(400000000000016);
    while(~getL(n) && n)
    {
        ll a=-2,b=1,c=1,d=2-2*n;
        ll p = -(d<<1) + 1;
        //p *= -1;
        //debug(p)
        printf("%lld %lld\n",n,NOD(p));
    }

    return 0;
}


