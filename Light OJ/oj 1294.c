#include <stdio.h>

int main()
{
    int T,l,c=1,i,n,m,sum,a,j;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d",&n,&m);
        sum=0;
        a=1;
        l=1;
        while(a<=(n/m))
        {
            if(a%2 != 0)
            {
                for(l=l,j=1;j<=m;l++,j++)
                    sum=sum-l;
                a++;
            }
            else if(a%2 == 0)
            {
                for(l=l,j=1;j<=m;l++,j++)
                    sum=sum+l;
                a++;
            }
        }
        printf("Case %d: %d\n",c++,sum);
    }
}
