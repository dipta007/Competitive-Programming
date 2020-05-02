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
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            sum=sum+k;
        }
        int l=(n*(n+1))/2;
        if(sum==l)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
