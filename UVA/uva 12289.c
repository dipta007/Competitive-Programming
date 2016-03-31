#include <stdio.h>
#include <string.h>

int main()
{
    int n,b,i;
    char a[7];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",&a);
        b=strlen(a);
        if(b==3)
        {
            if(a[0]!='o' && a[1]!='n')
                printf("2\n");
            else if(a[2]!='e' && a[1]!='n')
                printf("2\n");
            else if(a[2]!='e' && a[0]!='o')
                printf("2\n");
            else
                printf("1\n");
        }
        else if(b==5)
            printf("3\n");
    }
    return 0;
}
