#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

bool p[1000004];
int dp[1000004];
void sieve()
{
    memset(p,0,sizeof(p));
    for(int i=3;i*i<=1000002;i=i+2)
    {
        if(p[i]==0)
        {
            for(int j=i*i;j<=1000002;j=j+i+i)
                p[j]=1;
        }
    }
}

int factor(int n)
{
    if(dp[n]!=0)
        return dp[n];
    else
    {
        for(int j=2;y!=1;)
        {
            if((j==2) || (j%2!=0 && p[j]==0))
            {
                if(y%j==0)
                {
                    y=y/j;
                    cnt++;
                }
                else
                    j++;
            }
            else
                j++;
        }
        dp[n]=cnt;
        return dp[n];
    }
}

int main()
{
    int n;
    sieve();
    memset(dp,0,sizeof(dp));
    while(scanf("%d",&n)!=EOF)
    {

        for(int i=2;i<=n;i++)
        {
            sum=sum+

        }

    printf("%d\n",cnt);
    }
}
