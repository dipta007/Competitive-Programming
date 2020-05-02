//POJ 1509
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<cctype>
#include<ctime>
#include<cstdlib>
#define rep(i,n) for(int i=0;i<n;++i)
const int MAXN=10000+5;
const int SIGMA_SIZE=26;
struct State{
	State*suf,*go[SIGMA_SIZE];
	int val;
	State():suf(0),val(0) {memset(go,0,sizeof go);}
}*root,*last;
State mem[MAXN<<1],*cur;
inline void init()
{
	cur=mem;
	mem[0]=State();
	root=last=cur++;
}
void extend(int w)
{
	State* p=last,*np=cur++;
	*np=State();
	np->val=p->val+1;
	while(p && !p->go[w]) p->go[w]=np,p=p->suf;
	if(!p) np->suf=root;
	else
	{
		State* q=p->go[w];
		if(q->val == p->val+1) np->suf=q;
		else
		{
			State* nq=cur++;
			memcpy(nq->go,q->go,sizeof q->go);
			nq->suf=q->suf;
			nq->val=p->val+1;
			np->suf=q->suf=nq;
			while(p && p->go[w]==q)
				p->go[w]=nq,p=p->suf;
		}
	}
	last=np;
}
char s[MAXN<<1],ans[MAXN];
int n,T;
int main()
{
//	freopen("1.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		init();
		n=strlen(s);
		rep(i,n) extend(s[i]-'a');
		rep(i,n) extend(s[i]-'a');
		State* t=root;
		rep(i,n)
		{
			rep(j,SIGMA_SIZE) if(t->go[j])
			{
				t=t->go[j];
				break;
			}
		}
		printf("%d\n",t->val-n+1);
	}
	return 0;
}
