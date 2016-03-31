#include <stdio.h>

int main()
{
    int n,i,j,temp;
    char a[2000000];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n-1;i++)
            for(j=0;j<n-i-1;j++)
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
        for(i=0;i<n;i++)
            printf("%d ",a[i]);

        printf("\n");
    }
    return 0;
}
