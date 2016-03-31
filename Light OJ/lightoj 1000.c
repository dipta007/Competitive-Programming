#include <stdio.h>

int main()
{
    int T,a,b,c,count=1;
    scanf("%d",&T);
    if(T>125)
        return 0;
    while(scanf("%d %d",&a,&b) !=EOF)
    {
        if(a>=0 && b>=0 && a<=10 && b<=10)
        {
            c=a+b;
            printf("Case %d: %d\n",count,c);

            count++;
            if(count>T)
                break;
        }
    }
    return 0;
}
