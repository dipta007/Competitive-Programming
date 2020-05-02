//SGU 176
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
const int MAXN=100+10;
const int INF=~0U>>2;
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
		que.push(s); vis[s]=1; d[s]=0;
		while(!que.empty())
		{
			int u=que.front();que.pop();
			for(int i=0;i<G[u].size();++i)
			{
				Edge& e=edges[G[u][i]];
				if(e.cap>e.flow && !vis[e.to])
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
	void delst()
	{
		edges[m-1].cap=edges[m-2].cap=0;
		edges[m-1].flow=edges[m-2].flow=0;
	}
	void reduce()
	{
		for(int i=0;i<m;++i) edges[i].flow=0;
	}
}S;
int n,m;
int s,t,ss,tt;
int du[MAXN],ans[MAXN*MAXN];
void work()
{
	scanf("%d%d",&n,&m);
	S.init(n+2);
	memset(du,0,sizeof du);
	memset(ans,0,sizeof ans);
	for(int i=0;i<m;++i)
	{
		int u,v,z,c;
		scanf("%d%d%d%d",&u,&v,&z,&c);
		if(c) du[u]-=z,du[v]+=z,ans[i]=z;
		S.addEdge(u,v,z-z*c);
	}
	s=1,t=n;
	ss=0;tt=n+1;
	int sum=0;
	for(int i=1;i<=n;++i)
	{
		if(du[i]>0) sum+=du[i],S.addEdge(ss,i,du[i]);
		else if(du[i]<0) S.addEdge(i,tt,-du[i]);
	}
	S.addEdge(t,s,INF);
	if(S.maxflow(ss,tt)<sum)
		puts("Impossible");
	else
	{
		int res=S.edges[S.m-2].flow;
		S.delst();
		int tmp=S.maxflow(t,s);
		res-=tmp;
		if(res<0)
		{
			S.reduce();
			S.maxflow(ss,tt);
			res=0;
		}
		printf("%d\n",res);
		for(int i=0;i<m;++i)
			printf("%d%c",S.edges[i<<1].flow+ans[i],i==m-1?'\n':' ');
	}
}
int main()
{
	freopen("1.in","r",stdin);
	work();
	return 0;
}
