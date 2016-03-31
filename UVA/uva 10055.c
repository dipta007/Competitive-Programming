#include <stdio.h>
int main()
{
    long long int a,b,c;
    while(scanf("%lld %lld",&a,&b)!=EOF)
    {
        if(a > b)
        {
            c = a - b;
            printf("%lld\n",c);
        }
        else
        {
            c = b - a;
            printf("%lld\n",c);
        }
    }
    return 0;
}

