/*
模板说明：实际上保存的是一棵没有重复结点的treap，然后与普通treap不同的是多了一个重复值域w，代表有多少个v在这棵树上。初始时w=1。这时各个函数都要做一些小的修改。插入时如果发现有相同节点，直接给它的size域和重复值域加1就行了。删除时，如果待删除结点w>1，直接减1即可。查询第k大以及查询x的排名等细节详见代码。
*/
//对应题目：tyvj1728 (bzoj3224)
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=1<<28;
struct Node{
	int s,v,r,w;		//w代表重复值域
	Node* ch[2];
	Node(int v):v(v) {ch[0]=ch[1]=NULL;s=w=1;r=rand();}
	bool operator<(const Node& rhs)
	{
		return r<rhs.r;
	}
	int cmp(int x)
	{
		if(v==x) return -1;
		return x<v?0:1;
	}
	void maintain()
	{
		s=1;
		if(ch[0]!=NULL) s+=ch[0]->s;
		if(ch[1]!=NULL) s+=ch[1]->s;
		s+=w-1;
	}
}*root;

void rotate(Node* &o,int d)
{
	Node* k=o->ch[d^1];
	o->ch[d^1]=k->ch[d];
	k->ch[d]=o;
	o->maintain();
	k->maintain();
	o=k;
}

void insert(Node* &o,int x)
{
	if(o==NULL) o=new Node(x);
	else
	{
		int d=o->cmp(x);
		if(d==-1) ++(o->w),++(o->s);
		else
		{
			insert(o->ch[d],x);
			if(o->ch[d]->r > o->r) rotate(o,d^1);
		}
	}
	o->maintain();
}

void remove(Node* &o,int x)
{
	int d=o->cmp(x);
	if(d==-1)
	{
		if(o->w>1) --(o->w),--(o->s);
		else
		{
			if(o->ch[0]!=NULL && o->ch[1]!=NULL)
			{
				int d2=o->ch[0]->r > o->ch[1]->r ? 1:0;
				rotate(o,d2);
				remove(o->ch[d2],x);
			}
			else
			{
				if(o->ch[0]==NULL) o=o->ch[1];
				else o=o->ch[0];
			}
		}
	}
	else remove(o->ch[d],x);
	if(o!=NULL) o->maintain();
}

#define getsz (o->ch[0]==NULL?0:o->ch[0]->s)
int kth(Node* o,int k)		//第k小的数
{
	if(o==NULL || k>o->s || k<=0) return 0;
	int s=getsz;
	if(k>s && k<=s+o->w) return o->v;
	else if(k<=s) return kth(o->ch[0],k);
	else return kth(o->ch[1],k-s-o->w);
}

int getrank(Node* o,int x)		//如果有多个x，输出的是最小的那个排名
{
	if(o==NULL) return 0;
	int d=o->cmp(x),s=getsz;
	if(d==-1) return s+1;
	else if(d==0) return getrank(o->ch[0],x);
	else return getrank(o->ch[1],x)+s+o->w;
}

int getbefore(Node* o,int x)		//查询小于x且最大的数
{
	if(o==NULL) return -INF;
	if(o->v < x) return max(o->v,getbefore(o->ch[1],x));
	else return getbefore(o->ch[0],x);
}

int getafter(Node* o,int x)			//查询大于x且最小的数
{
	if(o==NULL) return INF;
	if(o->v > x) return min(o->v,getafter(o->ch[0],x));
	else return getafter(o->ch[1],x);
}

int n;
int main()
{
	//freopen("1.in","r",stdin);
	srand(23333);
	scanf("%d",&n);
	root=NULL;
	while(n--)
	{
		int opt,x;
		scanf("%d%d",&opt,&x);
		switch(opt)
		{
			case 1:insert(root,x);
				   break;
			case 2:remove(root,x);
				   break;
			case 3:printf("%d\n",getrank(root,x));
				   break;
			case 4:printf("%d\n",kth(root,x));
				   break;
			case 5:printf("%d\n",getbefore(root,x));
				   break;
			default:printf("%d\n",getafter(root,x));
		}
	}
	return 0;
}
