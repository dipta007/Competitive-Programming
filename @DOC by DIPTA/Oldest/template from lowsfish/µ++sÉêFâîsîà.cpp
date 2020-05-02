//codevs 3269
#include<cstdio>
#include<algorithm>
const int MAXN=200+10;
const int MAXV=200000+10;
int dp[MAXV];
int W;
void ZeroOne(int w,int v)		//weight and value
{
	for(int i=W;i>=w;--i)
		dp[i]=std::max(dp[i],dp[i-w]+v);
}
void Complete(int w,int v)
{
	for(int i=w;i<=W;++i)
		dp[i]=std::max(dp[i],dp[i-w]+v);
}
int deq[MAXV],deqv[MAXV];
void Multiple(int w,int v,int m)
{
	for(int a=0;a<w;++a)
	{
		int s=0,t=0;
		for(int j=0;j*w+a<=W;++j)
		{
			int val=dp[j*w+a]-j*v;
			while(s<t && deqv[t-1]<=val) --t;
			deq[t]=j;
			deqv[t++]=val;
			dp[j*w+a]=deqv[s]+j*v;
			if(deq[s]==j-m) ++s;
		}
	}
}
int w[MAXN],v[MAXN],p[MAXN];
int n;
int main()
{
	scanf("%d%d",&n,&W);
	for(int i=0;i<n;++i) scanf("%d%d%d",w+i,v+i,p+i);
	for(int i=0;i<n;++i)
	{
		if(p[i]==1) ZeroOne(w[i],v[i]);
		else if(p[i]==-1) Complete(w[i],v[i]);
		else Multiple(w[i],v[i],p[i]);
	}
	printf("%d\n",dp[W]);
	return 0;
}
