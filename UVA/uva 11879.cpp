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
    char a[10000];
    while(1)
    {
        scanf("%s",a);
        int sa=strlen(a);
        if(a[0]=='0' && sa==1)
            break;
        int sum=0;
        for(int i=0;i<sa;i++)
        {
            sum=(sum*10 + (a[i]-'0'))%17;
        }
        if(sum==0)
            printf("1\n");
        else
            printf("0\n");
    }
}
