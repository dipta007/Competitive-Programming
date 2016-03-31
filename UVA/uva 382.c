#include <stdio.h>

int main()
{
    int N,i,sum=0,count=1;
    while(scanf("%d",&N) !=EOF)

    {
        if(count==1)
            printf("PERFECTION OUTPUT\n");
        if(N==0)
        {
            printf("END OF OUTPUT\n");
            return 0;
        }

        sum=0;
        for(i=1;i<=(N/2);i++)
        {
            if(N%i == 0)
            {
                sum=sum+i;
            }
        }


        count++;


        if(sum==N)
            printf("%5d  PERFECT\n",N);
        else if(sum < N)
            printf("%5d  DEFICIENT\n",N);
        else if(sum > N)
            printf("%5d  ABUNDANT\n",N);

    }
}
