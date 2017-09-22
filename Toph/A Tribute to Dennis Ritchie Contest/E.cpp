#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
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
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef dipta007
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


#define MAX 1000007
#define MOD 1000000007

ll fact[MAX], inv[MAX], inv2[MAX];

ll bigmod ( ll b, ll p, ll m ) {
    ll res = 1 % m, x = b % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}
ll modularInverse(int a, int m) {
    return bigmod(a, m-2, m);
}

void generate(){
    int i, j;
    /// generating fact
    fact[0] = 1;
    for (i = 1; i < MAX; i++) fact[i] = ((long long)i * fact[i - 1]) % MOD;
    /// generating inv fact
    inv[MAX - 1] = modularInverse(fact[MAX-1], MOD);
    for (i = MAX - 2; i >= 0; i--)
        inv[i] = ((long long)inv[i + 1] * (i + 1)) % MOD;

    inv2[1] = 1;
	for (i = 2; i < MAX; i++){
        inv2[i] = MOD - ((MOD / i) * (long long)inv2[MOD % i]) % MOD;
        if (inv2[i] < 0) inv2[i] += MOD;
	}
}

long long binomial(int n, int k){
    if (k > n) return 0;
    return (((long long)fact[n] * inv[k] % MOD) * inv[n - k]) % MOD;
}


struct data
{
    int n;
    int a[22];
};

bool cmp(const data &a, const data &b)
{
    FOR(i,0,a.n-1)
    {
        if(a.a[i] < b.a[i]) return true;
        if(a.a[i] > b.a[i]) return false;
    }
    return false;
}

data vd[104];
int tot;

bool check()
{
    int nn = vd[0].n;
    FOR(i,1,(int)tot-1)
    {
        FOR(j,0,nn-1)
        {
//            debug(i, j, vd[i].a[j] , vd[i-1].a[j])
            if(vd[i].a[j] < vd[i-1].a[j]) return false;
        }
    }
    return true;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    generate();

//    debug((NCR(4,2)*NCR(24,12))%MOD)

    int t;
    getI(t);
    FOR(ci,1,t)
    {
//        vd.clear();
        int n,k,m;
        getIII(n,k,m);
        tot = m;
        FOR(i,1,m-2)
        {
//            debug(i,n)
            data d;
            d.n = n;
            FOR(j,0,n-1)
            {
                getI(d.a[j]);
//                debug(j, d.a[j])
            }
//            debug(i)
            vd[i] = d;
            //vd.PB(d);
//            debug(i)
        }

        data d;
        d.n = n;
        FOR(i,0,n-1) d.a[i] = 1;
        vd[0]=d;
        FOR(i,0,n-1) d.a[i] = k;
        vd[m-1] = d;

//        debug("*")
        //sort(vd, vd+m, cmp);

//        debug(vd.size())

        printf("Case %d: ",ci);
        if(check()==0)
        {
            printf("0\n");
            continue;
        }

        ll res = 1;
        FOR(i,1,(int)tot-1)
        {
            int cnt = 0;
            FOR(j,0,n-1)
            {
                cnt += (vd[i].a[j] - vd[i-1].a[j]);
            }
//            debug(i, cnt)

            ll now = 1;
            FOR(j,0,n-1)
            {
                ll kk = (vd[i].a[j] - vd[i-1].a[j]);
                now *= binomial(cnt, kk);
                now %= MOD;
                cnt -= kk;
            }
            res *= now;
            res %= MOD;
        }
        printf("%lld\n",res);
    }

    return 0;
}



