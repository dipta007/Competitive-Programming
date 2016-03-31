#include <stdio.h>

int main()
{
    unsigned long int N,M,i,j,sum,x;
    while(scanf("%u %u",&N,&M)!=EOF)
    {
        sum=1;
        for(i=N;i>=(N-M+1);i--)
        {
            sum=sum*i;
        }
        x=0;
        for(j=1;x==0;j++)
        {
            x=sum%10;
            sum=sum/10;
        }
        printf("%u\n",x);
    }
    return 0;
}
