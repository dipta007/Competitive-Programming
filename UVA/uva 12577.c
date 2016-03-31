#include <stdio.h>
#include <string.h>

int main()
{
    int count=1,H,U,E;
    char a[7];
    while(scanf("%s",&a)!=EOF)
    {
        H=strncmp(a,"Hajj",7);
        U=strncmp(a,"Umrah",7);
        E=strncmp(a,"*",2);
        if(H==0)
            printf("Case %d: Hajj-e-Akbar\n",count++);
        else if(U==0)
            printf("Case %d: Hajj-e-Asghar\n",count++);
        else if(E==0)
            break;
    }
    return 0;
}
