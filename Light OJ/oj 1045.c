#include <stdio.h>
int fact(long long int n);

int main()
{
    long long int T,i,n,x,p,sum,y,j,base;
    scanf("%lld",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lld %lld",&n,&base);
        x=fact(n);
        sum=0;
        p=1;
        for(j=1;x!=0;j++)
        {
            y=x%base;
            x=x/base;
            sum=sum+(x*p);
            p=p*10;
        }
        printf("Case %lld: %lld\n",i,sum);
    }


}

int fact(long long int n)
{
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}
