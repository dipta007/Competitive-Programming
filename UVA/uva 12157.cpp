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
    int T,n;
    scanf("%d",&T);
        for(int i=1;i<=T;i++)
        {
            scanf("%d",&n);
            int summ=0,sumj=0,a;
            for(int j=0;j<n;j++)
            {
                scanf("%d",&a);
                float m=a/30.0;
                int mr=ceil(m);
                if(a%30==0)
                    mr++;
                summ=summ+mr*10;
                float ju=a/60.0;
                int jr=ceil(ju);
                if(a%60==0)
                    jr++;
                sumj=sumj+jr*15;
            }
            printf("Case %d: ",i);
            if(summ<sumj)
                printf("Mile %d\n",summ);
            else if(sumj<summ)
                printf("Juice %d\n",sumj);
            else
                printf("Mile Juice %d\n",summ);
        }
}
