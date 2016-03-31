#include <stdio.h>

int main()
{
    int n,c,count=1,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<0)
            break;
        c=1;
        for(i=1,j=1;i<=c*2;i++)
        {
            if(i==c*2 && n>c*2)
            {
                c=c*2;
                j++;
            }
        }
        printf("Case %d: %d\n",count++,j);
    }

    return 0;
}
