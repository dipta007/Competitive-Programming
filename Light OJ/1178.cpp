#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int T,i;
    double a,b,c,d,A,B,C,S,A_T,h,a_p;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);

        A=d;
        B=fabs(c-a);

        C=b;
        S=(A+B+C)/2;
        A_T=sqrt(S*(S-A)*(S-B)*(S-C));
        h=2*A_T/B;


        if(B!=0)
            printf("Case %d: %.10lf\n",i,a_p);
    }
    return 0;
}

