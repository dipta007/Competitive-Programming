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
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        vector < long long int > v;
        for(int j=0;j<4;j++)
        {
            long long int k;
            scanf("%lld",&k);
            v.push_back(k);
        }
        sort(v.begin(),v.end());
        if(v[0]==v[1] && v[1]==v[2] && v[2]==v[3])
            printf("square\n");
        else if(v[0]==v[1] && v[2]==v[3])
            printf("rectangle\n");
        else if((v[0]+v[1]+v[2])>=v[3])
            printf("quadrangle\n");
        else
            printf("banana\n");
    }
}
