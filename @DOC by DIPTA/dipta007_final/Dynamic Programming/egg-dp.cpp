int dp[55][1005];
int call(int dim,int height)
{
//    debug(dim,height)
    if(dim==1||height==0)return height;
//    if(dim==0||height==0)return height;
    int &ret=dp[dim][height];
    if(ret!=-1)return ret;
    int ans=INF;
    ///1 theka height sb floor e try korbo ai dim dia
    for(int i=1; i<=height; i++)
    {
        ///dim vangse ai floor e so 1 theka height i-1 er modde
        ///dim-1 ta die try korbo
        int tmp=call(dim-1,i-1);
        ///dim vange nai tai i+1 theka baki floor e
        ///dim ta die try korbo
        tmp=max(tmp,call(dim,height-i));
        ans=min(ans,tmp);
    }
    return ret=1+ans;

}
void solveiterative()
{

        CLR(dp);
        rep(i,m)dp[1][i]=i;
        FOR(i,1,n)
        {
            if(i==1)continue;
            ///if(i>j)then dp[i][j]=dp[i-1][j]
            FOR(j,1,m)
            {
                int ans=INF;
                FOR(k,1,j)
                {
                    ans=min(ans,max(dp[i-1][k-1],dp[i][j-k]));
                }
                dp[i][j]=1+ans;
            }
        }
//        printf("%d %d\n",cs,dp[n][m]);
}
