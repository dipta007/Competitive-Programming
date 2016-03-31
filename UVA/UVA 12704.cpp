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
        double x,y,r;
        scanf("%lf %lf %lf",&x,&y,&r);
        double re=sqrt(x*x+y*y);
        printf("%.2lf %.2lf\n",r-re,r+re);
    }
}
