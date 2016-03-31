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
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        vector <int> v;
        int n;
        scanf("%d",&n);
        int sum=0;
        for(int j=0;j<n;j++)
        {
            int k;
            scanf("%d",&k);
            v.push_back(k);
            sum=sum+k;
        }
        float ss=(float)sum/n;
        int s=ceil(ss);
        sort(v.begin(),v.end());
        int fsum=abs(s-v[0]);
        for(int j=1;j<n;j++)
        {
            fsum =fsum + abs(v[j]-v[j-1]);
        }
        fsum=fsum+ abs(v[n-1]-s);

        printf("%d\n",fsum);
    }
}
