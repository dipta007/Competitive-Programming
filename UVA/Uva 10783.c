#include <stdio.h>

int main()
{
    int T,a,b,s,odd,count=1;
    scanf("%d",&T);
    if(T<1 || T>100)
        return 0;
    while(scanf("%d %d",&a,&b) !=EOF)
    {
        odd=0;
        if(a>=0 && b>=a && b<=100)
        {
            for(s=a;s<=b;s++)
            {
                if(s%2 != 0)
                {
                    odd=s+odd;
                }
            }
            printf("Case %d: %d\n",count,odd);

            count++;
            if(count > T)
                break;
        }
    }
    return 0;
}
