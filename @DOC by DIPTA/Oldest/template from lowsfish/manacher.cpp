#include<iostream>
#include<cstdio>
#include<cstdlib>
#define M 110001
using namespace std;
int p[2*M+3];
int manacher(char *s)
{
	int len=strlen(s);
	char *s1;
	int nlen=2*len+3,i,j=0,max=0,id=0;
	s1=new char[nlen];
	s1[0]='$';
	s1[1]='#';
	for(i=0;i<len;++i)
	{
		s1[i*2+2]=s[j++];
		s1[i*2+3]='#';
	}
	for(i=0;i<nlen;++i)
	{
		if(max>i)
		{
			p[i]=min(p[2*id-i],max-i);
		}
		else
		{
			p[i]=1;
		}
		while(s1[i+p[i]]==s1[i-p[i]]) ++p[i];
		if(i+p[i]>max)
		{
			max=i+p[i];
			id=i;
		}
	}
	int ans=0;
	for(i=0;i<nlen;++i)
	{
		if(p[i]-1>ans) ans=p[i]-1;
	}
	return  ans;
}
int main()
{
	char s[M];
	while(cin.getline(s,M))
	{
		cout<<manacher(s)<<endl;
		cin.getline(s,M);
	}
	return 0;
}
