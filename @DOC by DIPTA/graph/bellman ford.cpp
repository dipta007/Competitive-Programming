struct edge
{
    int x,y,w;
};

vector <edge> ve;

void bellmanFord(int u)
{
    CLR(dist);
    FOR(i,0,n)
    {
        dist[i]=-1;
    }
    dist[src]=0;

    FOR(i,1,n-1)
    {
        FOR(j,0,e-1)
        {
            edge e = ve[j];
            int u = e.x;
            int v = e.y;
            int weight = e.w;
            if(dist[u]!=-1 && dist[u]+weight<dist[v])
            {
                dist[v]=dist[u]+weight;
            }
        }
    }

    FOR(i,0,e-1)
    {
        edge e = ve[j];
        int u = e.x;
        int v = e.y;
        int weight = e.w;
        if(dist[u]!=-1 && dist[u]+weight<dist[v])
        {
            ///negetive
        }
    }
}
