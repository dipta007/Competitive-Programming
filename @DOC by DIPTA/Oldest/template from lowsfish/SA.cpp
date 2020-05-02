#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=200000+10;
char s1[MAXN];
int s[MAXN],sa[MAXN],t[MAXN],t2[MAXN],rank[MAXN],height[MAXN];
int *x=t,*y=t2,n;
inline int idx(char c)
{return c-'a'+1;}
inline bool cmp(int a,int b,int l)
{return y[a]==y[b] && y[b+l] == y[a+l];}
void Sort(int m)
{
	static int c[MAXN];
	int i;
	for(i=0;i<m;++i) c[i]=0;
	for(i=0;i<n;++i) c[x[y[i]]]++;
	for(i=1;i<m;++i) c[i]+=c[i-1];
	for(i=n-1;i>=0;--i) sa[--c[x[y[i]]]]=y[i];
}
void da(int m)
{
	int i,j,p;
	for(i=0;i<n;++i) y[i]=i,x[i]=s[i];
	Sort(m);
	for(j=1,p=1;p<n;m=p,j<<=1)
	{
		for(p=0,i=n-j;i<n;++i) y[p++]=i;
		for(i=0;i<n;++i) if(sa[i]>=j) y[p++]=sa[i]-j;
		Sort(m);
		for(swap(x,y),p=1,x[sa[0]]=0,i=1;i<n;++i)
			x[sa[i]]=cmp(sa[i],sa[i-1],j)?p-1:p++;
	}
}
void calheight()
{
	int i,j,k=0;
	for(i=1;i<=n;++i) rank[sa[i]]=i;
	for(i=0;i<n;height[rank[i++]]=k)
		for(k?k--:0,j=sa[rank[i]-1];s[i+k]==s[j+k];++k);
}
int main()
{
	freopen("1.in","r",stdin);
	scanf("%s",s1);
	n=strlen(s1);
	for(int i=0;i<n;++i) s[i]=idx(s1[i]);
	s[n++]=0;
	da(30);
	--n;
	calheight();
	for(int i=1;i<=n;++i)
	{
		if(i!=1) putchar(' ');
		printf("%d",sa[i]+1);
	}
	putchar(10);
	for(int i=1;i<=n;++i)
	{
		if(i!=1) putchar(' ');
		printf("%d",height[i]);
	}
	putchar(10);
	return 0;
}
