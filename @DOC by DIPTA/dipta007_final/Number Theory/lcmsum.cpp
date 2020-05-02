ll res[1000010];
ll phi[1000010];

void precal( int n )
{
    ///Calculate phi from 1 to n using sieve
    FOR(i,1,n) phi[i] = i;
    FOR(i,2,n)
    {
        if ( phi[i] == i )
        {
            for ( int j = i; j <= n; j += i )
            {
                phi[j] /= i;
                phi[j] *= i - 1;
            }
        }
    }
    ///Calculate partial result using sieve
    ///For each divisor d of n, add phi(d)*d to result array
    FOR(i,1,n)
    {
        for ( int j = i; j <= n; j += i )
        {
            res[j] += ( i * phi[i] );
        }
    }
}

int main ()
{
    precal( 1000000 );
    ll n;
    scanf ( "%lld", &n );

    ///We already have partial result in res[n]
    ll ans = res[n] + 1;
    ans *= n;
    ans /= 2;

    printf ( "%lld\n", ans );
}
