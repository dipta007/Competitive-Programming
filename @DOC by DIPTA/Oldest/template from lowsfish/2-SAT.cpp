//bzoj 1823
#include<cstdio>
#include<cstring>
#include<vector>
#define rep(i,n) for(int i=0;i<n;++i)
const int MAXN=100+5;
typedef std::vector<int>::iterator it;
struct TwoSAT{
	int n;
	std::vector<int> G[MAXN<<2];
	bool mark[MAXN<<2];
	int S[MAXN<<2],c;
	void init(int n)
	{
		this->n=n;
		rep(i,(n<<2)) G[i].clear();
		memset(mark,0,sizeof(mark));
	}
	bool dfs(int u)
	{
		if(mark[u]) return 1;
		if(mark[u^1]) return 0;
		mark[u]=1;
		S[c++]=u;
		for(it e=G[u].begin();e!=G[u].end();++e)
			if(!dfs(*e)) return 0;
		return 1;
	}
	void addEdge(char* s1,char* s2)
	{
		int num1=0,num2=0,p1=1,p2=1;
		while(s1[p1]) num1=num1*10+s1[p1++]-'0';
		while(s2[p2]) num2=num2*10+s2[p2++]-'0';
		int x=(num1<<1)+(s1[0]=='h'),y=(num2<<1)+(s2[0]=='h');
		G[x^1].push_back(y);
		G[y^1].push_back(x);
	}
	bool solve()
	{
		for(int i=0;i<(n<<2);i+=2) if(!mark[i] && !mark[i+1])
		{
			c=0;
			if(!dfs(i))
			{
				while(c>0) mark[S[--c]]=0;
				if(!dfs(i+1)) return 0;
			}
		}
		return 1;
	}
}ts;
int T;
int n,m;
int main()
{
	//freopen("1.in","r",stdin);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		ts.init(n);
		while(m--)
		{
			char s1[10],s2[10];
			scanf("%s%s",s1,s2);
			ts.addEdge(s1,s2);
		}
		printf("%s\n",ts.solve()?"GOOD":"BAD");
	}
	return 0;
}
