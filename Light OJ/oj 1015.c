#include <stdio.h>

int main()
{
    int T,i,N,a[1200],sum,b=1;
    scanf("%d",&T);
    while(scanf("%d",&N)!=EOF)
    {
        sum=0;
        for(i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<0)
                continue;
            else
                sum=sum+a[i];
        }
        printf("Case %d: %d\n",b++,sum);
    }
    return 0;
}
