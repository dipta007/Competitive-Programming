#include <stdio.h>

int main()
{
    int T,count,CTT,Term1,Term2,Final,Attendance,CT1,CT2,CT3;
    scanf("%d",&T);
    if(T>=100)
        return 0;
    for(count=1;count<=T;count++)
    {
        scanf("%d %d %d %d %d %d %d",&Term1,&Term2,&Final,&Attendance,&CT1,&CT2,&CT3);
        if(Term1<0 || Term1>20 || Term2<0 || Term2>20 || Final<0 || Final>30 || Attendance<0 || Attendance>10 || CT1<0 || CT1>20 || CT2<0 || CT2>20 || CT3<0 || CT3>20)
            break;
        if(CT1 >= CT2 && CT2 >= CT3)
        {
            CTT=(CT1+CT2)/2;
            T=Term1+Term2+Final+Attendance+CTT;
        }
        else if(CT1 >= CT3 && CT3 >= CT2)
        {
            CTT=(CT1+CT3)/2;
            T=Term1+Term2+Final+Attendance+CTT;
        }
        else if(CT2 >= CT1 && CT1 >= CT3)
        {
            CTT=(CT2+CT1)/2;
            T=Term1+Term2+Final+Attendance+CTT;
        }
        else if(CT2 >= CT3 && CT3 >= CT1)
        {
            CTT=(CT2+CT3)/2;
            T=Term1+Term2+Final+Attendance+CTT;
        }
        else if(CT3 >= CT1 && CT1 >= CT2)
        {
            CTT=(CT3+CT1)/2;
            T=Term1+Term2+Final+Attendance+CTT;
        }
        else if(CT3 >= CT2 && CT2 >= CT1)
        {
            CTT=(CT3+CT2)/2;
            T=Term1+Term2+Final+Attendance+CTT;
        }
        if(T>=90)
            printf("Case %d: A\n",count);
        else if(T<90 && T>=80)
            printf("Case %d: B\n",count);
        else if(T<80 && T>=70)
            printf("Case %d: C\n",count);
        else if(T<70 && T>=60)
            printf("Case %d: D\n",count);
        else if(T<60)
            printf("Case %d: F\n",count);
    }
    return 0;
}
