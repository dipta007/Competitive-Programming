#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int T,i,m,j,k,l,p;
    scanf("%d", &T);
    for(i=1;i<=T;i++)
    {
        int cnt=0;
        scanf("%d", &m);
        k=sqrt(m);
        printf("Case %d:",i);
        for(j=k+1;j<m;j++)
        {
            l=(j*j)%m;
            if(l==j)
            {
                printf(" %d", l);
                cnt=1;
            }
        }
        if(cnt==0)
            printf(" no solution");
        printf("\n");
    }
    return 0;
}

