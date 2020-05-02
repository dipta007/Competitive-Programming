//Cycle contains which scc node belongs too.

struct SCC{
    int num[NODE], low[NODE], col[NODE], cycle[NODE], st[NODE];
    int tail, cnt, cc, scc_cnt;
    vi adj[NODE];

    SCC():tail(0),cnt(0),cc(0) {}
    void clear () {
        cc += 3;
        FOR(i,0,NODE-1) adj[i].clear();
        tail = 0;
    }
    void tarjan ( int s ) {
        num[s] = low[s] = cnt++;
        col[s] = cc + 1;
        st[tail++] = s;
        FOR(i,0,(int)adj[s].size()-1) {
            int t = adj[s][i];
            if ( col[t] <= cc ) {
                tarjan ( t );
                low[s]=MIN(low[s],low[t]);
            }
            /*Back edge*/
            else if (col[t]==cc+1)
                low[s]=MIN(low[s],low[t]);
        }
        if ( low[s] == num[s] ) {
            scc_cnt++;
            while ( 1 ) {
                int temp=st[tail-1];
                tail--;
                col[temp] = cc + 2;
                cycle[temp] = s;
                if ( s == temp ) break;
            }
        }
    }
    void shrink( int n ) {
        FOR(i,0,n){
            FOR(j,0,(int)adj[i].size()-1){
                adj[i][j] = cycle[adj[i][j]]; ///Careful. This will create self-loop. Just ignore i->i edges when processing.
            }
        }
        FOR(i,0,n){
            if ( cycle[i] == i ) continue;
            int u = cycle[i];
            FOR(j,0,(int)adj[i].size()-1){
                int v = adj[i][j];
                adj[u].PB ( v );
            }
            adj[i].clear();
        }
        FOR(i,0,n){ ///Not always necessary
            sort ( ALL(adj[i]) );
            UNIQUE(adj[i]);
        }
    }

    int findSCC( int n, int strt = 0 ) {
        scc_cnt = 0;
        FOR(i,strt,n) {
            if ( col[i] <= cc ) {
                tarjan ( i );
            }
        }
        return scc_cnt;
    }

    void add_edge(int x, int y) {
        adj[x].PB(y);
    }
};

