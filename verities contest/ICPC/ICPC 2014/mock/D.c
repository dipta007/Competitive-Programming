#include<stdio.h>

int run[15]={0,1,2,3,4,6,1,2,3,5,1,2,5,7,0};
int ball[15]={1,1,1,1,1,1,0,0,0,0,0,0,0,0,1};
long count,n;
long a[10000][7]={0};

void fun(long rnew,int bnew)
{


	long nb,nr,i,bn,rn,c;
	c=0;

	for(i=0;i<15;i++)
	{
		bn=bnew-ball[i];
		rn=rnew-run[i];

		if(bn>=0)
		{
			if(i==14)	c++;
			if(rn<=0)
			{
				c++;

			}
			else
			{
				if(bn>0)
					c=c+a[rn][bn];
				else
					c++;
			}
		}
	}
	a[rnew][bnew]=c%10000007;
}


int main()
{
	int i,j,t,b,r;

	scanf("%d",&t);


	for(i=1;i<10001;i++)
	{
	for(j=1;j<7;j++)
		{
		fun(i,j);

		}

	}

	for(i=0;i<t;i++)
	{
		scanf("%ld",&n);
		printf("Case %d: %ld\n",i+1,a[n][6]);
	}



	return 0;
}

