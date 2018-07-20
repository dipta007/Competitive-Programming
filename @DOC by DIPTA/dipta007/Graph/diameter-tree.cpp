/// Can be used in negative weighted tree
/// Can be used in normal weighted tree
/// Can be used in unweighted tree
ll dist[250004];
ll ans, X;

void dfs (int u, int from = -1)
{
    dist[u] = 0;
    ll mx = 0, nxtMx = 0;
    for (auto vp: adj[u])
    {
        int v = vp.ff;
        ll w = vp.ss;
        if (v == from) continue;
        dfs(v, u);
        dist[u] = max(dist[u], dist[v] + w);
        if (dist[v] + w > mx)
        {
            nxtMx = mx;
            mx = dist[v] + w;
        }
        else if (dist[v] + w > nxtMx)
        {
            nxtMx = dist[v] + w;
        }
    }
    ans = max(ans, mx + nxtMx);
}

inline ll getDiameterLength(ll x)
{
    X = x, ans = 0;
    dfs(1);
    return ans;
}
