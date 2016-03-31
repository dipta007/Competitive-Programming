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
    char a[30000];
    while(1)
    {
        scanf("%s",a);
        int sa=strlen(a);
        if(a[0]=='0' && sa==1)
            break;
        int sum1=0,sum2=0;
        for(int i=0;i<sa;i++)
        {
            if(i%2==0)
                sum1=sum1+ (a[i]-48);
            else
                sum2=sum2+ (a[i]-48);
        }
        if(sum1%11==sum2%11)
            printf("%s is a multiple of 11.\n",a);
        else
            printf("%s is not a multiple of 11.\n",a);
    }
}
