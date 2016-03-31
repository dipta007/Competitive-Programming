#include <stdio.h>

int main()
{
    int T,i,n,m,j,sum,l,k;
    for(i=1;i<=T;i++)
    {
        scanf("%d %d",&n,&m);
        int l=-1;
        sum=0;
        for(j=1;j<=n;)
        {
            for(k=1;k<=m;k++)
            {
                sum=sum+ (j*l);
                j++;
            }
            l=-l;
        }
        printf("%d\n",sum);
    }

}
