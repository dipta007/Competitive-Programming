#include <stdio.h>

int main()
{
    int N,i,n1,sum,n2,e,f,c,n;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        scanf("%d %d %d",&e,&f,&c);
        sum=0;
        n=e+f;
        n1=2;
        while(n1>0)
        {
            n1=n/c;
            n2=n%c;
            n=n1 + n2;
            sum=sum+ n1;
        }
        printf("%d\n",sum);
    }

    return 0;
}
