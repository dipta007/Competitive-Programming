struct Edge{
	int from,to,cap,flow,cost;
	Edge(int from,int to,int cap,int flow,int cost):from(from),to(to),cap(cap),flow(flow),cost(cost) {}
};
const int MAXN=500+5;
//const int INF=1<<28;
struct MCMF{
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[MAXN];
	bool inq[MAXN];
	int d[MAXN],p[MAXN],a[MAXN];
	void init(int n)
	{
		this->n=n;
		edges.clear();
		for(int i=0;i<=n;++i) G[i].clear();
	}
	void addEdge(int from,int to,int cap,int cost)
	{
		edges.push_back(Edge(from,to,cap,0,cost));
		edges.push_back(Edge(to,from,0,0,-cost));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	bool spfa(int &flow,int& cost)
	{
		for(int i=0;i<n;++i) d[i]=INF,inq[i]=0;
		queue<int> que;
		que.push(s);
		inq[s]=1;d[s]=0;p[s]=0;a[s]=INF;
		while(!que.empty())
		{
			int x=que.front();que.pop();
			inq[x]=0;
			for(int i=0;i<G[x].size();++i)
			{
				Edge &e=edges[G[x][i]];
				if(e.cap>e.flow && d[e.to]>d[x]+e.cost)
				{
					d[e.to]=d[x]+e.cost;
					p[e.to]=G[x][i];
					a[e.to]=min(a[x],e.cap-e.flow);
					if(!inq[e.to]) inq[e.to]=1,que.push(e.to);
				}
			}
		}
		if(d[t]==INF) return 0;
		flow+=a[t];
		cost+=d[t];
		int u=t;
		while(u!=s)
		{
			edges[p[u]].flow+=a[t];
			edges[p[u]^1].flow-=a[t];
			u=edges[p[u]].from;
		}
		return 1;
	}
	pair<int,int> mincost(int s,int t)
	{
		this->s=s;this->t=t;
		int flow=0,cost=0;
		while(spfa(flow,cost));
		return make_pair(flow,cost);
	}
}mcmf;
//typedef pair<int,int> P;
//#define fi first
//#define se second
//P house[MAXN>>2],man[MAXN>>2];
//int n,m;
//char mat[MAXN>>2][MAXN>>2];
//int dist(P a,P b)
//{
//	return abs(a.fi-b.fi)+abs(a.se-b.se);
//}
//int main()
//{
////	freopen("1.in","r",stdin);
//	while(scanf("%d%d",&n,&m)!=EOF && m && n)
//	{
//		int p1=0,p2=0;
//		for(int i=0;i<n;++i)
//		{
//			scanf("%s",mat[i]);
//			for(int j=0;j<m;++j)
//			{
//				if(mat[i][j]=='H') house[p1++]=P(i,j);
//				else if(mat[i][j]=='m') man[p2++]=P(i,j);
//			}
//		}
//		mcmf.init(2*p1+p2+2);
//		for(int i=0;i<p1;++i)
//			mcmf.addedge(p2+i+1,p2+i+p1+1,1,0);
//		for(int i=0;i<p1;++i)
//			for(int j=0;j<p2;++j)
//			{
//				mcmf.addedge(j+1,p2+i+1,INF,dist(man[j],house[i]));
//			}
//		for(int i=1;i<=p2;++i) mcmf.addedge(0,i,1,0);
//		for(int i=1;i<=p2;++i) mcmf.addedge(p2+i+p1,2*p1+p2+1,INF,0);
//		printf("%d\n",mcmf.mincost(0,2*p1+p2+1));
//	}
//	return 0;
//}
