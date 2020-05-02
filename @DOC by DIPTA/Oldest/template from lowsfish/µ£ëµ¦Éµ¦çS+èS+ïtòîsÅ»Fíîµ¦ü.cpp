//POJ 2396
//这份代码忘了加当前弧优化。。也懒得改了
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define fail puts("IMPOSSIBLE")
const int MAXN=200+20+10;
const int MAXL=200+5;
const int MAXR=20+5;
const int INF=~0U>>1;
typedef std::vector<int>::iterator vit;
struct Edge{
	int from,to,cap,flow;
	Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f) {}
};
using std::min;
using std::max;
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
			for(vit i=G[u].begin();i!=G[u].end();++i)
			{
				Edge& e=edges[*i];
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
		for(vit i=G[u].begin();i!=G[u].end();++i)
		{
			Edge& e=edges[*i];
			if(d[e.to]==d[u]+1 && (f=dfs(e.to,min(a,e.cap-e.flow)))>0)
			{
				a-=f;
				flow+=f;
				e.flow+=f;
				edges[(*i)^1].flow-=f;
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
	void init(int n)
	{
		this->n=n;
		edges.clear();
		for(int i=0;i<n;++i) G[i].clear();
	}
}S;
int n,m;
int low[MAXL][MAXR],high[MAXL][MAXR];
int du[MAXN],sumdu;
int s,t,ss,tt;
inline bool update(int i,int j,char c,int v)
{
	if(c=='=') low[i][j]=max(low[i][j],v),high[i][j]=min(high[i][j],v);
	else if(c=='<') high[i][j]=min(high[i][j],v-1);
	else low[i][j]=max(low[i][j],v+1);
	if(low[i][j]>high[i][j]) return 0;
	return 1;
}
bool build()
{
	bool flag=1;
	s=0;t=n+m+1;ss=t+1;tt=ss+1;
	int sum1=0,sum2=0;
	for(int i=1;i<=n;++i)
	{
		int t; scanf("%d",&t);
		sum1+=t; du[s]-=t; du[i]+=t;
	}
	for(int i=n+1;i<=m+n;++i)
	{
		int t;scanf("%d",&t);
		sum2+=t; du[i]-=t; du[s]+=t;
	}
	if(sum1 != sum2) flag=0;
	int C;
	scanf("%d",&C);
	while(C--)
	{
		char s[2];
		int a,b,c;
		scanf("%d%d%s%d",&a,&b,s,&c);
		int i1=a,i2=a,j1=b,j2=b;
		if(a==0) i1=1,i2=n;
		if(b==0) j1=1,j2=m;
		for(int i=i1;i<=i2;++i)
			for(int j=j1;j<=j2;++j)
				if(!update(i,j,s[0],c)) flag=0;
	}
	if(!flag) return 0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			du[i]-=low[i][j]; du[j+n]+=low[i][j];
			S.addEdge(i,j+n,high[i][j]-low[i][j]);
		}
	for(int i=1;i<=m+n;++i)
	{
		if(du[i] > 0) S.addEdge(ss,i,du[i]),sumdu+=du[i];
		else if(du[i] < 0) S.addEdge(i,tt,-du[i]);
	}
	S.addEdge(t, s, INF);
	return 1;
}
inline void init()
{
	S.init(n+m+4);
	memset(low,0,sizeof low);
	memset(du,0,sizeof du);
	std::fill(high[0],&high[MAXL-1][MAXR-1]+1,INF);
	sumdu=0;
}
void print()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			printf("%d%c",S.edges[((i-1)*m+j)*2-2].flow+low[i][j],j==m?'\n':' ');
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		init();
		if(!build()) fail;
		else
		{
			int flow=S.maxflow(ss,tt);
			if(flow<sumdu) fail;
			else print();
		}
		if(T) puts("");
	}
	return 0;
}
