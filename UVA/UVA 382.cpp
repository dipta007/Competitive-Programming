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
    int a[110],i;
    for(i=0;;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==0)
            break;
    }
    printf("PERFECTION OUTPUT\n");
    for(int j=0;j<i;j++)
    {
        int sum=0;
        for(int k=1;k<=a[j]/2;k++)
        {
            if(a[j]%k==0)
                sum=sum+k;
        }
        if(sum==a[j])
            printf("%5d  PERFECT\n",a[j]);
        else if(sum<a[j])
            printf("%5d  DEFICIENT\n",a[j]);
        else
            printf("%5d  ABUNDANT\n",a[j]);
    }
    printf("END OF OUTPUT\n");
}
