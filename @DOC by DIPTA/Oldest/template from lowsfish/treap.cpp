#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
struct Node{
    Node *ch[2];
    int r,v,s;
    Node(int v):v(v) {ch[0]=ch[1]=NULL;r=rand();s=1;}
    bool operator < (const Node& rhs)const
    {
        return r < rhs.r;    
    }
    
    int cmp(int x)const
    {
        if(x==v) return -1;
        return x < v ? 0 : 1;
    }
    void maintain()
    {
        s=1;
        if(ch[0] != NULL) s += ch[0]->s;
        if(ch[1] != NULL) s += ch[1]->s;     
    }
}*root;

void rotate(Node* &o, int d)    //d==0 left; d==1 right
{
    Node *k = o->ch[d^1];
    o->ch[d^1] = k->ch[d];
    k->ch[d] = o;
    o->maintain();
    k->maintain();
    o=k;
}

bool find(Node *o,int x)
{
    while(o != NULL)
    {
        int d=o->cmp(x);
        if(d == 1) return 1;
        else o = o->ch[d];    
    }    
    return 0;
}

void insert(Node *&o, int x)
{
    if(o == NULL) o=new Node(x);
    else {
        int d = (x < o->v? 0 : 1);
        //int d = o->cmp(x);
        insert(o->ch[d],x);
        if(o->ch[d] -> r > o->r) rotate(o,d^1);    
    }
    o->maintain();
}

void remove(Node* &o,int x)
{
    int d = o->cmp(x);
    if(d==-1)
    {
        if(o->ch[0] != NULL && o->ch[1] != NULL)
		{
			int d2 = (o->ch[0]->r > o->ch[1]->r ? 1 : 0);
			rotate(o,d2);
			remove(o->ch[d2],x);
		}
		else
		{
			if(o->ch[0] == NULL) o = o->ch[1];
			else o = o->ch[0];
		}
    }
	else remove(o->ch[d],x);
	if(o != NULL) o->maintain();
}

int kth(Node *o,int k)
{
	if(o == NULL || k <= 0 || k > o->s) return 0;
	int s = (o->ch[0] == NULL ? 0 : o->ch[0]->s);
	if(k == s+1) return o->v;
	else if(k <= s) return kth(o->ch[0],k);
	else return kth(o->ch[1],k-s-1);
}

typedef pair<int,int> P;
const int MAXM=50000+10;
struct query{
	P seg;
	int id,k;
	bool operator < (const query &a)const
	{
		return seg < a.seg;
	}
}q[MAXM];

const int MAXN=100000+10;
int num[MAXN];
int ans[MAXM];

#define sf seg.first
#define ss seg.second
int main()
{
	freopen("1.in","r",stdin);
	srand((int)time(NULL));
	root=NULL;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;++i)
	{
		scanf("%d",num+i);
	}
	for(int i = 0;i < m;++i)
	{
		scanf("%d%d%d",&q[i].sf,&q[i].ss,&q[i].k);
		if(q[i].sf > q[i].ss) swap(q[i].sf,q[i].ss);
		q[i].id = i+1;
	}
	sort(q,q+m);
	for(int i=q[0].sf;i<=q[0].ss;++i) insert(root,num[i]);
	ans[q[0].id] = kth(root,q[0].k);
	for(int i=1;i<m;++i)
	{
		for(int j=q[i-1].sf;j<=min(q[i-1].ss,q[i].sf-1);++j) remove(root,num[j]);
		for(int j=max(q[i-1].ss+1,q[i].sf);j<=q[i].ss;++j) insert(root,num[j]);
		ans[q[i].id]=kth(root,q[i].k);
	}
	for(int i=1;i<=m;++i) printf("%d\n",ans[i]);
	return 0;
}
