/// Dinic's algorithm for directed graphs (0 based index for graphs)
/// For undirected graphs, just add two directed edges

namespace flow
{
    struct edge
    {

        int u, v;
        ll cap, flow;
        edge() {}
        edge(int a, int b, ll c, ll f)
        {
            u = a, v = b, cap = c, flow = f;
        }
    };

    vector <int> adj[N];
    vector <edge> E;
    int n, source, sink, ptr[N], len[N], dis[N], Q[N];

    inline void init(int nodes, int s, int t)
    {
        CLR(len);
        E.clear();
        n = nodes, source = s, sink = t;
        for (int i = 0; i < N; i++) adj[i].clear();
    }

    // Adds a directed edge with capacity c
    inline void addEdge(int a, int b, long long cap, long long flow = 0)
    {

        adj[a].push_back(E.size());
        E.push_back(edge(a, b, cap, flow));
        len[a]++;

        adj[b].push_back(E.size());
        E.push_back(edge(b, a, 0, 0));
        len[b]++;

    }

    inline bool bfs()
    {

        int cur, j, k, id, f = 0, l = 0;
        SET(dis);
        dis[source] = 0, Q[l++] = source;

        while (f < l && dis[sink] == -1)
        {
            cur = Q[f++];
            for (k = 0; k < len[cur]; k++)
            {
                id = adj[cur][k];
                if (dis[E[id].v] == -1 && E[id].flow < E[id].cap)
                {
                    Q[l++] = E[id].v;
                    dis[E[id].v] = dis[cur] + 1;
                }
            }
        }

        return (dis[sink] != -1);
    }

    long long dfs(int s, ll flow)
    {
        if (s == sink || !flow) return flow;
        while (ptr[s] < len[s])
        {
            int id = adj[s][ptr[s]];
            if (dis[E[id].v] == dis[s] + 1)
            {
                ll x = dfs(E[id].v, min(flow, E[id].cap - E[id].flow));
                if (x)
                {
                    E[id].flow += x, E[id ^ 1].flow -= x;
                    return x;
                }
            }
            ptr[s]++;
        }
        return 0;
    }

    long long dinic()
    {
        ll res = 0, flow;

        while (bfs())
        {
            CLR(ptr);
            while (flow = dfs(source, INF))
            {
                res += flow;
            }
        }
        return res;
    }
}

namespace nodeflow
{
    void init(int n, int source, int sink)
    {
        //think about the sink, it can be sink * 2
        flow::init(n * 2, source * 2, sink * 2 + 1);
        for (int i = 0; i <= n; i++)
        {
            flow::addEdge(i * 2, i * 2 + 1, 1);
        }
    }

    void addEdge(int a, int b, ll cap)
    {
        flow::addEdge(a * 2 + 1, b * 2, cap);
        //For Bi-directional Edge
        //flow::addEdge(b * 2 + 1, a * 2 , cap);
    }

    long long dinic()
    {
        return flow::dinic();
    }
}

