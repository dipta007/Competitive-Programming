//POJ 2104
#include<cstdio>
#include<algorithm>
#define fr first
#define sc second
const int MAXN=100000+5;
const int INF=~0U>>1;
const int BUFFER_SIZE=10000;
struct Tree{
	int l,r,sum;
	Tree* pl,*pr;
	Tree* set(int _l,int _r,Tree* _pl,Tree* _pr)
	{
		l=_l;r=_r;pl=_pl;pr=_pr;
		sum=pl->sum+pr->sum;
		return this;
	}
	Tree* set(int _l,int _r,int all);
	Tree* add(int pos,int ad);
};
Tree* buffer=0,*cur;
inline Tree* get()
{
	if(!buffer || cur-buffer==BUFFER_SIZE)
		buffer=new Tree[BUFFER_SIZE],cur=buffer;
	return cur++;
}
Tree* Tree::set(int _l,int _r,int all)
{
	l=_l;r=_r;
	if(l+1==r) sum=all;
	else
	{
		int m=(l+r)>>1;
		pl=get()->set(l,m,all);
		pr=get()->set(m,r,all);
		sum=pl->sum+pr->sum;
	}
	return this;
}
Tree* Tree::add(int pos,int ad)
{
	if(l+1==r) return get()->set(l,r,sum+ad);
	int m=(l+r)>>1;
	if(pos<m) return get()->set(l,r,pl->add(pos,ad),pr);
	else return get()->set(l,r,pl,pr->add(pos,ad));
}
int n,m;
typedef std::pair<int,int>P;
P ps[MAXN];
int na[MAXN];
Tree* root[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	int t;
	for(int i=0;i<n;++i) scanf("%d",&t),ps[i]=P(t,i);
	std::sort(ps,ps+n);
	for(int i=0;i<n;++i) na[ps[i].sc]=i;
	root[0]=get()->set(0,n,0);
	for(int i=1;i<=n;++i) root[i]=root[i-1]->add(na[i-1],1);
	while(m--)
	{
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		Tree* ta=root[a-1],*tb=root[b];
		--k;
		while(ta->l +1 < ta->r)
		{
			int cnt=tb->pl->sum - ta->pl->sum;
			if(cnt<=k) k-=cnt,ta=ta->pr,tb=tb->pr;
			else ta=ta->pl,tb=tb->pl;
		}
		printf("%d\n",ps[ta->l].fr);
	}
	return 0;
}
