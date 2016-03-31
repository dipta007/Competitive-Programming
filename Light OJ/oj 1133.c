#include <stdio.h>

int main()
{
    int T,i,j,a[120],n,m;
    char b[10];
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d",&n,&m);
        for(j=0;j<n;j++)
            scanf("%d ",&a[j]);
        gets(b);
        printf("%c\n\n",b[2]);
        if(b[0] == 'S')
        {
            for(j=0;j<n;j++)
            {
                a[j]=a[j]+b[2];
                printf("%d ",a[j]);
            }
        }
    }
}
