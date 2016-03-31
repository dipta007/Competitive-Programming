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
    int t,cnt=0;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        double l,w,d,wei;
        scanf("%lf %lf %lf %lf",&l,&w,&d,&wei);
        if(l<=56.0 && w<=45.0 && d<=25.0 && wei<=7.0)
        {
            printf("1\n");
            cnt++;
        }
        else if((l+w+d)<=125.0 && wei<=7.0)
        {
            printf("1\n");
            cnt++;
        }
        else
            printf("0\n");
    }
    cout <<cnt<<endl;
}
