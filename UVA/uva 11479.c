#include <stdio.h>

int main()
{
    long long int T,i,j,a[3],max,k,sum;
    scanf("%lld",&T);
    for(i=1;i<=T;i++)
    {
        max=0;
        for(j=0;j<3;j++)
        {
            scanf("%lld",&a[j]);
            if(a[j]>=max)
            {
                max=a[j];
                k=j;
            }
        }

        sum=0;
        for(j=0;j<3;j++)
        {
            if(j==k)
                continue;
            sum=sum+a[j];
        }

        if(sum<=max)
            printf("Case %d: Invalid\n",i);
        else
        {
            if((a[0]==a[1]) && (a[1]==a[2]))
                printf("Case %lld: Equilateral\n",i);
            else if((a[0]==a[1]) || a[1]==a[2] || (a[2]==a[0]))
                printf("Case %lld: Isosceles\n",i);
            else if(a[0]!=a[1]!=a[2])
                printf("Case %lld: Scalene\n",i);
        }

    }
    return 0;
}
