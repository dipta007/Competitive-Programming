#include <stdio.h>
#include <math.h>

int main()
{
    int T,Ox,Oy,Ax,Ay,Bx,By,i;
    double r1,r,OA1,OA,AB1,AB,theta1,theta,result;
    scanf("%d",&T);
    if(T>100)
        return 0;
    for(i=1;i<=T;i++)
    {
        scanf("%d %d %d %d %d %d",&Ox,&Oy,&Ax,&Ay,&Bx,&By);


        OA1=(Ox-Ax)*(Ox-Ax)+(Oy-Ay)*(Oy-Ay);
        OA=sqrt(OA1);

        AB1=(Ax-Bx)*(Ax-Bx)+(Ay-By)*(Ay-By);
        AB=sqrt(AB1);

        theta1=(2.0*OA*OA-AB*AB)/(2.0*OA*OA);
        theta=acos(theta1);

        r=OA;
        result=r * theta;

        printf("Case %d: %lf\n",i,result);
    }

    return 0;

}
