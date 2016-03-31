#include <stdio.h>
#include <math.h>

int main()
{
    int N,b,flag,i,c,d,j;
    double a;
    while(scanf("%d",&N)!=EOF)
    {
        if(N==0)
            break;

        a=1/3.0;
        b=pow(N,a);

        flag=0;
        d=0;
        for(i=1;d!=N;i++)
        {
            c=(i*i*i)-((i-1)*(i-1)*(i-1));
            if(c>N)
                break;

            for(j=1;j<i;j++)
            {
                d=(i*i*i)-(j*j*j);
                if(d==N)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
            printf("%d %d\n",(i-1),j);
        else
            printf("No Solution\n");
    }
    return 0;
}
