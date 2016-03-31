#include <stdio.h>

int main()
{
    long long int T,sum,fsum,p,c,d,i,k,l,j,n,m;
    scanf("%lld",&T);
    for(i=1;i<=T;i++)
    {
        sum=0;
        fsum=0;
        p=-1;
        scanf("%lld %lld",&n,&m);
        for(j=1;j<=m;j++)
            sum=sum+j;
        c=n/m;
        d=m*m;
        printf("%lld\n\n",d);
        for(k=sum,l=1;l<=c;l++,k=k+d)
        {
            fsum=fsum+(k*p);
            p=(-1)*p;


        }
        printf("Case %lld: %lld\n",i,fsum);
    }
    return 0;
}
