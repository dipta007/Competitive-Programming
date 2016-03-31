#include <stdio.h>

int main()
{
    int T,n,p,count,i,a,j;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&n);
        p=1;
        count=0;
        for(j=0;n!=0;j++)
        {
            a=n%2;
            if(a==1)
                count++;
            n=n/2;
        }
        if(count%2==0)
            printf("Case %d: even\n",i);
        else
            printf("Case %d: odd\n",i);
    }
    return 0;
}
