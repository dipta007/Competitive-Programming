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
const int INF = 1000000;
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

int n,m,s;
int shop[22];
pii dp[16][(1<<15)+4];
bool vis[16][(1<<15)+4];
int adj[22][22];
int strt, endd;

pii min(pii &a, pii &b)
{
    if(a.ff > b.ff) return a;
    if(a.ff == b.ff)
    {
        if(a.ss <= b.ss) return a;
        return b;
    }
    return b;
}

pii add(pii &a, pii &b)
{
    pii tmp;
    tmp.ff = a.ff + b.ff;
    tmp.ss = a.ss + b.ss;
    debug(a.ff, a.ss, b.ff, b.ss, tmp.ff, tmp.ss);
    return tmp;
}

pii call(int in, int mask)
{
    if(bitCount(mask) == s)
    {
        if(adj[in][endd] >= INF) return MP(-INF, INF);
        return MP(0, adj[in][endd]);
    }

    pii &ret = dp[in][mask];
    if(vis[in][mask]) return ret;
    vis[in][mask] = 1;

    ret = MP(0, adj[in][endd]);
    if(adj[in][endd] >= INF) ret = MP(-INF, INF);
    FOR(i,0,s-1)
    {
        if(bitCheck(mask, i) == 0 && adj[in][i] < INF)
        {
            pii a = MP(1, adj[in][i]);
            pii b = call(i, bitOn(mask, i) );
            pii p = add( a , b );
            ret = min(ret,  p);
//            debug(adj[shop[in]][shop[i]], ret.ff, ret.ss)
        }
    }
    return ret;
}

#define mx 510

vector<int> g[mx],cost[mx];
struct node
{
    int u,w;
    node(int a,int b){u=a;w=b;}
    bool operator< (const node &p)const {return w > p.w;}
};

int d[mx];
int djkstra(int n, int de)
{
    for(int i=0;i<mx;i++)d[i]=INF;
    priority_queue<node> q;
    q.push(node(n,0));
    d[n]=0;
    while(!q.empty())
    {
        node top=q.top();q.pop();
        int u=top.u;

        if(u == de) return d[de];

        for(int i=0;i<(int)g[u].size();i++)
        {
            int v=g[u][i];
            if(cost[u][i] + d[u] < d[v])
            {
                d[v]=cost[u][i] + d[u];
                q.push(node(v,d[v]));
            }
        }
    }
    return d[de];
}

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
        getIII(n,m,s);

        FOR(i,0,n) g[i].clear();
        FOR(i,0,n) cost[i].clear();

        FOR(i,0, s-1)
        {
            getI(shop[i]);
        }

        FOR(i,0,n) FOR(j,0,n) adj[i][j] = INF;
        FOR(i,0,n) adj[i][i] = 0;
        FOR(i,1,m)
        {
            int u,v,w;
            getIII(u,v,w);

            g[u].PB(v);
            cost[u].PB(w);
        }

        FOR(i,0,s-1)
        {
            FOR(j,0, s-1)
            {
                adj[i][j] = djkstra(shop[i], shop[j]);
            }
        }

        strt = s, endd = s+1;
        FOR(i,0,s-1)
        {
            adj[strt][i] = djkstra(0, shop[i]);
            adj[i][endd] = djkstra(shop[i], n-1);
        }

        adj[strt][endd] = djkstra(0, n-1);

        printf("Case %d: ", ci);
        if(adj[strt][endd] >= INF)
        {
            printf("Impossible\n");
            continue;
        }

        CLR(vis);
        pii res = MP(0, adj[strt][endd]);
        int mask = 0;
        FOR(i,0,s-1)
        {
            if(adj[strt][i] == INF) continue;

            pii a = MP(1, adj[strt][i]);
            pii b = call(i, bitOn(mask, i) );
            pii p = add( a , b );
            res = min(res, p );
        }

        printf("%d %d\n", res.ff, res.ss);
    }

    return 0;
}

