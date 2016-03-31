#include <stdio.h>

int main()
{
    long long int N,i,j,a[3],max,k,sum;
    scanf("%lld",&N);
    for(i=1;i<=N;i++)
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
            printf("Wrong!!\n",i);
        else
            printf("OK\n");
    }
    return 0;
}
