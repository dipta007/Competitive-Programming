#define LOG 20
#define MAX 200010
namespace lca{
    long long sum[MAX];
    vector <int> ar[MAX], weight[MAX];
    int n, r, parent[MAX], depth[MAX], lg[MAX], dp[MAX][LOG];

    void init(int nodes, int root){
        n = nodes, r = root, lg[0] = lg[1] = 0;
        for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
        for (int i = 0; i <= n; i++) ar[i].clear(), weight[i].clear();
    }

    void add_edge(int u, int v, int w){
        ar[u].push_back(v), weight[u].push_back(w);
        ar[v].push_back(u), weight[v].push_back(w);
    }

    int lca(int a, int b){
        if (a == b) return a;
        if (depth[a] < depth[b]) swap(a, b);

        int diff = depth[a] - depth[b];
        for (int i = lg[diff]; i >= 0; i--){
            if ((depth[a] - (1 << i)) >= depth[b]) a = dp[a][i];
        }
        if (a == b) return a;

        for (int i = lg[depth[a]]; i >= 0; i--){
            if (dp[a][i] != dp[b][i]){
                a = dp[a][i];
                b = dp[b][i];
            }
        }

        return (a == b) ? a : parent[a];
    }

    long long dis(int u, int v){
        int l = lca(u, v);
        long long res = sum[u] + sum[v] - (sum[l] << 1LL);
        return res;
    }

    void dfs(int u, int p){
        int len = ar[u].size();
        parent[u] = p;
        for (int i = 0; i < len; i++){
            int v = ar[u][i];
            int w = weight[u][i];
            if (v != p){
                sum[v] = sum[u] + w;
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        }
    }

    void build(){
        depth[r] = 0, sum[r] = 0;
        dfs(r, r);

        for (int l = 0; l <= lg[n]; l++){
            for (int i = 0; i < n; i++){
                if (!l) dp[i][l] = parent[i];
                else dp[i][l] = dp[dp[i][l - 1]][l - 1];
            }
        }
    }
}
