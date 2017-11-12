#define edge pair < pii, ll >

vector < edge > edges;
const int MAX = 204;
ll dist[204];

int bellmanFord(int n, int src, int dest=0)
{
    repI(i, 201) dist[i] = LLONG_MAX;

    dist[src] = 0;
    FOR(step, 1, n-1)
    {
        for(auto e: edges)
        {
            int u = e.ff.ff;
            int v = e.ff.ss;
            ll w = e.ss;

            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    /// For finding negative cycle
//    for(auto e: edges)
//    {
//        int u = e.ff.ff;
//        int v = e.ff.ss;
//        ll w = e.ss;
//
//        if(dist[v] > dist[u] + w)
//        {
//            return -1;
//        }
//    }

    return dist[dest];
}
