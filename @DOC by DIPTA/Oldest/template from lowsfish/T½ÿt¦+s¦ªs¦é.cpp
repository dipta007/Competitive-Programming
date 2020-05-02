#include<iostream>
#include<cstdio>
#include<cstring>
#define M 100000
using namespace std;
typedef long double l;
class bign{
	private:int a[M],len;
	public:
	bign();
	bign(const int &n);
	bign operator*(const int &n);
	bign operator*=(const int &n);
	friend ostream & operator<<(ostream &out,bign &a);
	friend istream & operator>>(istream &in,bign &a);
};
bign::bign()
{
	len=0;
	for(int i=0;i<M;++i) a[M]=0;
}
bign::bign(const int &n)
{
	int t=n;
	len=0;
	while(t)
	{
		a[len++]=t%10;
		t/=10;
	}
	for(int i=len;i<M;++i)a[i]=0;
}
bign bign::operator*(const int &n)
{
	int i;
	for(i=0;i<len;++i) a[i]*=n;
	for(i=0;i<len;++i)
		{
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
	if(a[len]==0) return *this;
	int x=a[len];			//处理进位 
	while(x!=0)
	{
		a[len]=x%10;
		x/=10;
		++len;
	}
	return *this; 
}

bign bign::operator*=(const int &n)
{
	*this=*this*n;
	return *this;
}
/*bign pow(const bign &a,int  b)
{
	int r=1,base=b;
	while(b)
	{
		if(b&1) r*=base;
		base*=base;
		b>>=1;
	}
	return r;
}*/

ostream & operator<<(ostream &out,bign &a)
{
	for(int i=a.len-1;i>=0;--i)
		out<<a.a[i];
	return out;
}

istream & operator>>(istream &in,bign &a)
{
	char s[M];
	cin>>s;
	for(int i=0;i<strlen(s);++i)
		a.a[i]=s[i]-'0';
	return in;
}
int main()
{
	int a,b;
	cin>>a>>b;
	bign r=bign(a);
	--b; 
	while(b)
	{
		r*=a;
		--b;
	}
	cout<<r<<endl;
	return 0;
}
