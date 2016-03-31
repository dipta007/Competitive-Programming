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
    char y[30000],c[100];
    int yt=0;
    while(scanf("%s",&y)!=EOF)
    {
        if(yt)
            printf("\n");
        yt=1;

        int i,l=0,h=0,b=0,j;
        int sy=strlen(y);
        for(i=0,j=sy-4;i<4;i++,j++)
            c[i]=y[j];
        c[i]=0;
        int ic=atoi(c);
        if((ic%4==0 && ic%100!=0) || ic%400==0)
        {
            l=1;
        }

        int sum=0,sum1=0,sum2=0;
        for(j=0;j<sy;j++)
        {
            sum=sum+ (y[j]-48);
            if(j%2==0)
                sum1=sum1+ (y[j]-48);
            else
                sum2=sum2+ (y[j]-48);
        }

        if(y[sy-1]=='0' || y[sy-1]=='5')
        {
            if(sum%3==0)
                h=1;
            if((sum1%11==sum2%11) && l==1)
                b=1;
        }

        if(l==1)
            printf("This is leap year.\n");
        if(h==1)
            printf("This is huluculu festival year.\n");
        if(b==1)
            printf("This is bulukulu festival year.\n");
        if(l==0 && h==0 && b==0)
            printf("This is an ordinary year.\n");


    }
}
