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
    char a[40];
    while(1)
    {
        scanf("%s",a);
        int sa=strlen(a);
        if(sa==1 && a[0]=='0')
            break;

        int sum=0;
        for(int i=sa-1,l=0;i>=0;i--,l++)
        {
            int p=pow(2,i+1);
            p=p-1;
            int k=a[l]-'0';
            int T=k*p;
            sum=sum+ T;
        }
        printf("%d\n",sum);
    }
}

