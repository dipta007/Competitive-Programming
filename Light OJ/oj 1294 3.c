#include <stdio.h>

int main()
{
    long long int T,i,res,n,m,f;
    scanf("%lld",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lld %lld",&n,&m);
        res=n*m;
        f=res/2;
        printf("Case %lld: %lld\n",i,f);
    }
    return 0;
}
