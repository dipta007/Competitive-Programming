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
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    vi 	              vector < ll >
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
const ll INF = 3000040000000LL;

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out


vector < vector < ll > > a;
int r,c;

ll callR(int x, int y)
{
    FOR(i,0,c-1)
    {
        swap(a[x][i], a[y][i]);
    }

    ll res = 0;
    FOR(i,0,r-2)
    {
        FOR(j,0,c-2)
        {
            ll now = a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1];
            res += now;
        }
    }

    FOR(i,0,c-1)
    {
        swap(a[x][i], a[y][i]);
    }

    return res;
}

ll callC(int x, int y)
{
    FOR(i,0,r-1)
    {
        swap(a[i][x], a[i][y]);
    }

    ll res = 0;
    FOR(i,0,r-2)
    {
        FOR(j,0,c-2)
        {
            ll now = a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1];
            res += now;
        }
    }

    FOR(i,0,r-1)
    {
        swap(a[i][x], a[i][y]);
    }

    return res;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    while(~getII(r,c))
    {
        a.assign(r+4, vector < ll > (c+4));
        FOR(i,0,r-1)
        {
            FOR(j,0,c-1)
            {
                getL(a[i][j]);
            }
        }

        vi v, mv;
        FOR(i,0,r-1)
        {
            ll now = 0;
            FOR(j,0,c-1)
            {
                now += a[i][j];
            }
            v.PB(now);
        }

        vi b, mb;
        FOR(i,0,c-1)
        {
            ll now = 0;
            FOR(j,0,r-1)
            {
                now += a[j][i];
            }
            b.PB(now);
        }

        ll res = callC(0,0);
        if(v.size() > 2)
        {
            /// row 0
            ll maxy = -INF;
            int in = -1;

            if(v[1] < v[0])
            {
                maxy = v[1]+v[2];
                in = 1;
            }
            FOR(i,2,(int)v.size()-2)
            {
                if(v[i-1] + v[i+1] > maxy && v[i] < v[0])
                {
                    maxy = v[i-1] + v[i+1];
                    in = i;
                }
            }

            if(in != -1) res = max(res, callR(in, 0));

            maxy = -INF;
            in = -1;
            if(v[v.size()-2] < v[r-1])
            {
                maxy = v[v.size()-2] + v[v.size()-3];
                in = v.size()-2;
            }
            FOR(i,1,(int)v.size()-3)
            {
                if(v[i-1] + v[i+1] > maxy && v[i] < v[r-1])
                {
                    maxy = v[i-1] + v[i+1];
                    in = i;
                }
            }

            if(in!=-1) res = max(res, callR(in, r-1));
        }

        if(b.size() > 2)
        {
            ll maxy = -INF;
            int in = -1;
            if(b[1] < b[0])
            {
                maxy = b[1]+b[2];
                in = 1;
            }
            FOR(i,2,(int)b.size()-2)
            {
                if(b[i-1] + b[i+1] > maxy && b[i] < b[0])
                {
                    maxy = b[i-1] + b[i+1];
                    in = i;
                }
            }

            if(in != -1) res = max(res, callC(in, 0));

            maxy = -INF;
            in = -1;
            if(b[b.size()-2] < b[c-1])
            {
                maxy = b[b.size()-2] + b[b.size()-3];
                in = b.size()-2;
            }
            FOR(i,1,(int)b.size()-3)
            {
                if(b[i-1] + b[i+1] > maxy && b[i] < b[c-1])
                {
                    maxy = b[i-1] + b[i+1];
                    in = i;
                }
            }

            if(in != -1) res = max(res, callC(in, c-1));
        }

        printf("%lld\n", res);
    }

    return 0;
}

