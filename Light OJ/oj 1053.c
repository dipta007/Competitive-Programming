#include <stdio.h>

int main()
{
    int T,i,a[3],max,j,b,k,sum;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        max=0;
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[j]);
            if(a[j]>max)
            {
                max=a[j];
                b=j;
            }
        }
        sum=0;
        for(k=0;k<3;k++)
        {
            if(k==b)
                continue;
            else
                sum=sum+(a[k]*a[k]);
        }
        if(sum==max*max)
            printf("Case %d: yes\n",i);
        else
            printf("Case %d: no\n",i);
    }
    return 0;
}
