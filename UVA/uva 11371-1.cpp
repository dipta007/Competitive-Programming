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
    int j,l;
    char a[1000],b[1000];
    while(scanf("%s",a)!=EOF)
    {
        int sa=strlen(a);
        long long int ia=atoll(a);
        int zero=0;
        for(int i=0;i<sa-1;i++)
        {
            for(j=0;j<sa-i-1;j++)
            {
                if(a[j]<a[j+1])
                {
                    int temp;
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        for(int i=0;i<sa;i++)
        {
            if(a[i]=='0')
                zero++;
        }
        long long int iam=atoll(a);

        for(int i=0;i<sa-1;i++)
        {
            for(int j=0;j<sa-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    int temp;
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        for(j=0,l=zero;j<sa;j++)
        {
            if(j>=1 && j<=zero)
                b[j]='0';
            else
                b[j]=a[l++];
        }
        b[j]=0;
        ia=atoll(b);
        printf("%lld - %lld = %lld = 9 * %lld\n",iam,ia,iam-ia,(iam-ia)/9);
    }
}
