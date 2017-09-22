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

#define M 1000005
bool marked[M];
vector<ll> primes;
vector<ll> mainfactor;
vector<int> countfactor;
vector<ll>allfactor;
void sieve(ll n)
{
    primes.push_back(2);
    ll i;
    ll nn = sqrt(n)+2;
    for (i = 3; i <= nn; i += 2)
    {
        if (marked[i] == 0)
        {
            primes.push_back(i);
            for (ll j = i * i; j <= nn; j += i + i)
            {
                marked[j] = 1;
            }
        }
    }
    while(i<=nn)
    {
        if(marked[i]==0)primes.push_back(i);
        i+=2;
    }
}

void divisor ( ll n )
{
    ll sqrtn = sqrt ( n );
    for ( ll i = 0; i < primes.size() && (ll)primes[i] <= sqrtn; i++ )
    {
        if ( n % (ll)primes[i] == 0 )
        {
            int p = 0; /*Counter for power of prime*/
            while ( n % (ll)primes[i] == 0 )
            {
                n /= (ll)primes[i];
                p++;
            }
            sqrtn = sqrt ( n );
            mainfactor.push_back((ll)primes[i]);
            countfactor.push_back(p);
        }
    }
    if ( n != 1 )
    {
        mainfactor.push_back((ll)n);
        countfactor.push_back(1);
    }
}
void alldivisor(int idx,ll num)
{
    if(idx==mainfactor.size())
    {
        allfactor.push_back(num);
        return;
    }
    alldivisor(idx+1,num);
//    alldivisor(idx+1,mainfactor[idx]);
    for(int i=countfactor[idx];i;i--)
    {
        alldivisor(idx+1,num*mainfactor[idx]);
        num*=mainfactor[idx];
    }

}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int n,k;
    //sieve(1000000000);
    while(~getII(n,k))
    {
        int a[n];
        int gc=-1;
        FOR(i,0,n-1)
        {
            getI(a[i]);
            if(gc==-1) gc=a[i];
            else gc=gcd(gc,a[i]);
        }
        int nn = sqrt(gc);
        ll maxy = -1;
        FOR(i,2,(int)nn)
        {
            if(gc%i==0)
            {
                ll kk = k/i;
                maxy = max(maxy, kk*i);
                kk = k/(gc/i);
                maxy = max(maxy, kk*(gc/i));
            }
        }
        ll kk = k/gc;
        maxy = max(maxy, kk*gc);
//        FOR(i,0,(int)allfactor.size()-1)
//        {
//            debug(allfactor[i]);
//        }
//        ll kk = k/gc;
        printf("%lld\n",maxy);
    }

    return 0;
}



