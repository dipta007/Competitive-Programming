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

int adj[34][34];
int dist[34][34];

// 4 direction
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void bfs(int sx, int sy, int n)
{
    SETI(dist);
    queue < int > q;
    q.push(sx);
    q.push(sy);
    dist[sx][sy] = 0;
    while(!q.empty())
    {
        int ux = q.front(); q.pop();
        int uy = q.front(); q.pop();
        FOR(i,0,3)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];

            if(vx >= 0 && vy >= 0 && vx < n && vy < n)
            {
                if(adj[vx][vy] == 1) continue;
                if(dist[ux][uy] + 1 < dist[vx][vy]) {
                    dist[vx][vy] = dist[ux][uy] + 1;
                    if(adj[vx][vy] != 2) {
                        q.push(vx);
                        q.push(vy);
                    }
                }
            }
        }
    }
}


namespace mcmf{
    const long long INF = 1LL << 60;
    const int MAX = 10000;
    long long potential[MAX], dis[MAX], cap[MAX], cost[MAX];
    int n, m, s, t, to[MAX], from[MAX], last[MAX], next[MAX], adj[MAX];

    struct compare{
        inline bool operator()(int a, int b){
            if (dis[a] == dis[b]) return (a < b);
            return (dis[a] < dis[b]);
        }
    };
    set<int, compare> S;

    void init(int nodes, int source, int sink){
        m = 0, n = nodes;
        s = source, t = sink;
        for (int i = 0; i <= n; i++) potential[i] = 0, last[i] = -1;
    }

    /// u -> v, capacity, cost
    void addEdge(int u, int v, long long c, long long w){
        from[m] = u, adj[m] = v, cap[m] = c, cost[m] = w, next[m] = last[u], last[u] = m++;
        from[m] = v, adj[m] = u, cap[m] = 0, cost[m] = -w, next[m] = last[v], last[v] = m++;
    }

    pair<long long, long long> solve(){
        int i, j, e, u, v;
        long long w, aug = 0, mincost = 0, maxflow = 0;

        while (1){
            S.clear();
            for (i = 0; i < n; i++) dis[i] = INF;

            dis[s] = 0, S.insert(s);
            while (!S.empty()){
                u = *(S.begin());
                if (u == t) break;
                S.erase(S.begin());

                for (e = last[u]; e != -1; e = next[e]){
                    if (cap[e] != 0){
                        v = adj[e];
                        w = dis[u] + potential[u] + cost[e] - potential[v];

                        if (dis[v] > w){
                            S.erase(v);
                            dis[v] = w, to[v] = e;
                            S.insert(v);
                        }
                    }
                }
            }
            if (dis[t] >= (INF >> 1)) break;

            aug = cap[to[t]];
            for (i = t; i != s; i = from[to[i]]) aug = min(aug, cap[to[i]]);
            for (i = t; i != s; i = from[to[i]]){
                cap[to[i]] -= aug;
                cap[to[i] ^ 1] += aug;
                mincost += (cost[to[i]] * aug);
            }
            for (i = 0; i <= n; i++) potential[i] = min(potential[i] + dis[i], INF);
            maxflow += aug;
        }
        return make_pair(mincost, maxflow);
    }
}



pii arr[34];
vector <pii> mills;

int main() {
    #ifdef dipta007
        READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        int n, k, m;
        cin >> n >> k >> m;

        mills.clear();
        CLR(adj);

        FOR(i,0,n-1)
        {
            string st;
            cin >> st;
            FOR(j,0,n-1)
            {
                if(st[j] == '#') adj[i][j] = 1;
                else if(st[j] == 'm')
                {
//                    adj[i][j] = 2;
                    mills.PB(MP(i,j));
                }
                else if(st[j] != '.')
                {
                    int kk = st[j] - 'A';
                    kk++;
                    arr[kk] = MP(i,j);
                }
            }
        }

        int lim[k+4];
        FOR(i,1,k) cin >> lim[i];

        mcmf::init(n*n+4, 0, n*n+2);
        FOR(i,1,k)
        {
            int ux = arr[i].ff + 1;
            int uy = arr[i].ss + 1;
            mcmf::addEdge(0, (ux-1)*n + uy, lim[i], 0);
            trace("src ->", ux, uy, lim[i]);
            bfs(arr[i].ff, arr[i].ss, n);

            FOR(j,0,m-1)
            {
                int vx = mills[j].ff + 1;
                int vy = mills[j].ss + 1;
                int d = dist[vx-1][vy-1];


                if(d <= n*n) {
                    trace(ux, uy, vx, vy, d);
                    mcmf::addEdge((ux-1)*n + uy, (vx-1)*n + vy, 1, d);//                    mcmf::addEdge((vx-1)*n + vy, (ux-1)*n + uy, 1, d);
                }
            }
        }

        FOR(j,0,m-1)
        {
            int vx = mills[j].ff + 1;
            int vy = mills[j].ss + 1;

            mcmf::addEdge((vx-1)*n+vy, n*n+2, 1, 0);
        }

        pair<ll,ll> p = mcmf::solve();
        trace(p.ff, p.ss);
        cout << "Case " << ci << ": " << p.ff << endl;
    }

    return 0;
}


