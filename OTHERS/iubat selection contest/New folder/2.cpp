
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
    while((scanf("%d", &n))!= EOF)
    {
        int a[10]={0,0,0,0,0,0,0,0,0,0},j,k,i,d=0;
        char b[16];
        for(j=0,k=0;j<16;j++,k++)
        {
            cin>> b[j];
            k=b[j]-48;
            a[k]++;
        }
        for(j=1;j<10;j++)
        {
            if(a[j]>2*n)
            {
                d++;
                break;
            }
        }
        if(d==1)
            cout<< "NO"<<endl;
        else
            cout<< "YES"<<endl;

    }
    return 0;
}
