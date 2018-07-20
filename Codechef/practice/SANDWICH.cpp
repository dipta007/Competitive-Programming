//#include <algorithm>
//#include <bitset>
//#include <cassert>
//#include <cctype>
//#include <climits>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <fstream>
//#include <iostream>
//#include <iomanip>
//#include <iterator>
//#include <list>
//#include <map>
//#include <numeric>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <string>
//#include <utility>
//#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getF(n)           scanf("%lf",&n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    ranL(a, b)         ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define    ranI(a, b)         ((((ll)rand() * rand()) % ((b) - (a) + 1)) + (a))
#define    ranF(a, b)         (((double)rand()/RAND_MAX)*((b) - (a)) + (a))
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    ff 	              first
#define    ss 	              second
#define    sf                 scanf
#define    pf                 printf
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector < int >     vi;
typedef    vector < vi >      vii;
typedef    pair < int, int>   pii;
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
#else
    #define debug(args...)  /// Just strip off all debug tokens
    #define trace(...) ///yeeeee
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const double PI = 2.0 * acos(0.0);

ll MIN() { return INF; }
template <typename T, typename... Args >
inline T MIN(T a, Args... args) { return min(a, (T)MIN(args...)); }

ll MAX() { return -INF; }
template <typename T, typename... Args >
inline T MAX(T a, Args... args) { return max(a, (T)MAX(args...)); }

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

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
        ll e = ((m/p) * modInverse_relativePrime(m/p,p))%m;
        ans = (ans + (L[i] * e)%m)%m;
        i++;
    }
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


int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        ll n, k, m;
        cin >> n >> k >> m;
        ll r;
        r = (n/k) + (n%k != 0);

        cout << r << " " << binomial(r*k - n + r - 1, r - 1, m) << endl;
    }

    return 0;
}


