#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void build(char *s1,char *s2,char* s,int n)
{
	if(n<=0) return;
	char t;
	t=s1[0];
	int p=strchr(s2,t)-s2;
	build(s1+1,s2,s,p);
	build(s1+p+1,s2+p+1,s+p,n-p-1);
	s[n-1]=t;
}
int main()
{
	char s1[]="ABDEGMNCFH";
	char s2[]="DBMGNEACHF";
	int n=10;
	char s[100];
	build(s1,s2,s,n);
	s[n]='\0';
	cout<<s;
	cin.get();
	return 0;
}
