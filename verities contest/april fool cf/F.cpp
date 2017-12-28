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
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n/10==0)
            printf("%d\n",n/2);
        else
        {
            int a,b;
            b=n%10;
            n=n/10;
            a=n%10;
            if(a>b)
                printf("%d\n",a+b);
            else
                printf("%d\n",b-a);
        }
    }
}
