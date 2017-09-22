#define M 1000005
bool marked[M];
vector<ll> primes;
vector<ll> mainfactor;
vector<int> countfactor;
vector<ll>allfactor;
void sieve(ll n)
{
    primes.push_back(2);
    ll i;
    for (i = 3; i * i <= n; i += 2)
    {
        if (marked[i] == 0)
        {
            primes.push_back(i);
            for (ll j = i * i; j <= n; j += i + i)
            {
                marked[j] = 1;
            }
        }
    }
    while(i<=n)
    {
        if(marked[i]==0)primes.push_back(i);
        i+=2;
    }
}
void divisor ( ll n )
{
    ll sqrtn = sqrt ( n );
    for ( ll i = 0; i < primes.size() && (ll)primes[i] <= sqrtn; i++ )
    {
        if ( n % (ll)primes[i] == 0 )
        {
            int p = 0; /*Counter for power of prime*/
            while ( n % (ll)primes[i] == 0 )
            {
                n /= (ll)primes[i];
                p++;
            }
            sqrtn = sqrt ( n );
            mainfactor.push_back((ll)primes[i]);
            countfactor.push_back(p);
        }
    }
    if ( n != 1 )
    {
        mainfactor.push_back((ll)n);
        countfactor.push_back(1);
    }
}
void alldivisor(int idx,ll num)
{
    if(idx==mainfactor.size())
    {
        allfactor.push_back(num);
        return;
    }
    alldivisor(idx+1,num);
//    alldivisor(idx+1,mainfactor[idx]);
    for(int i=countfactor[idx];i;i--)
    {
        alldivisor(idx+1,num*mainfactor[idx]);
        num*=mainfactor[idx];
    }

}
