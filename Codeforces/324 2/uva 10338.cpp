#include <bits/stdc++.h>

using namespace std;

unsigned long long int factorial[21];

void fact()
{
    factorial[1]=1;

    for(int i=2;i<=20;i++)
    {
        factorial[i]=factorial[i-1]*i;
    }
}

int main()
{
    fact();
    int n;
    cin>>n;
    getchar();
    int color[100];
    for(int i=1;i<=n;i++)
    {

        memset(color,0,sizeof color);
        char a[22];
        gets(a);
        int len = strlen(a);

        unsigned long long int ans=factorial[len];


        for(int j=0;j<len;j++)
        {
            int x=a[j];
            color[x]++;

        }

        for(int i=65;i<=90;i++)
        {
            if(color[i]>1)
            {
                ans/= factorial[color[i]];
            }

        }

        printf("Data set %d: %llu\n",i,ans);

    }
}
