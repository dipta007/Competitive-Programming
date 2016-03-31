#include <stdio.h>

int main()
{
    int n,m,i,T,p,j,k=1,l=0,sum;

    scanf("%d",&T);
    if(T>10000)
        return 0;
    for(p=1;p<=T;p++)
    {
        sum=0;
        scanf("%d %d",&n,&m);

        if(n%(2*m)!=0)
            return 0;
        for(i=1;i<=(n/m);i++)
        {
            k=-k;
            for(j=1;j<=m;j++)
            {
                l++;
                sum=sum+l*k;
            }
        }
        printf("Case %d: %d\n",p,sum);
    }
    return 0;
}
