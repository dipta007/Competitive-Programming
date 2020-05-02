//POJ 3580
#include<cstdio>
#include<algorithm>
#include<cstring>
const int INF=~0U>>1;
const int MAXN=100000+10;
int n,m;
int a[MAXN];
struct Node{
	int s,v,add,mn;
	bool rev;
	Node* p,*ch[2];
	Node() {s=0;add=0;v=mn=INF;}
	inline bool d() {return p->ch[1]==this;}
	inline void setc(Node* o,int d)
	{
		ch[d]=o;
		o->p=this;
	}
	inline void addIt(int x)
	{
		add+=x;
		mn+=x;
		v+=x;
	}
	inline void revIt()
	{
		rev^=1;
	}
	inline void maintain()
	{
		s=ch[0]->s+ch[1]->s+1;
		mn=std::min(v,std::min(ch[0]->mn,ch[1]->mn));
	}
	inline void pushdown();
}Tnull,*null=&Tnull;
Node mem[MAXN<<1],*C=mem;
inline void Node::pushdown()
{
	if(add)
	{
		if(ch[0]!=null) ch[0]->addIt(add);
		if(ch[1]!=null) ch[1]->addIt(add);
		add=0;
	}
	if(rev)
	{
		std::swap(ch[0],ch[1]);
		if(ch[0]!=null) ch[0]->revIt();
		if(ch[1]!=null) ch[1]->revIt();
		rev=0;
	}
}
inline Node* newnode(int v)
{
	C->ch[0]=C->ch[1]=null;
	C->s=1;
	C->v=C->mn=v;
	C->add=C->rev=0;
	return C++;
}
Node* build(int l,int r) //[l,r)
{
	if(l>=r) return null;
	int m=l+(r-l)/2;
	Node* t=newnode(a[m]);
	t->setc(build(l,m),0);
	t->setc(build(m+1,r),1);
	t->maintain();
	return t;
}
Node* root;
inline void rot(Node* t)
{
	Node* p=t->p;
	p->pushdown();t->pushdown();
	int d=t->d();
	p->p->setc(t,p->d());
	p->setc(t->ch[d^1],d);
	t->setc(p,d^1);
	p->maintain();
	if(p==root)
		root=t;
}
void splay(Node* t,Node* f=null)
{
	while(t->p!=f)
	{
		if(t->p->p==f) rot(t);
		else t->d()==t->p->d()?(rot(t->p),rot(t)):(rot(t),rot(t));
	}
	t->maintain();
}
Node* select(int k)
{
	for(Node* t=root;;)
	{
		t->pushdown();
		int s=t->ch[0]->s;
		if(k==s) return t;
		if(k>s) k-=s+1,t=t->ch[1];
		else t=t->ch[0];
	}
}
inline Node*& get(int l,int r) //[l,r)
{
	Node* L=select(l-1);
	Node* R=select(r);
	splay(L);
	splay(R,root);
	return R->ch[0];
}
inline void Reverse(int l,int r)
{
	Node*& t=get(l,r+1);
	t->revIt();
}
inline void Insert(int x,int P)
{
	splay(select(x));
	Node* t=newnode(P);
	t->setc(root->ch[1],1);
	root->setc(t,1);
	t->maintain();
	root->maintain();
}
inline void Add(int x,int y,int D)
{
	Node*& t=get(x,y+1);
	t->addIt(D);
}
inline void Revolve(int x,int y,int T)
{
	int l=y+1-x;
	T=(T%l+l)%l;
	if(T==0) return;
	Reverse(x,y);
	Reverse(x,x+T-1);
	Reverse(x+T,y);
}
inline int Min(int x,int y)
{
	Node* &t=get(x,y+1);
	return  t->mn;
}
inline void Delete(int x)
{
	splay(select(x-1));
	splay(select(x+1),root);
	root->ch[1]->ch[0]=null;
	root->ch[1]->maintain();
	root->maintain();
}
int main()
{
//	freopen("1.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	a[0]=a[n+1]=INF;
	root=build(0,n+2);
	root->p=null;
	scanf("%d",&m);
	while(m--)
	{
		int x,y,k;
		char s[20];
		scanf("%s",s);
		switch(s[0])
		{
			case 'A':scanf("%d%d%d",&x,&y,&k);
					 Add(x,y,k);
					 break;
			case 'I':scanf("%d%d",&x,&k);
					 Insert(x,k);
					 break;
			case 'D':scanf("%d",&x);
					 Delete(x);
					 break;
			case 'M':scanf("%d%d",&x,&y);
					 printf("%d\n",Min(x,y));
					 break;
			case 'R':if(s[3]=='E')
					 {
					 	scanf("%d%d",&x,&y);
						Reverse(x,y);
					 }
					 else
					 {
					 	scanf("%d%d%d",&x,&y,&k);
						Revolve(x,y,k);
					 }
		}
	}
	return 0;
}
