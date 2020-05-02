#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())

template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef mamun
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///****************** template ends here ****************
int t,n,m;

ll arr[100005];
ll maxi = 12*1e12;
ll fun(ll tme)
{
    if(tme < 0) tme += maxi;
    tme %= (maxi);
    ll tot = 0;
    rep(i,n)
    {
        ll lagbe = tme - arr[i];
        if(lagbe < 0)
            lagbe += maxi;
        tot += lagbe;
    }
    return tot;
}
void printans(ll ans)
{
    ll anss = ans % (ll)(1e6);
    ans /= 1e6;
    ll ansm = ans % (ll)(1e6);
    ans /= 1e6;
    printf("%lld %lld %lld\n",ans,ansm,anss);
}
ll pre[100005];
ll suf[100005];
int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
    READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    while(~getI(n))
    {
//        int flag = 1;
        rep(i,n)
        {
            int h,m,s;
            getIII(h,m,s);
            ll tot = 0;
            tot += h*1e6;
            tot += m;
            tot *= 1e6;
            tot += s;
            arr[i] = tot;
        }
        sort(arr+1,arr+1+n);
        ll ans = 1e18;
        ll cur = 0;
        arr[0] = arr[1];
        arr[n+1] = arr[n];
        rep(i,n)
        {
            ll dif = arr[i] - arr[i-1];
            cur += dif*(i-1);
            pre[i] = cur;
        }
        cur = 0;
        ROF(i,n,1)
        {
            ll dif = arr[i] - arr[i+1];
            if(dif < 0)dif += maxi;
            cur -= dif * (n-i);
            suf[i] = cur;
        }
        rep(i,n)
            ans = min(ans,pre[i]+suf[i]);
        printans(ans);
    }


    return 0;
}

