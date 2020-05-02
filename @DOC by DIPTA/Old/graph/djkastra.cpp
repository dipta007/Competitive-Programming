#define mx 510

vector<int> g[mx],cost[mx];
struct node
{
    int u,w;
    node(int a,int b){u=a;w=b;}
    bool operator< (const node &p)const {return w > p.w;}
};
int d[mx];
void dijktra(int n)
{
    for(int i=0;i<mx;i++)d[i]=INF;
    priority_queue<node> q;
    q.push(node(n,0));
    d[n]=0;
    while(!q.empty())
    {
        node top=q.top();q.pop();
        int u=top.u;
        //debugI();
        //debug(u);
        for(int i=0;i<(int)g[u].size();i++)
        {
            int v=g[u][i];
            if(max(cost[u][i],d[u])<d[v])
            {
                d[v]=max(cost[u][i],d[u]);
                //cout<<v<<" "<<d[v]<<endl;
                q.push(node(v,d[v]));
            }
        }
    }
}