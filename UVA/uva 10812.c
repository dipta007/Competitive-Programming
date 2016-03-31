#include <stdio.h>

int main()
{
    int n,s,d,i,x,y,temp;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&s,&d);
        x=(s+d)/2;
        y=((s-d)/2);

        if(y>x)
        {
            temp=x;
            x=y;
            y=temp;
        }

        if((s+d)%2!=0 && (s-d)%2!=0)
            printf("impossible\n");
        else if(x<0 || y<0)
            printf("impossible\n");
        else if(x>=0 && y>=0)
            printf("%d %d\n",x,y);
    }
    return 0;
}
