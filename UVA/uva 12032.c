#include <stdio.h>

int main()
{
    int T,i,j,a[100000],d[100000],max,n;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%d",&a[j]);
        for(j=0;j<n;j++)
        {
            if(j==0)
                d[j]=a[j]-0;
            else
                d[j]=a[j]-a[j-1];
        }
        max=d[0];
        for(j=1;j<n;j++)
        {
            if(d[j]>max)
                max=d[j];
        }
        printf("Case %d: %d\n",i,max);
    }
    return 0;
}
