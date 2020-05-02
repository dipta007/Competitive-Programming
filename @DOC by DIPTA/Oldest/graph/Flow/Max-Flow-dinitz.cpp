/**
max flow (dinitz algorithm)
works on undirected graph
can have loops, multiple edges, cycles
**/


/**
*********   MUST be 1 indexed
*********   0 can not be a node
**/
namespace mf
{
    int src, snk, nNode, nEdge;
    const int MAXN = 100005;
    const int MAXE = 300005; /// MAXE = twice the number of edges

    int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
    int flow[MAXE], cap[MAXE], nextt[MAXE], to[MAXE];

    inline void init(int _src, int _snk, int _n) {
        src = _src, snk = _snk, nNode = _n, nEdge = 0;
        SET(fin);
    }

    /// for directed graph _cap2 = 0
    inline void addEdge(int u, int v, int _cap, int _cap2) {
        to[nEdge] = v, cap[nEdge] = _cap, flow[nEdge] = 0;
        nextt[nEdge] = fin[u], fin[u] = nEdge++;
        to[nEdge] = u, cap[nEdge] = _cap2, flow[nEdge] = 0;
        nextt[nEdge] = fin[v], fin[v] = nEdge++;
    }

    bool bfs() {
        int st, en, i, u, v;
        SET(dist);
        dist[src] = st = en = 0;
        Q[en++] = src;
        while(st < en) {
            u = Q[st++];
            for(i=fin[u]; i>=0; i=nextt[i]) {
                v = to[i];
                if(flow[i] < cap[i] && dist[v]==-1) {
                    dist[v] = dist[u]+1;
                    Q[en++] = v;
                }
            }
        }
        return dist[snk]!=-1;
    }

    int dfs(int u, int fl) {
        if(u==snk) return fl;
        for(int &e=pro[u], v, df; e>=0; e=nextt[e]) {
            v = to[e];
            if(flow[e] < cap[e] && dist[v]==dist[u]+1) {
                df = dfs(v, min(cap[e]-flow[e], fl));
                if(df>0) {
                    flow[e] += df;
                    flow[e^1] -= df;
                    return df;
                }
            }
        }
        return 0;
    }

    int dinitz() {
        ll ret = 0;
        int df;
        while(bfs()) {
            for(int i=1; i<=nNode; i++) pro[i] = fin[i];
            while(true) {
                df = dfs(src, INF);
                if(df) ret += df;
                else break;
            }
        }
        return ret;
    }
}

