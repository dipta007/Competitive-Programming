#include <stdio.h>
#include <math.h>

int main()
{
    int N,t1,t2,i,j,k,l,sum,count,flag1,flag2,x,b,m,s1,s2;
    scanf("d",&N);
    for(m=1;m<=N;m++)
    {
        count=0;
        scanf("%d %d",&t1,&t2);
        for(i=t1;i<=t2;i++)
        {
            flag1=1;
            b=i;
            s1=sqrt(b);
            for(j=2;j<=s1;j++)
            {
                if(b%j==0)
                {
                    flag1=0;
                    break;
                }
            }

            if(flag1==1)
            {
                sum=0;
                for(k=1;b!=0;k++)
                {
                    x=b%10;
                    b=b/10;
                    sum=sum+x;
                }

                flag2=1;
                s2=sqrt(sum);
                for(l=2;l<=s2;l++)
                {
                    if(sum%l==0)
                    {
                        flag2=0;
                        break;
                    }
                }
                if(flag2==1)
                    count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
