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
    int n,q;
    scanf("%d %d",&n,&q);
    int a[n];
    int p[65544];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    for(int i=0;i<q;i++)
    {
        int qq;
        scanf("%d",&qq);
        if(qq==1)
        {
            memset(p,0,sizeof(p));
            int l,r;
            scanf("%d %d",&l,&r);
            int min=a[l];
            for(int i=l-1;i<r;i++)
            {
                if(a[i]<min)
                    min=a[i];
                p[a[i]]++;
            }
            printf("%d %d\n",min,p[min]);
        }
        else if(qq==2)
        {
            int l,r,k;
            scanf("%d %d %d",&l,&r,&k);
            for(int i=l-1;i<r;i++)
            {
                a[i]=a[i]^k;
            }
        }
    }
}
