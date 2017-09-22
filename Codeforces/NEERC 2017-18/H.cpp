#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)          freopen(f, "w", stdout)
#define    MP(x, y)          make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)        for (int i = L; i <= R; i++)
#define    ROF(i,L,R)        for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
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
#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef dipta007
     #define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<< v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************

int n;
ll a[100004];
map <int, ll> dp[100004][2];

ll call(int in, int now, int prev)
{
    if(in>=n)
    {
        return 0;
    }
    if(dp[in][now].find(prev) != dp[in][now].end()) return dp[in][now][prev];

    ll ret = INF;
    if(now == 1)
    {
        if(a[in] > prev) ret = min(ret, call(in+1, 1, a[in]));
        else
        {
            int kk = prev + 1;
            ret = min(ret, (ll)kk - a[in] + call(in+1, 1, kk));
            if(a[in]!= prev) ret = min(ret, call(in+1, 0, a[in]));

            if(in!=n-1) ret = min(ret, a[in+1] + 1 - a[in] + call(in+1, 0, a[in+1]+1));
        }
    }
    else
    {
        if(a[in]<prev) ret = min(ret, call(in+1, 0, a[in]));

        if(in!=n-1) ret = min(ret, a[in+1] + 1 - a[in] + call(in+1, 0, a[in+1]+1));
    }

    return ret;
}


int main() {
    ///check for 0 or -1 if input not specified
    #ifdef dipta007
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);

//    int n;
    while(~getI(n))
    {
        FOR(i,0,n-1)
        {
            getL(a[i]);
        }

        FOR(i,0,n)
        {
            dp[i][0].clear();
            dp[i][1].clear();
        }

//        int rgt[n];
//        CLR(rgt);
//        rgt[n-1] = 1;
//        ROF(i,n-2,0)
//        {
//            if(a[i] > a[i+1])
//            {
////                debug(i)
//                rgt[i] = rgt[i+1];
//            }
//            else break;
//        }

        ll cnt = call(0,1,0);
//        FOR(i,0,n-2)
//        {
//            if(a[i] > a[i+1]  && rgt[i+1]==1) break;
////            debug(i, rgt[i])
//            if(a[i] >= a[i+1])
//            {
//                ll kk = a[i] + 1;
//                cnt += (ll)(kk - a[i+1]);
//                debug(i, kk-a[i+1])
//                a[i+1] = kk;
//
////                ROF(j,i-1, 0)
////                {
////                    if(a[i] <= a[i+1])
////                    {
////                        cnt +=
////                    }
////                }
//            }
//        }

        printf("%lld\n",cnt);
    }

    return 0;
}
