#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define M 500010
using namespace std;
struct node{
	int v,pos;
}p[M];
int a[M],n,c[M];

int lowbit(int x)
{
	return x&(-x);
}

void update(int x)
{
	while(x<=n)
	{
		c[x]+=1;
		x+=lowbit(x);
	}
}

int getsum(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}

bool cmp(const node &a,const node &b)
{
	return a.v<b.v;
}

int main()
{
	freopen("1.in","r",stdin);
	while(cin>>n)
	{
		if(!n) return 0;
		for(int i=1;i<=n;++i)
		{
			cin>>p[i].v;
			p[i].pos=i;
		}
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;++i)
			a[p[i].pos]=i;
		long long ans=0;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;++i)
		{
			update(a[i]);
			ans+=i-getsum(a[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
