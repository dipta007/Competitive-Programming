#include <stdio.h>
#include <math.h>

int main()
{
    int T,i;
    double ax,ay,bx,by,cx,cy,dx,dy,a,b,c,s,A;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&ax,&ay,&bx,&by,&cx,&cy);
        dx=ax+cx-bx;
        dy=ay+cy-by;

        a=sqrt((ax-dx)*(ax-dx)+(ay-dy)*(ay-dy));
        b=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
        c=sqrt((bx-dx)*(bx-dx)+(by-dy)*(by-dy));

        s=(a+b+c)/2;
        A=2*sqrt(s*(s-a)*(s-b)*(s-c));

        printf("Case %d: %.0lf %.0lf %.0lf\n",i,dx,dy,A);

    }
    return 0;
}
