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

char a[104][104];
char s[200];

void sum(int x,int y)
{
    int sx=strlen(a[x]);
    int sy=strlen(a[y]);
    int k=0;
    int carry=0;
    for(int i=sx-1,j=sy-1;i>=0 && j>=0;i++,k++)
    {
        s[k]=(a[x][i]+a[y][j]+carry)%18;
        carry=(a[x][i]+a[y][j]+carry)/18;
    }
}

int main()
{
    int l=0;
    while(1)
    {
        scanf("%s",a[l++]);
        if(a[l-1][0]=='0' && strlen(a[l-1])==1)
        {
            for(int i=1;i<l-1;i++)
            {
                sum(i,i-1)
            }
        }
    }
}
