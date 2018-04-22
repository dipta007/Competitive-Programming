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
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

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

const int MAX = 1e6 + 4;

ll koiber[MAX];
char ki[MAX];

ll Z[MAX];
void zAlgo(int n)
{

    ll L = 0, R = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && ( ((R-L == 0 || ki[R-L+1] == '#') && ki[R-L] == ki[R] && koiber[R-L] <= koiber[R]) || (ki[R-L] == ki[R] && koiber[R-L] == koiber[R]) ))
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            /// We are operating in the box
            ll k = i-L;
            /// Does not touch the right of the box
            if (i + Z[k] < R+1)
                Z[i] = Z[k];
            /// Touched the right of the box, so calculate again
            else
            {
                L = i;
                while (R < n && ( ((R-L == 0 || ki[R-L+1] == '#') && ki[R-L] == ki[R] && koiber[R-L] <= koiber[R]) || (ki[R-L] == ki[R] && koiber[R-L] == koiber[R]) ))
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m;
    while(~getII(n,m))
    {
        char prev = '#';
        int in = m+1;
        int nn = 0;
        FOR(i,m+1, m+n)
        {
            getchar();
            scanf("%lld-%c",&koiber[in], &ki[in]);

            if(ki[in] == prev)
            {
                koiber[in-1] += koiber[in];
                nn--;
            }
            else
            {
                prev = ki[in];
                in++;
            }
        }

        prev = '#';
        in = 0;
        int mm = 0;
        FOR(i,0,m-1)
        {
            getchar();
            scanf("%lld-%c",&koiber[in], &ki[in]);


            debug(koiber[i], ki[i])
            if(ki[in] == prev)
            {
                debug(i, prev, ki[in])
                koiber[in-1] += koiber[in];
                mm--;
            }
            else
            {
                prev = ki[in];
                in++;
            }
        }



        n += nn;
        in = m+1;
        m += mm;

        koiber[m] = 1;
        ki[m] = '#';

        FOR(i, m+1, m+n)
        {
            koiber[i] = koiber[in];
            ki[i] = ki[in++];
        }

        debug(m)

        if(m==1)
        {
            ll cnt = 0;
            FOR(i,m+1, m+n)
            {
                if(ki[i] == ki[0] && koiber[i] >= koiber[0])
                {
                    ll kk = koiber[i] - koiber[0] + 1;
                    cnt += kk;
                }
            }
            printf("%lld\n", cnt);
            continue;
        }

        FOR(i,0,m+n)
        {
            debug(i, ki[i], koiber[i]);
        }


        zAlgo(n+m+1);

        ll cnt = 0;
        FOR(i,0,n+m) cnt += (Z[i] == m);
        printf("%lld\n", cnt);
    }

    return 0;
}

