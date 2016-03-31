#include <stdio.h>

int main()
{
    long long int I,i,j,P,a,p,x;
    long double B;
    while(scanf("%lld",&I)!=EOF)
    {
        if(I==0)
            break;

        p=1;
        P=0;
        B=0;
        for(i=0;I!=0;i++)
        {
            x=I%2;
            if(x==1)
                P++;
            I=I/2;
            B=B+ (x*p);
            p=p*10;
        }
        printf("The parity of %0.0llf is %lld (mod 2).\n",B,P);
    }
    return 0;
}
