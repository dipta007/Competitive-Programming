#include <stdio.h>

int main()
{
    int year;
    while(scanf("%d",&year) !=EOF)
    {
        if(year>=2000)
        {
            if(year%100 != 0 && year%4 == 0)
            {
                printf("This is leap year.\n");
                if(year%55 == 0)
                    printf("This is bulukulu festival year.\n");
            }
            else if(year%100 == 0 && year%400 == 0)
            {
                printf("This is leap year.\n");
                if(year%55 == 0)
                    printf("This is bulukulu festival year.\n");
            }
            else if(year%15 == 0)
                printf("This is huluculu festival year.\n");\
            else
                printf("This is an ordinary year.");
        }
        printf("\n");
    }
    return 0;
}

