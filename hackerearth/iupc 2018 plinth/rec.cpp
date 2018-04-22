#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)

#define    m_p(x, y) 	     make_pair(x,y)
#define    p_b(x)            push_back(x)

#define    rep(i,n)          for(int i=1;i<=n;i++)
#define    rep0(i,n)         for(int i=0;i<n;i++)
#define    FOR(i,L,R) 	     for(int i=(int)(L);i<=(int)(R);i++)
#define    ROF(i,L,R) 	     for(int i=(int)(L);i>=(int)(R);i--)

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))
#define    all(v)            v.begin(),v.end()

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    pis 	 pair< int, string >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int

#define    MOD   1000000007

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

ll bigmod(ll a,ll p,ll mod){ll ans=1;while(p){if(p&1)ans=ans*a%mod;a=a*a%mod;p>>=1;}return ans;}
ll power(ll x,ll n){if(n==0)return 1;else if(n%2==0){ll y=power(x,n/2);return y*y;}else return x*power(x,n-1);}


int bitOn(int N,int pos) {return N=N | (1<<pos);}
int bitOff(int N,int pos) {return N=N & ~(1<<pos);}
bool bitCheck(int N,int pos) {return (bool)(N & (1<<pos));}


//******************DELETE****************

#ifdef rafsan_rana
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;



///*******************************************************************************************

 ll fact[100005];

void f()
{

    fact[0]=1; fact[1]=1;
    for(ll i=1;i<=100003;i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=1000000007;
    }
}

ll mod = 1000000007;

ll mod(ll x)
{
    return ((x % mod) + mod) %mod;
}


int main()
{
    // ios_base::sync_with_stdio(0);    cin.tie(0);

#ifdef rafsan_rana

    // READ("in.txt");
     //WRITE("in.txt");

#endif // rafsan_rana


    int t;
    getI(t);
    f();
    while(t--)
    {
        ll n,m;
        getLL(m,n);

        if(m==1)
        {
            printf("%lld\n",fact[n]);
            continue;
        }
        else if(n<m)
        {
            printf("0\n");
            continue;
        }

       // debug(m,n);

        ll res=fact[n]-fact[n-1];
        debug(res);
        for(int i=3;i<=m;i++)
        {
            res=res-fact[n-1];
        }

        printf("%lld\n",res);
    }




    return 0;

}
