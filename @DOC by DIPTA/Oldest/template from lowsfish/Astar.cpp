//POJ 2449
#include<cstdio>
#include<vector>
#include<queue>
struct Edge{
	int to,cost;
	Edge() {}
	Edge(int to,int cost):to(to),cost(cost) {}
};
const int MAXN=1000+5;
const int INF=1<<28;
std::vector<Edge> G[MAXN];
std::vector<Edge> RG[MAXN];
int n,m,s,t,k;
int d[MAXN];
bool inq[MAXN];
void spfa()
{
	for(int i=1;i<=n;++i) d[i]=INF;
	d[t]=0;inq[t]=1;
	std::queue<int> que;
	que.push(t);
	while(!que.empty())
	{
		int x=que.front();que.pop();
		inq[x]=0;
		for(int i=0;i<RG[x].size();++i)
		{
			Edge e=RG[x][i];
			if(d[e.to]>d[x]+e.cost)
			{
				d[e.to]=d[x]+e.cost;
				if(!inq[e.to]) inq[e.to]=1,que.push(e.to);
			}
		}
	}
}
struct state{
	int f,v,g;
	state(int f,int v,int g):f(f),v(v),g(g) {}
	bool operator<(const state& rhs)const
	{
		return f>rhs.f;
	}
};
std::priority_queue<state> pq;
int cnt;
int Astar()
{
	if(d[s]==INF) return -1;
	pq.push(state(d[s],s,0));
	while(!pq.empty())
	{
		state st=pq.top();pq.pop();
		int v=st.v;
		if(v==t) cnt++;
		if(cnt==k) return st.f;
		for(int i=0;i<G[v].size();++i)
		{
			Edge e=G[v][i];
			pq.push(state(st.g+e.cost+d[e.to],e.to,st.g+e.cost));
		}
	}
	return -1;
}
int main()
{
//	freopen("1.in","r",stdin);
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		G[u].push_back(Edge(v,c));
		RG[v].push_back(Edge(u,c));
	}
	scanf("%d%d%d",&s,&t,&k);
	if(s==t) ++k;
	spfa();
	printf("%d\n",Astar());
	return 0;
}
