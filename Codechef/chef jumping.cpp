#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n%6==0 || n%6==1 || n%6==3)
            printf("yes\n");
        else
            printf("no\n");
    }
}
