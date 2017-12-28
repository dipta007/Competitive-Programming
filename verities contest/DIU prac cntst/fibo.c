#include <stdio.h>

int func(int n)
{
    if(n==1 || n==0 || n<0)
        return 1;
    //if(n==0) return 0;
    printf("->%d\n\n",n);
    int k= func(n-7)+func(n-14);
    printf("%d\n\n",n);
    return k;
}

int main()
{
    int k;
    scanf("%d",&k);
    printf("**%d**\n",func(k));
}
