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
int GCD(int i,int j);
int main()
{
    int N;
    while(1)
    {
        scanf("%d",&N);
        if(N==0)
            break;

        int G=0;
        for(int i=1;i<N;i++)
            for(int j=i+1;j<=N;j++)
            {
                G+=GCD(i,j);
            }
        printf("%d\n",G);
    }
}

int GCD(int i,int j)
{
    for(int a=1;i!=0;a++)
    {
        int r;
        r=j%i;
        j=i;
        i=r;
    }
    return j;
}
