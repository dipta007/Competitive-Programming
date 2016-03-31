#include <stdio.h>

int main()
{
    int T,i,a,m=2,flag,count;
    scanf("%d",&T);
    for(count=1;count<=T;count++)
    {
        scanf("%d",&a);
        flag=0;
        for(i=m;i<=a/2;i=i+2)
        {
            if(a%i==0)
            {
                flag=1;
                m=m+2;
                printf("Case %d: %d %d\n",count,(a/i),i);
                break;

            }
        }
        if(flag==0)
            printf("Case %d: Impossible\n",count);
    }
    return 0;
}
