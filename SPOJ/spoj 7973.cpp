
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


unsigned long long int party(unsigned long long int x)
{
    unsigned long long int y=1;
    while(y<x)
    {
        y=y*2;
    }
    return y-x;
}

int main()
{

    unsigned long long int g,t,a,d;
    while(1)
    {
        scanf("%llu %llu %llu %llu",&g,&t,&a,&d);
        if(g==-1 && t==-1 && a==-1 && d==-1)
            break;
        unsigned long long int x1=0;
        unsigned long long int cf=t-1;
        x1=cf*(cf+1);
        x1=x1/2;
        x1=x1*g;
        unsigned long long int ks=g*a + d;
        unsigned long long int Y;

        Y=party(ks);
        ks=ks+Y;
        unsigned long long int k=ks;
        x1=x1+ks-1;
        printf("%llu*%llu/%llu+%llu=%llu+%llu\n",g,a,t,d,x1,Y);
    }
}

