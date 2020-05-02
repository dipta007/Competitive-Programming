///Graph Theory

///BFS

///1. Connectivity

#define NODE 1001

int visited[NODE+10];
int parent[NODE+10];

vector<int> adj[NODE+10];

void bfs ( int s ) {

    ///Nothing is visited initially
    memset ( visited, 0, sizeof visited );

    visited[s] = 1; ///Source is visited
    parent[s] = -1; ///This has no parent


    queue<int> q;

    q.push ( s );

    while ( q.empty() == false ) {
        s = q.front(); q.pop();

        ///From this node to neighbors
        for ( int i = 0; i < adj[s].size(); i++ ) {
            int t = adj[s][i];

            if ( t != par[s] && visited[t] == 1 ) {
                printf ( "Cycle detected\n" );
            }

            if ( visited[t] == 1 ) continue; ///Already visited

            parent[t] = s;
            visited[t] = 1;
            q.push ( t );
        }
    }
}
