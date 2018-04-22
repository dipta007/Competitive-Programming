/**
Procedure:
    1. Call sieve()
    2. Call trailing_zero_of_factorial_base()
**/
vector< pair<int,int> >factors;
void factorize( int n )
{
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( sieve[n] == 0 ) break; // optimization
        if ( n % prime[i] == 0 ) {
                int cc=0;
            while ( n % prime[i] == 0 ) {
                cc++;
                n /= prime[i];
            }
            factors.push_back(make_pair(prime[i],cc));
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 ) {
        factors.push_back(make_pair(n,1));
    }

}
///http://blog.forthright48.com/2015/08/number-of-trailing-zeroes-of-factorial.html
int  trailing_zero_of_factorial_base (int n, int base)
{
    int temp,ans=INT_MAX,temp2;

    factorize(base);
    pair <int , int > p;

    for(int i=0;i<factors.size(); i++ )
    {
        temp=n;
        p=factors[i];
        int div = p.first;
        int cc=0;
        while(temp/div>0)
        {
            cc+=temp/div;
            div*=p.first;
        }

        ans=min(ans,cc/p.second);
    }
    return ans;
}
