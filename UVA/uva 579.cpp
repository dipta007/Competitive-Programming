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
    double h,m;
    while(scanf("%lf:%lf",&h,&m)!=EOF)
    {
        if(h==0.0 && m==0.0)
            break;
        else if(h>=m/5)
        {
            double a=(12.0-h)*30.0;
            double b=m*6.0;
            double re=a+b-(0.5*m);

            double re1=abs(360-re);
            double refi=min(re,re1);
            printf("%.3lf\n",refi);
        }
        else if(h<=m/5)
        {
            double a=h*30.0;
            double b=(60.0-m)*6;
            double re=a+b+(0.5*m);

            double re1=abs(360-re);
            double refi=min(re,re1);
            printf("%.3lf\n",refi);
        }
    }
}
