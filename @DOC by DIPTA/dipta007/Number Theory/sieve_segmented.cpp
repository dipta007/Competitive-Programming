int segSieve(int a,int b)
{
    if(a==1) a++;

    int sqrtn = sqrt(b);

    CLR(marked);

    for(int i=0; i<primes.size() && primes[i]<=sqrtn; i++)
    {
        ll p = primes[i];
        ll j = p*p;

        ///If j is smaller than a, then shift it inside of segment [a,b]
        if ( j < a ) j = ( ( a + p - 1 ) / p ) * p;


        for( ; j<=b ; j+=p)
        {
            marked[j-a]=1;
        }
    }

    int res=0;
    for(int i=a; i<=b; i++)
    {
        if(marked[i-a]==0) res++;
    }
    return res;
}

