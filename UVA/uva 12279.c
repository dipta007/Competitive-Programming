#include <stdio.h>

int main()
{
    int N,c=1,i,j,a[1100],count,b,res;
    while(scanf("%d",&N)!=EOF)
    {
        if(N==0)
            break;

        count=0;
        for(i=0;i<N;i++)
            scanf("%d",&a[i]);
        for(j=0;j<N;j++)
            if(a[j]==0)
                count++;
        b=N-count;
        res=b-count;

        printf("Case %d: %d\n",c++,res);
    }
    return 0;
}
