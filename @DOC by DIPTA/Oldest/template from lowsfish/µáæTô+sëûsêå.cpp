//BZOJ 1036
#include<cstdio>
#include<algorithm>
#include<vector>
typedef std::vector<int>::iterator it;
const int MAXN=30000+10;
const int MAXO=(1<<16)+10;
const int INF=~0U>>3;
int maxv[MAXO],sumv[MAXO];
int top[MAXN],dep[MAXN],fa[MAXN],son[MAXN],sz[MAXN],w[MAXN];
int val[MAXN];
std::vector<int> G[MAXN];
int n,root;
void dfs(int u)
{
	sz[u]=1;son[u]=-1;
	for(it e=G[u].begin();e!=G[u].end();++e) if(*e!=fa[u])
		{
			fa[*e]=u;
			dep[*e]=dep[u]+1;
			dfs(*e);
			if(son[u]==-1 || sz[*e]>sz[son[u]]) son[u]=*e;
			sz[u]+=sz[*e];
		}
}
void dfs2(int u,int tp)
{
	static int dfs_clock;
	w[u]=++dfs_clock;top[u]=tp;
	if(~son[u]) dfs2(son[u],tp);
	for(it e=G[u].begin();e!=G[u].end();++e)
		if(*e!=son[u] && *e!=fa[u])
			dfs2(*e,*e);
}
inline void maintain(int o)
{
	int lc=o<<1,rc=o<<1|1;
	maxv[o]=std::max(maxv[lc],maxv[rc]);
	sumv[o]=sumv[lc]+sumv[rc];
}
void update(int o,int l,int r,int x,int a)
{
	if(x<l || x>r) return;
	if(l==r) {maxv[o]=sumv[o]=a;return;}
	int m=l+r>>1;
	if(x<=m) update(o<<1,l,m,x,a);
	else update(o<<1|1,m+1,r,x,a);
	maintain(o);
}
int askmax(int o,int l,int r,int x1,int x2)
{
	if(x1>r || x2<l) return -INF;
	if(l>=x1 && r<=x2) return maxv[o];
	int m=l+r>>1;
	return std::max(askmax(o<<1,l,m,x1,x2),askmax(o<<1|1,m+1,r,x1,x2));
}
int asksum(int o,int l,int r,int x1,int x2)
{
	if(x1>r || x2<l) return 0;
	if(l>=x1 && r<=x2) return sumv[o];
	int m=l+r>>1;
	return asksum(o<<1,l,m,x1,x2)+asksum(o<<1|1,m+1,r,x1,x2);
}
int totn;
void init()
{
	int k;
	scanf("%d",&n);
	while((1<<k)<=n) ++k;
	totn=1<<k;
	for(int i=totn+1;i<=(totn<<1);++i) maxv[i]=-INF,sumv[i]=0;
	root=1;
	fa[root]=-1;
	dep[root]=0;
	for(int i=0;i<n-1;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;++i) scanf("%d",val+i);
	dfs(root);
	dfs2(root,root);
	for(int i=1;i<=n;++i)
		update(1,1,totn,w[i],val[i]);
}
void work()
{
	int m,a,b;
	char s[10];
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s%d%d",s,&a,&b);
		if(s[0]=='C')
			update(1,1,totn,w[a],b);
		else if(s[1]=='M')
		{
			int ans=-INF,f1=top[a],f2=top[b];
			while(f1!=f2)
			{
				if(dep[f1]<dep[f2]) std::swap(f1,f2),std::swap(a,b);
				ans=std::max(ans,askmax(1,1,totn,w[f1],w[a]));
				a=fa[f1];f1=top[a];
			}
			if(dep[a]<dep[b]) std::swap(a,b);
			ans=std::max(ans,askmax(1,1,totn,w[b],w[a]));
			printf("%d\n",ans);
		}
		else
		{
			int ans=0,f1=top[a],f2=top[b];
			while(f1!=f2)
			{
				if(dep[f1]<dep[f2]) std::swap(f1,f2),std::swap(a,b);
				ans+=asksum(1,1,totn,w[f1],w[a]);
				a=fa[f1];f1=top[a];
			}
			if(dep[a]<dep[b]) std::swap(a,b);
			ans+=asksum(1,1,totn,w[b],w[a]);
			printf("%d\n",ans);
		}
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	init();
	work();
	return 0;
}
