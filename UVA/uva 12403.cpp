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
    char d[]="donate";
    char r[]="report";
    int T;
    scanf("%d ",&T);
    int sum=0;
    for(int i=1;i<=T;i++)
    {
        char a[7];
        scanf("%s",a);
        if(!strcmp(a,d))
        {
            int k;
            scanf("%d",&k);
            sum=sum+k;
        }
        else
        {
            printf("%d\n",sum);
        }
    }
}
