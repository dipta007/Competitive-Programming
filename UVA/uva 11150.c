#include <stdio.h>

int main()
{
    int N,sum,n1,n2,flag;
    while(scanf("%d",&N)!=EOF)
    {
        flag =0;
        sum=N;
        if(N%3==2)
        {
            N=N+1;
            flag=1;s
        }
        while(N>2)
        {
            n1=N/3;
            n2=N%3;
            N=n1 + n2;
            if(N==2 && flag==0)
                N=N+1;
            sum=sum+n1;

        }
        printf("%d\n",sum);
    }
    return 0;
}
