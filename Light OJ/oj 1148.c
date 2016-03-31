#include <stdio.h>

int main()
{
    int T,i,j,a[56],k,N,sum;
    char c[1000001];
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        for(k=0;k<1000001;k++)
            c[k]=1;
        scanf("%d",&N);
        sum=0;
        for(j=0;j<N;j++)
            scanf("%d",&a[j]);
        for(j=0;j<N;j++)
        {
//            if(c[a[j]]%2!=0)
//            {
//                sum=a[j]+1+sum;
//            }
            c[a[j]]++;

        }

        for(k=1;k<1000001;k++)
        {
            if(k=1)
            {
                if(c[k]<=2)
                    sum=sum+1+k;
                else
                {

                }
            }
        }

        printf("Case %d: %d\n",i,sum);
    }
    return 0;
}
