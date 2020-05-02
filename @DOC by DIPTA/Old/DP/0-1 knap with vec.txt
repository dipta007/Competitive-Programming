#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;


int main()
{
    //freopen("file1.txt","r",stdin);
    vector<int> cost,weight,dp[1100];
    int t,w,n,j,k,x,y;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d",&n);
        cost.push_back(0);
        weight.push_back(0);
        for(j=1; j<=n; j++)
        {
            scanf("%d%d",&x,&y);
            cost.push_back(x);
            weight.push_back(y);
        }
        scanf("%d",&x);
        int res=0;
        w=0;
        for(int m=1; m<=x; m++)
        {
            scanf("%d",&y);
            for(int l=0;l<=y;l++)
            {
                dp[0].push_back(0);
            }
            w=y;
            for(j=1; j<=cost.size(); j++)
            {
                for(k=0; k<=w; k++)
                {
                    if(weight[j]<=k&&((cost[j]+dp[j-1][k-weight[j]])>dp[j-1][k]))
                    {
                        dp[j].push_back(cost[j]+dp[j-1][k-weight[j]]);
                    }
                    else
                    {
                        dp[j].push_back(dp[j-1][k]);
                    }
                }
            }
            res+=dp[n][w];
            for(j=0; j<=cost.size(); j++)
                dp[j].clear();
        }
        cout<<res<<endl;
        cost.clear();
        weight.clear();

    }
    return 0;
}
