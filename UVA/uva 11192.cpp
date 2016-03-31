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
    while(1)
    {
        int g;
        char a[102];
        scanf("%d",&g);
        if(g==0)
            break;
        scanf("%s",a);
        int s=strlen(a);
        int k=s/g;
        for(int i=0;i<s;i=i+k)
        {
            for(int j=i,l=i+k-1,m=0;m<k/2;m++,j++,l--)
            {
                char temp;
                temp=a[l];
                a[l]=a[j];
                a[j]=temp;
            }
        }
        printf("%s\n",a);
    }
}
