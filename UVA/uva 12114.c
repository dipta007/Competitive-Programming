#include <stdio.h>

int main()
{
    double B,S,c=1;
    while(scanf("%lf %lf",&B,&S)!=EOF)
    {
        if(B==0 && S==0)
            break;

        else if(B == 1)
            printf("Case %.0lf: :-\\\n",c++);
        else if(B>S)
            printf("Case %.0lf: :-(\n",c++);
        else if(S>B)
            printf("Case %.0lf: :-)\n",c++);
        else if(S==B)
            printf("Case %.0lf: :-|\n",c++);
    }
    return 0;
}
