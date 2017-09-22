#define M 10004
bool marked[M];
vector <int> primes;

int meu[M];

void sieve(int n) {
	primes.push_back(2);
	for (long long i = 3; i * i <= n; i += 2) {
		if (marked[i] == 0) {
			for (long long j = i * i; j <= n; j += i + i) {
				marked[j] = 1;
		}
    }
  }
  for(int i=4;i<=n;i+=2) marked[i]=1;
  for(int i=3;i<=n;i+=2)
  {
      if(marked[i]==0) primes.push_back(i);
  }
}

void calculateMobius(int n)
{
    sieve(M-2);
    for(int i=1;i<=n;i++)
    {
        meu[i]=1;
    }
    for(int k=2;k<=n;k++)
    {
        int i = k;
        if(marked[i]==0)
        {
            for(long long j=i;j<=n; j+=i)
            {
                meu[j] *= -1;
            }
            long long kk = i*1LL*i;
            for(long long j=kk;j<=n;j+=kk)
            {
                meu[(int)j] = 0;
            }
        }
    }
}

/*
Mobius function is a function which has one of the following values:
mu(x) = -1 : square free number with odd prime factors
mu(x) = 1  : square free number with even prime factors
mu(x) = 0  : not a square free number

In order to generate mu() from 1-N, we need to generate all primes between 1-N
*/

void sieve( int n ); ///generates prime from 1-N

int mobius[SIZE+10];
void mobiusCalc( int n ) {
    FOR(i,1,n) mobius[i] = 1; ///Initially all value is 1

    ///Mark all numbers with square factors 0
    int sqrtn = sqrt ( n );
    FOR(i,0,SZ(prime)-1) {
        if ( prime[i] > sqrtn ) break;

        int x = prime[i] * prime[i];
        for ( int j = x; j <= n; j += x ) mobius[j] = 0;
    }

    ///For each prime, all it's multiple gets multiplied by -1
    FOR(i,0,SZ(prime)-1) {
        for ( int j = prime[i]; j <= n; j += prime[i] ) mobius[j] *= -1;
    }
}

/*Application of Mobius function
It is mainly used with inclusion exclusion, when items are the first K primes.
Complexity is improved from 2^k to NloglogN
*/

