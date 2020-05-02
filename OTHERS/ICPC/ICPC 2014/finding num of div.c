#include <stdio.h>

int main()
{

    while(1)
    {
        int a[1000]={0};
        int n,y,i,j,s=1;
        scanf("%d",&n);
        y=n;
        for(i=2;i<=sqrt(n);)
        {
            if(y%i==0)
            {
                y=y/i;
                a[i]++;
            }
            else
                i++;
        }
        for(j=2;j<=i;j++)
        {
            if(a[j]>0)
            {
                s=s*(a[j]+1);
            }
        }
        printf("%d",s);
    }

}
