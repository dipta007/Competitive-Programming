#include <stdio.h>

int main()
{
    int n,sum,n1,n2;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        sum=0;
        while(n>1)
        {
            if(n==2)
                n=n+1;
            n1=n/3;
            n2=n%3;
            n=n1 + n2;
            sum=sum+ n1;

        }
        printf("%d\n",sum);


    }
    return 0;
}
