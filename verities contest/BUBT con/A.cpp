#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
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
#include <math.h>

long long int m=33554431;

long long int power(int y)
{
    long long int s=1;
    for(int j=1;j<=y;j++)
    {
        s=(s%m*2%m)%m;
    }
    return s;
}


int main()
{
    int t;

    scanf("%d",&t);
    for(int C=1;C<=t;C++)
    {
        int n;
        scanf("%d",&n);
        long long int sum=0;
        for(int i=0;i<=n;i++)
        {
            sum=(sum%m + power(i)%m)%m;
        }
        printf("Case %d: %lld\n",C,sum);
    }
}

