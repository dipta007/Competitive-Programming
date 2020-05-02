struct edge{
    int cost,node;
    bool operator<(const edge &b)const{
        return cost>b.cost;    // Min Priority Queue
    }
};

bool flag[mx];
int Prims(vector<edge>adj[],int source,int nodes){
    priority_queue<edge>Q;
    edge now ,next ;
    int i,sum;
    memo(flag,false);
    next.node=source;
    sum=next.cost=0;
    Q.push(next);
    while(!Q.empty()){
        now=Q.top();
        if(flag[now.node]==false)
            sum+=now.cost;
        flag[now.node]=true;
        Q.pop();
        rep(i,(int)adj[now.node].size()){
            if(flag[ adj[now.node][i].node]==false){
                next.node=adj[now.node][i].node;
                next.cost=adj[now.node][i].cost;
                Q.push(next);
            }
        }
    }
    return sum;
}


int main(){
    int nodes,edges,i,u,v,cost,source,val,t;
    edge V;
    vector<int>dist;
    vector<edge>adj[mx];

    scanf("%d",&t);

    For(cs,t){
        if(cs!=1)printf("\n");
        scanf("%d %d %d",&nodes,&edges,&source);

        rep(i,nodes)adj[i].clear(); //clear adj vector

        rep(i,edges){
            scanf("%d %d %d",&u,&v,&cost);
            V.cost=cost;
            V.node=v;
            adj[u].push_back(V);
            //   V.node=u; //For Bidirectional Edges
            //  adj[v].push_back(V);
        }

        val=Prims(adj,source,nodes);

        printf("Case %d: ",cs++);
        if(val)printf("%d\n",val);
        else printf("impossible\n");
    }


    return 0;
}
