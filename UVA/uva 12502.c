#include <stdio.h>

int main()
{
    int T,x,y,z;
    float to,to1,to2,count=1;
    scanf("%d",&T);
    if(T>100)
        return 0;
    while(scanf("%d %d %d",&x,&y,&z) !=EOF)
    {
        to=(x+y)/3.0;
        to1=x-to;
        to2=z/to*to1;
        printf("%.0f\n",to2);
        if(x>=1 && y<=10 && (z>=1 && z<=1000))
        {
            count++;
            if(count>T)
                break;
        }
    }
    return 0;
}
