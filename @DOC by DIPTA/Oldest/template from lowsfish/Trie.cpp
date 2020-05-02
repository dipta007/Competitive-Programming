#include<iostream>
#include<cstdio>
#include<cstring>
#define M 1000001
using namespace std;
struct Trie{
	int ch[M][27];
	int val[M];
	int sz;
	Trie(){sz=1;memset(ch[0],0,sizeof(ch[0]));}
	int idx(char c) {return c-'A';}
	void insert(char *s,int v)
	{
		int u=0,n=strlen(s);
		for(int i=0;i<n;++i)
		{
			int c=idx(s[i]);
			if(!ch[u][c])
			{
				memset(ch[sz],0,sizeof(ch[sz]));
				val[sz]=0;
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		val[u]=v;
	}
	void showsz()
	{cout<<sz<<endl;}
}trie;
int main()
{
		char s[M];
	while(cin>>s)
	{
		trie.insert(s,1);
	}
	trie.showsz();
	return 0;	
}
