/**************Disjoint Set Union ****************/
/*************************************************/
int const SIZE = 100000;
class DSU {
    int dsu[SIZE];

public:
    void clear( int n ) {
        for ( int i = 0; i <= n; i++ ) dsu[i] = i;
    }

    int findUnion ( int x ) {
        if ( dsu[x] == x ) return x;

//        int t = findUnion ( dsu[x] );
//        dsu[x] = t;
//        return dsu[x];

        return dsu[x] = findUnion ( dsu[x] );
    }

    void mergeUnion ( int x, int y ) {
//        int x2 = findUnion ( x );
//        int y2 = findUnion ( y );
//
//        dsu[x2] = y2; /// dsu[y2] = x2

        dsu[findUnion(x)] = findUnion(y);

    }
}mst;


/*************************************************/
/*******************Compare Function**************/

char buf[10000];

vector<int> v;

///Compare function for any structure

struct EDGE {
    int a, b, cost;
}edge[1000];

bool compare_xyz ( const EDGE &a, const EDGE &b ) {
    if ( a.cost < b.cost ) return true;
    else return false;
}

/*************************************************/
/*****************Minimum Spanning Tree***********/

void mstSampleCode() {
     ///Edge input taken: M edges

    mst.clear ( n );

    sort ( edge, edge + M, compare_xyz );

    int res = 0;
    for ( int i = 0; i < m; i++ ) {
        int a = edge[i].a;
        int b = edge[i].b;

        int cost = edge[i].cost;

        a = mst.findUnion ( a );
        b = mst.findUnion ( b );

        if ( a == b ) {
            ///They are in same component
        }
        else {
            res += cost;
            mst.mergeUnion ( a, b );
        }
    }
}


/*************************************************/
/*****************Warshall Algo*******************/

long long mat[NODE][NODE];
int middleMan[NODE][NODE];

vector<int> path;
void printPath ( int a, int b ) {

    int k = middleMan[a][b];

    if ( k == -1 ) {
        path.push_back ( b );
    }
    else {
        printPath ( k, b );
        printPath ( a, k );
    }
}

void sampleWarshall() {
    ///Take input of all edge

    for ( int i = 0; i <= n; i++ ) {
        for ( int j = 0; j <= n; j++ ) {
            mat[i][j] = inf;
        }
    }

    ///Build the initial matrix

    ///Lets M edge
    FOR(i,0,m-1) {

        ///A -> B cost C
        mat[a][b] = c;
    }


    ///Perform warshall

    for ( int k = 1; k <= n; k++ ) {
        for ( int i = 1; i <= n; i++ ) {
            for ( int j = 1; j <= n; j++ ) {
                if ( mat[i][k] + mat[k][j] < mat[i][j] ) {
                    mat[i][j] = mat[i][k] + mat[k][j];
                    middleMan[i][j] = k;
                }
            }
        }
    }

    printPath ( 2, 9 );
    path.push_back ( 2 );

    reverse ( path.begin(), path.end() );
}


/*************************************************/
/**************Dijkstra Algo**********************/
int vis[NODE];
int done[NODE];

void dijkstra( int s ) {
    memset ( done, 0, sizeof done );

    priority_queue< pair<int,int> > pq;
    for ( int i = 0; i < n; i++ ) vis[i] = inf;

    pq.push( make_pair(-0,s) );

    while ( !pq.empty() ) {

        int s = pq.top().second;
        int cost = pq.top().first * -1;

        pq.pop();

        if ( done[s] == 1 ) {
            continue;
        }

        for ( int i = 0; i < adj[s].size(); i++ ) {
            int t = adj[s][i].first;
            int e = adj[s][i].second;

            if ( cost + e < vis[t] ) {
                vis[t] = cost + e;
                pq.push ( make_pair ( -vis[t], t ) );
            }
        }

        done[s] = 1;
    }

}

/*************************************************/
/***************Topo Sort*************************/

#define WHITE 0
#define GRAY 1
#define BLACK 2

bool flagCycle;
int vis[NODE];

vector<int> topo;

int dfs ( int s ) {
    vis[s] = GRAY;

    for ( int i = 0; i < adj[s].size(); i++ ) {
        int t = adj[s][i];

        if ( vis[t] == WHITE ) {
            dfs ( t );
        }
        else if ( vis[t] == GRAY ) {
            ///Cycle detected
            flagCycle = true;
        }
    }

    vis[s] = BLACK;
    topo.push_back ( s );
}


/*************************************************/
/****************Strongly Connected Component*****/

#define NODE 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int disc[NODE], low[NODE];
int vis[NODE];
int globalCnt = 0;

vector<int> tarjan;

int cycle[NODE];

int SCC ( int s ) {
    vis[s] = GRAY;
    disc[s] = low[s] = globalCnt++;
    tarjan.push_back(s);

    for ( int i = 0; i < adj[s].size(); i++ ) {
        int t = adj[s][i];

        if ( vis[t] == WHITE ) { ///This is tree edge
            SCC ( t );
            low[s] = min ( low[s], low[t] );
        }
        else if ( vis[t] == GRAY ) { ///This is back edge
            ///Cycle detected
            flagCycle = true;
            low[s] = min ( low[s], low[t] );
        }
    }

    if ( disc[s] == low[s] ) {
        while ( 1 ) {
            int lastNode = tarjan.back();

            cycle[lastNode] = s;

            tarjan.pop_back();
            vis[lastNode] = BLACK;
            if ( lastNode == s ) break;
        }
    }

}

