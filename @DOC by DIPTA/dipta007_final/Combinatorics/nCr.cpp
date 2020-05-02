ncr[0][0] = 1 ;
int limncr = 10 ;
for (int i = 1 ; i <= limncr ; i++)
    for (int j = 0 ; j <= limncr ; j++)
    {
        if ( j > i )
            ncr[i][j] = 0 ;
        else if ( j == i || j == 0 ) ncr[i][j] = 1 ;
        else
            ncr [i][j] = ncr[i-1][j - 1] + ncr[i-1][j] ;
    }

/// ncr avoiding overflow
ll nCr(long long n, long long m)
{
    ll ans = 1;
    ll cur = 2;
    FOR(i,m+1,n)
    {
        ans *= (ll)i;
        if(cur<=n-m && ans%cur == 0)
            ans /= cur,cur++;
    }
    return ans;
}

ll nCr(ll n, ll m){
   if(m > n - m) m = n - m;
   ll ans = 1, cou = m;
   while(cou --){
        ans *= n --;
        while(ans % m == 0 && m > 1)
            ans /= m --;
   }
   return ans;
}

/// Use this if you need nCr too much in every tc
#define MAX 1000005
#define MOD 1000000007

int fact[MAX], inv[MAX], inv2[MAX];

ll bigmod ( ll b, ll p, ll m )
{
    ll res = 1 % m, x = b % m;
    while ( p )
    {
        if ( p & 1 )
            res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}
ll modularInverse(int a, int m)
{
    return bigmod(a, m-2, m);
}

void generate()
{
    int i, j;
    /// generating fact
    fact[0] = 1;
    for (i = 1; i < MAX; i++)
        fact[i] = ((long long)i * fact[i - 1]) % MOD;
    /// generating inv fact
    inv[MAX - 1] = modularInverse(fact[MAX-1], MOD);
    for (i = MAX - 2; i >= 0; i--)
        inv[i] = ((long long)inv[i + 1] * (i + 1)) % MOD;

    inv2[1] = 1;
    for (i = 2; i < MAX; i++)
    {
        inv2[i] = MOD - ((MOD / i) * (long long)inv2[MOD % i]) % MOD;
        if (inv2[i] < 0)
            inv2[i] += MOD;
    }
}

long long binomial(int n, int k)
{
    if (k > n)
        return 0;
    return (((long long)fact[n] * inv[k] % MOD) * inv[n - k]) % MOD;
}



/***** generalized lucas for mod < 1e6 and mod not prime **************/
/**
Procedure:
    1. Call bionomial(n, r, mod)
**/

#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
ll Pow(ll  b,ll  p)
{
    ll  ret = 1;
    while(p)
    {
        if(p&1)
            ret *= b ;
        p >>= (1LL), b *= b ;
    }
    return ret ;
}

pair<ll,pair<ll,ll > > eea(ll a, ll b)
{
    ll gcd,x=0,y=1;
    ll u=1, v=0, m, n, q, r;
    gcd = b;
    while (a!=0)
    {
        q=gcd/a;
        r=gcd%a;
        m=x-u*q;
        n=y-v*q;
        gcd=a;
        a=r;
        x=u;
        y=v;
        u=m;
        v=n;
    }
    return make_pair(gcd,make_pair(x,y));
}

ll BigMod(ll B,ll P,ll M)
{
    ll R=1;    //compute b^p%m
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return (ll)R;
}
ll modInverse_prime(ll B,ll P)
{
    return BigMod(B,P-1,P);
}
ll modInverse_relativePrime(ll B,ll P)
{
    return eea(B,P).second.first;
}
ll mod;
ll fact[1000005];
vector<pii >primeDivisors;
vector<ll >L;
vector<ll>N ;
vector<ll>R ;
vector<ll>M ;
vector<ll>N_js ;
vector<ll>M_js ;
vector<ll>R_js;
vector<ll >e;
void generatefactorial(ll p)
{
    fact[0] = fact[1 ]= 1;
    ll i;
    for (i = 2; i < mod; i++)
    {
        if(i%p==0)
            fact[i] = fact[i-1];
        else
            fact[i] =  (fact[i - 1] * i)%mod;
    }
}

vector<ll >v;
vector<ll > tobase(ll a,ll b)
{
    v.clear();
    while(a)
    {
        v.PB(a%b);
        a /= b;
    }
    return v;
}
vector<ll >tmp;
vector<ll > compute_js(vector<ll >v,ll p,ll q)
{
    ll len = v.size();
    tmp.clear();
    tmp.resize(len);
    FOR(i,0,len-1)
    {
        ll a = 0,P = 1;
        for(ll j = i; j<len && j < i+q ; j++)
        {
            a += (v[j]*P);
            P *= p;
        }
        tmp[i] = a;
    }
    return tmp;
}
vector<ll > computeE(ll len,vector<ll >M,vector<ll >R,ll p)
{
    ll m = M.size(),r = R.size(),c = 0;
    tmp.clear();
    tmp.resize(len);
    forab(i,m,len-1) M.PB(0);
    forab(i,r,len-1) R.PB(0);
    FOR(i,0,len-1)
    {
        c += M[i];
        c += R[i];
        c /= p;
        tmp[i] = c;
    }
    per(i,len-1) tmp[i] = tmp[i] + tmp[i+1];
    return tmp;
}
ll generelize_lucas_theoram(ll n,ll r,ll p,ll q)
{
    ll m = (n-r);
    N = tobase(n,p);
    R = tobase(m,p);
    M = tobase(r,p);
    N_js = compute_js(N,p,q);
    M_js = compute_js(M,p,q);
    R_js = compute_js(R,p,q);
    ll n_len = N.size(), m_len = M.size(), r_len = R.size();
    e =computeE(n_len,R,M,p);
    ll ans = 1;
    mod = Pow(p,q);
    generatefactorial(p);
    rep(i,e[0]) ans = (ans*p)%mod;
    rep(i,n_len) ans = (ans*fact[N_js[i]%mod])%mod;
    rep(i,m_len) ans = (ans*modInverse_relativePrime(fact[M_js[i]%mod],mod))%mod;
    rep(i,r_len) ans = (ans*modInverse_relativePrime(fact[R_js[i]%mod],mod))%mod;
    if((p != 2 || q<3) && (q<=e.size() && e[q-1]%2))
        ans = (-1*ans)%mod;
    return ans<0?ans+mod:ans;
}

void generate_primeDivisors(ll n)
{
    primeDivisors.clear();

    ll cnt = 0 ;

    while(n % 2 == 0 )
    {
        n>>=1, cnt++;
    }

    if(cnt)
        primeDivisors.push_back( pii(2,cnt) );

    int sq = sqrt(n) + 1 ;

    for( int i = 3 ; i <= sq ; i += 2 )
    {
        cnt = 0 ;
        while(n % i == 0 )
            n /= i, cnt++ ;
        if(cnt)
            primeDivisors.push_back( pii(i,cnt) );
    }

    if(n > 1 )
        primeDivisors.push_back( pii(n,1) ) ;
}


ll Chinese_Remainder_Theorem(ll m)
{
    int i = 0;
    ll ans = 0;
    forstl(it,primeDivisors)
    {
        ll p = Pow((*it).first,(*it).second);
        //cout << p << endl;
        ll e = ((m/p) * modInverse_relativePrime(m/p,p))%m;
        ans = (ans + (L[i] * e)%m)%m;
        i++;
    }
    //cout << ans << endl;
    return ans<0?ans+m:ans;
}
ll binomial(ll n,ll r, ll m)
{
    /// if mod doesnot change it can be called one time only
    generate_primeDivisors(m);
    L.clear();
    forstl(it,primeDivisors)
    {
        L.PB(generelize_lucas_theoram(n,r,(*it).first,(*it).second));
    }
    return Chinese_Remainder_Theorem(m);
}

ll nPk()
{
    for (i = 0; i < MAX; i++){
        for (j = 0; j <= i; j++){
            if (!j) nPk[i][j] = 1;
            else nPk[i][j] = (nPk[i][j - 1] * (i - j + 1)) % MOD;
        }
    }
}
