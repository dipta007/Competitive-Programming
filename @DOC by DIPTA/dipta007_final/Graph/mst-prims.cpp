// This function runs Prim's algorithm for constructing minimum
// weight spanning trees.
//
// Running time: O(|V|^2)
//
//   INPUT:   w[i][j] = cost of edge from i to j
//
//            NOTE: Make sure that w[i][j] is nonnegative and
//            symmetric.  Missing edges should be given -1
//            weight.
//
//   OUTPUT:  edges = list of pair<int,int> in minimum spanning tree
//            return total weight of tree

#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;

T Prim (const VVT &w, vector <pii> &edges)
{
    int n = w.size();
    vi found (n);
    vi prev (n, -1);
    VT dist (n, 1000000000);
    int src = 0;
    dist[src] = 0;

    while (src != -1)
    {
        found[src] = true;
        int best = -1;
        for (int k = 0; k < n; k++)
            if (!found[k])
            {
                if (w[src][k] != -1 && dist[k] > w[src][k])
                {
                    dist[k] = w[src][k];
                    prev[k] = src;
                }
                if (best == -1 || dist[k] < dist[best])
                    best = k;
            }
        src = best;
    }

    T tot_weight = 0;
    for (int i = 0; i < n; i++)
        if (prev[i] != -1)
        {
            edges.push_back (make_pair (prev[i], i));
            tot_weight += w[prev[i]][i];
        }
    return tot_weight;
}

int main()
{
    int ww[5][5] =
    {
        {0, 400, 400, 300, 600},
        {400, 0, 3, -1, 7},
        {400, 3, 0, 2, 0},
        {300, -1, 2, 0, 5},
        {600, 7, 0, 5, 0}
    };
    VVT w(5, VT(5));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            w[i][j] = ww[i][j];

    // expected: 305
    //           2 1
    //           3 2
    //           0 3
    //           2 4

    vector <pii> edges;
    cout << Prim (w, edges) << endl;
    for (int i = 0; i < edges.size(); i++)
        cout << edges[i].first << " " << edges[i].second << endl;
}

