//bzoj 3282
#include<cstdio>
#include<algorithm>
#define rep(i,n) for(int i=0;i<n;++i)
const int MAXN=300000+10;
const int INF=~0U>>1;
struct Node{
	Node* p,*ch[2];
	int v,xsum;
	bool rev;
	Node()
	{
		v=xsum=rev=0;
	}
	inline void revIt()
	{
		std::swap(ch[0],ch[1]);
		rev^=1;
	}
	inline void maintain()
	{
		xsum=ch[0]->xsum^ch[1]->xsum^v;
	}
	inline void setc(Node* t,bool d)
	{
		ch[d]=t;
		t->p=this;
	}
	inline bool d() const
	{
		return p->ch[1]==this;
	}
	inline bool isRoot() const;
	inline void pushdown();
}Tnull,*null=&Tnull;
inline void Node::pushdown()
{
	if(rev)
	{
		rev=0;
		rep(i,2) if(ch[i]!=null)
			ch[i]->revIt();
	}
}
inline bool Node::isRoot() const
{
	return p==null || (p->ch[0]!=this && p->ch[1]!=this);
}
inline void rot(Node *t)
{
	Node* p=t->p;
	p->pushdown();t->pushdown();
	bool d=t->d();
	if(!p->isRoot())p->p->setc(t,p->d());
	else t->p=p->p;
	p->setc(t->ch[d^1],d);
	t->setc(p,d^1);
	p->maintain();
}
inline void splay(Node* t)
{
	t->pushdown();
	while(!t->isRoot())
	{
		if(t->p->isRoot()) rot(t);
		else t->d()==t->p->d()?(rot(t->p),rot(t)):(rot(t),rot(t));
	}
	t->maintain();
}
inline void access(Node* u)
{
	for(Node* v=null;u!=null;v=u,u=u->p)
	{
		splay(u);
		u->setc(v,1);
		u->maintain();
	}
}
inline void makeRoot(Node* u)
{
	access(u);
	splay(u);
	u->revIt();
}
inline Node* getRoot(Node* u)
{
	for(;u->p!=null;u=u->p);
	return u;
}
inline void link(Node* u,Node* v)
{
	if(getRoot(u)==getRoot(v)) return;
	makeRoot(u);
	u->p=v;
}
inline void cut(Node* u,Node* v)
{
	if(u==v || getRoot(u)!=getRoot(v)) return;
	makeRoot(u);
	access(v);
	splay(v);
	if(v->ch[0]==u)
	{
		u->p=null;
		v->setc(null,0);
		v->maintain();
	}
}
inline void change(Node* u,int v)
{
	access(u);
	splay(u);
	u->v=v;
	u->maintain();
}
inline int query(Node* u,Node* v)
{
	makeRoot(u);
	access(v);
	splay(v);
	return v->xsum;
}
Node mem[MAXN],*C=mem;
inline Node* newNode(int x)
{
	C->p=C->ch[0]=C->ch[1]=null;
	C->v=C->xsum=x;
	C->rev=0;
	return C++;
}
int n,m;
Node* pt[MAXN];
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x;
	rep(i,n) scanf("%d",&x),pt[i+1]=newNode(x);
	while(m--)
	{
		int q,u,v;
		scanf("%d%d%d",&q,&u,&v);
		switch(q)
		{
			case 0:printf("%d\n",query(pt[u],pt[v]));break;
			case 1:link(pt[u],pt[v]);break;
			case 2:cut(pt[u],pt[v]);break;
			case 3:change(pt[u],v);break;
		}
	}
	return 0;
}
