#include<stdio.h>

int main()
{
    int cases, caseno, a, b, c, d,o;

    scanf("%d", &cases);
    for(caseno = 1; caseno <= cases; caseno++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        printf("Case %d: ", caseno);
        if(a<=(b+c+d))
            o=1;
        else
        {
            o=0;
            printf("Not Okay\n");
            continue;
        }

        if(b<=(a+c+d))
            o=1;
        else
            {
            o=0;
            printf("Not Okay\n");
            continue;
        }

        if(c<=(a+b+d))
            o=1;
        else
            {
            o=0;
            printf("Not Okay\n");
            continue;
        }

        if(d<=(a+b+c))
            o=1;
        else
        {
            o=0;
            printf("Not Okay\n");
            continue;
        }

        if(o==1)
            printf("Okay\n");

    }

    return 0;
}
