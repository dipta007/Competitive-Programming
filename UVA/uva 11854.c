#include <stdio.h>

int main()
{
    int a[3],i,max,k,sum;
    while(1)
    {
        max=0;
        for(i=0;i<3;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>max)
            {
                max=a[i];
                k=i;
            }
        }
        if(a[0]==0 && a[1]==0 && a[2]==0)
            break;

        sum=0;
        for(i=0;i<3;i++)
        {
            if(i==k)
                continue;
            sum=sum+ (a[i]*a[i]);
        }
        max=max*max;
        if(sum==max)
            printf("right\n");
        else
            printf("wrong\n");
    }
    return 0;
}
