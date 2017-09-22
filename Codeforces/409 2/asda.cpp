#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;
#define p_ii pair <int, int>
vector < p_ii > adjList[54];
int par[54];
int weight[54];
int tt;


struct HeapForMinimum
{
    int hh[2504]; /// array of weights
    int v[2504]; /// array of vertices
    int cap; /// size of min heap
    int SZ; /// Current size of min heap

    HeapForMinimum()
    {
        SZ = 0;
        cap = 2500;
    }

    /// to heapify a subtree at given index
    void heapify(int i)
    {
        int l = getLeftChild(i);
        int r = getRightChild(i);
        int smallest = i;
        if (l < SZ && hh[l] < hh[i])
            smallest = l;
        if (r < SZ && hh[r] < hh[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(hh[i], hh[smallest]);
            swap(v[i], v[smallest]);
            heapify(smallest);
        }
    }

    /// to get the par node
    int getparNode(int i) { return (i-1)/2; }

    /// to get left child
    int getLeftChild(int i) { return (2*i + 1); }

    /// to get right child
    int getRightChild(int i) { return (2*i + 2); }

    /// check if min heap is empty or not
    bool isEmpty()
    {
        if(SZ<=0) return 1;
        return 0;
    }

    /// to extract the root which is the minimum element
    p_ii getTheMinimum()
    {
        if (SZ == 1)
        {
            SZ--;
            return p_ii(hh[0],v[0]);
        }

        /// Store the minimum value, and remove it from heap
        p_ii root = p_ii(hh[0],v[0]);
        hh[0] = hh[SZ-1];
        v[0] = v[SZ-1];
        SZ--;
        heapify(0);

        return root;
    }

    /// Inserts a new weight 'k' with weight 'vv'
    void insertValueInHeap(int k, int vv)
    {
        if (SZ == cap)
        {
            cout << "\nOverflow: Could not insertweight\n";
            return;
        }

        /// First insert the new weight at the end
        SZ++;
        int i = SZ - 1;
        hh[i] = k;
        v[i] = vv;

        /// Fix the min heap property if it is violated
        while (i != 0 && hh[getparNode(i)] > hh[i])
        {
           swap(hh[i], hh[getparNode(i)]);
           swap(v[i], v[getparNode(i)]);
           i = getparNode(i);
        }
    }
};

int MST(int nodeNo, int source)
{
    /// Its for marking the node is set to MST (1) or not (0)
    int mstMark[nodeNo+4];

    /// Set MSTmark to 0
    /// weight[i] is the weight for reaching i node
    /// par[i] is the par node of i
    for(int i=1;i<=nodeNo;i++)
    {
        mstMark[i]=0;
        weight[i] = INF;
        par[i]=-1;
    }

    /// Weight of source is 0
    /// Source is set to MST tree
    weight[source] = 0;
    mstMark[source] = 1;
    /// Initialize the min heap
    priority_queue <p_ii> min_heap;
    /// 1st push the source with weight
    min_heap.insertValueInHeap( p_ii(0,source) );

    /// Until min_heap is not empty do:
    while(!min_heap.isEmpty())
    {
        /// Get the minimum top node
        p_ii now = min_heap.getTheMinimum();

        int vertex = now.second;
        mstMark[vertex]=1;

        /// For all the adjListacent vertices of the nodes, do:
        for(int i=0; i<adjList[vertex].size(); i++)
        {
            p_ii p = adjList[vertex][i];
            int adjListVertex = p.first;
            int weightOfThatEdge = p.second;

            /// If node is not in MST yet
            /// And weight[node] is less than the new weight
            if(mstMark[adjListVertex]==0 && weightOfThatEdge < weight[adjListVertex])
            {
                /// Set the par, weight
                /// Push the vertex with weight to min heap
                par[adjListVertex] = vertex;
                weight[adjListVertex] = weightOfThatEdge;
                min_heap.insertValueInHeap( p_ii(weightOfThatEdge, adjListVertex) );
            }
        }
    }

    int totalWeight = print(nodeNo);

    return totalWeight;
}

int randomGenerator(int nodeNo)
{
    for(int i=1; i<=nodeNo; i++)
    {
        /// Clear all the adjListacent list for new graph
        adjList[i].clear();
        /// Edge no for each node is 25% of the total nodes
        int edgeNo = ceil(nodeNo*0.25);

        while(edgeNo--)
        {
            /// get the adjListacent nodes and weights randomly
            int connectTo = rand()%nodeNo + 1;
            int weight = rand()%100+1;
            adjList
            adjList[i].push_back( p_ii(connectTo, weight) );
        }
    }
    MST(nodeNo,1);
}

int main()
{
    randomGenerator(50);
}
