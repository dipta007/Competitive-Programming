#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,count,c,i;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(a==0 && b==0)
            break;

        count=0;
        for(i=b;i>=a;i--)
        {
            c=sqrt(i);
            if(c*c==i)
            {
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
