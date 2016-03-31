#include <stdio.h>

int f91(int x);

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;

        printf("f91(%d) = %d\n",n,f91(n));
    }
    return 0;
}

int f91(int x)
{
    if(x<=100)
        return f91(f91(x+11));
    else if(x>=101)
        return x-10;
}
