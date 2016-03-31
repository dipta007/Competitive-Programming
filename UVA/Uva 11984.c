#include <stdio.h>

int main()
{
    int T,C,d;
    float F,FF,FC,count=1;
    scanf("%d",&T);
    if(T>100)
        return 0;
    while(scanf("%d %d",&C,&d) !=EOF)
    {
        if(C>=0 && d<=100)
        {
            F=(((9/5.0)*C)+32);
            FF=F+d;
            FC=((FF-32)*(5/9.0));
            printf("Case %.0f: %.2f\n",count,FC);

            count++;
            if(count>T)
                break;
        }
    }
    return 0;
}
