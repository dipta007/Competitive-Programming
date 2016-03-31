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
        if(n==0)
            break;
        vector <int> a;
        a.push_back(0);
        for(int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            a.push_back(k);
        }
        sort(a.begin(),a.end());
        int c=1;
        for(int i=1;i<n+1;i++)
        {
            int k;
            k=a[i]-a[i-1];
            if(k>200)
            {
                c=0;
                break;
            }
        }
        if((1422-a[n])>100)
            c=0;
        if(c==1)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }
}
