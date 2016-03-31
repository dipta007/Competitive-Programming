#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int n;
    char a[100];
    while(scanf("%s",&a)!=EOF)
    {
        n=atoi(a);
        if(n==0)
            break;
        else if(n%11 ==0)
            printf("%s is a multiple of 11.\n",a);
        else
            printf("%s is not a multiple of 11.\n",a);
    }
    return 0;
}
