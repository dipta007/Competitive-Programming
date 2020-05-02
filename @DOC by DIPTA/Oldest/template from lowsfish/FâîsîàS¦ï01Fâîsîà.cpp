//POJ 3624
#include<cstdio>
#include<algorithm>
const int MAXM=12880+10;
const int MAXN=3402+10;
int dp[MAXM];
int n,m;
int w[MAXN],v[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i) scanf("%d%d",w+i,v+i);
	for(int i=0;i<n;++i)
		for(int j=m;j>=w[i];--j)
			dp[j]=std::max(dp[j],dp[j-w[i]]+v[i]);
	printf("%d\n",dp[m]);
	return 0;
}
