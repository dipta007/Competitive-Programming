#include <bits/stdtr1c++.h>

#define MAX 30010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

vector <int> ar[MAX];
int t, n, m, val[MAX], tree[MAX << 2];
int h, root, subtree[MAX], depth[MAX], parent[MAX], head[MAX], tail[MAX], chain[MAX], num[MAX];

void dfs(int i, int p){
    parent[i] = p;
    subtree[i] = 1;
    if (i != p) depth[i] = depth[p] + 1;

    int len = ar[i].size();
    for (int j = 0; j < len; j++){
        int x = ar[i][j];
        if (x != p){
            dfs(x, i);
            subtree[i] += subtree[x];
        }
    }
}

void hld(int i, int p){
    int heavy = -1;
    int len = ar[i].size();

    chain[i] = i;
    if (head[i] != -1) chain[i] = chain[p];

    for (int j = 0; j < len; j++){
        int x = ar[i][j];
        if ((x != p) && ((subtree[x] << 1) >= subtree[i])){
            heavy = x;
            head[x] = i;
            tail[i] = x;
        }
    }


    if (heavy != -1){
        num[heavy] = ++h;
        hld(heavy, i);
    }

    for (int j = 0; j < len; j++){
        int x = ar[i][j];
        if ((x != p) && (x != heavy)) hld(x, i);
    }
}

void HeavyLight(){
    h = 0;
    root = 0;
    memset(head, -1, sizeof(head));
    memset(tail, -1, sizeof(tail));

    depth[root] = 0;
    dfs(root, root);
    hld(root, root);
    for (int i = 0; i < n; i++){
        if (i == root) chain[i] = 0;
        else if (chain[i] == i) chain[i] = parent[i];
    }
}

int lca(int a, int b){
    while (chain[a] != chain[b]){
        if (depth[chain[a]] > depth[chain[b]]) a = chain[a];
        else b = chain[b];
    }

    if (a == b) return a;
    if (head[a] != -1 && head[b] != -1){
        if (depth[a] < depth[b]) return a;
        else return b;
    }

    return chain[a];
}

int query(int idx){
    int res = 0;
    while (idx > 0){
        res += tree[idx];
        idx ^= (idx & -idx);
    }

    return res;
}

void update(int idx, int value){
    while (idx <= h){
        tree[idx] += value;
        idx += (idx & -idx);
    }
}

void RMQ(){
    clr(tree);
    for (int i = 0; i < n; i++){
        if (head[i] != -1){
            update(num[i], val[i]);
        }
    }
}

void update_node(int u, int v){
    if (head[u] != -1){
        update(num[u], -val[u]);
        val[u] = v;
        update(num[u], val[u]);
    }
    else val[u] = v;
}

int F(int v){
    int res = 0;

    for (; ;){
        if (head[v] != -1){
            int x = chain[v];
            int d = depth[v] - depth[x];
            int idx = num[v];
            int r = query(idx) - query(idx - d);
            res += r;
            v = x;
        }
        else{
            res += val[v];
            if (!v) break;
            v = parent[v];
        }
    }
    return res;
}

int Solve(int a, int b){
    int l = lca(a, b);
    int x = F(a) + F(b);
    int y = F(l) << 1;
    int res = (x - y) + val[l];
    return res;
}

int main(){
    int T = 0, i, j, q, a, b;

    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for (i = 0; i <= n; i++) ar[i].clear();

        for (i = 0; i < n; i++) scanf("%d", &val[i]);
        for (i = 1; i < n; i++){
            scanf("%d %d", &a, &b);
            ar[a].push_back(b);
            ar[b].push_back(a);
        }

        HeavyLight();
        RMQ();

        printf("Case %d:\n", ++T);
        scanf("%d", &m);
        while (m--){
            scanf("%d %d %d", &q, &a, &b);
            if (!q) printf("%d\n", Solve(a, b));
            else update_node(a, b);
        }
    }
    return 0;
}
