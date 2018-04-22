const int NX = 70 ;

ll dp[2][2][NX][NX];
int vis[2][2][NX][NX];
int lim, tt ;
vector < int > inp ;

ll DP( int pos, int isSmall,int isStart, int value)
{
    if( pos == lim ) return value ;

    ll &ret = dp[isSmall][isStart][pos][value];
    int &v = vis[isSmall][isStart][pos][value];
    if( v == tt ) return ret ;
    v = tt ;

    int ses = isSmall ? 9 : inp[pos];
    int i ;
    ret = 0 ;
    if( !isStart )  /// Started before
    {
        for ( i = 0 ; i <= ses ; i++ )
        {
            ret += DP( pos + 1, isSmall | i < inp[pos],0, (i == 0) + value );
        }
    }
    else /// Starting from this position
    {
        for ( i = 1 ; i <= ses ; i++ )
        {
            ret += DP( pos + 1, isSmall | i < inp[pos],0, (i == 0) + value );
        }
        ret += DP( pos + 1, 1,1, 0 );
    }
    return ret ;
}

ll Cal( ll x )
{
    if( x < 0 ) return 0 ;
    if( x <= 9 ) return 1 ;
    inp.clear();
    while( x )
    {
        inp.PB(x%10);
        x/=10;
    }
    reverse(inp.begin(),inp.end());
    lim = inp.size();
    tt++;
    return DP( 0, 0, 1, 0 );
}

