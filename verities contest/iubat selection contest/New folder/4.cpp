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

int min(int a,int b)
{
    if(a<b)
        return a;
    else if(b<a)
        return b;
    if(a==b)
        return 0;
}

int main()
{
    int cnt=1;
    while(1)
    {
        int c,X,Y,Z, x[50],y[50],z[50],x1[50],y1[50],z1[50],a,b,ca;
        scanf("%d%d%d%d", &c,&X,&Y,&Z);
        if(c==0 && X==0 && Y==0 && Z==0)
            break;
        int i;
        for(i=0;i<c;i++)
        {
            scanf("%d%d%d", &x[i], &y[i], &z[i]);
            x1[i]=X-x[i];
            y1[i]=Y-y[i];
            z1[i]=Z-z[i];
        }
        for(i=1;i<c;i++)
        {
            a=min(x1[i],x1[i-1]);
            b=min(y1[i],y1[i-1]);
            ca=min(z1[i],z1[i-1]);
        }
        int r;
        r=a*c+b*c+ca*c;
        cout<< cnt<<". "<<r<< endl;
        cnt++;
    }
    return 0;
}
