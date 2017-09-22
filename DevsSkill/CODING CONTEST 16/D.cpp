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

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)          freopen(f, "w", stdout)
#define    MP(x, y)          make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)        for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R)        for (int i = (int)(L); i >= (int)(R); i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
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
#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifndef ONLINE_JUDGE
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

const int mx = 1e8+4;
int status[(mx/32)+2];
vector <ll > primes;

void sieve()
{
    ll N  = 1e8;
     ll i, j, sqrtN; 
     sqrtN =  N ;
     for( i = 3; i <= sqrtN; i += 2 ) 
     {
         if( bitCheck(status[i>>5],i&31)==0)
         {
             for( j = i*i; j <= N; j += (i<<1) )
             {
                 status[j>>5]=bitOn(status[j>>5],j & 31)   ;
             }
         }
     }
    
     // puts("2");
     primes.PB(2);
     for(i=3;i<=N;i+=2)
         if( bitCheck(status[i>>5],i&31)==0) primes.PB(i);
}

vector<ll>factors;
map <ll, int> mp;
void factorize( ll n )
{
    ll sqrtn = sqrt ( n );
    for ( int i = 0; i < primes.size() && primes[i] <= sqrtn; i++ )
    {
        if ( n % primes[i] == 0 )
        {
            int cnt = 0;
            while ( n % primes[i] == 0 )
            {
                n /= primes[i];
                cnt++;
                factors.push_back(primes[i]);
            }
            mp[primes[i]] += cnt;
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 )
    {
        mp[n] += 1;
        factors.push_back(n);
    }
}

/* Function to calculate (base^exponent)%modulus */
long long int modular_pow(long long int base, int exponent,
                          long long int modulus)
{
    /* initialize result */
    long long int result = 1;
 
    while (exponent > 0)
    {
        /* if y is odd, multiply base with result */
        if (exponent & 1)
            result = (result * base) % modulus;
 
        /* exponent = exponent/2 */
        exponent = exponent >> 1;
 
        /* base = base * base */
        base = (base * base) % modulus;
    }
    return result;
}
 
/* method to return prime divisor for n */
long long int PollardRho(long long int n)
{
    /* initialize random seed */
    srand (time(NULL));
 
    /* no prime divisor for 1 */
    if (n==1) return n;
 
    /* even number means one of the divisors is 2 */
    if (n % 2 == 0) return 2;
 
    /* we will pick from the range [2, N) */
    long long int x = (rand()%(n-2))+2;
    long long int y = x;
 
    /* the constant in f(x).
     * Algorithm can be re-run with a different c
     * if it throws failure for a composite. */
    long long int c = (rand()%(n-1))+1;
 
    /* Initialize candidate divisor (or result) */
    long long int d = 1;  
 
    /* until the prime factor isn't obtained.
       If n is prime, return n */
    while (d==1)
    {
        /* Tortoise Move: x(i+1) = f(x(i)) */
        x = (modular_pow(x, 2, n) + c + n)%n;
 
        /* Hare Move: y(i+1) = f(f(y(i))) */
        y = (modular_pow(y, 2, n) + c + n)%n;
        y = (modular_pow(y, 2, n) + c + n)%n;
 
        /* check gcd of |x-y| and n */
        d = __gcd(abs(x-y), n);
 
        /* retry if the algorithm fails to find prime factor
         * with chosen x and c */
        if (d==n) return PollardRho(n);
    }
 
    return d;
}

#define abs(x,y) (x > y? x - y : y - x)

ll f(ll y, ll c, ll n) {
    y = (y * y) % n;
    y += c;
    if (y < c)
        y += (std::numeric_limits<ll>::max() - n) + 1;
    y %= n;
    return y;
}

ll rho(ll n)
{
    if (n == 1) return 2;
    if (n % 2 == 0) return 2;

    ll y = rand() % n;
    ll x;
    ll ys = y;
    ll c;
    do c = rand() % n; while (c == 0 || c == n - 2);
    ll m = 1000;
    ll d = 1;
    ll q = 1;
    ll r = 1;
    do
    {
        x = y;
        for (int i = 0; i <= r; i++)
            y = f(y, c, n);

        int j = 0;
        do
        {
            ys = y;
            for (int i = 0; i <= min(m, r - j); i++)
            {
                y = f(y, c, n);
                q *= (abs((ll)x, (ll)y) % n);
            }
            d = gcd(q, n);
            j += m;
        } while (j < r && d == 1);
        r *= 2;
    } while (d == 1);
    if (d == n)
    {
        do
        {
            ys = f(ys, c, n);
            d = gcd(abs(x, ys), n);
        } while (d == 1);
    }
    return d;
}

int main() {
#ifndef ONLINE_JUDGE
    // READ("in.txt");
    // WRITE("out.txt");
#endif // dipta007
    // ios_base::sync_with_stdio(0);cin.tie(0);
    
    //sieve();
    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n;
        getI(n);
        vector <ll> v;
        mp.clear();
        ll gc = -1;
        int ff = 1;
        FOR(i,1,n)
        {
            ll x;
            getL(x);
            if(x==0) ff=0;
            if(i==1 && ff) gc = x;
            else if(ff) gc = gcd(x,gc);
            v.PB(x);
        }

        printf("Case %d: ", ci);
        if(n==1)
        {
            printf("Can't decrypt\n");
            continue;
        }

        if(gc==0 || ff==0)
        {
            printf("Invalid message\n");
            continue;
        }

        int flg = 1;
        FOR(i,0,n-1)
        {
            ll kk = v[i] / gc;
            ll pp = rho(kk);
            if(pp != kk && pp!=1)
            {
                flg=0;
                break;
            }
        }

        if(gc==1 || flg==0)
        {
            printf("Invalid message\n");
            continue;
        }

        FOR(i,0,n-1)
        {
            if(i) printf(" ");
            printf("%lld", v[i]/gc);
        }
        printf("\n");
        continue;
        map <ll, int> :: iterator it;
        ll res  =1;
        ll fst = 1;
        for(it = mp.begin(); it!=mp.end(); it++)
        {
            ll val = it->ff;
            ll cnt = it->ss;
            //debug(val, cnt)
            if(cnt >= n)
            {
                if(fst==1) fst = val;

                res *= val;
            }
        }
        //debug(res)

        if(res==1)
        {
            printf("Invalid message\n");
            continue;
        }

        FOR(i,0,n-1)
        {
            if(v[i]==res)
            {
                res /= fst;
                break;
            }
        }

        FOR(i,0,n-1)
        {
            if(i) printf(" " );
            printf("%lld", v[i]/res);
        }
        printf("\n");
    }

}


