int dp[20][2][220];
int visited[20][2][220];
vi inp;
int tt;

int call(int pos, int high_flag, int sum) {

    int &ret = dp[pos][high_flag][sum];
    if (pos == n) return ret = 1;
    int &v = visited[pos][high_flag][sum];
    if (v == tt) return ret;
    v = tt;

    int lo = 0;
    int hi = high_flag ? inp[pos] : 9;

    ret = 0;
    for (int i = lo; i <= hi; i++) {
        ret += call(pos+1, high_flag&(i==hi), sum+i);
    }

    return ret;
}

ll Cal( ll x )
{
    /// Give predefined conditions if needed
//    if( x < 0 ) return 0 ;
    inp.clear();
    while( x )
    {
        inp.PB(x%10);
        x/=10;
    }
    reverse(inp.begin(),inp.end());
    lim = inp.size();
    tt++;
    return DP( 0, 1,  0 );
}
