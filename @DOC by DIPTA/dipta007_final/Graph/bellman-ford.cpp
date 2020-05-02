// This function runs the Bellman-Ford algorithm for single source
// shortest paths with negative edge weights.  The function returns
// false if a negative weight cycle is detected.  Otherwise, the
// function returns true and dist[i] is the length of the shortest
// path from source to i.
//
// Running time: O(|V|^3)
//
//   INPUT:   source, w[i][j] = cost of edge from i to j
//   OUTPUT:  dist[i] = min weight path from source to i
//            par[i] = previous node on the best path from the
//                      source node

int par[MAX];
int dist[MAX];
vii w;

bool BellmanFord (const VVT &w, int source)
{
    int n = w.size();
    set(par);
    setInf(dist);
    dist[source] = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[j] > dist[i] + w[i][j])
                {
                    if (k == n-1) return false;
                    dist[j] = dist[i] + w[i][j];
                    par[j] = i;
                }
            }
        }
    }
    return true;
}

