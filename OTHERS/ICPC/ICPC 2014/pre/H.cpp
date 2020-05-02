#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[99999999];
int f(int n)
{
    if(n==0)
        return 1;
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    else
    {
        dp[n]=n*f(n-1);
        return dp[n];
    }
}
int main()
{
    int n,i,j,T;
    scanf("%d", &T);
    for(i=0;i<=99999999;i++)
        dp[i]=-1;
    for(j=1;j<=T;j++)
    {

    scanf("%d", &n);
    printf("Case %d: %d\n",j, f(n));
    }
    return 0;
}

