/***
    1. Call bcc.init()
    2. Call bcc.BCC(number of nodes)
    3. Clear adjShrink
    4. Call blockCutTree(number of nodes)
***/

#define MXNODE 100004
int cycle[MXNODE];
vi adjShirnk[MXNODE];

struct BiconnectedComponent
{
    vi tarjan;
    int disc[MXNODE], low[MXNODE], vis[MXNODE];
    int tym, comp;

    vector<int>adj[MXNODE];
    void init(int n)
    {
        tym = 0;
        comp = 0;
        CLR(vis);
        tarjan.clear();
        for(int i = 0; i <= n; i++)
            adj[i].clear();
    }
    void BCC(int s, int par)
    {
        disc[s] = low[s] = tym ++;
        vis[s] = 1;
        tarjan.push_back(s);
        for(int i = 0; i < adj[s].size(); i++)
        {
            int v = adj[s][i];
            if(v == par) continue;
            if(vis[v]) low[s] = min(low[s], disc[v]);
            else
            {
                BCC(v, s);
                low[s] = min(low[s], low[v]);
            }
        }
        if(low[s] == disc[s])
        {
            comp += 1;
            while(1)
            {
                int lst = tarjan.back();
                tarjan.pop_back();
                /// They are in same component
                cycle[lst] = comp;
                if(lst == s) break;
            }
        }
    }
} bcc;


void blockCutTree(int n){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < bcc.adj[i].size(); j++){
            int v = bcc.adj[i][j];
            if(cycle[i] != cycle[v]){
                adjShirnk[cycle[i]].PB(cycle[v]);
            }
        }
    }
}
