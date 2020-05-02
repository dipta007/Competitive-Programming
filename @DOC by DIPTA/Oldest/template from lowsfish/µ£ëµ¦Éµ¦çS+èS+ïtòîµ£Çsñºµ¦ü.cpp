//ZOJ 3229
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
const int MAXN=1400+5;
const int INF=~0U>>1;
struct Edge{
	int from,to,cap,flow;
	Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f) {}
};
using std::min;
using std::vector;
struct Dinic{
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[MAXN];
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
			int u = que.front(); que.pop();
			for(int i=0;i<G[u].size();++i)
			{
				Edge& e = edges[G[u][i]];
				if(e.cap > e.flow && !vis[e.to])
				{
					d[e.to]=d[u]+1;
					vis[e.to]=1;
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
				a-=f;
				flow+=f;
				e.flow+=f;
				edges[G[u][i]^1].flow-=f;
				if(a==0) break;
			}
		}
		return flow;
	}
	int maxflow(int _s,int _t)
	{
		s=_s;t=_t;
		int flow=0;
		while(bfs())
		{
			memset(cur,0,sizeof cur);
			flow+=dfs(s,INF);
		}
		return flow;
	}
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<n;++i) G[i].clear();
		edges.clear();
	}
}S;
int n,m;
int s,t,ss,tt;
int du[MAXN],id[MAXN][MAXN],low[MAXN][MAXN];
void work()
{
	s=0;t=n+m+1;
	ss=t+1;tt=ss+1;
	S.init(n+m+4);
	memset(id,0,sizeof id);
	memset(du,0,sizeof du);
	for(int i=1;i<=m;++i)
	{
		int tmp; scanf("%d",&tmp);
		S.addEdge(i+n,t,INF-tmp);
		du[t]+=tmp;
		du[i+n]-=tmp;
	}
	for(int i=1;i<=n;++i)
	{
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		S.addEdge(s,i,t2);
		for(int j=1;j<=t1;++j)
		{
			int num,l,h;
			scanf("%d%d%d",&num,&l,&h);
			S.addEdge(i,num+n+1,h-l);
			du[i]-=l;
			du[num+n+1]+=l;
			low[i][num]=l;
			id[i][num]=S.m-2;
		}
	}
	S.addEdge(t,s,INF);
	int sum=0;
	for(int i=1;i<=t;++i)
	{
		if(du[i]>0) sum+=du[i],S.addEdge(ss,i,du[i]);
		else if(du[i]<0) S.addEdge(i,tt,-du[i]);
	}
	int flow=S.maxflow(ss,tt);
	if(flow!=sum)
	{
		puts("-1");
		return;
	}
	int ans=S.maxflow(s,t);
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)
		for(int j=0;j<m;++j) if(id[i][j])
			printf("%d\n",S.edges[id[i][j]].flow+low[i][j]);
}
int main()
{
	//freopen("1.in","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		work();
		puts("");
	}
	return 0;
}
