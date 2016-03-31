#include <stdio.h>

int main()
{
    int T,i,b;
    double a;
    for(i=1;i<=T;i++)
    {
        scanf("%d %d",&a,&b);

        if(a%b==0)
            printf("Case %d: divisible\n");
        else
            printf("Case %d: not divisible\n");
    }
}
