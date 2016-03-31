#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int n;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
            break;

        long long k=sqrt(n);
        if(k*k==n) printf("yes\n");
        else printf("no\n");

    }
    return 0;
}
