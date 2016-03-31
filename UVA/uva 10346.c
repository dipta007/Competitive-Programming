#include <stdio.h>

int main()
{
    int n,k,sum,a,b,i;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        sum=n;
        for(i=1;(n/k)!=0;i++)
        {
            a=n/k;
            sum=sum+a;
            b=n%k;
            n=a+b;
        }
        printf("%d\n",sum);
    }
    return 0;
}
