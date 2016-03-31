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
    char a[10000],b[10000];
    int s=1,d=1;
    while(gets(a))
    {
        int l=0;
        int sl=strlen(a);
        for(int i=0;i<sl;i++)
        {
            if(a[i]=='"' && d%2!=0)
            {
                b[l++]='`';
                b[l++]='`';
                d++;
            }
            else if(a[i]=='\'' && s%2!=0)
            {
                b[l++]='`';
                s++;
            }
            else if(a[i]=='"' && d%2==0)
            {
                b[l++]='\'';
                b[l++]='\'';
                d++;
            }
            else if(a[i]=='\'' && s%2==0)
            {
                b[l++]='\'';
                s++;
            }
            else
                b[l++]=a[i];
        }
        b[l]=0;
        puts(b);
    }
}
