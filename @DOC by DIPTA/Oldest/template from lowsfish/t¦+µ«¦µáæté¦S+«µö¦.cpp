#include<iostream>
#include<cstdio>
using namespace std;
const int INTMAX=1<<31;
const int MAXN=1<<17;
int n,dat[MAXN*2-1];

void init(int n_)		//初始化线段树 
{
	n=1;
	while(n<n_) n<<=1;
	for(int i=0;i<2*n-1;++i)
		dat[i]=INTMAX;
}

void update(int k,int a)		//将第k个值更新为a 
{
	k+=n-1;
	dat[k]=a;
	while(k>0)
	{
		k=(k-1)>>1;
		dat[k]=min(k*2+1,k*2+2);
	}
}

int query(int a,int b,int k,int l,int r)	//查询区间[a,b)内最小值 
{
	if(r<=a||b<=l) return INTMAX;		//如果[a,b)和[l,r)没有交集，就返回一个足够大的数 
	if(a<=l&&b>=r) return dat[k];		//如果[a,b)完全包含[l,r)，就返回当前节点的值 
	return min(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));		//否则返回两个儿子中的最小者 
}

int main()
{
	return 0;
}
