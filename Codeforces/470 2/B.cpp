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
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define dipta00
#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
#else
    #define debug(args...)  /// Just strip off all debug tokens
    #define trace(...) ///yeeeee
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

#define M 1000000
bool marked[M];
vector <int> primes;

bool isPrime(int n)
{
  if (n < 2) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  return marked[n] == 0;
}

void sieve(int n)
{
    primes.push_back(2);
    for (int i = 3; i * i <= n; i += 2)
    {
        if (marked[i] == 0)
        {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i + i)
            {
                marked[j] = 1;
            }
        }
    }
}

int pre[1000004];
int vag[1000004];

int main() {
    #ifdef dipta007
//        READ("in.txt");
//       WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int x2;

    sieve(1000000);
    debug(primes.size())

    FOR(i,3,1000000)
    {
        int n = i;
        int nn = sqrt(i);

        int mx = -1;
        FOR(j,0,(int)primes.size()-1)
        {
            if(primes[j] > nn) break;
            if(n % primes[j] == 0)
            {
                while(n%primes[j] == 0) n/= primes[j];

                nn = sqrt(n);
                mx = max(mx, primes[j]);
            }
        }

        if(n != 1) mx = max(mx, n);
        vag[i] = mx;

    }
    FOR(i,3,1000000)
    {
        if(isPrime(i) == 1)
        {
            pre[i] = i;
            continue;
        }
//        int ii = sqrt(i);
        int mn = INF;
//        for(int j=0; j<primes.size(); j++)
//        {
//            debug(i, j, primes.size(), primes[j])
//            if( i % primes[j] == 0 )
//            {
//
//                int l = ((i / primes[j]) - 1) * primes[j] + 1;
//                trace(i, primes[j], l);
//                mn = min(mn, l);
//            }
//        }

        int kk = vag[i];
        int l = ((i / kk) - 1) * kk + 1;
        mn = l;

//        if(isPrime(i) == 1) l = i-1;

//        if(l != mn)
//        {
//            trace("vul", i, mn, kk, l);
//        }


        pre[i] = mn;
    }
    while(~ getI(x2))
    {
        int xx2 = sqrt(x2);
        int mnx0 = INF;
        int tx2 = x2;
        for(int i=0; i< primes.size(); i++)
        {
            if(primes[i] > xx2) break;
            if(x2 % primes[i] == 0)
            {
                int l = ((tx2 / primes[i]) - 1) * primes[i] + 1;
                int r = tx2 - 1;

//                trace(l, r, primes[i]);
                for(int x1=l; x1<=r; x1++)
                {
//                    trace(x1, pre[x1]);
                    if(x1 < 3) continue;
                    mnx0 = min(mnx0, pre[x1]);
                }

                while(x2 % primes[i] == 0) x2 /= primes[i];

                xx2 = sqrt(x2);
            }
        }
        if(x2 != 1)
        {
            int l = ((tx2 / x2) - 1) * x2 + 1;
                int r = tx2 - 1;
                for(int x1=l; x1<=r; x1++)
                {
//                    trace(x1, pre[x1]);
                    if(x1 < 3) continue;
                    mnx0 = min(mnx0, pre[x1]);
                }
        }
        printf("%d\n", mnx0);
    }

    return 0;
}

