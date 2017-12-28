#include <stdio.h>

int main()
{
    int d,y;
    char a[100],m[6];
    scanf("%s",a);
    sscanf(a," %d %s %d",&d,m,&y);
    printf("%d \n%s\n %d",d,m,y);
}
