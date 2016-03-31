#include <stdio.h>
#include <string.h>

int main()
{
    int T,n,a[7],i,A,B;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %s",&n,&a);

        A=strncmp(a,"Alice",10);
        B=strncmp(a,"Bob",10);

        if(n%2 != 0)
        {
            if(A == 0)
                printf("Case %d: Bob\n",i);
            else
                printf("Case %d: Alice\n",i);
        }
        else
        {
            if(A==0)
                printf("Case %d: Alice\n",i);
            else
                printf("Case %d: Bob\n",i);
        }
    }
    return 0;
}
