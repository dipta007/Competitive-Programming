#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN=100+10;
int dfs_clock;
vector<int> G[MAXN];
int n;
int pre[MAXN],low[MAXN];
bool iscut[MAXN];
void init()
{
	for(int i=0;i<=n;++i) G[i].clear();
	memset(pre,0,sizeof(pre));
	memset(iscut,0,sizeof(iscut));
	memset(low,0,sizeof(low));
	dfs_clock=0;
}

int dfs(int u,int fa)
{
	int lowu=pre[u]=++dfs_clock;
	int child=0;
	for(int i=0;i<G[u].size();++i)
	{
		int v=G[u][i];
		if(!pre[v])
		{
			++child;
			int lowv=dfs(v,u);
			lowu=min(lowu,lowv);
			if(lowv>=pre[u])
			{
				iscut[u]=1;
			}
		}
		else if(pre[v]<pre[u] && v!=fa)
			lowu=min(lowu,pre[v]);
	}
	if(fa<0 && child==1) iscut[u]=0;
	return low[u]=lowu;	
}

int main()
{
    //freopen("1.in","r",stdin);
	while(scanf("%d",&n)!=EOF && n)
	{
        init();
		int u,ans=0;
		dfs_clock=0;
		while(scanf("%d",&u) && u)
		{
			char ch;
			int v;
			while(scanf("%d%c",&v,&ch))
			{
				G[u].push_back(v);
				G[v].push_back(u);
				if(ch==10) break;
			}
		}
		for(int i=1;i<=n;++i) if(!pre[i])	dfs(i,-1);
		for(int i=1;i<=n;++i) if(iscut[i]) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}
