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
    while(scanf("%d",&n)!=EOF)
    {
        stack <int> s;
        for(int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            s.push(k);
        }

        int p[n];
        memset(p,0,sizeof(p));
        int k,l;
        for(int i=0;i<n-1;i++)
        {

            k=s.top();
            s.pop();
            l=s.top();
            int a=abs(k-l);

            p[a]++;
        }

        int flg=1;
        for(int i=1;i<n;i++)
        {
            if(p[i]==0)
            {
                flg=0;
                break;
            }
        }
        if(flg==1)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
}
