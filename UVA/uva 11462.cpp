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

    while(1)
    {
        scanf("%d",&n);
        vector <int > v;
        if(n==0)
            break;

        for(int i=1;i<=n;i++)
        {
            int k;
            scanf("%d",&k);
            v.push_back(k);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            if(i==n-1)
                printf("%d\n",v[i]);
            else
                printf("%d ",v[i]);
        }
    }
}
