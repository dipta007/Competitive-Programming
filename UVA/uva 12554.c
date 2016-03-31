#include <stdio.h>

int main()
{
    int n,i,z,y,j,s,ac;
    char a[110][110],song[18][10]={"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s",&a[i]);

    z=n/16;
    if(n!=(z*16))
    {
        y=(z+1)*16;

    }
    else
        y=16;

    for(j=0,s=0,ac=0;j<y;ac++,s++,j++)
    {
        printf("%s: %s\n",a[ac],song[s]);
        if(ac==n-1)
            ac=-1;
        if(s==15)
            s=-1;
    }
    return 0;
}
