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
    int a,b[3],c,fre=0;
    char d[100],b1[100];
    while(scanf("%s",&d)!=EOF)
    {
        int sd=strlen(d);
        int l=0,flg,fflg=1,cnt=0;
        for(int i=0;i<sd;i++)
        {
            if(fflg==0)
                break;
            if(d[i]=='+' || d[i]=='-')
            {
                if(d[i]=='+')
                    flg=1;
                else
                    flg=0;
                b1[l]=0;
                l=0;
                b[cnt++]=atoi(b1);
                continue;
            }
            else if(d[i]=='=')
            {
                if(d[i+1]=='?')
                {
                    fflg=0;
                    break;
                }
                b1[l]=0;
                l=0;
                b[cnt++]=atoi(b1);
            }
            else
                b1[l++]=d[i];
        }
        b1[l]=0;
        b[cnt]=atoi(b1);

        if(fflg==1 && flg==1)
        {
            if((b[0]+b[1])==b[2])
                fre++;
        }
        else if(fflg==1 && flg==0)
        {
            if((b[0]-b[1])==b[2])
                fre++;
        }
    }
    printf("%d\n",fre);
    return 0;
}
