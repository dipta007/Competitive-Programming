#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,a,b,i,c,d;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(a==-1 && b==-1)
            break;
        c=abs(b-a);
        if(a<b)
            d=(a+100)-b;
        else
            d=(b+100)-a;

        if(d>=c)
            printf("%d\n",abs(c));
        else
            printf("%d\n",abs(d));
    }
    return 0;
}
