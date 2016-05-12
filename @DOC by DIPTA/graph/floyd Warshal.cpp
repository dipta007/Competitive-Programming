void floydWarshall(int node)
{
    /// There is no path from I to J
    /// Then adjMatrix[i][j] = adjMatrix[j][i] = INF;

    for(int k=0;k<node;k++)
    {
        for(int i=0;i<node;i++)
        {
            for(int j=0;j<node;j++)
            {
                if(adjMatrix[i][k]+adjMatrix[k][j]<adjMatrix[i][j])
                {
                    adjMatrix[i][j] = adjMatrix[i][k]+adjMatrix[k][j];
                }
            }
        }
    }
}
