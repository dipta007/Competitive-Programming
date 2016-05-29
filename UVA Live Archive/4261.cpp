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
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< ll, ll >
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

pii add(pii a, pii b)
{
    pii c;
    c.ff = a.ff + b.ff;
    c.ss = a.ss + b.ss;
    return c;
}

pii dp[1004][204];
int vis[1004][204],pri[1004][204];
int n,a[1004];

pii call(int in, int prev)
{
    if(in>=n) return pii(0,0);

    pii &ret = dp[in][prev];
    if(vis[in][prev]==1) return ret;
    vis[in][prev]=1;

    ret = pii(INF,INF);
    int sum=0;
    FOR(i,in,n-1)
    {
        sum += a[i];
        ll x = (ll)sum;
        pii k = add( pii((x-100)*(x-100), 1) , call(i+1, a[i]) );
        if(k.ff<ret.ff)
        {
            ret = k;
            pri[in][prev]=i;
        }
        else if(k.ff==ret.ff && k.ss<ret.ss)
        {
            ret = k;
            pri[in][prev]=i;
        }
    }
    return ret;
}

vector <int> res;

void print(int in, int prev)
{
    if(in>=n) return;

    int k = pri[in][prev];
    res.PB(k+1);
    print(k+1,a[k]);
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        WRITE("out.txt");
    #endif // dipta007

    int f=0;
    while(~getI(n))
    {
        if(n==0) break;
        if(f) printf("\n");
        f=1;

        FOR(i,0,n-1)
        {
            getI(a[i]);
            //if(i) a[i] += a[i-1];
        }
        CLR(vis);
        res.clear();
        res.PB(0);
        pii resi = call(0,0);
        print(0,0);
        printf("p=%lld\n",resi.ff);
        int i=0;
        while(i<res.size())
        {
            for(int k = 1; k<=30 && i<res.size();k++)
            {
                printf(" ");
                printf("%d",res[i++]);
            }
            printf("\n");
        }
    }

    return 0;
}



