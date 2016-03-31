#include <stdio.h>

int main()
{
    int a[1100],i,max,j,flag,k,l,rem;
    while(scanf("%d",&a[0])!=EOF)
    {
        if(a[0]==0)
            break;

        for(i=1;a[i-1]>0;i++)
        {
            scanf("%d",&a[i]);
        }

        max=a[0];
        for(j=1;j<=i-2;j++)
        {
            if(a[j]>max)
                max=a[j];
        }

        flag=0;
        for(k=1;k<=max;k++)
        {
            for(l=0;l<=i-2;l++)
            {
                if(l==0)
                    rem=a[l]%k;
                else
                {
                    if(rem!=(a[l]%k))
                    {
                        flag=0;
                        break;
                    }
                    else
                        flag=1;
                }
            }
        }
    }
}
