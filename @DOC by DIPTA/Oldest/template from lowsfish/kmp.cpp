#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define M 1005
using namespace std;
queue<int> que;
void getfail(char *P,int *f)
{
	int m=strlen(P);
	f[0]=0;f[1]=0;
	for(int i=1;i<m;++i)
	{
		int j=f[i];
		while(j&&P[i]!=P[j]) j=f[j];
		f[i+1]=P[i]==P[j]?j+1:0;
	}
}
void find(char *T,char *P,int *f)
{
	int m=strlen(T),n=strlen(P);
	getfail(P,f);
	int j=0;
	for(int i=0;i<m;++i)
	{
		while(j&&T[i]!=P[j]) j=f[j];
		if(T[i]==P[j]) ++j;
		if(j==n) que.push(i-n+1);
	}
}
int main()
{
	char a[M],b[M];
	int f[M];
	cin>>a>>b;
	find(a,b,f);
	while(que.size())
	{
		cout<<que.front();
		que.pop();
	}
	return 0;
}
