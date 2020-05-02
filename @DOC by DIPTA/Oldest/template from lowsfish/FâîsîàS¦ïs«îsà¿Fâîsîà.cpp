//POJ 1384
#include<cstdio>
#include<algorithm>
const int MAXN=500+10;
const int MAXM=10000+10;
const int INF=1<<28;
int dp[MAXM];
int w[MAXN],v[MAXN];
int n,m;
int T;
int main()
{
	//freopen("1.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		m=t2-t1;
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%d%d",v+i,w+i);
		for(int i=0;i<=m;++i) dp[i]=INF;
		dp[0]=0;
		for(int i=0;i<n;++i)
			for(int j=w[i];j<=m;++j)
				dp[j]=std::min(dp[j],dp[j-w[i]]+v[i]);
		if(dp[m]==INF)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[m]);
	}
	return 0;
}
