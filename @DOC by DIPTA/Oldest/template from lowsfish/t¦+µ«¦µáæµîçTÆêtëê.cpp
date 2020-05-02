//BZOJ 1798
#include<cstdio>
#include<algorithm>
typedef long long LL;
const int MAXN=100000+5;
int n,MOD;
struct Mark{
	LL mul,add;
	Mark(LL mul=1,LL add=0):mul(mul%MOD),add(add%MOD) {}
};
Mark operator*(const Mark& a,const Mark& b)
{
	return Mark(a.mul*b.mul%MOD,(a.add*b.mul+b.add)%MOD);
}
struct Tree{
	int l,r;
	Mark m;
	LL sum;
	Tree* pl,*pr;
	void apply(Mark a)
	{
		m=m*a;
		sum=(sum*a.mul%MOD+a.add*(r-l)%MOD)%MOD;
	}
	void maintain()
	{
		if(l+1==r) return;
		sum=(pl->sum+pr->sum)%MOD;
	}
	void pushdown()
	{
		if(l+1==r) return;
		pl->apply(m);
		pr->apply(m);
		m=Mark();
	}
	void update(int x,int y,Mark a)
	{
		pushdown();
		if(x>=r || y<l) return;
		if(l>=x && r-1<=y) apply(a);
		else
		{
			int m=(l+r)>>1;
			pl->update(x,y,a);
			pr->update(x,y,a);
			maintain();
		}
	}
	int query(int x,int y)
	{
		pushdown();
		if(x>=r || y<l) return 0;
		if(l>=x && r-1<=y) return sum;
		return (pl->query(x,y)+pr->query(x,y))%MOD;
	}
}*root;
const int BUFFER_SIZE=10000;
Tree* buf,*cur;
inline Tree* get()
{
	if(!buf || cur-buf==BUFFER_SIZE)
		buf=new Tree[BUFFER_SIZE],cur=buf;
	return cur++;
}
int a[MAXN];
Tree* build(int l,int r)
{
	Tree* t=get();
	t->l=l;t->r=r;
	if(l+1==r) t->sum=a[l]%MOD,t->pl=t->pr=0;
	else
	{
		int m=(l+r)>>1;
		t->pl=build(l,m);t->pr=build(m,r);
		t->maintain();
	}
	return t;
}
int main()
{
	scanf("%d%d",&n,&MOD);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	root=build(0,n);
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int k,t,g,c;
		scanf("%d",&k);
		if(k==1)
		{
			scanf("%d%d%d",&t,&g,&c);
			--t;--g;
			root->update(t,g,Mark(c,0));
		}
		else if(k==2)
		{
			scanf("%d%d%d",&t,&g,&c);
			--t;--g;
			root->update(t,g,Mark(1,c));
		}
		else
		{
			scanf("%d%d",&t,&g);
			--t;--g;
			printf("%d\n",root->query(t,g));
		}
	}
	return 0;
}
