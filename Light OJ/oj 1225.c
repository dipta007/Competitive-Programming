#include <stdio.h>

int main()
{
    int T,i,n,rev,j,a;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&n);
        a=n;
        for(rev=0;n!=0;j++)
        {
            rev=rev*10+n%10;
            n=n/10;
        }
        if(rev==a)
            printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n",i);
    }
    return 0;
}
