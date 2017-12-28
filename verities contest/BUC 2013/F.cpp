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
    for(int C=1;C<=t;C++)
    {
        int n,yw;
        scanf("%d %d",&n,&yw);
        int rx[n],ry[n],r[n];
        for(int i=0;i<n;i++)
            scanf("%d %d %d",&rx[i],&ry[i],&r[i]);

        for(int we=0;we<yw;we++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(we==0)
                printf("Case %d:\n",C);
            for(int i=0;i<n;i++)
            {
                float k;
                k=(float)(x-rx[i])*(x-rx[i])+(y-ry[i])*(y-ry[i]);
                k=(float)sqrt(k);
                k=(float)r[i]-k;
                if(k>=0.0){
                    printf("Yes\n");
                    break;
                }
                else{
                    printf("No\n");
                    break;
                }
            }
        }

    }
}
