stack<int >s;
vector<int >adj[mx];
bool vis[mx];
void dfs(int a){
    s.push(a);
    while(!s.empty()){
        int x = s.top();
        if(!vis[x]){
            vis[x] = true;
            forstl(it,adj[x]){
                if(vis[*it]) continue;
                s.push(*it);
            }
        }else{
            s.pop();
        }
    }
}

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    int n  = II,m = II;
    rep(i,m){
        int u = II,v = II;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    For(i,n)if(!vis[i]) dfs(i);
}
