#include <stdio.h>
int main()
{
    int T,S,S1,S2;
    int i,j,k;
    int A1,D1,K1,A2,D2,K2;
    scanf("%d",&T);
    for(i=1; i<=T; i++)
    {
        scanf("%d %d %d %d %d %d",&A1,&D1,&K1,&A2,&D2,&K2);
        if(A1<K1 && D1>0)
        {
            S1=0;

            for(j=A1; j<=K1; j=j+D1)
            {
                S1=S1+j;
            }
        }
        else if(A1>K1 && D1<0)
        {
            S1=0;
            for(j=A1; j>=K1; j=j+D1)
            {
                S1=S1+j;
            }
        }

        if(A2>K2 && D2>0)
        {
            S2=0;
            for(k=A2; k<=K2; k=k+D2)
            {
                S2=S2+k;
            }
        }
        else if(A2>K2 && D2<0)
        {
            S2=0;
            for(k=A2; k>=K2; k=k+D2)
            {
                S2=S2+k;
            }
        }
        else(A2>K2 && D2>0)
        {
            S2=0;
            for(k=A2; k>=K2; k=k-D2)
            {
                S2=S2+k;
            }
        }
        S=S1+S2;
        printf("Case %d: %d",i,S);
    }

    return 0;
}

