#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int ii,ij,count,x,i,n,k,d,max,z,a,b,temp;
    while(scanf("%lld %lld",&ii,&ij)!=EOF)
    {
        a=ii;
        b=ij;
        if(ii>ij)
        {
            temp=ii;
            ii=ij;
            ij=temp;
        }

        max=0;
        for(i=ii;i<=ij;i++)
        {
            n=i;
            count=1;
            for(k=1;n!=1;k++)
            {


                while(n%2==0)
                {
                    if(n==1)
                        break;

                    n=n/2;
                    count++;
                }

                while(n%2!=0)
                {
                    if(n==1)
                        break;

                    n=3*n+1;
                    count++;
                }
            }
            if(count>max)
                max=count;
        }

        printf("%lld %lld %lld\n",a,b,max);
    }
    return 0;
}
