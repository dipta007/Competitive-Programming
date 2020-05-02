int SOD( int n )
{
    int res = 1;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < primes.size() && primes[i] <= sqrtn; i++ )
    {
        if ( n % primes[i] == 0 )
        {
            int tempSum = 1; //Contains value of (p^0+p^1+...p^a)
            int p = 1;
            while ( n % primes[i] == 0 )
            {
                n /= primes[i];
                p *= primes[i];
                tempSum += p;
            }
            sqrtn = sqrt ( n );
            res *= tempSum;
        }
    }
    if ( n != 1 )
    {
        res *= ( n + 1 ); //Need to multiply (p^0+p^1)
    }
    return res;
}
