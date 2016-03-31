#include <stdio.h>

int main()
{
    int T,i;
    double v1,v2,v3,a1,a2,s1,s2,s,t1,t2,t,s3;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lf %lf %lf %lf %lf",&v1,&v2,&v3,&a1,&a2);

        s1=(((v1*v1)/2)/a1);
        s2=(((v2*v2)/2)/a2);

        s= s1+s2;
        t1=v1/a1;
        t2=v2/a2;

        if(t1>t2)
            t=t1;
        else
            t=t2;

        s3=v3*t;

        printf("Case %d: %.10lf %.10lf\n",i,s,s3);
    }
    return 0;
}
