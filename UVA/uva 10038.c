#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a[3200],b[3200],c[3200],i,d,flag;

    while(scanf("%d",&n)!=EOF)
    {
        flag=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
        {
            b[i]=abs(a[i]-a[i+1]);
            c[b[i]]++;
        }
        for(i=0;i<10;i++)
        {
            if(c[i]>1)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
