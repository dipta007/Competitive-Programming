#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

bool p[10010];

void sieve()
{
    int n=10004;
    memset(p,0,sizeof(p));
    for(int i=3;i*i<=n;i=i+2)
    {
        if(p[i]==0)
        {
            for(int j=i*i;j<=n;j=j+i+i)
            {
                p[j]=1;
            }
        }
    }
}

bool isprime(int n)
{
    if(n<2) return 1;
    if(n==2) return 0;
    if(n%2==0) return 1;
    return p[n];
}

int main()
{
    int n;
    sieve();
    while(scanf("%d",&n)!=EOF)
    {
        int cnt=0,flg=1;
        int y=n;
        for(int i=2;i*i<=y;)
        {
            if(!isprime(i))
            {
                if(n%i==0)
                {
                    if(cnt==0 && flg==0)
                        printf(" * ");
                    n=n/i;
                    cnt++;
                }
                else
                {
                    printf("%d^%d",i,cnt);
                    i++;
                    cnt=0;
                    if(flg==1)
                        flg=0;
                }
            }
            else
                i++;
        }
        printf("\n");
    }
}

