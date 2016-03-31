#include <stdio.h>

int main()
{
    long long int N,p,a,sum,j;
    while(scanf("%lld",&N)!=EOF)
    {
        if(N<0)
            break;
        p=1;
        sum=0;
        for(j=1;N!=0;j++)
        {
            a=N%3;
            sum=sum + (a*p);
            N=N/3;
            p=p*10;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
