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

int total;
int dp[7][7][7][140];
int pri[7][7][7][140];
int ta,tb,tc;
int vis[5][5][5];
int aa[] = {0,0, 1,2, 1,2};
int bb[] = {1,2, 0,0, 2,1};
int cc[] = {2,1, 2,1, 0,0};

int call(int a, int b, int c, int tot)
{
    if(a>ta || b>tb|| c>tc) return 0;
    if(a<1 || b<1 || c<1) return 0;
    if(vis[a][b][c]) return 0;
    vis[a][b][c]=1;
    if(tot==total)
    {
        return 1;
    }

    int ret=0;
    FOR(i,0,11)
    {
        if(i<=5) ret  = call(a+aa[i], b+bb[i], c+cc[i], tot+1);
        else ret  = call(a-aa[i-6], b-bb[i-6], c-cc[i-6], tot+1);
        if(ret)
        {
            pri[a][b][c][tot]=i;
            return ret;
        }
    }
    vis[a][b][c]=0;
    return ret;
}

void callPrint(int a, int b, int c, int tot)
{
    printf("%d %d %d\n",a,b,c);
    if(tot==total)
    {
        return;
    }

    int kk = pri[a][b][c][tot];
    if(kk<=5) callPrint(a+aa[kk], b+bb[kk], c+cc[kk], tot+1);
    else callPrint(a-aa[kk-6], b-bb[kk-6], c-cc[kk-6], tot+1);
}

int main() {
//        READ("knight.in");
//        WRITE("knight.out");
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int a,b,c;
    while(~getIII(a,b,c))
    {
        ta=a, tb=b, tc=c;
        SET(dp);
        CLR(vis);
        total = a*b*c;
        int kk = call(1,1,1,1);
        if(kk)
        {
            printf("YES\n");
            callPrint(1,1,1,1);
        }
        else printf("NO\n");
    }

    return 0;
}



