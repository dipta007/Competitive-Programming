/**
Procedure:
    1. Call sieve()
    2. Call NOD(n) to find the divisor of n
**** Number of divisors can be maximum n ^ (1/3)
**/
int NOD ( int n )
{
    int sqrtn = sqrt ( n );
    int res = 1;
    for ( int i = 0; i < primes.size() && primes[i] <= sqrtn; i++ )
    {
        if ( n % primes[i] == 0 )
        {
            int p = 0; /*Counter for power of primes*/
            while ( n % primes[i] == 0 )
            {
                n /= primes[i];
                p++;
            }
            sqrtn = sqrt ( n );
            p++;/*Increase it by one at end*/
            res *= p; /*Multiply with answer*/
        }
    }
    if ( n != 1 )
    {
        res *= 2; /*Remaining prime has power p^1. So multiply with 2*/
    }
    return res;
}
