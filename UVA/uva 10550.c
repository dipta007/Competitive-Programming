#include <stdio.h>

int main()
{
    int a,x,y,z,sum,c_w,i,c_c;
    while(scanf("%d %d %d %d",&a,&x,&y,&z)!=EOF)
    {
        if(a==0 && x==0 && y==0 && z==0)
            break;

        sum=720;

        c_w=-1;
        for(i=a;i!=x;i--)
        {
            if(i==0)
                i=41;
            c_w++;
        }
        sum=sum+(c_w*9)+360;

        c_c=-1;
        for(i=x;i!=y;i++)
        {
            if(i==40)
                i=-1;
            c_c++;
        }
        sum=sum+(c_c*9);

        c_w=-1;
        for(i=y;i!=x;i--)
        {
            if(i==0)
                i=41;
            c_w++;
        }
        sum=sum+(c_w*9);

        printf("%d\n",sum);
    }
    return 0;
}
