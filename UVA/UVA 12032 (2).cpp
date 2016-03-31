//hoi nai :((


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
        vector <int> diff;
        int n;
        scanf("%d",&n);
        int a[n];
        for(int j=0;j<n;j++)
            scanf("%d",&a[j]);
        for(int j=1;j<n;j++)
        {
            int c;
            c=a[j]-a[j-1];
            diff.push_back(c);
        }
        sort(diff.begin(),diff.end());
        int sdiff=n-1;
        int maxx=diff[n-2];
        int cnt =0;
        for(int j=1,l=n-3;j<=maxx;j++,l--)
        {
            if(diff[l]==maxx)
                maxx++;
            else
            {
                cnt=1;
                break;
            }
        }
        if(cnt==1)
            printf("Case %d: %d\n",i,maxx);
        else
            printf("Case %d: %d\n",i,maxx+1);

    }
}
