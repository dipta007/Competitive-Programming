#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int t;
    int m=1000000007;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector < int > a;
        int l=0;
        for(int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            a.push_back(k);
            l=(l%m+k%m)%m;
        }
        int b=0;
        for(int i=0;i<n;i++)
        {
            if(i==n-1)
            {
                l=(l%m+(a[0]^a[i])%m)%m;
            }
            else
            {
                l=(l%m+(a[i]^a[i+1])%m)%m;

            }
            if(i==0)
                b=a[i];
            else
                b=(b^a[i])%m;
        }
        l=(l%m+b%m)%m;
        printf("%d\n",l);
    }
    return 0;
}
