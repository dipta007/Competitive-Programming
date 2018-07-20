#include <stdio.h>

int main()
{
    long long int T,i,n,j,a[10020];
    scanf("%lld",&T);
    for(i=1;i<=T;i++)
    {
        for(j=0;j<6;j++)
            scanf("%lld",&a[j]);
        scanf("%lld",&n);
        for(j=6;j<=n;j++)
            a[j]=(a[j-1]%10000007+a[j-2]%10000007+a[j-3]%10000007+a[j-4]%10000007+a[j-5]%10000007+a[j-6]%10000007)%10000007;
        if(n==0)
            printf("Case %lld: %lld\n",i,a[n]%10000007);
        else
            printf("Case %lld: %lld\n",i,a[n]);
    }
}
