#include <stdio.h>

int main()
{
    int N,i,j,k,x,a[6],y,c,sum;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        for(j=0;j<4;j++)
            scanf("%d",&a[j]);

        sum=0;
        for(j=0;j<4;j++)
        {
            for(k=0;a[j]!=0;k++)
            {
                x=a[j]%10;
                a[j]=a[j]/10;
                if(k==1 || k==3)
                {
                    y=x*2;
                    while(y!=0)
                    {
                        c=y%10;
                        y=y/10;
                        sum=sum+c;
                    }
                }
                else if(k==0 || k==2)
                {
                    sum=sum+x;
                }
            }
        }
        if(sum==0)
            printf("Valid\n");
        else
            printf("Invalid\n");
    }
    return 0;
}
