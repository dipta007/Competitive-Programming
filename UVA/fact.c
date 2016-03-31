#include<stdio.h>

int main()
{
    int a,b;
    scanf("%d",&a);
    b=1;
    int sum=1;
    while(a>=b)
    {
        sum=sum*b;
        b++;
    }
    printf("%d",sum);
    return 0;
}
