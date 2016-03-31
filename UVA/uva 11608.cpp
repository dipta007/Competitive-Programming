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
    int a[20],b[20];
    int cnt=1;
    while(1)
    {
        scanf("%d",&a[0]);
        if(a[0]<0)
            break;
        for(int i=1;i<=12;i++)
        {
            scanf("%d",&a[i]);

        }
        for(int j=0;j<12;j++)
        {
            if(j>0)
                a[j]=a[j]+a[j-1];
            scanf("%d",&b[j]);
            if(j==0)
                printf("Case %d:\n",cnt++);
            if(b[j]<=a[j])
            {
                printf("No problem! :D\n");
                a[j]=a[j]-b[j];
            }
            else
                printf("No problem. :(\n");
        }

    }
}
