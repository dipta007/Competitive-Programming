#include<stdio.h>
int prime(int num,int i)
{
    if(i==1) return 1;
    else
    {
        if(num%i==0) return 0;
        else return prime(num,i-1);
    }
}
int main()
{
    int n,i,d;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            d=prime(i,i/2);
            }
        else continue;
        if(d==1) printf(" %d",i);
    }
}
