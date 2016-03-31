#include <stdio.h>

int main()
{
    int n,i,j,sum;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        sum=345;
        for(j=1;(sum/10)!=0;j++)
        {
            sum=0;
            for(i=1;n!=0;i++)
            {
                sum=sum+(n%10);
                n=n/10;
            }
            n=sum;
        }
        printf("%d\n",sum);
    }
    return 0;
}
