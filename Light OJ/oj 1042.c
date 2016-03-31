#include <stdio.h>

int main()
{
    int T,i,N,k,l,mc,m,c,M,a,j;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&N);
        M=N;
        mc=0;
        for(k=1;N!=0;k++)
        {
            a=N%2;
            if(a==1)
                mc++;
            N=N/2;
        }

        for(j=M+1;;j++)
        {
            c=0;
            m=j;
            for(l=1;m!=0;l++)
            {
                a=m%2;
                if(a==1)
                    c++;
                m=m/2;
            }
            if(c==mc)
            {
                printf("Case %d: %d\n",i,j);
                break;
            }
        }
    }
    return 0;
}
