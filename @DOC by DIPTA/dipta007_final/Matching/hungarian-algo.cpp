/**
    For WEIGHTED BIPARTITE GRAPH
    1. Call hm::hungarian(row, col, adj, MAXIMIZE/MINIMIZE)

    1-based indexing
    match[i] contains the column to which row i is matched
**/
#define MAX 666
#define MAXIMIZE +1
#define MINIMIZE -1

#define INF (~0U >> 1)
#define CLR(ar) memset(ar, 0, sizeof(ar))
namespace hm{ /// hash = 581023
    bool visited[MAX];
    int U[MAX], V[MAX], P[MAX], way[MAX], minv[MAX], match[MAX], ar[MAX][MAX];

    int hungarian(int n, int m, int mat[MAX][MAX], int flag){
        CLR(U), CLR(V), CLR(P), CLR(ar), CLR(way);

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                ar[i][j] = mat[i][j];
                if (flag == MAXIMIZE) ar[i][j] = -ar[i][j];
            }
        }
        if (n > m) m = n;

        int i, j, a, b, d, r, w;
        for (i = 1; i <= n; i++){
            P[0] = i, b = 0;
            for (j = 0; j <= m; j++) minv[j] = INF, visited[j] = false;

            do{
                visited[b] = true;
                a = P[b], d = 0, w = INF;

                for (j = 1; j <= m; j++){
                    if (!visited[j]){
                        r = ar[a][j] - U[a] - V[j];
                        if (r < minv[j]) minv[j] = r, way[j] = b;
                        if (minv[j] < w) w = minv[j], d = j;
                    }
                }

                for (j = 0; j <= m; j++){
                    if (visited[j]) U[P[j]] += w, V[j] -= w;
                    else minv[j] -= w;
                }
                b = d;
            } while (P[b] != 0);

            do{
                d = way[b];
                P[b] = P[d], b = d;
            } while (b != 0);
        }
        for (j = 1; j <= m; j++) match[P[j]] = j;

        return (flag == MINIMIZE) ? -V[0] : V[0];
    }
}
