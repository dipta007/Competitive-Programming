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
    char a[100],o[100];
    while(scanf("%s",a)!=EOF)
    {
        int l=0;
        int k=strlen(a);
        for(int i=0;i<k;i++)
        {
            if(a[i]=='B' || a[i]=='F' || a[i]=='P' || a[i]=='V')
                a[i]='1';
            else if(a[i]=='G' || a[i]=='C' || a[i]=='J' || a[i]=='K' || a[i]=='Q' || a[i]=='S' || a[i]=='X' || a[i]=='Z')
                a[i]='2';
            else if(a[i]=='D' || a[i]=='T')
                a[i]='3';
            else if(a[i]=='L')
                a[i]='4';
            else if(a[i]=='M' || a[i]=='N')
                a[i]='5';
            else if(a[i]=='R')
                a[i]='6';
            else
                a[i]='7';
        }
        for(int i=0;i<k;i++)
        {
            if(i!=0 && a[i]==a[i-1])
                continue;
            else if(a[i]=='7')
                continue;
            else
                o[l++]=a[i];
        }
        o[l]=NULL;
        cout << o << endl;
    }
}
