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
// #include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define FOR(i, L, R) for (int i = (int)(L); i <= (int)(R); i++)
#define ROF(i, L, R) for (int i = (int)(L); i >= (int)(R); i--)
#define ALL(p) p.begin(), p.end()
#define ALLR(p) p.rbegin(), p.rend()
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define getI(a) scanf("%d", &a)
#define getII(a, b) scanf("%d%d", &a, &b)
#define getIII(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define getL(a) scanf("%lld", &a)
#define getLL(a, b) scanf("%lld%lld", &a, &b)
#define getLLL(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define getF(n) scanf("%lf", &n)
#define bitCheck(N, in) ((bool)(N & (1 << (in))))
#define bitOn(N, in) (N | (1 << (in)))
#define bitOff(N, in) (N & (~(1 << (in))))
#define bitFlip(a, k) (a ^ (1 << (k)))
#define bitCount(a) __builtin_popcount(a)
#define bitCountLL(a) __builtin_popcountll(a)
#define bitLeftMost(a) (63 - __builtin_clzll((a)))
#define bitRightMost(a) (__builtin_ctzll(a))
#define ranL(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define ranI(a, b) ((((ll)rand() * rand()) % ((b) - (a) + 1)) + (a))
#define ranF(a, b) (((double)rand() / RAND_MAX) * ((b) - (a)) + (a))
#define UNIQUE(V) (V).erase(unique((V).begin(), (V).end()), (V).end())
#define SETI(ar) memset(ar, 126, sizeof ar)

#define printbits(x, n) cout << #x << " = " << x << " = " << bitset<n>(x) << endl /// Least significant n bits of x, n must be constant
#define tobinary(x) string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(min(63, __builtin_clzll(x)), 64)
#define lastbits(x, n) cout << string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(64 - n, 64) << endl
#define firstbits(x, n) cout << string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(min(63, __builtin_clzll(x)), 64).substr(0, n) << endl;

#define ff first
#define ss second
#define sf scanf
#define pf printf

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;
#define FMT(...) (sprintf(CRTBUFF, __VA_ARGS__) ? CRTBUFF : 0)
char CRTBUFF[30000];

#ifdef dipta007
#define debug(args...)              \
    {                               \
        cerr << __LINE__ << " D: "; \
        dbg, args;                  \
        cerr << endl;               \
    }
#define trace(...)                           \
    {                                        \
        cerr << "Line " << __LINE__ << ": "; \
        __f(#__VA_ARGS__, __VA_ARGS__);      \
    }
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define debug(args...) /// Just strip off all debug tokens
#define trace(...)     ///yeeeee
#endif

struct debugger
{
    template <typename T>
    debugger &operator,(const T &v)
    {
        cerr << v << " ";
        return *this;
    }
} dbg;

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const double PI = 2.0 * acos(0.0);

ll MIN() { return INF; }
template <typename T, typename... Args>
inline T MIN(T a, Args... args) { return min(a, (T)MIN(args...)); }

ll MAX() { return -INF; }
template <typename T, typename... Args>
inline T MAX(T a, Args... args) { return max(a, (T)MAX(args...)); }

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

/***
    1. Call bridge.clear() for each node
    2. Call bridge.findBride(number of nodes, starting node(0,1) )
***/

#define BRIDGENODE 10010
class BridgeFinding
{
    int disc[BRIDGENODE]; ///Discovery time of nodes
    int low[BRIDGENODE];  ///Lowest back edge extension
    int col[BRIDGENODE];  ///Color for marking node

    int cnt; ///Timer
    int cc;  ///Color

    void tarjan(int s, int parentEdge)
    {
        disc[s] = low[s] = cnt++;
        col[s] = cc + 1;

        for (int i = 0; i < adj[s].size(); ++i)
        {

            int t = adj[s][i].ff;
            int edgeNumber = adj[s][i].ss;
            if (edgeNumber == parentEdge)
                continue; ///Don't use the same edge from parent

            if (col[t] <= cc)
            { ///New node. Discovery.

                tarjan(t, edgeNumber);
                low[s] = min(low[s], low[t]); ///Update back edge extension for S

                if (low[t] > disc[s])
                { ///Back edge of T did not go above S
                    /// This edge is Bridge
                    // cout << s << " " << t << "Sad" << endl;
                    mark[s][i] = 1;
                }
            }
            else if (col[t] == cc + 1)
            { ///Back Edge
                low[s] = min(low[s], disc[t]);
            }
        }
    }

  public:
    vector<pair<int, int>> adj[BRIDGENODE]; ///Enter target and edge number as pair
    vector<int> mark[BRIDGENODE];

    void clear(int n)
    {
        cnt = 1;
        cc += 3; ///cc is now 0. cc+1 is 1
        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
            mark[i].clear();
        }
    }

    void findBridge(int n, int start = 0)
    {
        for (int i = start; i <= n; i++)
        {
            if (col[i] <= cc)
            {
                tarjan(i, -1);
            }
        }
    }
} bridge;

int vis[10004];

int dfs(int u)
{
    vis[u] = 1;
    int ret = 1;
    FOR(i, 0, (int)bridge.adj[u].size() - 1)
    {
        int v = bridge.adj[u][i].ff;
        int m = bridge.mark[u][i];
        if (vis[v] == 0 && m == 0)
        {
            ret += dfs(v);
        }
    }
    return ret;
}

int main()
{
#ifdef dipta007
    //READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m)
    {
        int edge = 1;
        bridge.clear(n);
        FOR(i, 1, m)
        {
            int u, v;
            cin >> u >> v;
            bridge.adj[u].PB(MP(v, i));
            bridge.adj[v].PB(MP(u, i));

            bridge.mark[u].PB(0);
            bridge.mark[v].PB(0);
        }

        bridge.findBridge(n, 0);

        CLR(vis);
        int res = dfs(0);
        cout << res << endl;
    }

    return 0;
}
