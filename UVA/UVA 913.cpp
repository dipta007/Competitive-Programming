#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

int main()
{
    long long int n;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        long long int s=1;
        for(long long i=3;i<=n;i=i+2)
            s=s+i;
        s=s-3+1;
        s=(s*2)-1;
        long long int sum=0;
        for(long long j=1,l=s;j<=3;j++,l=l+2)
            sum=sum+l;
        printf("%lld\n",sum);
    }
}
