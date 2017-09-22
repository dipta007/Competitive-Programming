ncr[0][0] = 1 ;
int limncr = 10 ;
for (int i = 1 ; i <= limncr ; i++)
    for (int j = 0 ; j <= limncr ; j++)
    {
        if ( j > i ) ncr[i][j] = 0 ;
        else if ( j == i || j == 0 ) ncr[i][j] = 1 ;
        else ncr [i][j] = ncr[i-1][j - 1] + ncr[i-1][j] ;
    }
/// ncr *****************
long long nCr(long long m, long long n)
{
    long long ans = 1;
    for (long long i = 1; i <= n; i++)
    {
        ans = ans * (m - i + 1) / i;

    }
    return ans;
}

///ncr
#define MOD 1000003

typedef pair<ll, ll> pll;
#define x first
#define y second

pll extended_euclid(ll a, ll b)
{
    if (b == 0)
    {
        return pll(1, 0);
    }
    else
    {
        pll d = extended_euclid(b, a % b);
        return pll(d.y, d.x - d.y * (a / b));
    }
}

ll modular_Inverse(ll a, ll n)
{
    pll ret = extended_euclid(a, n);
    return ((ret.x % n) + n) % n;
}


ll N,K;
ll fact[1000000];

ll NCR(ll N,ll R)
{
    ll top = fact[N];
    ll dwn = (fact[R]*fact[N-R])%MOD;
    dwn = modular_Inverse(dwn,MOD);
    return (top*dwn)%MOD;
}

int main()
{
    fact[0] = 1;
    for(ll i = 1; i<1000000; i++)
    {
        fact[i] = (fact[i-1]*i)%MOD;
    }
}

/// dp
ll nCr(ll n,ll r)
{
    if(r==1)
        return n;
    if(n==r || r==0)
        return 1;
    ll &ret=dp[n][r];
    if(ret!=-1)
        return ret;
    ret=(nCr(n-1,r-1)%mod+nCr(n-1,r)%mod)%mod;
    return ret;
}
