#include <stdio.h>

int main()
{
    int T,x,y,z,count=1;
    scanf("%d",&T);
    if(T>19)
        return 0;
    while(scanf("%d %d %d",&x,&y,&z) !=EOF)
    {
        if((x>=1000 && x<=10000) && (y>=1000 && y<=10000) && (z>=1000 && z<=10000))
        {
            if(x>=y && y>=z)
                printf("Case %d: %d\n",count,y);
            else if(x>=z && z>=y)
                printf("Case %d: %d\n",count,z);
            else if(y>=x && x>=z)
                printf("Case %d: %d\n",count,x);
            else if(y>=z && z>=x)
                printf("Case %d: %d\n",count,z);
            else if(z>=x && x>=y)
                printf("Case %d: %d\n",count,x);
            else if(z>=y && y>=x)
                printf("Case %d: %d\n",count,y);
            count++;
            if(count>T)
                return 0;
        }
    }
    return 0;
}
