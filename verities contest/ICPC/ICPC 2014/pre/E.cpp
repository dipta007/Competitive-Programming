#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T,i,m,j,k,l,p,a[10000],z,x;
    scanf("%d", &T);
    for(i=1;i<=T;i++)
    {
        int cnt=0,x=0;
        scanf("%d", &m);
        k=sqrt(m);
        printf("Case %d: ",i);
        for(j=k+1;j<m;j++)
        {
            l=(j*j)%m;
            if(l==j)
            {
                a[x]=l;
                x++;
                cnt++;
            }
        }
        if(cnt>0)
        {
            for(z=0;z<x;z++)
            {
                if(z==(x-1))
                    printf("%d",a[z]);
                else
                    printf("%d ",a[z]);
            }
        }
        else if(cnt==0)
            printf("no solution");
        printf("\n");
    }
    return 0;
}


