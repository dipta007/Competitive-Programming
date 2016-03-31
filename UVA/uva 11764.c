#include <stdio.h>

int main()
{
    int T,N,c,i,up,down,a[60];
    scanf("%d",&T);
    for(c=1;c<=T;c++)
    {
        up=0;
        down=0;
        scanf("%d",&N);
        for(i=0;i<N;i++)
            scanf("%d",&a[i]);
        for(i=0;i<N-1;i++)
        {
            if(a[i]<a[i+1])
                up++;
            else if(a[i]>a[i+1])
                down++;
        }
        printf("Case %d: %d %d\n",c,up,down);
    }
    return 0;
}
