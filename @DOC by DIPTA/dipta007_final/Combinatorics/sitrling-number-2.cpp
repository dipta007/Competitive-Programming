/**
    Stirling(N,K,R) = Partition N people into K non-empty groups so that each group contains at least R people.
    Stirling(N,K,R) = Stirling(N-1,K,R)*K + Stirling(N-R,K-1,R) * Binomial(N-1,R-1)
**/
void Stirling_numbers_of_the_second_kind(){
    FOR(i,1,1000){
        stirling_numbers[i][1] = 1;
        FOR(j,2,i){
            stirling_numbers[i][j] = (stirling_numbers[i-1][j-1] + (j*stirling_numbers[i-1][j]));
        }
    }
}

/// Recursive one

ll dp[1005][1005];
ll stirling(int n, int k)
{
    if(k==1 || n==k )return 1;
    if(n==0)return 0;
    if(k==0)return 0;
    ll &ret = dp[n][k];
    if(ret != -1) return ret;
    ret = 0;
    ret += stirling(n-1,k)*(k);
    ret %= mod;
    ret += stirling(n-1,k-1);
    ret %= mod;
    return ret;
}
