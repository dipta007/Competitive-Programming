//BZOJ 3676
#include<cstdio>
#include<algorithm>
#include<cstring>
const int MAXN=300000+5;
const int SIGMA_SIZE=26;
typedef long long LL;
struct Node{
	Node* go[SIGMA_SIZE],*fail;
	int cnt,num,len;	//本题中num(代表当前结点含有的本质不同回文串个数)可不保存
	Node():fail(0) {cnt=num=len=0;memset(go,0,sizeof go);}
};
Node mem[MAXN],*cur=mem;
Node* last;
Node* root0,*root1;
void init()
{
	cur=mem;
	root0=cur++;
	root1=cur++;
	root1->len=-1;
	root0->fail=root1;
	last=root1;
}
inline Node* newNode(int len)
{
	cur->len=len;
	return cur++;
}
char s[MAXN];
int p=0;
inline Node* getFail(Node* t)
{
	while(s[p- t->len -1]!=s[p]) t=t->fail;
	return t;
}
inline void extend(int w)
{
	++p;
	Node* t=getFail(last);
	if(!t->go[w])
	{
		Node* nt=newNode(t->len+2);
		t->go[w]=nt;
		if(t==root1) nt->fail=root0;
		else nt->fail=getFail(t->fail)->go[w];
		nt->num=nt->fail->num+1;
	}
	(last=t->go[w])->cnt++;
}
LL ans=0;
void count()
{
	for(Node* t=cur-1;t>=mem+2;--t)
	{
		t->fail->cnt+=t->cnt;
		ans=std::max(ans,(LL)t->len*t->cnt);
	}
}
int main()
{
	//freopen("1.in","r",stdin);
	scanf("%s",s+1);
	init();
	int n=strlen(s+1);
	s[0]='a'-1;
	for(int i=1;i<=n;++i) extend(s[i]-'a');
	count();
	printf("%lld\n",ans);
	return 0;
}
