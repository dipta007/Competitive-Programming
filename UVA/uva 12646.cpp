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
    int a,b,c;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        if(a==b && b==c)
            printf("*\n");
        else if(a==b && b!=c)
            printf("C\n");
        else if(a==c && b!=c)
            printf("B\n");
        else if(b==c && b!=a)
            printf("A\n");

    }
}
