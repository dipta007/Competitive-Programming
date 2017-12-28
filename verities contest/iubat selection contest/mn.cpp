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
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        int cnt=0;
        int y=0;
        int c=0;
        while(a){
        int d=a%10;
        c=c+d;

        if(c!=1)
        {
            if(c!=41)
            {
                if(c!=441)
                {
                    y++;
                    cnt++;
                    c=c*10;
                }
                else
                {
                    y=0;
                    cnt=0;
                    c=0;
                }
            }
            else
            {
                y=0;
                cnt=0;
                c=0;
            }
        }
        else
        {
            y=0;
            cnt=0;
            c=0;
        }
        if(d!=1 && d!=4)
            a=-1;
        if(cnt==3 && c!=0)
        {
            a=-1;
            break;
        }
        a=a/10;}

        if(a==0 && cnt>0)
            printf("NO\n");
        else if(a==-1)
            printf("NO\n");
        else
            printf("YES\n");
    }
}
