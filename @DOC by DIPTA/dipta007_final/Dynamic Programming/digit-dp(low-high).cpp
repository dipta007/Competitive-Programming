int dp[20][2][2][220];
int vis[20][2][2][220];
vi A, B;
int tt, lim;

int call(int pos, int high_flag, int low_flag, int sum) {

    int &ret = dp[pos][high_flag][low_flag][sum];
    if (pos == n) return ret = 1;

    int &v = vis[pos][high_flag][low_flag][sum];
    if (v == tt) return ret;
    v = tt;

    int lo = low_flag ? A[pos] : 0;
    int hi = high_flag ? B[pos] : 9;
    ret = 0;
    for (int i = lo; i <= hi; i++) {
        ret += call(pos+1, high_flag&(i==hi), low_flag&(i==lo), sum+i);
    }

    return ret;
}

ll Cal( ll l, ll r )
{
    /// Give predefined conditions if needed
//    if(l < 0) return 0;
    A.clear();
    B.clear();
    while( l )
    {
        A.PB(l%10);
        l/=10;
    }
    while(r)
    {
        B.PB(r%10);
        r/=10;
    }
    while(A.size() != B.size())
    {
        if(A.size() < B.size()) A.PB(0);
        else B.PB(0);
    }

    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());

    lim = A.size();
    tt++;
    return DP( 0, 1,  1, 0 );
}

