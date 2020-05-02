#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<functional>
using namespace std;
const int SIGMA_SIZE=100;
const int MAXNODE=500*200+10;
const int MAXL=200+10;
const int MAXLEN=10000+10;
class AhoCorasick{
	private:
	int ch[MAXNODE][SIGMA_SIZE];
	int f[MAXNODE],val[MAXNODE][2],last[MAXNODE];
	int sz;
	bool used[MAXNODE];
	priority_queue<int,vector<int>,greater<int> > ans;
	int res;

	int idx(char c)
	{
		return c-' ';
	}

	public:
	void init()
	{
		res=0;
		sz=1;
		memset(ch[0],0,sizeof(ch[0]));
		memset(val,0,sizeof(val));
		memset(last,0,sizeof(last));
		memset(f,0,sizeof(f));
	}
	
	void insert(char *s,int v)
	{
		int n=strlen(s),u=0;
		for(int i=0;i<n;++i)
		{
			int c=idx(s[i]);
			if(!ch[u][c])
			{
				memset(ch[sz],0,sizeof(ch[sz]));
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		val[u][0]=v;
		val[u][1]++;
	}

	void getfail()
	{
		queue<int>que;
		for(int c=0;c<SIGMA_SIZE;++c)
		{
			int u=ch[0][c];
			if(u)
			{
				que.push(u);
				last[u]=0;
				f[u]=0;
			}
		}
		while(!que.empty())
		{
			int r=que.front();que.pop();
			for(int c=0;c<SIGMA_SIZE;++c)
			{
				int u=ch[r][c];
				if(!u) continue;
				que.push(u);
				int v=f[r];
				while(v && !ch[v][c]) v=f[v];
				f[u]=ch[v][c];
				last[u]=val[f[u]]?f[u]:last[f[u]];
			}
		}
	}
	
	void count(int j)
	{
		if(j&& val[j][0])
		{
			ans.push(val[j][0]);
			count(last[j]);
		}

	}
	void find(char *T)
	{
		int n=strlen(T),j=0;
		for(int i=0;i<n;++i)
		{
			int c=idx(T[i]);
			while(j && !ch[j][c]) j=f[j];
			j=ch[j][c];
			if(val[j]) count(j);
			else if(last[j]) count(last[j]);
		}	
	}
	void show(int i)
	{
		if(ans.empty()) return;
		++res;
		printf("web %d:",i);
		while(!ans.empty())
		{
			printf(" %d",ans.top());
			ans.pop();
		}
		putchar('\n');
	}	
	
	void showtot()
	{
		printf("total: %d\n",res);
	}
}ac;
int main()
{
	//freopen("1.in","r",stdin);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
	ac.init();
	for(int i=1;i<=n;++i)
	{
		char s[MAXL];
		scanf("%s",s);
		ac.insert(s,i);
	}
	scanf("%d",&n);
	ac.getfail();
	for(int i=1;i<=n;++i)
	{
		char s[MAXLEN];
		scanf("%s",s);
		ac.find(s);
		ac.show(i);
	}
	ac.showtot();
	}
	return 0;
}
