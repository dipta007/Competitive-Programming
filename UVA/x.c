#include<stdio.h>
int main()
{
    int n,a,b,x=1;
    double sum,sum1,sum2;
    scanf("%d",&n);
    if(n>100) return 0;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if((a>=0&&a<=100)&&(b>=0&&b<=100)){
            sum=((9.0/5)*a+32);
            sum1=(sum+b);
            sum2=((5.0/9)*(sum1-32));
            printf("Case %d: %.02lf\n",x,sum2);
        }
        x++;
        if(x>n) break;
    }
    return 0;
}
