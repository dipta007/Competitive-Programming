//codevs 1515
#include<cstdio>
#include<algorithm>
typedef long long LL;
const int MAXN=1000000+5;
const int MOD=1000000007;
LL fac[MAXN];
LL pow_mod(LL a,LL b)
{
	LL ans=1;
	for(;b;b>>=1,a=a*a%MOD)
		if(b&1) ans=ans*a%MOD;
	return ans;
}
LL C(LL n,LL m)
{
	if(m>n) return 0;
	if(m>n-m) m=n-m;
	if(!m) return 1;
	LL ca=1,cb=1;
	while(m)
	{
		ca=(ca*n)%MOD;
		cb=(cb*m)%MOD;
		--m;--n;
	}
	return ca*pow_mod(cb,MOD-2)%MOD;
}
LL lucas(LL n,LL m)
{
	if(!m) return 1;
	return lucas(n/MOD,m/MOD)*C(n%MOD,m%MOD)%MOD;
}
LL n,m;
int main()
{
	scanf("%lld%lld",&n,&m);
	if(n<m) std::swap(n,m);
	LL ans=n;
	ans+=lucas(n+m+1,m);
	ans%=MOD;
	printf("%lld\n",ans);
	return 0;
}
