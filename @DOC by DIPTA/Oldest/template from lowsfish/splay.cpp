//tyvj 1729
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
	int s,v;
	bool flip;
	Node* ch[2];
	int cmp(int k)const
	{
		int d=k-ch[0]->s;
		if(d==1) return -1;
		return d<=0?0:1;
	}
	void maintain()
	{
		s=ch[0]->s + ch[1]->s +1;
	}
	void pushdown()
	{
		if(flip)
		{
			flip=0;
			swap(ch[0],ch[1]);
			ch[0]->flip^=1;
			ch[1]->flip^=1;
		}
	}
};

Node *null=new Node();

void rotate(Node* &o,int d)
{
	Node* k=o->ch[d^1];
	o->ch[d^1]=k->ch[d];
	k->ch[d]=o;
	o->maintain();
	k->maintain();
	o=k;
}
void splay(Node* &o,int k)
{
	o->pushdown();
	int d=o->cmp(k);
	if(d==1) k-=o->ch[0]->s+1;
	if(d!=-1)
	{
		Node* p=o->ch[d];
		p->pushdown();
		int d2=p->cmp(k);
		int k2=(d2==0?k:k-p->ch[0]->s-1);
		if(d2!=-1)
		{
			splay(p->ch[d2],k2);
			if(d==d2) rotate(o,d^1);
			else rotate(o->ch[d],d);
		}
		rotate(o,d^1);
	}
}

Node* merge(Node* left,Node* right)
{
	splay(left,left->s);
	left->ch[1]=right;
	left->maintain();
	return left;
}

void split(Node* o,int k,Node* &left,Node* &right)
{
	splay(o,k);
	left=o;
	right=o->ch[1];
	o->ch[1]=null;
	left->maintain();
}

const int MAXN=100000+10;
struct splay_sequence{
	int n;
	Node seq[MAXN];
	Node* root;
	Node* build(int sz)
	{
		if(!sz) return null;
		Node* L=build(sz>>1);
		Node* o=&seq[++n];
		o->v=n;
		o->ch[0]=L;
		o->ch[1]=build(sz-(sz>>1)-1);
		o->flip=o->s=0;
		o->maintain();
		return o;
	}
	void init(int sz)
	{
		n=0;
		null->s=0;
		root=build(sz);
	}
}ss;
vector<int> ans;
void print(Node* o)
{
	if(o==null) return;
	o->pushdown();
	print(o->ch[0]);
	ans.push_back(o->v);
	//printf("%d ",o->v-1);
	print(o->ch[1]);
}


int n,m;
int main()
{
	freopen("1.in","r",stdin);
	scanf("%d%d",&n,&m);
	ss.init(n+1);
	//print(ss.root);
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==b) continue;
		Node *left,*mid,*right,*o;
		split(ss.root,a,left,o);
		split(o,b-a+1,mid,right);
		mid->flip^=1;
		ss.root=merge(merge(left,mid),right);
	}
	print(ss.root);
	for(int i=1;i<ans.size();++i)
	{
		if(i!=1) putchar(' ');
		printf("%d",ans[i]-1);
	}
	return 0;
}
