#include <bits/stdc++.h>
using namespace std;
int dp[104][104];
int n;
int a[104][104];
int call(int r,int c)
{
    if(r>n) return 0;
    int &ret = dp[r][c];
    if(ret!=-1) return ret;
    ret = 0;
    ret = max(ret, a[r][c] + call(r+1,c));
    ret = max(ret, a[r][c] + call(r+1,c+1));
    return ret;
}
int main()
{
    int t;
    cin >> t;
    for(int ci=1; ci<=t; ci++)
    {
        cin >> n;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cin >> a[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n",call(1,1));
    }
}
