#include <stdio.h>

int dig[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int dp[100004];
int pri[100004];
int v[100004];

int call(int n)
{
    if(n<=0) return 0;

    if(dp[n]!=-1) return dp[n];
    int ret=0;

    int i;
    for(i=0;i<=9;i++)
    {
        if(n-dig[i]>=0)
        {
            int now = 1 + call(n-dig[i]);
            if(now >=ret)
            {
                ret = now;
                pri[n] = i;
            }
        }
    }

    return dp[n] = ret;
}

void callP(int n, int in)
{
    if(n<=0)
    {
        int i;
        for(i=0;i<=in-1;i++)
        {
            printf("%d",v[i]);
        }
        printf("\n");
        return;
    }

    int kk = pri[n];
    v[in] = kk;
    callP(n - dig[kk], in+1);

}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(~scanf("%d",&n))
    {
        memset(dp,-1,sizeof(v));
        call(n);
        callP(n,0);
    }

    return 0;
}





