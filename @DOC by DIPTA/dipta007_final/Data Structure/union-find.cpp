/**
Procedure:
    1. Call UnionFind(Max Node)
    2. Call findSet(i) to find set number of i
    3. Call isSameSet(x,y) to find if they are in same set
    4. Call unionSet(x,y) to make them united
    5. Call numDisjointSets() to get the number of disjoint set
    6. Call sizeOfSet(x) to get the size of set of x
Time Complexity = O(N)
**/
class UnionFind
{
private:
    vi p, rank, setSize;
    int numSets;
public:
    UnionFind(int N)
    {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            numSets--;
            int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
            if (rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    int numDisjointSets()
    {
        return numSets;
    }
    int sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }
};
