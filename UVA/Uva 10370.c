#include <stdio.h>

int main()
{
    int C,count,count1,count2,i,tn,n[1000];
    float ttn,N,per;
    scanf("%d",&C);
    for(count1=1;count1<=C;count1++)
    {
        tn=0;
        count=0;
        scanf("%f",&N);
        if(N>=1 && N<=1000)
        {
            for(i=1;i<=N;i++)
            {
                scanf("%d",&n[i]);
                if(n[i]>=0 && n[i]<=100)
                {
                    tn=tn+n[i];
                    ttn=tn/N;
                }
            }
            for(i=1;i<=N;i++)
            {
                if(n[i]>ttn)
                {
                    count++;
                }
            }
            per=count/N*100.0;
            printf("%.3f%%\n",per);
        }
    }
    return 0;
}
