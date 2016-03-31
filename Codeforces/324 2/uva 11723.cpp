#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    int cas=1;
    while(scanf("%d %d",&m,&n)==2)
    {
        if(m==0 && n==0) break;
        printf("Case %d: ",cas++);

        if(n*27<m) printf("impossible\n");

        else printf("%d\n",(m-1)/n);
    }
}
