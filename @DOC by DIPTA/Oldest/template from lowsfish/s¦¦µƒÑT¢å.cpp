#include<iostream>
#include<cstdio>
#define M 1000
using namespace std;
int par[M];
int rank[M];
void init()
{
	for(int i=0;i<M;++i)
		par[i]=i;
}

int getfather(int i)
{
	if(par[i]==i) return i;
	else return par[i]=getfather(par[i]);
}

void unite(int x,int y)
{
	x=getfather(x);
	y=getfather(y);
	if(x==y) return;
	if(rank[x]<rank[y])
	{
		par[x]=y;	
	}else {
		par[y]=x;
		if(rank[x]==rank[y])++rank[x];
	}
}

bool same(int x,int y)
{
	return getfather(x)==getfather(y);
}
int main()
{
	return 0;
}