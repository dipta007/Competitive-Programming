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

//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#define    ranL(a, b)         ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define    ranI(a, b)         ((((ll)rand() * rand()) % ((b) - (a) + 1)) + (a))
#define    ranF(a, b)         (((double)rand()/RAND_MAX)*((b) - (a)) + (a))
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    SETI(ar)           memset(ar,126,sizeof ar)


#define printbits(x, n) cout << #x << " = " << x << " = " << bitset<n>(x) << endl /// Least significant n bits of x, n must be constant
#define tobinary(x) string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(min(63, __builtin_clzll(x)), 64)
#define lastbits(x, n) cout << string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(64 - n, 64) << endl
#define firstbits(x, n) cout << string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(min(63, __builtin_clzll(x)), 64).substr(0, n) << endl;

#define    ff 	              first
#define    ss 	              second
#define    sf                 scanf
#define    pf                 printf

typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector < int >     vi;
typedef    vector < vi >      vii;
typedef    pair < int, int>   pii;
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


namespace flow
{
    const int N = 1004;
    struct edge
    {

        int u, v;
        ll cap, flow;
        edge() {}
        edge(int a, int b, ll c, ll f)
        {
            u = a, v = b, cap = c, flow = f;
        }
    };

    vector <int> adj[N];
    vector <edge> E;
    int n, source, sink, ptr[N], len[N], dis[N], Q[N];

    inline void init(int nodes, int s, int t)
    {
        CLR(len);
        E.clear();
        n = nodes, source = s, sink = t;
        for (int i = 0; i < N; i++) adj[i].clear();
    }

    // Adds a directed edge with capacity c
    inline void addEdge(int a, int b, long long cap, long long flow = 0)
    {

        adj[a].push_back(E.size());
        E.push_back(edge(a, b, cap, flow));
        len[a]++;

        adj[b].push_back(E.size());
        E.push_back(edge(b, a, 0, 0));
        len[b]++;

    }

    inline bool bfs()
    {

        int cur, j, k, id, f = 0, l = 0;
        SET(dis);
        dis[source] = 0, Q[l++] = source;

        while (f < l && dis[sink] == -1)
        {
            cur = Q[f++];
            for (k = 0; k < len[cur]; k++)
            {
                id = adj[cur][k];
                if (dis[E[id].v] == -1 && E[id].flow < E[id].cap)
                {
                    Q[l++] = E[id].v;
                    dis[E[id].v] = dis[cur] + 1;
                }
            }
        }

        return (dis[sink] != -1);
    }

    long long dfs(int s, ll flow)
    {
        if (s == sink || !flow) return flow;
        while (ptr[s] < len[s])
        {
            int id = adj[s][ptr[s]];
            if (dis[E[id].v] == dis[s] + 1)
            {
                ll x = dfs(E[id].v, min(flow, E[id].cap - E[id].flow));
                if (x)
                {
                    E[id].flow += x, E[id ^ 1].flow -= x;
                    return x;
                }
            }
            ptr[s]++;
        }
        return 0;
    }

    long long dinic()
    {
        ll res = 0, flow;

        while (bfs())
        {
            CLR(ptr);
            while (flow = dfs(source, INF))
            {
                res += flow;
            }
        }
        return res;
    }
}


int add[204];

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n, m;
        getII(n,m);
        CLR(add);
        flow::init(n+4, 0, n+1);
        int low[m+4];
        FOR(i,0,m-1)
        {
            int u, v, l, h;
            getII(u,v);
            getII(l,h);
            add[v] += l;
            add[u] -= l;
            low[i] = l;
//            trace(u, v, h-l);
            flow::addEdge(u, v, h-l);
        }

        int sum = 0;
        FOR(i,1,n)
        {
//            trace(add[i]);
            if(add[i] <= 0) flow::addEdge(i, n+1, -add[i]);
            else flow::addEdge(0, i, add[i]), sum += add[i];
        }

//        FOR(i,0,(int)flow::E.size()-1)
//        {
//            trace(flow::E[i].u, flow::E[i].v, flow::E[i].cap, flow::E[i].flow);
//        }
//        trace("");

        flow::addEdge(n, 1, INF);

        int res = flow::dinic();

        pf("Case %d: ", ci);
        if(res != sum)
            pf("no\n");
        else
        {
            pf("yes\n");
            FOR(i,0,(m*2)-1)
            {
//                trace(flow::E[i].u, flow::E[i].v, flow::E[i].cap, flow::E[i].flow, add[i]);
                pf("%d\n", flow::E[i].flow + low[i/2]);
                i++;
            }
        }

    }

    return 0;
}

