#include <stdio.h>
    #include <math.h>

    int main()
    {
        int a,b,bia,c,p,i,bib,cp;
        while(scanf("%d %d",&a,&b)!=EOF)
        {
            p=1;
            bia=0;
            for(i=0;a>0;i++)
            {
                c=a%2;
                a=a/2;

                bia=bia+ (c*p);
                p=p*10;
            }
            for(i=0;bia!=0 || bib!=0;i++)
            {
                c1=bia%10;
                c2=bib%10;

                T=c1+c2;

                if()
            }


            bib=0;
            p=1;
            for(i=0;b!=0;i++)
            {
                c=b%2;
                b=b/2;

                bib=bib+ (c*p);
                p=p*10;
            }
            printf("%d %d\n",bia,bib);
        }
    }
