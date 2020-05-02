//POJ 2155
#include<iostream>
#include<cstdio>
#include<cstring>
#define M 1010
using namespace std;
int bit[M][M];
int N,T;
void init()
{
	memset(bit,0,sizeof(bit));
}

int lowbit(int x)
{
	return x&-x;
}
void update(int x,int y)
{
	for(int i=x;i<=N+1;i+=lowbit(i))
		for(int j=y;j<=N+1;j+=lowbit(j))
		{
			bit[i][j]++;
		}
}

int getsum(int x,int y)
{
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
		{
			ans+=bit[i][j];
		}
	return ans;
}

int main()
{
	//freopen("1.in","r",stdin);
	ios::sync_with_stdio(false);
	int X,x1,y1,x2,y2;
	char c;
	cin>>X;
	while(X--)
	{
		init();
		cin>>N>>T;
		for(int i=0;i<T;++i)
		{
			cin>>c;
			if(c=='C'||c=='c')
			{
				cin>>x1>>y1>>x2>>y2;
				++x2;++y2;
				update(x1,y1);
				update(x2,y1);
				update(x1,y2);
				update(x2,y2);
			}
			else
			{
				cin>>x1>>y1;
				cout<<(1&getsum(x1,y1))<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}
