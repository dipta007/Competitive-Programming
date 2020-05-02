//uoj 78
#include<cstdio>
#include<cstring>
const int MAXN=500+5;
int nl,nr,m;
bool mat[MAXN][MAXN];
bool used[MAXN];
int link[MAXN];
bool find(int x)
{
	for(int i=1;i<=nl;++i) if(mat[x][i] && !used[i])
	{
		used[i]=1;
		if(link[i]==0 || find(link[i])) {link[i]=x;return 1;}
	}
	return 0;
}
int main()
{
	//freopen("1.in","r",stdin);
	scanf("%d%d%d",&nl,&nr,&m);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		mat[v][u]=1;
	}
	int ans=0;
	for(int i=1;i<=nr;++i)
	{
		memset(used,0,sizeof used);
		ans+=find(i);
	}
	printf("%d\n",ans);
	for(int i=1;i<=nl;++i) printf("%d%c",link[i],i==nl?'\n':' ');
	return 0;
}
