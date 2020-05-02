//BZOJ 2653
#include<cstdio>
#include<algorithm>
#define fr first
#define sc second
const int MAXN=20000+5;
const int INF=~0U>>1;
struct Info{
	int sum,maxl,maxr;
	Info(int v) {sum=maxl=maxr=v;}
	Info() {}
};
Info operator+(const Info& a,const Info& b)
{
	Info ans;
	ans.sum=a.sum+b.sum;
	ans.maxl=std::max(a.maxl,a.sum+std::max(0,b.maxl));
	ans.maxr=std::max(b.maxr,b.sum+std::max(0,a.maxr));
	return ans;
}
struct Tree{
	int l,r;
	Info v;
	Tree* pl,*pr;
	Tree(int l,int r,int all):l(l),r(r)
	{
		if(l+1==r)
		{
			v=Info(all);
			return;
		}
		int m=(l+r)>>1;
		pl=new Tree(l,m,all);
		pr=new Tree(m,r,all);
		v=pl->v+pr->v;
	}
	Tree(int l,int r,Tree* pl,Tree* pr):l(l),r(r),pl(pl),pr(pr) {v=pl->v+pr->v;}
	Info query(int L,int R)
	{
		if(L<=l && R>=r) return v;
		int m=(l+r)>>1;
		if(R<=m) return pl->query(L,R);
		else if(L>=m) return pr->query(L,R);
		else return pl->query(L,R)+pr->query(L,R);
	}
	Tree* change(int pos,int w)
	{
		if(l+1==r) return new Tree(l,r,w);
		int m=(l+r)>>1;
		if(pos<m) return new Tree(l,r,pl->change(pos,w),pr);
		else return new Tree(l,r,pl,pr->change(pos,w));
	}
};
typedef std::pair<int,int> P;
P ps[MAXN];
Tree* root[MAXN];
int n;
inline bool judge(int v,int a,int b,int c,int d)	//[a,b) [c,d)
{
	Tree* r=root[v];
	return (r->query(a,b).maxr+(b<c?r->query(b,c).sum:0)+r->query(c,d).maxl)>=0;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int t;
		scanf("%d",&t);
		ps[i]=P(t,i);
	}
	std::sort(ps,ps+n);
	root[0]=new Tree(0,n,1);
	for(int i=1;i<n;++i)
		root[i]=root[i-1]->change(ps[i-1].sc,-1);
	int q,last=0;
	scanf("%d",&q);
	while(q--)
	{
		int t[4];
		for(int i=0;i<4;++i) scanf("%d",t+i),t[i]=(t[i]+last)%n;
		std::sort(t,t+4);
		int l=0,r=n;
		while(l+1<r)
		{
			int m=(l+r)>>1;
			if(judge(m,t[0],t[1]+1,t[2],t[3]+1)) l=m;
			else r=m;
		}
		printf("%d\n",ps[l].fr);
		last=ps[l].fr;
	}
	return 0;
}
