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
    char a[1000];
    while(gets(a))
    {
        int l=0;
        int s=strlen(a);
        for(int i=0;i<s;i++)
        {
            if((a[i]>=1 && a[i]<=64) || (a[i]>=91 && a[i]<=96) || (a[i]>=123 && a[i]<127))
            {
                for(int j=i-1;((a[j]>='A' && a[j]<='Z') || (a[j]>='a' && a[j]<='z'))&& j!=-1;j--)
                {
                    if((a[j]>='A' && a[j]<='Z') || (a[j]>='a' && a[j]<='z'))
                    {
                        l++;
                        break;
                    }
                }
            }
            else if(i==s-1)
            {
                for(int j=i;((a[j]>='A' && a[j]<='Z') || (a[j]>='a' && a[j]<='z'))&& j!=-1;j--)
                {
                    if((a[j]>='A' && a[j]<='Z') || (a[j]>='a' && a[j]<='z'))
                    {
                        l++;
                        break;
                    }
                }
            }

        }
        if(s>0)
        printf("%d\n",l);
    }
}
