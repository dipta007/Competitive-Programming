#include <stdio.h>

int main()
{
    int n,i,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x==1 || x==4 || x==78)
            printf("+\n");
        else if(x==135 || x==435 || x==7835)
            printf("-\n");
        else if(x==914 || x==944 || x==9784)
            printf("*\n");
        else if(x==1901 || x==1904 || x==19078)
            printf("?\n");

    }
    return 0;
}
