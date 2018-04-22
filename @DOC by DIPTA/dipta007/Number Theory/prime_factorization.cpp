vector<int>factors;
void factorize( int n )
{
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < primes.size() && primes[i] <= sqrtn; i++ )
    {
        if ( n % primes[i] == 0 )
        {
            while ( n % primes[i] == 0 )
            {
                n /= primes[i];
                factors.push_back(primes[i]);
            }
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 )
    {
        factors.push_back(n);
    }
}
