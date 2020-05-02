//bzoj 3781
#include<cstdio>
#include<cmath>
#include<algorithm>
typedef long long LL;
const int MAXN=50000+5;
int a[MAXN];
int n,m,k,sz;
struct Ask{
	int l,r,id;
	bool operator<(const Ask& rhs) const
	{
		if(l/sz == rhs.l/sz) return r<rhs.r;
		return l/sz<rhs.l/sz;
	}
}ask[MAXN];
int num[MAXN];
LL sum=0;
inline void modify(int x,int f)
{
	sum-=num[x]*num[x];
	num[x]+=f;
	sum+=num[x]*num[x];
}
LL ans[MAXN];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	sz=sqrt(n)+1;
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=0;i<m;++i)
		ask[i].id=i,scanf("%d%d",&ask[i].l,&ask[i].r);
	std::sort(ask,ask+m);
	int l=1,r=0;
	for(int i=0;i<m;++i)
	{
		while(l<ask[i].l) modify(a[l],-1),++l;
		while(l>ask[i].l) --l,modify(a[l],1);
		while(r<ask[i].r) ++r,modify(a[r],1);
		while(r>ask[i].r) modify(a[r],-1),--r;
		ans[ask[i].id]=sum;
	}
	for(int i=0;i<m;++i) printf("%lld\n",ans[i]);
	return 0;
}
