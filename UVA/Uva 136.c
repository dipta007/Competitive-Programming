#include <stdio.h>

int main()
{
    int count=0,i;
    for(i=1;i<30;i++)
    {
        if(i%2==0 || i%3==0 || i%5==0)
        {
            printf("%d\n",i);
            count++;
            if(count==1499)
            {
                printf("The 1500'th ugly number is %d",i);
                break;
            }
        }

    }
    return 0;
}
