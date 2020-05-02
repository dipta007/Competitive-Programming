#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
const int MAXV=2500+10;

struct Edge{
	int to,cost;
	Edge(int to,int cost):to(to),cost(cost) {}
	Edge() {}
};

vector<Edge> G[MAXV];
bool inq[MAXV];
int d[MAXV],T,C,Ts,Te;
const int INF=(1<<29)-1;

void SPFA(int s)
{
	queue<int> que;
	memset(inq,0,sizeof(inq));
	for(int i=0;i<=T;++i) d[i]=i==s?0:INF;
	que.push(s);
	while(!que.empty())
	{
		int x=que.front();que.pop();
		inq[x]=0;
		for(int e=0;e<G[x].size();++e)
		{
			Edge es=G[x][e];
			if(d[es.to]>d[x]+es.cost)
			{
				d[es.to]=d[x]+es.cost;
				if(!inq[es.to])
				{
					inq[es.to]=1;
					que.push(es.to);
				}
			}
		}
	}
}

void read_gragh()
{
	scanf("%d%d%d%d",&T,&C,&Ts,&Te);
	for(int i=0;i<C;++i)
	{
		int u,v,cost;
		scanf("%d%d%d",&u,&v,&cost);
		G[u].push_back(Edge(v,cost));
		G[v].push_back(Edge(u,cost));
	}
}

int main()
{
	//freopen("1.in","r",stdin);
	read_gragh();
	SPFA(Ts);
	printf("%d\n",d[Te]);
	return 0;
}
