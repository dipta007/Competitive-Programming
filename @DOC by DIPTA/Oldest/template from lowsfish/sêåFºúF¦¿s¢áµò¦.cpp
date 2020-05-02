//problem:codevs(wikioi) 1792
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
const int MAXN=50000+10;
int prime[MAXN];
bool vis[MAXN];
map<int,int> ms;
map<int,int>::iterator it;
int p;
void sieve(int n)		//筛素数
{
	p=0;
	memset(vis,0,sizeof(vis));
	int m=(int)(sqrt(n)+0.5);
	for(int i=2;i<=m;++i) if(!vis[MAXN])
	{
		prime[p++]=i;
		for(int j=i*i;j<=m;j+=i) vis[j]=1;
	}
}

void work1(int n)
{
	sieve(n);
	int m=(int)(sqrt(n)+0.5);
	printf("%d=",n);
	int t=0;
	while(1)
	{
		while(n%prime[t]==0)
		{
			printf("%d",prime[t]);
			n/=prime[t];
			if(n!=1) putchar('*');
		}
		t++;
		if(n==1) break;
		if(n<m && !vis[n])
		{
			printf("%d",n);
			break;
		}
		if(t>=p || prime[p]>n)
		{
			printf("%d",n);
			break;
		}
	}
	putchar(10);
}

void prime_factor(int n)	//分解因数
{
	for(int i=2;i*i<=n;++i)
	{
		while(n%i==0)
		{
			++ms[i];
			n/=i;
		}
	}
	if(n!=1) ms[n]=1;
}

void work2(int n)
{
	printf("%d=",n);
	prime_factor(n);
	for(it=ms.begin();it!=ms.end();++it)
	{
		int t=it->second;
		for(int i=0;i<t;++i)
		{
			if(i!=0 || it!=ms.begin()) putchar('*');
			printf("%d",it->first);
		}
	}
	putchar(10);
}
int main()
{
	int n;
	cin>>n;
	work2(n);
	return 0;
}
