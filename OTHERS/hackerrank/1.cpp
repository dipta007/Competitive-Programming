#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        double c=sqrt(a);
        double d=sqrt(b);
        double f=floor(d)-floor(c);
        if(a==floor(c)*floor(c))
        {
            f++;
        }


        printf("%.0lf\n",f);
    }
}

