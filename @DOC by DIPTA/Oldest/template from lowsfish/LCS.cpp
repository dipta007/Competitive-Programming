//tyvj 1050
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=2000+10;
char a[MAXN],b[MAXN];
int dp[MAXN][MAXN];
int main()
{
	//freopen("1.in","r",stdin);
	int n,m;
	scanf("%s",a);
	scanf("%s",b);
	n=strlen(a);
	m=strlen(b);
	for(int i=0;i<=n;++i) dp[i][0]=0;
	for(int j=0;j<=m;++j) dp[0][j]=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
		{
			if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j]+1;
			else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
		}	
	printf("%d\n",dp[n][m]);
	return 0;
}
