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
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
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

/**
min cost flow (bellman ford)
works only on directed graphs
handles multiple edges, cycles, loops
**/

const int MAXN = 3016;
const int MAXE = 2000316;

int src, snk, nNode, nEdge;
int fin[MAXN], pre[MAXN];
ll dist[MAXN];
int cap[MAXE], cost[MAXE], nextt[MAXE], to[MAXE], from[MAXE];

inline void init(int _src, int _snk, int nodes) {
    SET(fin);
    nNode = nodes, nEdge = 0;
    src = _src, snk = _snk;
}

inline void addEdge(int u, int v, int _cap, int _cost) {
    from[nEdge] = u, to[nEdge] = v, cap[nEdge] = _cap, cost[nEdge] = _cost;
    nextt[nEdge] = fin[u], fin[u] = nEdge++;
    from[nEdge] = v, to[nEdge] = u, cap[nEdge] = 0, cost[nEdge] = -(_cost);
    nextt[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bellman() {
    int iter, u, v, i;
    bool flag = true;
    MEM(dist, 0x7f);
    SET(pre);
    dist[src] = 0;
    for(iter = 1; iter < nNode && flag; iter++) {
        flag = false;
        for(u = 0; u < nNode; u++) {
            for(i = fin[u]; i >= 0; i = nextt[i]) {
                v = to[i];
                if(cap[i] && dist[v] > dist[u] + cost[i]) {
                    dist[v] = dist[u] + cost[i];
                    pre[v] = i;
                    flag = true;
                }
            }
        }
    }
    return (dist[snk] < INF);
}

ll mcmf(ll &fcost) {
    ll netflow, i, bot, u;
    netflow = fcost = 0;
    while(bellman()) {
        bot = INF;
        ll costt = 0;
        for(u = pre[snk]; u >= 0; u = pre[from[u]]) bot = min(bot, (ll)cap[u]);
        for(u = pre[snk]; u >= 0; u = pre[from[u]]) {
            cap[u] -= bot;
            cap[u^1] += bot;
            costt += (ll)bot * cost[u];
        }
        debug("2", costt);
        fcost = max(fcost, (ll)costt);
        netflow += bot;
    }
    return netflow;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,k,p;
    while(~getIII(n,k,p))
    {
        vi v1,v2;
        map <int,int> mp;
        int in=2;
        FOR(i,0,n-1)
        {
            int x;
            getI(x);
            mp[x] = in++;
            v1.PB(x);
        }
        FOR(i,0,k-1)
        {
            int x;
            getI(x);
            if(mp[x]==0) mp[x] = in++;
            v2.PB(x);
        }

        init(1, in, n+k+2+2);

        FOR(i,0,n-1)
        {
            addEdge(1, mp[v1[i]], 1, 0);
        }

        FOR(i,0,n-1)
        {
            FOR(j,0,k-1)
            {
                addEdge(mp[v1[i]], mp[v2[j]], 1, abs(v1[i] - v2[j]));
            }
        }

        FOR(i,0,k-1)
        {
            addEdge(mp[v2[i]], in, 1, abs(v2[i]-p));
        }

        ll res;
        ll kk = mcmf(res);

        debug(res, kk)

        printf("%lld\n",res);
    }

    return 0;
}



