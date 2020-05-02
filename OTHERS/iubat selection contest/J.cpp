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

int ab[32];

void pow()
{
    for(int i=0;i<32;i++)
        ab[i]=pow(2,(i+1));
}

int part(int y,int z)
{
    int c=ab[y];
    for(;c!=0;)
    {
        if(c==z)
        {
            return y;
        }
        c=c/10;
    }
    return -1;
}

int main()
{
    int n,x;
    pow();
    while(scanf("%d",&n)!=EOF)
    {
        int cnt=0;
        for(int j=0;j<32;j++)
        {
            x=part(j,n);
            if(x!=-1)
                cnt++;
            if(cnt==2)
                break;
        }
        if(x==-1)
        {
            printf("no power of 2\n");
        }
        else
            printf("%d\n",x+1);
    }
}
