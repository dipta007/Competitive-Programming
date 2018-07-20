/***
    1. Call bridge.clear() for each node
    2. Call bridge.findBride(number of nodes, starting node(0,1) )
    3. Set comp = 1
    4. Call BridgeTree(source, number of nodes)
    *. CLR isBridge, vis, adjShrink
***/
#define BRIDGENODE 10010

vii adjShrink;
int isBridge[BRIDGENODE];
bool vis[BRIDGENODE];

class BridgeFinding
{
    int disc[BRIDGENODE]; ///Discovery time of nodes
    int low[BRIDGENODE]; ///Lowest back edge extension
    int col[BRIDGENODE]; ///Color for marking node

    int cnt; ///Timer
    int cc; ///Color

    void tarjan ( int s, int parentEdge )
    {
        disc[s] = low[s] = cnt++;
        col[s] = cc + 1;

        for ( int i = 0; i < adj[s].size(); ++i )
        {

            int t = adj[s][i].ff;
            int edgeNumber = adj[s][i].ss;
            if ( edgeNumber == parentEdge ) continue; ///Don't use the same edge from parent

            if ( col[t] <= cc )   ///New node. Discovery.
            {

                tarjan ( t, edgeNumber );
                low[s]=min(low[s],low[t]); ///Update back edge extension for S

                if ( low[t] > disc[s] )   ///Back edge of T did not go above S
                {
                    /// This edge is Bridge
                    isBridge[edgeNumber] = 1;
                }
            }
            else if ( col[t] == cc + 1 )   ///Back Edge
            {
                low[s]=min(low[s],disc[t]);
            }
        }
    }

public:

    vector< pair<int,int> > adj[BRIDGENODE]; ///Enter target and edge number as pair

    void clear ( int n )
    {
        CLR(isBridge);
        cnt = 1;
        cc += 3; ///cc is now 0. cc+1 is 1
        for (int i = 0; i <= n; i++ )
        {
            adj[i].clear();
        }
    }

    void findBridge( int n, int start = 0 )
    {
        for ( int i = start; i <= n; i++ )
        {
            if ( col[i] <= cc )
            {
                tarjan ( i, -1 );
            }
        }
    }
} bridge;

int comp;
void BridgeTree(int s, int n)
{
    queue<int>q;
    q.push(s);
    vis[s] = 1;
    int cur = comp;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < bridge.adj[u].size(); i++)
        {
            int v = bridge.adj[u][i].ff;
            int edge = bridge.adj[u][i].ss;
            if(vis[v]) continue;
            vis[v] = 1;
            if(isBridge[edge])
            {
                comp += 1;
                adjShrink[cur].PB(comp);
                adjShrink[comp].PB(cur);
                BridgeTree(v, n);
            }
            else
            {
                q.push(v);
            }
        }
    }
}

