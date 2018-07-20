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
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************

ll dp[1200][1200];

ll call(int beg, int end)
{
    if(beg > end) return 1;

    ll &ret = dp[beg][end];
    if(ret!=-1) return ret;

    ret = 0;
    FOR(i, beg, end)
    {
        int lft = call(beg, i-1);
        int rgt = call(i+1, end);
        debug(beg, end, i)
        ret += max(lft, rgt);
    }
    return ret;
}

ll mod = 100000007;
ll catalan[2000];
ll catalanDP(unsigned int n)
{

    // Initialize first two values in table
    catalan[0] = catalan[1] = 1;

    // Fill entries in catalan[] using recursive formula
    for (int i=2; i<=n; i++)
    {
        catalan[i] = 0;
        for (int j=0; j<i; j++){
            catalan[i] += catalan[j] * catalan[i-j-1];
            catalan[i] %= mod;
        }
    }

    // Return last entry
    return catalan[n];
}


int main() {
    ///check for 0 or -1 if input not specified
    #ifdef dipta007
        READ("in.txt");
        WRITE("out.txt");
    #endif // mamun
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector < ll > v;
    FOR(i,2,100000)
    {
        ll c = i;
        while(c <= 10000000000LL)
        {
            c *= i;
            v.PB(c);
        }
    }
    sort(ALL(v));

//    FOR(i,0,(int)v.size()-1)
//    {
////        7955591200 7956047966
//        if(v[i] >= 7955591200LL && v[i] <= 7956047966LL)
//        {
//            debug(i)
//        }
//    }
    UNIQUE(v);

    int t;
    cin >> t;
    catalanDP(1900);
    FOR(ci, 1 ,t)
    {
        ll l,r;
        cin >> l >> r;

        if(l > r) swap(l,r);

        int lft = lower_bound(ALL(v), l) - v.begin();
        int rgt = lower_bound(ALL(v), r) - v.begin();
        if(binary_search(ALL(v), r)==false) rgt--;
        int len = rgt - lft + 1;
//        debug(len, catalan(len))
        cout << "Case " << ci << ": ";
        if(len==0)
        {
            cout << "0" << endl;
            continue;
        }
        cout << catalan[len] << endl;
    }

    return 0;
}
