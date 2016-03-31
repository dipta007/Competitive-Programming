#include <stdio.h>

int main()
{
    int T,count=1;
    long long int s,i;
    scanf("%d",&T);
    if(T>200)
        return 0;
    while(scanf("%lld",&s) !=EOF)
    {
        i=pow(10,15);
        if(s>=1 && s<=i)
        {
            if(s<=25)
            {
                if(s==1)
                    printf("Case %d: 1 1\n",count);
                else if(s==2)
                    printf("Case %d: 1 2\n",count);
                else if(s==3)
                    printf("Case %d: 2 2\n",count);
                else if(s==4)
                    printf("Case %d: 2 1\n",count);
                else if(s==5)
                    printf("Case %d: 3 1\n",count);
                else if(s==6)
                    printf("Case %d: 3 2\n",count);
                else if(s==7)
                    printf("Case %d: 3 3\n",count);
                else if(s==8)
                    printf("Case %d: 2 3\n",count);
                else if(s==9)
                    printf("Case %d: 1 3\n",count);
                else if(s==10)
                    printf("Case %d: 1 4\n",count);
                else if(s==11)
                    printf("Case %d: 2 4\n",count);
                else if(s==12)
                    printf("Case %d: 3 4\n",count);
                else if(s==13)
                    printf("Case %d: 4 4\n",count);
                else if(s==14)
                    printf("Case %d: 4 3\n",count);
                else if(s==15)
                    printf("Case %d: 4 2\n",count);
                else if(s==16)
                    printf("Case %d: 4 1\n",count);
                else if(s==17)
                    printf("Case %d: 5 1\n",count);
                else if(s==18)
                    printf("Case %d: 5 2\n",count);
                else if(s==19)
                    printf("Case %d: 5 3\n",count);
                else if(s==20)
                    printf("Case %d: 5 4\n",count);
                else if(s==21)
                    printf("Case %d: 5 5\n",count);
                else if(s==22)
                    printf("Case %d: 4 5\n",count);
                else if(s==23)
                    printf("Case %d: 3 5\n",count);
                else if(s==24)
                    printf("Case %d: 2 5\n",count);
                else if(s==25)
                    printf("Case %d: 1 5\n",count);

            }
            else if(s>25)
            {
                s=s%25;
                if(s==1)
                    printf("Case %d: 1 1\n",count);
                else if(s==2)
                    printf("Case %d: 1 2\n",count);
                else if(s==3)
                    printf("Case %d: 2 2\n",count);
                else if(s==4)
                    printf("Case %d: 2 1\n",count);
                else if(s==5)
                    printf("Case %d: 3 1\n",count);
                else if(s==6)
                    printf("Case %d: 3 2\n",count);
                else if(s==7)
                    printf("Case %d: 3 3\n",count);
                else if(s==8)
                    printf("Case %d: 2 3\n",count);
                else if(s==9)
                    printf("Case %d: 1 3\n",count);
                else if(s==10)
                    printf("Case %d: 1 4\n",count);
                else if(s==11)
                    printf("Case %d: 2 4\n",count);
                else if(s==12)
                    printf("Case %d: 3 4\n",count);
                else if(s==13)
                    printf("Case %d: 4 4\n",count);
                else if(s==14)
                    printf("Case %d: 4 3\n",count);
                else if(s==15)
                    printf("Case %d: 4 2\n",count);
                else if(s==16)
                    printf("Case %d: 4 1\n",count);
                else if(s==17)
                    printf("Case %d: 5 1\n",count);
                else if(s==18)
                    printf("Case %d: 5 2\n",count);
                else if(s==19)
                    printf("Case %d: 5 3\n",count);
                else if(s==20)
                    printf("Case %d: 5 4\n",count);
                else if(s==21)
                    printf("Case %d: 5 5\n",count);
                else if(s==22)
                    printf("Case %d: 4 5\n",count);
                else if(s==23)
                    printf("Case %d: 3 5\n",count);
                else if(s==24)
                    printf("Case %d: 2 5\n",count);
                else if(s==0)
                    printf("Case %d: 1 5\n",count);
            }
            count++;
            if(count>T)
                break;
        }

    }
    return 0;
}
