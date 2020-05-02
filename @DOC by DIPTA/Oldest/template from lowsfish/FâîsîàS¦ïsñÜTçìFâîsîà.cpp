//POJ 1276
#include<cstdio>
#include<algorithm>
#include<cstring>
const int MAXN=10+2;
const int MAXM=100000+10;
int dp[MAXM];
int n,W;
void ZeroOne(int v,int w)
{
	for(int i=W;i>=w;--i)
		dp[i]=std::max(dp[i],dp[i-w]+v);
}
void Complete(int v,int w)
{
	for(int i=w;i<=W;++i)
		dp[i]=std::max(dp[i],dp[i-w]+v);
}
void Multiple(int v,int w,int m)
{
	if(w*m>=W)
	{
		Complete(v,w);
		return;
	}
	int k=1;
	while(k<m)
	{
		ZeroOne(k*v,k*w);
		m-=k;
		k<<=1;
	}
	ZeroOne(m*v,m*w);
}
int num[MAXN],v[MAXN];

int main()
{
	//freopen("1.in","r",stdin);
	while(scanf("%d%d",&W,&n)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;++i) scanf("%d%d",num+i,v+i);
		for(int i=0;i<n;++i)
			Multiple(v[i],v[i],num[i]);
		printf("%d\n",dp[W]);
	}
	return 0;
}
