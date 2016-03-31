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

int fibo(int n);

int main()
{
    long long int n,sum;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)
            break;
        else if(n==1)
            sum= 1;
        else if(n==2)
            sum= 2;
        else
        {
            long long int n1=1,n2=2;
            for(long long int i=1;i<=n-2;i++)
            {
                sum=n1+n2;
                n1=n2;
                n2=sum;
            }
        }
        printf("%lld\n",sum);
    }
}
