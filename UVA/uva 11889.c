#include <stdio.h>

int main()
{
    int i,T,A,C;
    while(scanf("%d",&T)!=EOF)
    {
        for(i=1;i<=T;i++)
        {
            scanf("%d %d",&A,&C);
            if(C%A==0)
                printf("%d\n",(C/A));
            else
            printf("NO SOLUTION\n");
        }
    }
    return 0;
}
