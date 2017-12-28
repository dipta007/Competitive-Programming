#include <stdio.h>
#include <math.h>

int main()
{
    long long int T,p,n,s,i,j,l;
    for(l=1;l<=32;l++)
    {
        p=p*2;
    }
    scanf("%lld",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lld",&n);
        if(n==0){
            printf("Case %lld: 1\n",i);
            continue;
        }
        s=1;
        for(j=2;j<=n;j++)
        {
            s=(s%p)*(j%p);
        }
        printf("Case %lld: %lld\n",i,s);
    }
}
