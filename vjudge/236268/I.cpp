//#include <algorithm>
//#include <bitset>
//#include <cassert>
//#include <cctype>
//#include <climits>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <fstream>
//#include <iostream>
//#include <iomanip>
//#include <iterator>
//#include <list>
//#include <map>
//#include <numeric>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <string>
//#include <utility>
//#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getF(n)           scanf("%lf",&n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    ff 	              first
#define    ss 	              second
#define    sf                 scanf
#define    pf                 printf
typedef    vector < int >     vi;
typedef    vector < vi >      vii;
typedef    pair < int, int>   pii;
typedef    long long          ll;
typedef    unsigned long long ull;
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

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

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const double PI = 2.0 * acos(0.0);

ll MIN() { return INF; }
template <typename T, typename... Args >
inline T MIN(T a, Args... args) { return min(a, (T)MIN(args...)); }

ll MAX() { return -INF; }
template <typename T, typename... Args >
inline T MAX(T a, Args... args) { return max(a, (T)MAX(args...)); }

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

int even[100004];
int odd[100004];

#define MAX 100004
#define MOD 1000000007

int fact[MAX], inv[MAX], inv2[MAX];

ll bigmod ( ll b, ll p, ll m ) {
    ll res = 1 % m, x = b % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}

ll modularInverse(int a, int m)
{
    return bigmod(a, m-2, m);
}
void generate()
{
    int i, j;
    /// generating fact
    fact[0] = 1;
    for (i = 1; i < MAX; i++)
        fact[i] = ((long long)i * fact[i - 1]) % MOD;
    /// generating inv fact
    inv[MAX - 1] = modularInverse(fact[MAX-1], MOD);
    for (i = MAX - 2; i >= 0; i--)
        inv[i] = ((long long)inv[i + 1] * (i + 1)) % MOD;

    inv2[1] = 1;
    for (i = 2; i < MAX; i++)
    {
        inv2[i] = MOD - ((MOD / i) * (long long)inv2[MOD % i]) % MOD;
        if (inv2[i] < 0)
            inv2[i] += MOD;
    }
}

long long binomial(int n, int k)
{
    if (k > n)
        return 0;
    return (((long long)fact[n] * inv[k] % MOD) * inv[n - k]) % MOD;
}

ll minMod(ll x)
{
    return (x%MOD + MOD) % MOD;
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    generate();
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        CLR(even);
        CLR(odd);

        FOR(i,1,n)
        {
            int x;
            getI(x);
            if(x%2 == 1) odd[i] = 1;
            else even[i] = 1;

            even[i] += even[i-1];
            odd[i] += odd[i-1];
        }

        while(m--)
        {
            int l,r,t;
            cin >> l >> r >> t;
            if(t==0)
            {
                ll od = odd[r] - odd[l-1];
                ll ev = even[r] - even[l-1];
                trace(od, ev);
                cout << minMod( minMod(bigmod(2, ev, MOD)-1) * bigmod(2, od, MOD) ) << endl;
//                cout << minMod(ev * bigmod(2, r-l, MOD)) << endl;
            }
            else if(t == 1)
            {
                ll tot = odd[r] - odd[l-1];
                trace(tot);
                cout << minMod(bigmod(2, tot, MOD) - 1) << endl;
            }
        }
    }

    return 0;
}


