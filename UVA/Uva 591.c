#include <stdio.h>

int main()
{
    int n,a[60],i,sum,b,res,j,count=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;

        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum=sum+a[i];
        }
        b=sum/n;

        res=0;
        for(j=0;j<n;j++)
        {
            if(a[j]>b)
                res=res+ (a[j]-b);
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",count++,res);
    }
    return 0;
}
