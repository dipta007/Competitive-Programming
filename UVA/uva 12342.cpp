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
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        double sum=0.0,k,re;
        scanf("%lf",&k);

        if(k>1180000)
        {
            re=k-1180000;
            sum=sum+((re*25.0)/100.0);
            k=1180000;
        }
        if(k>880000)
        {
            re=k-880000;
            sum=sum+((re*20.0)/100.0);
            k=880000;
        }
        if(k>480000)
        {
            re=k-480000;
            sum=sum+((re*15.0)/100.0);
            k=480000;
        }
        if(k>180000)
        {
            re=k-180000;
            sum=sum+((re*10.0)/100.0);
            k=180000;
        }

        int res=ceil(sum);
        if(res>0 && res<2000)
            res=2000;
        printf("Case %d: %d\n",i,res);
    }
}
