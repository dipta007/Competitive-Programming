#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=200+10;
const int INF=(1<<29)-1;
int n,m;
int cap[MAXN][MAXN],flow[MAXN][MAXN],a[MAXN],p[MAXN];
int f,s,t;
void input()
{
	s=1;t=m;
	memset(cap,0,sizeof(cap));
	for(int i=0;i<n;++i)
	{
		int from,to,cost;
		scanf("%d%d%d",&from,&to,&cost);
		cap[from][to]+=cost;
	}
}

void ek()
{
	queue<int> que;
	memset(flow,0,sizeof(flow));
	f=0;
	for(;;)
	{
		memset(a,0,sizeof(a));
		a[s]=INF;
		que.push(s);
		while(!que.empty())
		{
			int u=que.front();que.pop();
			for(int v=1;v<=m;++v)
			{
				if(!a[v] && cap[u][v]>flow[u][v])
				{
					p[v]=u;
					que.push(v);
					a[v]=min(a[u],cap[u][v]-flow[u][v]);
				}
			}
		}
		if(a[t]==0) break;
		for(int u=t;u!=s;u=p[u])
		{
			flow[p[u]][u]+=a[t];
			flow[u][p[u]]-=a[t];
		}
		f+=a[t];
	}
}

int main()
{
	//freopen("1.in","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		input();
		ek();
		printf("%d\n",f);
	}
	return 0;
}
