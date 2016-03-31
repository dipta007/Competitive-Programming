#include <stdio.h>

int main()
{
    int T,n,c,count=1;
    scanf("%d",&T);
    if(T>25)
        return 0;
    while(scanf("%d",&n) !=EOF)
    {
        if(n>=0 && n<=20)
        {
            if(n<=10)
            {
                c=n-1;
                printf("1 %d\n",c);
            }
            else if(n>10)
            {
                c=n-10;
                printf("10 %d\n",c);
            }

            count++;
            if(count>T)
                break;
        }
    }
    return 0;
}
