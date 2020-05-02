#include<iostream>
#include<cstdio>
using namespace std;
int f(int a,int b,int m)
{
	if(!b) return a%m;
	int r,k;
	r=a%m;
	k=1;
	while(b>1)
	{
		if(b&1) k=(k*r)%m;
		r=(r*r)%m;
		b>>=1;
	}
	return (r*k)%m;
	
}
int main()
{
	int a,b,m;
	cin>>a>>b>>m;
	cout<<f(a,b,m);
	return 0;
}
