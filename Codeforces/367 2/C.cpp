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
#define    iseq(a,b)          (fabs(a-b)<EPS)
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

int n,c[100004];
vector <string> vs[2];

ll dp[100004][2];
bool visited[100004][2];

vector <string> v;

ll long_long_max = 9223372036854775807L;
ll infll = 100000000000000L;

ll call(int in, int rev)
{
    //debug(in)
    if(in>=n)
    {
        FOR(i,1,n-1)
        {
            if(v[i]<v[i-1])
            {
                return infll;
            }
        }
        return 0;
    }

    ll &ret = dp[in][rev];
    if(visited[in][rev]==1) return ret;

    ll res = long_long_max;

    v.PB(vs[0][in]);
    res = min( res, call(in+1,0) );
    v.pop_back();

    v.PB(vs[1][in]);
    res = min( res, (ll)c[in] + call(in+1,1) );
    v.pop_back();

    visited[in][rev]=1;
    return ret = res;
}

ll call1(int in, int rev, string st)
{
    //debug(in)
    if(in>=n)
    {
        return 0;
    }

    ll &ret = dp[in][rev];
    if(visited[in][rev]==1) return ret;

    ll res = infll;

    if(in==0)
    {
        res = min( res, call1(in+1, 0, vs[0][in]) );
        res = min( res, (ll)c[in]+call1(in+1, 1, vs[1][in]) );

        visited[in][rev]=1;
        return ret = res;
    }
    if(vs[0][in]>=st)
    {
        res = min( res, call1(in+1, 0, vs[0][in]) );
    }
    if(vs[1][in]>=st)
    {
        res = min( res, (ll)c[in]+call1(in+1, 1, vs[1][in]) );
    }

    visited[in][rev]=1;
    return ret = res;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    while(~getI(n))
    {
        FOR(i,0,n-1)
        {
            getI(c[i]);
        }
        getchar();
        vs[0].clear();
        vs[1].clear();
        v.clear();
        FOR(i,0,n-1)
        {
            string st;
            getline(cin,st);
            vs[0].PB(st);
            reverse(ALL(st));
            vs[1].PB(st); ///ulta ta 1 e
        }
        CLR(visited);
        //debug(LONG_LONG_MAX);
        ll res = call1(0,0, vs[0][0]);
        if(res>=infll) res=-1;
        printf("%lld\n",res);
    }

    return 0;
}



