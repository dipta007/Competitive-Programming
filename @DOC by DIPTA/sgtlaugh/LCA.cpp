#include <bits/stdtr1c++.h>

#define LOG 20
#define MAX 200010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))

using namespace std;

namespace lca{ /// LCA of undirected tree, 0-based index
    vector <int> ar[MAX];
    int n, r, parent[MAX], depth[MAX], lg[MAX], dp[MAX][LOG];

    void init(int nodes, int root){
        n = nodes, r = root, lg[0] = lg[1] = 0;
        for (int i = 0; i <= n; i++) ar[i].clear();
        for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
    }

    void add_edge(int u, int v){
        ar[u].push_back(v);
        ar[v].push_back(u);
    }

    int lca(int a, int b){
        if (a == b) return a;
        if (depth[a] < depth[b]) swap(a, b);

        for (int i = lg[depth[a] - depth[b]]; i >= 0; i--){
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

    void dfs(int i, int p){
        int j, len = ar[i].size();
        for (j = 0, parent[i] = p; j < len; j++){
            if (ar[i][j] != p){
                depth[ar[i][j]] = depth[i] + 1;
                dfs(ar[i][j], i);
            }
        }
    }

    void build(){
        depth[r] = 0;
        dfs(r, r);

        for (int l = 0; l <= lg[n]; l++){
            for (int i = 0; i < n; i++){
                if (!l) dp[i][l] = parent[i];
                else dp[i][l] = dp[dp[i][l - 1]][l - 1];
            }
        }
    }
}

int main(){

}
