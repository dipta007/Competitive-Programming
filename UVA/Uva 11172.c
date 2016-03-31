#include <stdio.h>

int main()
{
    int t,a,b,count=1;
    scanf("%d",&t);
    if(t >= 15)
        return 0;
    while(scanf("%d %d",&a,&b) !=EOF)
    {
        if(a>-1000000001 && a<1000000001 && b>-1000000001 && b<1000000001)
        {
            if(a>b)
                printf(">\n");
            else if(a<b)
                printf("<\n");
            else if(a==b)
                printf("=\n");

            count++;
            if(count > t)
                break;
        }
    }
    return 0;
}
