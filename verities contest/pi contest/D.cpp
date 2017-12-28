#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,m;
    char oz[]="10";
    char oo[]="11";
    char ooz[]="110";
    char ozo[]="101";
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(m<=n || (m-(n*2))>2)
            printf("-1\n");
        else
        {
            if(m==(n+1))
            {
                for(int i=1;i<=n;i++)
                {
                    if(i==n)
                    {
                        printf("%s\n",ozo);
                        break;
                    }
                    printf("%s",oz);
                }
            }
            else if(m==n*2)
            {
                for(int i=1;i<=n;i++)
                {
//                    if(i==n)
//                    {
//                        printf("%s\n",ozo);
//                        break;
//                    }
                    printf("%s",ozo);
                }
                printf("\n");
            }
            else if(m==n*2+1)
            {
                printf("1");
                for(int i=1;i<=n;i++)
                {
                    printf("%s",ozo);
                }
                printf("\n");
            }
            else if(m==n*2+2)
            {
                printf("1");
                for(int i=1;i<=n;i++)
                {
//
                    printf("%s",ozo);
                }
                printf("1\n");
            }

        }
    }
}
