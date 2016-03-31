#include <stdio.h>
#include <math.h>

int main()
{
    long long int N,A,i,b,sum;
    while(scanf("%lld %lld",&N,&A)!=EOF)
    {
        sum=0;
        for(i=1;i<=N;i++)
        {
            b=pow(A,i);
            sum=sum+ (i*b);
        }
        printf("%lld\n",sum);
    }
}
