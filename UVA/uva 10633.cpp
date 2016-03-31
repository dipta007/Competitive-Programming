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
    int n,a[100];
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        int l=0;
        for(int i=n+1;;i++)
        {
            int k=i%10;
            k=k/10;
            k=k%10;
            if(k==i-n)
                a[l++]=i;
            else
                break;
        }
        for(int i=0;i<l;i++)
        {
            if(i<l-1)
                printf("%d ",a[i]);
            else
                printf("%d",a[i]);
        }
    }
}
