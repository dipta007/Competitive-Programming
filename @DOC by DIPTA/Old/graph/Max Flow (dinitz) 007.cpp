/// ********** FASTER one *******************///
namespace mf
{
    const int MAXN = 10004;
    struct edge {
        int a, b, cap, flow ;
        edge(int _a,int _b,int _c,int _d) {
            a=_a,b=_b,cap=_c,flow=_d;
        }
    } ;

    int INF = 1500000001 ;

    int n, s, t, d [ MAXN*2 ] , ptr [ MAXN*2 ] , q [ MAXN*2*10 ] ;
    vector < edge > e ;
    vector < int > g [ MAXN * 2 ] ;

    void addEdge ( int a, int b, int cap ,int cap2) {
        edge e1 =edge( a, b, cap, 0 ) ; /// forward cap
        edge e2 =edge( b, a, cap2 , 0 ) ; /// backward cap change here if needed
        g [ a ] . push_back ( ( int ) e. size ( ) ) ;
        e. push_back ( e1 ) ;
        g [ b ] . push_back ( ( int ) e. size ( ) ) ;
        e. push_back ( e2 ) ;
    }

    bool bfs ( ) {
        int qh = 0 , qt = 0 ;
        q [ qt ++ ] = s ;
        memset ( d, -1 , sizeof d ) ;
        d [ s ] = 0 ;
        while ( qh < qt && d [ t ] == - 1 ) {
            int v = q [ qh ++ ] ;
            for ( size_t i = 0 ; i < g [ v ] . size ( ) ; ++ i ) {
                int id = g [ v ] [ i ] ,
                    to = e [ id ] . b ;
                if ( d [ to ] == - 1 && e [ id ] . flow < e [ id ] . cap ) {
                    q [ qt ++ ] = to ;
                    d [ to ] = d [ v ] + 1 ;
                }
            }
        }
        return d [ t ] != - 1 ;
    }

    int dfs ( int v, int flow ) {
        if ( ! flow )  return 0 ;
        if ( v == t )  return flow ;
        for ( ; ptr [ v ] < ( int ) g [ v ] . size ( ) ; ++ ptr [ v ] ) {
            int id = g [ v ] [ ptr [ v ] ] ,
                to = e [ id ] . b ;
            if ( d [ to ] != d [ v ] + 1 )  continue ;
            int pushed = dfs ( to, min ( flow, e [ id ] . cap - e [ id ] . flow ) ) ;
            if ( pushed ) {
                e [ id ] . flow += pushed ;
                e [ id ^ 1 ] . flow -= pushed ;
                return pushed ;
            }
        }
        return 0 ;
    }

    ll dinic ( ) {
        ll flow = 0 ;
        for ( ;; ) {
            if ( !bfs () )  break ;
            memset ( ptr, 0 , sizeof ptr ) ;
            while ( int pushed = dfs ( s, INF ) ) {
                flow += (ll)pushed ;
                if(pushed == 0)break;
            }
        }
        return flow ;
    }

    void init(int src, int dest , int nodes){
        e.clear();
        FOR(i,0,n+n) g[i].clear();
        n = nodes; s = src; t = dest;
    }
};




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
    const int MAXN = 104;
    const int MAXE = 20004; /// MAXE = twice the number of edges

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

    ll dinitz() {
        ll ret = 0;
        ll df;
        for(int i=1; i<=nNode; i++) pro[i] = fin[i];
        while(bfs()) {

            while(true) {
                df = dfs(src, INF);
                if(df) ret += df;
                else break;
            }
        }
        return ret;
    }
}

