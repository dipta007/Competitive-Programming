#include <stdio.h>
#include <string.h>

int main()
{
    int n,count,i;
    char a[10000];
    for(;;)
    {
        gets(a);
        count=1;
        n=strlen(a);
        for(i=0;i<n-1;i++)
        {
            if(a[i]==' ')
                if((a[i+1]>='a' && a[i+1]<='z') || (a[i+1]>='A' && a[i+1]<='Z'))
                    count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
