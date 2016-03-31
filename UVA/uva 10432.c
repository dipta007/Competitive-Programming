#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

int main()
{
    double r,n,a,b,area;
    while(scanf("%lf %lf",&r,&n)!=EOF)
    {
        b=360.0/n;
        a=sin(b*PI/180.0);
        area=(((r*r)*n)*a)/2;

        printf("%.3lf\n",area);
    }
    return 0;
}
