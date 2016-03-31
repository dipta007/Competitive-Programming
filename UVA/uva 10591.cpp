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
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        int n;
        scanf("%d",&n);
        int y=n,sum=n;
        for(int j=0;sum>=10;j++)
        {
            sum=0;
            for(int k=0;y!=0;k++)
            {
                int r=y%10;
                sum=sum+r*r;
                y=y/10;
            }
            y=sum;

        }
        if(sum==1 || sum==7)
                printf("Case #%d: %d is a Happy number.\n",i,n);
        else
            printf("Case #%d: %d is an Unhappy number.\n",i,n);
    }
}
