//SGU 194
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
const int MAXN=200+5;
const int INF=~0U>>1;
struct Edge{
	int from,to,cap,flow;
	Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f) {}
};
using std::min;
struct Dinic{
	int n,m,s,t;
	std::vector<Edge> edges;
	std::vector<int> G[MAXN];
	int cur[MAXN],d[MAXN];
	bool vis[MAXN];
	inline void addEdge(int from,int to,int cap)
	{
		edges.push_back(Edge(from,to,cap,0));
		edges.push_back(Edge(to,from,0,0));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	bool bfs()
	{
		memset(vis,0,sizeof vis);
		std::queue<int> que;
		que.push(s);vis[s]=1;d[s]=0;
		while(!que.empty())
		{
			int u=que.front();que.pop();
			for(int i=0;i<G[u].size();++i)
			{
				Edge& e=edges[G[u][i]];
				if(e.cap>e.flow && !vis[e.to])
				{
					vis[e.to]=1;
					d[e.to]=d[u]+1;
					que.push(e.to);
				}
			}
		}
		return vis[t];
	}
	int dfs(int u,int a)
	{
		if(u==t || a==0) return a;
		int flow=0,f;
		for(int& i=cur[u];i<G[u].size();++i)
		{
			Edge& e=edges[G[u][i]];
			if(d[e.to]==d[u]+1 && (f=dfs(e.to,min(a,e.cap-e.flow)))>0)
			{
				flow+=f;
				a-=f;
				e.flow+=f;
				edges[G[u][i]^1].flow-=f;
				if(a==0) break;
			}
		}
		return flow;
	}
	int maxflow(int s,int t)
	{
		this->s=s;this->t=t;
		int flow=0;
		while(bfs())
		{
			memset(cur,0,sizeof cur);
			flow+=dfs(s,INF);
		}
		return flow;
	}
	inline void init(int n)
	{
		this->n=n;
		for(int i=0;i<n;++i) G[i].clear();
		edges.clear();
	}
}T;
int du[MAXN],dn[MAXN*MAXN>>1];
int n,m;
inline void init()
{
	T.init(n+2);
	memset(du,0,sizeof du);
}
int main()
{
	//freopen("1.in","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		for(int i=0;i<m;++i)
		{
			int u,v,l,h;
			scanf("%d%d%d%d",&u,&v,&l,&h);
			T.addEdge(u,v,h-l);
			du[v]+=l;
			du[u]-=l;
			dn[i]=l;
		}
		int sum=0;
		int s=0,t=n+1;
		for(int i=1;i<=n;++i)
		{
			if(du[i]>0) sum+=du[i],T.addEdge(s,i,du[i]);
			else T.addEdge(i,t,-du[i]);
		}
		int flow=T.maxflow(s,t);
		if(flow<sum) puts("NO");
		else
		{
			puts("YES");
			for(int i=0;i<m;++i)
				printf("%d\n",T.edges[i<<1].flow+dn[i]);
		}
	}
	return 0;
}
