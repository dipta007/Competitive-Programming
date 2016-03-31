#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,n,a,j,x;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        a=((((((n*567)/9)+7492)*235)/47)-498);
        for(j=1;j<=2;j++)
        {
            x=a%10;
            a=a/10;
        }
        printf("%d\n",abs(x));
    }
    return 0;
}
