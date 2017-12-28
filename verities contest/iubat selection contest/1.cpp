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

int p[1010];
int main()
{
    int n;

    while(scanf("%d",&n)!=EOF){
            vector <int> a;
            memset(p,0,sizeof(p));
    for(int i=1;i<=n;i++)
    {
        int c;
        scanf("%d",&c);
        p[c]++;
        a.push_back(c);
    }
    sort(a.begin(),a.end());
    int x=n;
    for(int j=0;j<n-1;j++)
    {
        if(a[j+1]==a[j])
            x--;
    }
    int max=0;
    for(int i=0;i<1002;i++)
    {
        if(p[i]>=max)
            max=p[i];
    }
    printf("%d %d\n",max,x);
    }
}
