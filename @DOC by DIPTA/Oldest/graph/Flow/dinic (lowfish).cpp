//POJ 1273 Drainage Ditches
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
struct Edge{
	int from,to,cap,flow;
	Edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow) {}
};
const int MAXN=200+10;
const int INF=1<<28;
struct Dinic{
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[MAXN];
	bool vis[MAXN];
	int d[MAXN];
	int cur[MAXN];
	void addedge(int from,int to,int cap)
	{
		edges.push_back(Edge(from,to,cap,0));
		edges.push_back(Edge(to,from,0,0));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	bool bfs()
	{
		memset(vis,0,sizeof(vis));
		d[s]=0;
		vis[s]=1;
		queue<int> que;
		que.push(s);
		while(!que.empty())
		{
			int x=que.front();que.pop( );
			for(int i=0;i<G[x].size();++i)
			{
				Edge &e=edges[G[x][i]];
				if(!vis[e.to] && e.cap>e.flow)
				{
					vis[e.to]=1;
					que.push(e.to);
					d[e.to]=d[x]+1;
				}
			}
		}
		return vis[t];
	}
	int dfs(int x,int a)
	{
		if(x==t || a==0) return a;
		int flow=0,f;
		for(int &i=cur[x];i<G[x].size();++i)
		{
			Edge &e=edges[G[x][i]];
			if(d[x]+1==d[e.to] && (f=dfs(e.to,min(a,e.cap-e.flow)))>0)
			{
				e.flow+=f;
				edges[G[x][i]^1].flow-=f;
				flow+=f;
				a-=f;
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
			memset(cur,0,sizeof(cur));
			flow+=dfs(s,INF);
		}
		return flow;
	}
	void init(int n)
	{
		this->n=n;
		for(int i=0;i<=n;++i) G[i].clear();
		edges.clear();
		memset(vis,0,sizeof(vis));
	}
}dinic;
int n,m;
int main()
{
//	freopen("1.in","r",stdin);
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		dinic.init(n);
		while(m--)
		{
			int u,v,f;
			scanf("%d%d%d",&u,&v,&f);
			--u;--v;
			dinic.addedge(u,v,f);
		}
		printf("%d\n",dinic.maxflow(0,n-1));
	}
	return 0;
}
