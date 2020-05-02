//codevs 1602
#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
#define M 101
using namespace std;
typedef pair<int,int> P;
typedef pair<double,int>P1;
const int INF=(1<<29);
double ans[M];
int n,m;
struct edge{int to;double cost;};
vector<edge> G[M];
P d[M];

double juli(P a,P b)
{
	int dx=a.first-b.first,dy=a.second-b.second;
	return sqrt(dx*dx+dy*dy);
}
void dijkstra(int s)
{
	priority_queue<P1,vector<P1>,greater<P1> >que;
	for(int i=0;i<M;++i) ans[i]=INF;
	ans[s]=0;
	que.push(P1(0,s));
	while(que.size())
	{
		P1 p=que.top();que.pop();
		int v=p.second;
		if(ans[v]<p.first) 
			continue;
		for(int i=0;i<G[v].size();++i)
		{
			edge e=G[v][i];
			if(ans[e.to]>ans[v]+e.cost)
			{
				ans[e.to]=ans[v]+e.cost;
				que.push(P1(ans[e.to],e.to));
			}
		}
	}
}

int main()
{
	int i,j,s,t;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>d[i].first>>d[i].second;
	cin>>m;
	for(j=0;j<m;++j)
	{
		edge e;
		int a;
		cin>>a>>e.to;
		--a;--e.to;
		e.cost=juli(d[a],d[e.to]);
		G[a].push_back(e);
		int b=e.to;
		e.to=a;
		G[b].push_back(e);
	}
	cin>>s>>t;
	--s;--t;
	dijkstra(s);
	printf("%.2f",ans[t]);
	return 0;
}
