///Starts from here After Template

struct edge
{
    int u,v,w;
    edge()
    {

    }
    edge(int x,int y,int z)
    {
        u=x,v=y,w=z;
    }
    bool operator < (const edge &p) const
    {
        return w < p.w;
    }
};

class UnionFind
{
private:
    vi p,rank;
public:
    UnionFind(int n)

    {
        rank.assign(n+1,0);
        p.assign(n+1,0);
        for(int i=0; i<=n; i++)
            p[i]=i;
    }
    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i]=findSet(p[i]));
    }
    bool isSameSet(int i,int j)
    {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i,int j)
    {
        if(!isSameSet(i,j))
        {
            int x=findSet(i);
            int y=findSet(j);
            if(rank[x]>rank[y]) p[y]=x;
            else
            {
                p[x]=y;
                if(rank[x]==rank[y])
                    rank[y]++;
            }
        }
    }
};

vector <edge> e;

int MST(int node)
{
    sort(ALL(e));
    UnionFind uMst(node);

    int cnt=0,sum=0;
    for(int i=0;i<e.size();i++)
    {
        int x=uMst.findSet(e[i].u);
        int y=uMst.findSet(e[i].v);
        if(x!=y)
        {
            cnt++;
            uMst.unionSet(x,y);
            sum += e[i].w;
            if(cnt==node-1) break;
        }
    }
    return sum;
}


int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int n,m;
    while(~getII(n,m))
    {
        e.clear();
        for(int i=0;i<m;i++)
        {
            int x,y,z;
            getIII(x,y,z);
            e.PB(edge(x,y,z));
        }
        cout << MST(n) <<endl;
    }

    return 0;
}

