#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    int i,b;
    while(gets(a))
    {   int c=0,d=0,e=0,f=0,g=0,h=0;
        b=strlen(a);
        for(i=0;i<b;i++)
        {
            if( a[i]=='B' || a[i]=='F' || a[i]=='P'|| a[i]=='V')
            {
                if(c-1!=0)
                {
                    printf("1");
                    c++;
                }
                else c=0;
            }
            else if(a[i]=='C' || a[i]=='G' || a[i]=='J' || a[i]=='K' || a[i]=='Q' || a[i]=='S' || a[i]=='X' || a[i]=='Z')
                {
                if(d-1!=0)
                {
                    printf("2");
                    d++;
                }
                else d=0;
            }
            else if(a[i]=='D' || a[i]=='T')
            {
                if(e-1!=0)
                {
                    printf("3");
                    e++;
                }
                else e=0;
            }
            else if(a[i]=='L')
            {
                if(f-1!=0)
                {
                    printf("4");
                    f++;
                }
                else f=0;
            }
            else if(a[i]=='N' || a[i]=='M')
            {
                if(g-1!=0)
                {
                    printf("5");
                    g++;
                }
                else g=0;
            }
            else if(a[i]=='R')
            {
                if(h-1!=0)
                {
                    printf("6");
                    h++;
                }
                else h=0;
            }
            else continue;
        }
        printf("\n");
    }

}
