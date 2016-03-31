#include <stdio.h>
#include <string.h>

int main()
{
    int T,i,sum,k,N,j,rd,rr;
    char a[7],b[7];
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        int l=1;
        sum=0;
        k=0;
        scanf("%d",&N);
        for(j=1;j<=N;j++)
        {
            scanf("%s",&a);
            rd=strncmp(a, "donate",10);
            rr=strncmp(a, "report",10);

            if(rd==0)
            {
                scanf("%d",&k);
                sum=sum+k;
            }
            else if(rr==0)
            {

                if(l==1)
                    printf("Case %d:\n",i);
                printf("%d\n",sum);
                l++;
            }

        }
    }
    return 0;
}
