#include <stdio.h>
#include <math.h>

int main()
{
    int T,p,n,s,i,j,l;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&n);
        if(n==0){
            printf("Case %d: 1\n",i);
            continue;
        }
        s=1;
        for(j=2;j<=n;j++)
        {
            s=s*j;
        }
        printf("Case %d: %d\n",i,s);
    }
}

