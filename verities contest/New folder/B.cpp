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
    char a[3020];
    while(scanf("%d",&n)!=EOF)
    {
        int L=0,R=0;
        scanf("%s",a);
        int mcnt=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='L')
            {
                a[i]='b';
                for(;a[i];i--)
                {
                    a[i]='b';
                }
            }
            else if(a[i]=='R')
            {
                a[i]='d';
                int j,c=0,flg=1;
                for(j=i+1;a[j]!='L';j++)
                {
                    c++;
                    if(j==n-1 && a[j]!='L')
                    {
                        flg=0;
                        break;
                    }
                }
                if(flg==0)
                {
                    for(j=i+1;a[j];j++)
                        a[j]='d';
                    break;
                }
                a[j]='b';
                c=c/2;
                j--;
                i++;
                for(int k=1;k<=c;k++,j--,i++)
                {
                    a[j]='b';
                    a[i]='d';
                }
                //for(int k=1;k<=c;k++)

            }
            else if(a[i]=='.')
            {

            }
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]=='.')
                mcnt++;
        }
        printf("%d\n",mcnt);

    }
}
