#include <stdio.h>

int main()
{
    long long int T,i,n,j,p,k,x,y,sum;
    scanf("%lld",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lld",&n);
        for(j=n+1;;j++)
        {
            y=j;
            sum=0;
            for(k=1;y!=0;k++)
            {
                x=y%10;
                sum=(sum*10)+x;
                y=y/10;
            }
            if(sum==j)
            {
                printf("Case %lld: %lld\n",i,j);
                break;
            }
        }
    }
    return 0;
}
