void floydWarshall(int node)
{
    /// There is no path from I to J
    /// Then adj[i][j] = adj[j][i] = INF;

    for(int k=0;k<node;k++)
    {
        for(int i=0;i<node;i++)
        {
            for(int j=0;j<node;j++)
            {
                if(adj[i][k]+adj[k][j]<adj[i][j])
                {
                    adj[i][j] = adj[i][k]+adj[k][j];
                }
            }
        }
    }
}
