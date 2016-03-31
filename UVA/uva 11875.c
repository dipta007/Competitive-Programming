#include <stdio.h>

int main()
{
    int T,i,N,j,b,a[14];
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&N);
        for(j=0;j<N;j++)
            scanf("%d",&a[j]);
        b=N/2;
        printf("Case %d: %d\n",i,a[b]);
    }
    return 0;
}
