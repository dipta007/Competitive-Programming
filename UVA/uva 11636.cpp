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
    int n,i,cnt=1;
    while(1)
    {
        scanf("%d",&n);
        if(n<0)
            break;

        int sum=1;
        int l=1;
        for(i=1;l<n;i++)
        {
            sum=sum+l;
            l=sum;
        }
        printf("Case %d: %d\n",cnt++,i-1);
    }
}

