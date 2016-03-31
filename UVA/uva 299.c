#include <stdio.h>

int main()
{
    int N,i,L,j,a[60],k,temp,count;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        count=0;
        scanf("%d",&L);
        for(j=0;j<L;j++)
            scanf("%d",&a[j]);
        for(k=1;k<=(L-1);k++)
        {
            for(j=0;j<L-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    count++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",count);

    }
    return 0;
}
