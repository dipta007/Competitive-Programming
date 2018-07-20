///0-Based                  MO on Tree
map<int,int>mp;
vector<int>adj[N];
int st[N], en[N], node[N], counter, arr[N], ans[N];
int cnt[N], sum, visit[N];
int parent[N],sparse[N][22],level[N];
int magic = 320;
struct query{
    int l, r, id, _lca;
    query(){}
    query(int l, int r, int id, int _lca):l(l),r(r),id(id), _lca(_lca){}
}Q[N];
bool comp(query a, query b){
    int l1 = a.l/magic, l2 = b.l/magic;
    if(l1 != l2) return l1 < l2;
    return a.r < b.r;
}
void init(int n){
    CLR(cnt), CLR(visit), sum = 0;
    for(int i = 0; i <= n; i++)adj[i].clear();
}
void compress(int n){
    int id = 0;
    for(auto it : mp) mp[it.ff] = id++;
    for(int i = 0; i < n; i++) arr[i] = mp[arr[i]];
}
void dfs(int src, int from, int lvl){
    node[counter] = src;
    st[src] = counter ++;
    level[src] = lvl;
    for(auto v : adj[src]){
        if(v == from) continue;
        parent[v] = src;
        dfs(v, src, lvl+1);
    }
    node[counter] = src;
    en[src] = counter ++;
}
void lca(int n){
    SET(sparse);
    for(int i=0;i<n;i++)sparse[i][0]=parent[i];
    for(int j=1;(1<<j)<n;j++){
        for(int i=0;i<n;i++){
            if(sparse[i][j-1]!=-1)
            sparse[i][j]=sparse[sparse[i][j-1]][j-1];
        }
    }
}
int query(int p,int q){
    if(level[p]<level[q])swap(p,q);
    int log;
    for(log=1;1<<log<=level[p];log++);
    log--;
    for(int i=log;i>=0;i--){
        if(level[p]-(1<<i)>=level[q]){
                p=sparse[p][i];
        }
    }
    if(p==q)return p;
    for(int i=log;i>=0;i--){
        if(sparse[p][i]!=-1 &&sparse[p][i]!=sparse[q][i]){
            p=sparse[p][i];
            q=sparse[q][i];
        }
    }
    return parent[p];
}
void check(int cur){
    /*If a node is two times in the range then it will not
    influence the ans, visit array is checking that.*/
    if(visit[cur] && (--cnt[arr[cur]] == 0)) sum -= 1;
    else if(!visit[cur] && (++cnt[arr[cur]] == 1)) sum += 1;
    visit[cur] ^= 1;
}
int get_ans(){
    return sum;
}
void MO_on_Tree(int q){
    sort(Q,Q+q,comp);
    int l = 0, r = -1;
    for(int i=0; i < q; i++){
        while(l > Q[i].l)check(node[--l]);
        while(r < Q[i].r)check(node[++r]);
        while(l < Q[i].l)check(node[l++]);
        while(r > Q[i].r)check(node[r--]);
        int u = node[l], v = node[r];
        /*If lca is different then we have to handle the lca node separately*/
        if(Q[i]._lca != u && Q[i]._lca != v)check(Q[i]._lca);
        ans[Q[i].id] = get_ans();
        if(Q[i]._lca != u && Q[i]._lca != v)check(Q[i]._lca);
    }
    for(int i=0; i < q; i++){
        cout << ans[i] << endl;
    }
}

void ProcessInput(int n, int q){
    init(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i], mp[arr[i]];
    }
    compress(n);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v; u -= 1, v -= 1;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(0,-1, 0);
    lca(n);
    for(int i = 0; i < q; i++){
        int u, v; cin >> u >> v;
        u -= 1, v -= 1;
        Q[i]._lca = query(u,v), Q[i].id = i;
        if(st[u] > st[v])swap(u,v);
        if(u == Q[i]._lca) Q[i].l = st[u], Q[i].r = st[v];
        else Q[i].l = en[u], Q[i].r = st[v];
    }
    MO_on_Tree(q);
}

