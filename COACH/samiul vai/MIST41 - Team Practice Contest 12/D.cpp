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
//
//#define M 100000004
//bool marked[M];
vi primes;

//bool isPrime(int n) {
//  if (n < 2) return 1;
//  if (n == 2) return 0;
//  if (n % 2 == 0) return 1;
//  return marked[n];
//}
//
//void sieve(int n) {
//    primes.PB(2);
//  for (ll i = 3; i * i <= n; i += 2) {
//    if (marked[i] == 0) {
//            primes.PB(i);
//      for (ll j = i * i; j <= n; j += i + i) {
//        marked[j] = 1;
//      }
//    }
//  }
//}

const int mx =100000004;

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
    ll N = 1e8;
    ll i, j, sqrtN;
    sqrtN = (ll)( sqrt( N ) );
    //primes.PB(2);
    for( i = 3; i <= sqrtN; i += 2 )
    {
        if( Check(status[i>>5],i&31)==0)
        {
            primes.PB(i);
            for( j = i*i; j <= N; j += (i<<1) )
            {
                status[j>>5]=Set(status[j>>5],j & 31)   ;
            }
        }
    }
}

bool isPrime(int n)
{
    if(n==2) return 0;
    if(n%2==0 || n<2) return 1;
    if(Check(status[n>>5], n&31) == 0)
        return 0;
    return 1;
}

int main()
{
#ifdef dipta007
    //READ("in.txt");
    //WRITE("out2.txt");
#endif // dipta007

    int n;
    sieve();
    debug(primes.size())
    while(~getI(n))
    {
        if(n%2==0)
        {
            int f=0;
            int nn = sqrt(n)+1;
            FOR(i,3,n)
            {
                if(n%i==0)
                {
                    printf("%d\n",i-1);
                    f=1;
                    break;
                }
            }
            if(f==0) printf("%d\n",n-1);
            continue;
        }
        if(isPrime(n)==0)
        {
            printf("%d\n",n-1);
        }
        else
        {
            FOR(i,0,(int)primes.size()-1)
            {
                if(n%primes[i]==0)
                {
                    printf("%d\n",primes[i]-1);
                    break;
                }
            }
        }
    }

    return 0;
}



