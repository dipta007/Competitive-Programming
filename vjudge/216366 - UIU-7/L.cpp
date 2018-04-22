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

vector < vector < pii > > adjx, adjy;
ll mx, mn;
vector < pair <ll, ll > > px, py;
bool visx[100004];
bool visy[100004];
int in[100004];

int dfsx(int u, ll x)
{
    visx[u] = 1;

    for(auto v: adjx[u])
    {
        if(visx[v.ff] == 0)
        {
            ll now = x + v.ss;
            px.PB(MP(v.ff, now));
            mx = max(mx, now);
            mn = min(mn, now);
            dfsx(v.ff, now);
        }
    }
}

int dfsy(int u, ll y)
{
    visy[u] = 1;

    for(auto v: adjy[u])
    {
        if(visy[v.ff] == 0)
        {
            ll now = y + v.ss;
            py.PB(MP(v.ff, now));
            mx = max(mx, now);
            mn = min(mn, now);
            dfsy(v.ff, now);
        }
    }
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m;
    while(~getII(n,m))
    {
        adjx.assign(n+4, vector < pii >() );
        adjy.assign(n+4, vector < pii >() );

        FOR(i,1,m)
        {
            int x,y,xx,yy;
            getII(x,y);
            getII(xx,yy);

            in[x]++;
            in[y]++;

            adjx[x].PB(MP(y, xx));
            adjx[y].PB(MP(x, -xx));

            adjy[x].PB(MP(y, yy));
            adjy[y].PB(MP(x, -yy));
        }

        int ix = 0, iy = 0;
        CLR(visx);
        CLR(visy);
        FOR(i,1,n)
        {
            if(visx[i] == 0)
            {
                mx = LONG_MIN;
                mn = LONG_MAX;
                px.PB( MP(i, 0) );
                dfsx(i, 0);

                ll biog = 0;
                if(mx > 1e9) biog = -(mx - 1e9);
                else if(mn < -1e9) biog = - 1e9 - mn;

                for(; ix < px.size(); ix++)
                {
                    px[i].ss += biog;
                }

                mx = LONG_MIN;
                mn = LONG_MAX;
                py.PB( MP(i, 0) );
                dfsy(i, 0);

                biog = 0;
                if(mx > 1e9) biog = -(mx - 1e9);
                else if(mn < -1e9) biog = - 1e9 - mn;

                for(; ix < py.size(); ix++)
                {
                    py[i].ss += biog;
                }
            }
        }

        sort(ALL(px));
        sort(ALL(py));

        FOR(i,0,n-1)
        {
            printf("%lld %lld\n", px[i].ss, py[i].ss);
        }
    }


    return 0;
}
