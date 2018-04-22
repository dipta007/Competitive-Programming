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
#ifdef dipta0
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

int n,m;

ll from[1004][1004];
ll to[1004][1004];
//ll cum[1004][1004];
ll ncr[2004][2004];
ll mod = 912;

void DP()
{
//    FOR(i,0,n)
//    {
//        FOR(j,0,m)
//        {
//            from[i][j] = to[i][j] = 1;
//        }
//    }
    to[0][1] = 1;
    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            int rr = n - i;
            int cc = m - j;
debug("SAdsad", i, j, rr, cc)
            from[i][j] = ncr[rr+cc][rr];

            from[i][j] %= mod;

//            cout << from[i][j] << " ";
        }
//        cout << endl;
    }

//    cout << endl << endl;

    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            int rr = i - 1;
            int cc = j - 1;
            to[i][j] = ncr[rr+cc][rr];

            to[i][j] %= mod;

//            cout << to[i][j] << " ";
        }
//        cout << endl;
    }
}

//2
//780 445 681
//113 104 488 104

void calcNcR()
{
    CLR(ncr);
    ncr[0][0] = 1 ;
    int limncr = 2002 ;
    for (int i = 1 ; i <= limncr ; i++)
        for (int j = 0 ; j <= limncr ; j++)
        {
            if ( j > i )
                ncr[i][j] = 0 ;
            else if ( j == i || j == 0 ) ncr[i][j] = 1 ;
            else
                ncr [i][j] = ncr[i-1][j - 1] + ncr[i-1][j] ;

            ncr [i][j] %= mod;
        }
}

ll query(int i, int j, int k, int l)
{
    ll now = 0;
    FOR(ik,j,l)
    {
        debug(i, ik)
        now += (from[i][ik] * to[i-1][ik]) % mod;;
        now %= mod;
    }
    FOR(ik, i, k)
    {
        now += (from[ik][j] * to[ik][j-1]) % mod;
        now %= mod;
    }
//    debug(now)
    return now;
//    return cum[k][l] - cum[i][j-1] - cum[i-1][j] + cum[i-1][j-1];
}

ll MOD(ll x)
{
    return (x%mod + mod) %mod;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
       WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);


    calcNcR();
    int t;
    getI(t);
    FOR(ci,1,t)
    {
        debug(ci)
        int q;
        getIII(n,m,q);
        DP();

        printf("Case %d\n", ci);
        FOR(i,1,q)
        {
            debug(i)
            int a,b,c,d;
            getII(a,b);
            getII(c,d);

            a++, b++, c++, d++;

//            debug(from[1][1])
            printf("   Query %d: %lld\n", i, MOD(from[1][1] - query(a, b, c, d)) );

        }
    }

    return 0;
}

