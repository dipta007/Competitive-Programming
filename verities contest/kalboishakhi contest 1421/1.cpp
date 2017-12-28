#include <iostream>
#include <cstring>
#include <stdio.h>
#include <sstream>
using namespace std;

int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        int sum=a+b;
        stringstream ss;
        ss << sum;
        string s1=ss.str();
        int k=s1.size();
        printf("%d\n",k);
    }
}
