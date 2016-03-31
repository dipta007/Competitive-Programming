#include <stdio.h>
#include <math.h>

#define Pi acos(-1)

int main()
{
    int T,count=1,le;
    float w,r,A_c,A_re;
    scanf("%d",&T);
    if(T>100) return 0;

    while(scanf("%d",&le) !=EOF)
    {
        if(le>0 && le<=1000)
        {
            w=(6*le)/10.0;
            r=le/5.0;
            A_c=Pi*r*r;
            A_re=(le*w)-A_c;

            printf("%.2f %.2f\n",A_c,A_re);

            count++;
            if(count > T)
                break;
        }
    }
    return 0;
}
