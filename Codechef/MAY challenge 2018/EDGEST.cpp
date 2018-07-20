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
#define    sf scanf
#define    pf printf
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

vii adj[2];
int gg;

const int lim = 6;

vector < bitset < lim > > T[2];

int vis[lim];

void dfs(int u)
{
    vis[u] = 1;
    bitset < lim > ret;
    ret.set(u);
    for(auto v: adj[gg][u])
    {
        if(vis[v] == 0)
        {
            dfs(v);
            ret = ret | T[gg][v];
        }
    }
    T[gg][u] = ret;
}

vector < pii > edges;
vii connected;

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n;
        getI(n);
        adj[0].assign(n+4, vi());
        adj[1].assign(n+4, vi());
        T[0].assign(n+4, bitset < lim >());
        T[1].assign(n+4, bitset < lim >());
        connected.assign(n+4, vi());

        FOR(i,1,n-1)
        {
            int u,v;
            getII(u,v);
            u--, v--;
            adj[0][u].PB(v);
            adj[0][v].PB(u);

            edges.PB( MP(u,v) );
        }
        FOR(i,1,n-1)
        {
            int u,v;
            getII(u,v);
            u--, v--;
            adj[1][u].PB(v);
            adj[1][v].PB(u);

            connected[u].PB(v);
            connected[v].PB(u);
        }

        CLR(vis);
        gg = 0;
        dfs(0);

        CLR(vis);
        gg = 1;
        dfs(0);
//
//        FOR(i,1,n)
//        {
//            cout << T[0][i].to_string() << endl;
//        }
//        FOR(i,1,n)
//        {
//            cout << T[1][i].to_string() << endl;
//        }

        bitset < lim > tester;
        FOR(i,0,n-1) tester.set(i);

        FOR(i,0,n-2)
        {
            pii u = edges[i];

//            bitset < lim > uff = T[0][u.ff];
//            bitset < lim > uss = T[0][u.ss];
//
//            if(uff.count() > uss.count()) uff = ~uss;
//            else uss = ~uff;
//
//            uff = uff & tester;
//            uss = uss & tester;

            int cnt = 0;
            for(auto v: connected[u.ff])
            {
                bitset < lim > uss = T[1][u.ss];
                bitset < lim > vss = T[1][v];



                bitset < lim > vff = T[1][u.ff];
                bitset < lim > vss = T[1][v];

                debug(u.ff, u.ss, uff, uss);

                if(vff.count() > vss.count()) vff = ~vss;
                else vss = ~vff;

                vff = vff & tester;
                vss = vss & tester;

                debug(u.ff, v, vff, vss);

                bitset < lim > nowff = vff & uff;
                bitset < lim > nowss = vss & uss;

                debug(nowff, nowss);
                debug("")

                if(nowff.count() > vff.count() && nowff.count() > uff.count()
                   && nowss.count() > vss.count() && nowss.count() > uss.count())
                {
                    cnt++;
                }
            }

            if(i) pf(" ");
            pf("%d", cnt);
        }
        pf("\n");
    }

    return 0;
}


