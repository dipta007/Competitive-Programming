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
        int a[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int cnt=0;
        for(int i=0;i<n;i++)
            cout << a[i] <<endl;
        for(int i=1;i<n-1;i++)
        {
                int j=i+1;
                while(a[j]<a[i]+a[i-1])
                    j++;
                if(a[j]==a[i]+a[i-1])
                    cnt++;
        }
        printf("%d\n",cnt);
    }
}
