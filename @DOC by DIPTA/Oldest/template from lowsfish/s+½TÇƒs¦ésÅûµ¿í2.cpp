#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
LL pow_mod(LL a,LL b)
{
	LL ans=1;
	for(;b;b>>=1,a=a*a%MOD)
		if(b&1) ans=ans*a%MOD;
	return ans;
}
int main()
{
}
              
