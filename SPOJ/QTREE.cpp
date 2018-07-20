#include <bits/stdc++.h>
using namespace std;

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
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
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    sf scanf
#define    pf printf
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
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

int t, n, m;

#define NIL -INF
#define MAX 50010
#define OPT(a, b) max((a), (b))
#define jump(x) ((num[x] == 0) ? -1 : down[up[x]])

/// Heavy Light Decomposition on Trees, 0 based indices
/// With RMQ support for edges
/// Define the operation, default is +
/// x * NIL = x, NIL = 0 for addition/subtraction, 1 for multiplication, INF/-INF for min/max, etc
/// RMQ to add values on edges, if required to set/replace values modify appropriately

namespace hld{ /// hash = 163953
    int r, n, id;
    vector <int> adj[MAX], weight[MAX];
    int nodeval[MAX], lazy[4 * MAX], tree[4 * MAX]; /// RMQ
    int parent[MAX], children[MAX], height[MAX], num[MAX], up[MAX], down[MAX]; /// HLD

    /// num[i] = 0 if the edge from i to parent[i] is not heavy, otherwise num[i] = unique id of the heavy edge
    /// down[i] = -1 if there is no heavy edge from i to it's children, otherwise down[i] = node number of the heavy child of i
    /// up[i] = i, if i is root, otherwise up[i] = node number of parent of i following only heavy up edges and one last light edge

    void dfs(int i, int p){
        parent[i] = p, children[i] = 1;
        if (i != p) height[i] = height[p] + 1;

        int j, x, len = adj[i].size();
        for (j = 0; j < len; j++){
            x = adj[i][j];
            if (x != p){
                dfs(x, i);
                nodeval[x] = weight[i][j];
                children[i] += children[x];
            }
        }
    }

    /// build heavy light decomposition
    void build(int i, int p){ /// hash = 989687
        up[i] = i;
        if (num[i]) up[i] = up[p];

        int j, x, h = -1, l = adj[i].size();
        for (j = 0; j < l; j++){
            x = adj[i][j];
            if ((x != p) && ((children[x] << 1) >= children[i])) h = x;
        }

        if (h != -1){
            num[h] = ++id;
            build(h, i);
        }
        for (j = 0, down[i] = h; j < l; j++){
            x = adj[i][j];
            if ((x != p) && (x != h)) build(x, i);
        }
    }

    void update_rmq(int idx, int a, int b, int l, int r, int x); /// RMQ update defined for build
    void build(int root){
        r = root, id = 0;
        height[r] = 0, nodeval[r] = NIL;

        dfs(r, r);
        build(r, r);
        for (int i = 0; i < n; i++){
            if (up[i] == i) up[i] = parent[i];
        }

        /// Builds RMQ
        CLR(lazy);
        for (int i = 0; i < (MAX << 2); i++) tree[i] = NIL;
        for (int i = 0; i < n; i++){
            if (num[i]) update_rmq(1, 1, id, num[i], num[i], nodeval[i]);
            trace(i, nodeval[i]);
        }
    }
    void build(){
        build(0); /// Root set to 0 by default!
    }

    int lca(int a, int b){
        while (up[a] != up[b]){
            if (height[up[a]] > height[up[b]]) a = up[a];
            else b = up[b];
        }

        if (a == b) return a;
        if (num[a] && num[b]){
            if (height[a] < height[b]) return a;
            else return b;
        }
        return up[a];
    }

    void add_edge(int a, int b, int w){
        adj[a].push_back(b), weight[a].push_back(w);
        adj[b].push_back(a), weight[b].push_back(w);
    }

    void init(int nodes){
        CLR(num), n = nodes;
        for (int i = 0; i < MAX; i++) adj[i].clear(), weight[i].clear();
    }

    /************** RMQ functions **************/


    /// Change lazy propagation accordingly
    /// Note lazy and updates set for adding values in node, update if set/replace operation
    inline void push(int idx, int a, int b){
        int c = (a + b) >> 1, d = c + 1, p = idx << 1, q = p | 1;
        if (lazy[idx] >= 0){
            tree[idx] = (lazy[idx] * (b - a + 1)); /// Change lazy according to operation
            if (a != b) lazy[p] = lazy[idx], lazy[q] = lazy[idx]; /// Change lazy according to operation
            lazy[idx] = -1;
        }
    }

    /// Change query accordingly
    int query_rmq(int idx, int a, int b, int l, int r){
        int c = (a + b) >> 1, d = c + 1, p = idx << 1, q = p | 1;

        push(idx, a, b);
        if (a == l && b == r) return tree[idx];
        else if (r <= c) return query_rmq(p, a, c, l, r);
        else if (l >= d) return query_rmq(q, d, b, l, r);
        else return OPT(query_rmq(p, a, c, l, c), query_rmq(q, d, b, d, r));
    }

    /// Change update accordingly
    void update_rmq(int idx, int a, int b, int l, int r, int x){ /// hash = 487503
        int p = (idx << 1), q = p + 1, c = (a + b) >> 1, d = c + 1;

        if (a == l && b == r) lazy[idx] = x; /// Change lazy according to operation, change here if set
        push(idx, a, b);
        if (a == l && b == r) return;

        if (r <= c){
            push(q, d, b);
            update_rmq(p, a, c, l, r, x);
        }
        else if (l >= d){
            push(p, a, c);
            update_rmq(q, d, b, l, r, x);
        }
        else{
            update_rmq(p, a, c, l, c, x);
            update_rmq(q, d, b, d, r, x);
        }

        tree[idx] = OPT(tree[p], tree[q]);
    }

    /************** HLD + RMQ **************/

    /// Sum of all edges in the path from u to l, l must be an ancestor of u
    int query_tree(int u, int l){ /// hash = 486879
        int res = NIL;
        while (height[u] > height[l]){
            if (num[u]){
                int v = jump(u);
                if (height[v] <= height[l]) v = down[l];
                res = OPT(res, query_rmq(1, 1, id, num[v], num[u]));
                u = parent[v];
            }
            else res = OPT(nodeval[u], res), u = parent[u];
        }
        return res;
    }

    /// Sum of all edges in the path from u to v
    int query(int u, int v){
        int l = lca(u, v), res = NIL;
        res = OPT(res, query_tree(u, l));
        res = OPT(res, query_tree(v, l));
        return res;
    }

    /// Add w to all edges in the path from u to l, l must be an ancestor of u
    void update_tree(int u, int l, int w){
        while (height[u] > height[l]){
            if (num[u]){
                int v = jump(u);
                if (height[v] <= height[l]) v = down[l];
                update_rmq(1, 1, id, num[v], num[u], w);
                u = parent[v];
            }
            else nodeval[u] = w, u = parent[u]; /// Change here if set instead of add
        }
    }

    /// Add w to all edges in the path from u to v
    void update(int u, int v, int w){
        int l = lca(u, v);
        update_tree(u, l, w);
        update_tree(v, l, w);
    }
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        int n;
        cin >> n;

        hld::init(n);
        vector < pii > vv;
        FOR(i,1,n-1)
        {
            int u,v,w;
            cin >> u >> v >> w;
            u--, v--;
            hld::add_edge(u, v, w);

            vv.PB( MP(u, v) );
        }

        hld::build();

        string st;
        cin >> st;
        while(st != "DONE") {
            int x, y;
            cin >> x >> y;
            if(st[0] == 'Q') {
                    x--, y--;
                cout << hld::query(x, y) << endl;
            }
            else {
                hld::update(vv[x-1].ff, vv[x-1].ss, y);
            }
            cin >> st;
        }
    }

    return 0;
}


