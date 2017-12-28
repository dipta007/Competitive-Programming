#include <stdio.h>

int main()
{
    int n,i,j,p;
    scanf("%d %d",&n,&i);
    p=1;
    for(j=1;j<=i;j++)
    {
        p=p*n;
    }
    printf("%d",p);
}
