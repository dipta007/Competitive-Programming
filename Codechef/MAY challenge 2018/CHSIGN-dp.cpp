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
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
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
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    sf scanf
#define    pf printf
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define dipta00
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
///****************** template ends here ****************

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

ll a[100004];
ll cum[100004];
bool mark[100004];
int n;

ll dp[100004][4];
bool path[100004][4];
int vis[100004][4];
int tt;

ll call(int in, int last)
{
//    if(last > 2) last = 0;
    if(in > n) return 0;

    ll &ret = dp[in][last];
    if(vis[in][last] == tt) return ret;
    vis[in][last] = tt;

    if(last == 0 || last == 2) ret = a[in] + call(in+1, 0);
    else ret = a[in] + call(in+1, last+1);
    path[in][last] = 0;
    if(mark[in] == 1)
    {
        if(last == 0)
        {
            ll kk = -a[in] + call(in+1, 1);
            if(kk < ret)
            {
                ret = kk;
                path[in][last] = 1;
            }
        }
        else if(last==2)
        {
            ll now = -a[in-2] + a[in-1];
            if(now > a[in])
            {
                ll kk = -a[in] + call(in+1, 1);
                if(kk < ret)
                {
                    ret = kk;
                    path[in][last] = 1;
                }
            }
        }
    }

    return ret;
}

void callPrint(int in, int last)
{
    if(in > n) return;
    int now = path[in][last];

    if(now == 0)
    {
        if(last == 0 || last == 2) callPrint(in+1, 0);
        else callPrint(in+1, last+1);
    }
    else
    {
        a[in] *= -1;
        callPrint(in+1, 1);
    }
}

int main() {
    #ifdef dipta007
        READ("in.txt");
       WRITE("out2.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);

    CLR(vis);
    tt = 0;
    FOR(ci,1,t)
    {
        getI(n);
        cum[0] = 0;
        FOR(i,1,n)
        {
            getL(a[i]);
            cum[i] = cum[i-1] + a[i];
        }
        a[0] = a[n+1] = LLONG_MAX;

        CLR(mark);
        FOR(i,1,n)
        {
            if(a[i] < a[i-1] && a[i] < a[i+1] )
            {
                mark[i] = 1;
            }
        }

        tt ++ ;
        ll res = call(1,0);
        callPrint(1,0);

        FOR(i,1,n)
        {
            if(i != 1) pf(" ");
            pf("%lld",a[i]);
        }
        pf("\n");

    }

    return 0;
}



