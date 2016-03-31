#include <stdio.h>

int main()
{
    int N,count=1,a,b,c,d,e,f,g,h,i,j;
    scanf("%d",&N);
    if(N<=0 || N>=20)
        return 0;
    while(scanf("%d %d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j) !=EOF)
    {
        if(count == 1)
            printf("Lumberjacks:\n");
        if((a>=0 && a<100) && (b>=0 && b<100) && (c>=0 && c<100) && (d>=0 && d<100) && (e>=0 && e<100) && (f>=0 && f<100) && (g>=0 && g<100) && (h>=0 && h<100) && (i>=0 && i<100) && (j>=0 && j<100))
        {
            if(a>b && b>c && c>d && d>e && e>f && f>g && g>h && h>i && i>j)
                printf("Ordered\n");
            else if(j>i && i>h && h>g && g>f && f>e && e>d && d>c && c>b && b>a)
                printf("Ordered\n");
            else
                printf("Unordered\n");

            count++;
            if(count>N)
                break;
        }
    }
    return 0;
}
