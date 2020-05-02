#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
const int MAXN=100+10;
vector<int> G[MAXN];
int pre[MAXN],lowlink[MAXN],sccno[MAXN],dfs_clock,scc_cnt;
stack<int> S;
void dfs(int u)
{
	pre[u]=lowlink[u]=++dfs_clock;
	S.push(u);
	for(int i=0;i<G[u].size();++i)
	{
		int v=G[u][i];
		if(!pre[v])
		{
			dfs(v);
			lowlink[u]=min(lowlink[u],lowlink[v]);
		}
		else if(!sccno[v])
		{
			lowlink[u]=min(lowlink[u],pre[v]);
		}
	}
	if(lowlink[u]==pre[u])
	{
		++scc_cnt;
		for(;;)
		{
			int x=S.top();S.pop();
			sccno[x]=scc_cnt;
			if(x==u) break;
		}
	}
}
void find_scc(int n)
{
	dfs_clock=scc_cnt=0;
	memset(pre,0,sizeof(pre));
	memset(sccno,0,sizeof(sccno));
	for(int i=0;i<n;++i)
		if(!pre[i]) dfs(i);
}
bool in0[MAXN],out0[MAXN];
int n;
int main()
{
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int v;
		while(1)
		{
			scanf("%d",&v);
			if(!v) break;
			--v;
			G[i].push_back(v);
		}
	}
	find_scc(n);
	for(int i=1;i<=scc_cnt;++i) in0[i]=out0[i]=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<G[i].size();++j)
		{
			int v=G[i][j];
			if(sccno[i] != sccno[v]) in0[sccno[v]]=out0[sccno[i]]=0;
		}
	int ans=0;
	for(int i=1;i<=n;++i) if(in0[i]) ++ans;
	printf("%d\n",ans);
	int t1=0,t2=0;
	for(int i=1;i<=n;++i)
	{
		if(in0[i]) ++t1;
		if(out0[i]) ++t2;
	}
	ans=max(t1,t2);
	if(scc_cnt==1) ans=0;
	printf("%d\n",ans);
	return 0;
}
