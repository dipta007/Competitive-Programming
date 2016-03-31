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

    char c;

    int k,l;
    while((c=getchar())!=EOF)
    {
        int n=0;
        int max=0;
        stack < int > s;
        do{
            if(c==' ')
                continue;
            else if(c=='-')
            {
                int d;
                scanf("%d",&d);
                d=-d;
                s.push(d);
                n++;
                if(d>max)
                    max=d;
                continue;
            }
            s.push(c-48);
            if(c-48>max)
                max=c-48;
            n++;
        }while((c=getchar())!='\n');

        bool p[n];
        memset(p,0,sizeof(p));
        int u=n;
        u--;
        while(u--)
        {
            k=s.top();
            s.pop();
            l=s.top();
            int a=abs(k-l);

            p[a]++;
        }
        int flg=1;
        for(int i=1;i<max;i++)
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
            printf("Not Jolly\n");
    }


}
