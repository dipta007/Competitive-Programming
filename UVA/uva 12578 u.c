#include <stdio.h>
#include <math.h>

#define Pi acos(-1)

int main()
{
    int T,i;
    double le,w,r,A_c,A_re;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lf",&le);

        w=(6.0*le)/10.0;
        r=le/5.0;
        A_c=Pi*r*r;
        A_re=(le*w)-A_c;

        printf("%.2lf %.2lf\n",A_c,A_re);
    }
    return 0;
}
