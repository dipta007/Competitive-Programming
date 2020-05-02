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
    int c=1;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        char a[n+1];
        int i;
        for(i=0;i<n;i++)
        {
            getchar();
            scanf("%c",&a[i]);

        }
        a[i]='\0';
        int l=0;
        int lo=0;
        for(i=0;i<n;i++)
        {
            if(a[i]!='W')
            {
                l++;
                lo++;
            }
            else if(a[i]=='W')
            {
                l=0;
            }
            if(l==3)
                break;
        }
        if(l==3)
            printf("Case %d: %d\n",c,i+1);
        else
            printf("Case %d: Yay! Mighty Rafa persists!\n",c);

        c++;
    }
}
