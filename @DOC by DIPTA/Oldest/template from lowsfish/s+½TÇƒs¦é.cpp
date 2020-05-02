#include<iostream>
#include<cstdio>
#define l unsigned long long
using namespace std;
l pow(l a,l b)
{
	l r=1,base=a;
	while(b)
	{
		if(b&1) r*=base;
		base*=base;
		b>>=1;
	}
	return r;
	
}
int main()
{
	l a,b;
	cin>>a>>b;
	cout<<pow(a,b);
	
	return 0;
}
