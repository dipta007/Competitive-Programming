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
    char a[1000],b[1000];
    char d[]="DONE";
    while(1)
    {
        gets(a);
        if(!strcmp(a,d))
            break;

        int sa=strlen(a);
        int l=0;
        for(int i=0;i<sa;i++)
        {
            if(a[i]>='a' && a[i]<='z')
                b[l++]=a[i];
            else if(a[i]>='A' && a[i]<='Z')
                b[l++]=a[i]+32;
        }
        b[l]=0;
        int sb=strlen(b);
        int pal=1;
        for(int j=0;j<sb/2;j++)
        {
            if(b[j]!=b[sb-j-1])
            {
                pal=0;
                break;
            }
        }
        if(pal==1)
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }
}
