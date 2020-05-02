//POJ 2104
#include<cstdio>
#include<algorithm>
const int MAXN=100000+5;;
const int MAXD=20;
const int INF=~0U>>1;
int a[MAXN],mer[MAXD][MAXN];
int n,q;
void build(int o,int l,int r,int dep)
{
	if(l==r)
	{
		mer[dep][l]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(o<<1,l,m,dep+1);
	build(o<<1|1,m+1,r,dep+1);
	int i=l,j=m+1,p=l;
	while(p<=r)
	{
		if(j>r || (i<=m && mer[dep+1][i]<mer[dep+1][j]))
			mer[dep][p++]=mer[dep+1][i++];
		else mer[dep][p++]=mer[dep+1][j++];
	}
}
int query(int o,int l,int r,int x,int y,int dep,int v)	//当前结点区间[l,r],查询区间[x,y]
{
	if(r<x || l>y) return 0;
	if(l>=x && r<=y) return std::lower_bound(&mer[dep][l],&mer[dep][r]+1,v)-&mer[dep][l];
	int m=(l+r)>>1;
	return query(o<<1,l,m,x,y,dep+1,v)+query(o<<1|1,m+1,r,x,y,dep+1,v);
} 
int solve(int a,int b,int k)
{
	int l=1,r=n,ans;
	while(l<r)
	{
		int m=(l+r+1)>>1;
		int t=query(1,1,n,a,b,1,mer[1][m]);
		if(t<=k) l=m;
		else r=m-1;
	}
	return mer[1][l];
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	build(1,1,n,1);
	while(q--)
	{
		int i,j,k;
		scanf("%d%d%d",&i,&j,&k);
		printf("%d\n",solve(i,j,k-1));
	}
	return 0;
}
