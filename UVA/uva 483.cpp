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
    int s;
    char a[10000],b[10000];
    while(gets(a))
    {
        s=strlen(a);
        int l=0;
        for(int i=0;i<s;i++)
        {
            if(i==s-1)
            {
                int k=i;
                for(l=l;k>=0 && a[l]!=' ';l++,k--)
                {
                    b[l]=a[k];
                }

            }
            else if(a[i]==' ')
            {
                int k=i-1;
                for(l=l;l>=0 && a[l]!=' ';l++,k--)
                {
                    b[l]=a[k];
                }
                b[l++]=' ';
            }
        }
        b[s]=0;
        cout << b << endl;
    }
}

