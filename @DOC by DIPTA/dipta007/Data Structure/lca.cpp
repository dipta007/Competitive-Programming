/**
Procedure:
    1. Set the parent in par[]
    2. Call calcLCA(NODE) - 0 indexed
    3. Call findLCA(x, y)
Time Complexity: log(n)
**/
#define SIZE 10000
int arr[SIZE];
int sparse[22][SIZE];
int par[SIZE];
void calcLCA( int n )
{
    ///Base case is parent of each node
    for ( int i = 0; i < n; i++ ) {
        sparse[0][i] = par[i];
    }
    int two = 1;
    for ( int i = 1; i < 22; i++ ) {
        if ( two > n ) {
            height = i;
            break;
        }
        for ( int j = 0; j < n; j++ ) {
            /// sparse[i][j]: I have sparse[i-1]
            int p = sparse[i-1][j];
            if ( p == -1 ) sparse[i][j] = -1;
            else sparse[i][j] = sparse[i-1][p];
        }

        two *= 2;
    }
}
int findLCA ( int u, int v )
{
    if ( level[u] > level[v] ) swap ( u, v );
    int dif = level[v] - level[u];
    if ( dif ) {
        int two = power(2,height);
        for ( int i = height; i >= 0; i--, two /= 2 ) {
            if ( two > dif ) continue;
            v = sparse[i][v];
        }
    }
    if ( u == v ) return u;
    for ( int i = height; i >= 0; i--) {
        if ( sparse[i][u] == sparse[i][v] ) continue;

        u = sparse[i][u];
        v = sparse[i][v];
    }
    return sparse[0][u];
}


