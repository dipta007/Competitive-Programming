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
    while(gets(a))
    {
        int s=strlen(a);
        for(int i=0;i<s;i++)
        {
            b[i]=a[i]-7;
        }
        b[s]=0;
        puts(b);
    }
}
