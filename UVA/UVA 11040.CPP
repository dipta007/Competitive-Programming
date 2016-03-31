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
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int a[9][9];
        memset(a,0,sizeof(a));
        for(int r=0;r<9;r++)
        {
            for(int c=0;c<=r;c++)
            {
                if(r%2==0 && c%2==0)
                {
                    scanf("%d",&a[r][c]);
                }
            }
        }
        for(int r=0;r<9;r++)
        {
            for(int c=0;c<=r;c++)
            {
                if(r%2==0 && c%2!=0)
                {
                    int k=a[r][c-1]+a[r][c+1];
                }
            }
            cout <<endl;
        }
    }
}
