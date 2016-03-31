#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,i,j,k,l,z,d[100]={0},p,sum,deci[300],e[100]={0},f[200];
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        for(i=0;a>0;i++)
        {
            d[i]=a%2;
            a=a/2;
        }
        for(j=0;b>0;j++)
        {
            e[j]=b%2;
            b=b/2;
        }

        if((i-1)>(j-1))
            z=i-1;
        else
            z=j-1;
            printf("\n\n%d\n\n",z);

        for(k=0;k<z;k++)
        {
            f[k]=d[k]+e[k];
            printf("%d\n",f[k]);
            if(f[k]==2)
                f[k]=0;
            printf("%d",f[k]);
        }
        p=1;
        sum=0;
        for(l=0;l<=z;l++)
        {
            deci[l]=f[l]*p;
            sum=sum+deci[l];
            p=p*2;
        }

        printf("\n\n%d\n",sum);

    }
}
