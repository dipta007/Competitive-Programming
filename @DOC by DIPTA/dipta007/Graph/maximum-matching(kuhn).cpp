const int NODE = 10004;

/***
    Minimum vertex cover = Maximum matching
    Minimum edge cover = number of vertices - Maximum matching
    Maximum independent set = Minimum edge cover

    Vertex cover is the number of edges to cover all the vertices
    Edge cover is the of vertices to cover all the edges
    Independent set is the set of vertices such that no one has connection with each other
***/

/// Let the nodes from 1 to n are for left
/// And n+1 to n+m are for right
/// Then we have to connect edge by (1,n+3)
/// And call by kuhn.solve(n)
struct KUHN{
    int left[NODE], right[NODE], vis[2*NODE], cc; ///Node double in vis for vertex print
    vector<int> adj[NODE];

    KUHN() : cc(1) {}

    bool tryK ( int v ) {
        if ( vis[v] == cc ) return false;
        vis[v] = cc;
        for ( int i = 0; i < (int) adj[v].size(); i++ ) {
            int t = adj[v][i];
            if ( right[t] == -1 ) {
                right[t] = v; left[v] = t;
                return true;
            }
        }
        for ( int i = 0; i < (int)adj[v].size(); i++ ) {
            int t = adj[v][i];
            if ( tryK ( right[t] ) ) {
                right[t] = v; left[v] = t;
                return true;
            }
        }
        return false;
    }

    int match(int n) {
        int res = 0;
        bool done;
        SET(left); SET(right);
        do {
            done = true; cc++;
            FOR(i,0,n) {
                if(left[i]==-1 && tryK(i)) {
                    done = false;
                }
            }
        } while(!done);
        FOR(i,0,n) res += (left[i]!=-1);
        return res;
    }

    void clear( int n ) {
        FOR(i,0,n) adj[i].clear();
    }

    void add_edge(int x, int y) {
        adj[x].PB(y);
        adj[y].PB(x);
    }
}kuhn;

