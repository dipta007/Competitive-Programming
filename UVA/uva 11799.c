#include <stdio.h>

int main()
{
    int T,i,N,j,a[10020],max;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&N);

        max=0;
        for(j=0;j<N;j++)
        {
            scanf("%d",&a[j]);
            if(a[j]>max)
                max=a[j];
        }
        printf("Case %d: %d\n",i,max);
    }
    return 0;
}
