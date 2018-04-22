#include <stdio.h>

int main()
{
    int T,count,a[30],i,sum,n,p,q,j,k,l;
    scanf("%d",&T);
    if(T>100)
        return 0;
    for(i=1;i<=T;i++)
    {
        sum=0;
        count=0;
        scanf("%d %d %d",&n,&p,&q);
        if((n>=1 && n<=30) && (p>=1 && p<=30) && (q>=1 && q<=30))
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[j]);
            }
            for(l=0;l<n;l++)
            {
                if((sum+a[l])>q || count==p)
                    break;
                sum=sum+a[l];
                count++;
            }
            printf("Case %d: %d\n",i,count);
        }

    }
    return 0;
}
