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
    int b,p,m;
    while(scanf("%d %d %d",&b,&p,&m)!=EOF)
    {
        long long int s=1;
        for(int i=1;i<=p;i++)
        {
            s=(s%m)*(b%m);
            s=s%m;
        }
        if(b==0)
            s=0;
        printf("%lld\n",s);
    }
}
