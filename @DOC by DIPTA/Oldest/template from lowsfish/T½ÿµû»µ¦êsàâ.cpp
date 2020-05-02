//tyvj 1455
#include<cstdio>
#include<algorithm>
#include<cmath>
const int MAXN=100+5;
typedef double Matrix[MAXN][MAXN];
void gauss(Matrix A,int n)
{
	for(int i=0;i<n;++i)
	{
		int r=i;
		for(int j=i+1;j<n;++j) if(fabs(A[j][i])>fabs(A[r][i])) r=j;
		if(r!=i) std::swap(A[i],A[r]);
		for(int k=i+1;k<n;++k)
		{
			double f=A[k][i]/A[i][i];
			for(int j=i;j<=n;++j) A[k][j]-=f*A[i][j];
		}
	}
	for(int i=n-1;i>=0;--i)
	{
		for(int j=i+1;j<n;++j)
			A[i][n]-=A[j][n]*A[i][j];
		A[i][n]/=A[i][i];
	}
}
int n;
Matrix A;
int main()
{
//	freopen("1.in","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		for(int j=0;j<=n;++j)
			scanf("%lf",&A[i][j]);
	gauss(A,n);
	for(int i=0;i<n;++i)
		printf("%d%c",(int)(A[i][n]+0.5),i==n-1?'\n':' ');
	return 0;
}
