#include <stdio.h>

int main()
{
    int n,i,count;
    while(scanf("%d",&n)!=EOF){
            count=1;
    printf("%d ",n);
    for(i=1;n!=1;i++)
    {
        for(n=n;n>0 && n%2==0;)
        {
            if(n==1)
            {
                printf("\ncount = %d",count);
                break;
            }
            n=n/2;
            printf("%d ",n);
            count++;

        }
        for(n=n;n>0 && n%2!=0;)
        {
            if(n==1)
            {
                printf("\ncount = %d\n\n",count);
                break;
            }
            n=3*n+1;
            printf("%d ",n);
            count++;
        }
    }}

}
