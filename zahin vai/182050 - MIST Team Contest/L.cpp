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

string p,t;
int dp[104][1000004];


int call(int i, int j)
{
    if(i>=p.size()) return 0;
    if(j>=t.size()) return (p.size()-i-1);

    int &ret = dp[i][j];
    if(ret!=-1) return ret;

    ret = INF;
    if(p[i] == t[j])
    {
        ret = min(ret, call(i+1, j+1));
    }
//    if(i==0)
//    {
//        ret = min(ret, call(i, j+1)); /// samne agai suru hbe
//    }
    ret = min(ret, 1 + call(i, j+1)); /// insertion
    ret = min(ret, 1 + call(i+1, j+1)); /// substitution
    ret = min(ret, 1 + call(i+1, j)); /// removal

    return ret;
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int m,n,k;
    while(cin >> m >> n >> k)
    {
        cin >> p >> t;


        FOR(i,0,m)
        {
            FOR(j,0,n)
            {
                dp[i][j] = INF;
            }
        }

        FOR(i,0,n-1)
        {
            if(p[0]==t[i]) dp[0][i] = 0;
            else dp[0][i] = 1;
        }

        FOR(i,1,m-1)
        {
            dp[i][0] = dp[i-1][0] + 1;
        }

        FOR(i,1,m-1)
        {
            FOR(j,1,n-1)
            {
                int &ret = dp[i][j];
                ret = INF;
                if(p[i]==t[j]) ret = min(ret, dp[i-1][j-1]);
                if(i==0) ret = min(ret, dp[i][j-1]);
                ret = min(ret, 1+ min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j])));
            }
        }

        FOR(i,0,n-1)
        {
            if(dp[m-1][i] <= k)
            {
                printf("S\n");
                return 0;
            }
        }
        printf("N\n");
    }

    return 0;
}



