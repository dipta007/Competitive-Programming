#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int i,t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        orintf("")
        int a[2];
        for(i=0;i<3;i++)
        {
            scanf("%d",&a[i]);
        }

        sort(a,a+3);

        if(a[2]>=(a[0]+a[1])) printf("Case %d: Invalid\n",t);
        else if (a[0]==a[2]) printf("Case %d: Equilateral\n",t);
        else if (a[0]==a[1] || a[1]==a[2]) printf("Case %d: Isosceles\n",t);
        else printf("Case %d: Scalene\n",t);

    }
    return 0;
}
