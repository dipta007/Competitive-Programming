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

int absurb(ll c)
{
    while(c%10==0)
    {
        c/=10;
    }
    int cnt=0,flg=0;
    if(c%10==5) flg=1;
    while(c)
    {
        c/=10;
        cnt++;
    }
    if(flg) return 2*cnt-1;
    else return 2*cnt;
}
int cabs;

int dp[12][2][2][2][12][12][2];
int vis[12][2][2][2][12][12][2];
int lim, tt ;
int got;
vector < int > ia, ib;

int call(int in, int isSmall, int isBig, int isStart, int digit,int zero, int d)
{
    if(got) return 1;
    if(in==lim)
    {
        int abss;
        int a = digit-zero;
        if(d) abss=2*a-1;
        else abss=2*a;
        if(abss<cabs)
        {
            got=1;
            return 1;
        }
        return 0;
    }
    int &ret = dp[in][isSmall][isBig][isStart][digit][zero][d];
    int &v = vis[in][isSmall][isBig][isStart][digit][zero][d];
    if(v==tt) return ret;
    v=tt;

    int suru = isBig ? 0 : ia[in];
    int sesh = isSmall ? 9 : ib[in];
    //debug(in, suru, sesh)

    ret = 0;
    if(isStart==0)
    {
        for(int i = suru; i<=sesh; i++)
        {
            int kk = call(in+1, isSmall | i<ib[in], isBig | i>ia[in], 0, digit+1, i==0?zero+1:0, (d && i==0) || (i==5));
            if(kk==1)
            {
                ret=1;
                break;
            }
            //ebug(in,i,ret)
        }
    }
    else ///
    {
        for(int i = max(suru,1); i<=sesh; i++)
        {
            int kk = call(in+1, isSmall | i<ib[in], isBig | i>ia[in], 0, digit+1 ,0, i==5);
            if(kk==1)
            {
                ret=1;
                break;
            }
//            ret = max(ret , (ll)i * call(in+1, isSmall | i<ib[in], isBig | i>ia[in], 0));
        }
        if(ia[in]==0)
        {
            int kk = call(in+1, 1, 0, 1, 0, 0, 0);
            if(kk==1) ret=1;
        }
    }
    return ret;
}

int Cal( ll a, ll b )
{
//    if( x < 0 ) return 0 ;
//    if( x <= 9 ) return 9 ;
    ia.clear();
    ib.clear();
    while( a )
    {
        ia.PB(a%10);
        a/=10;
    }
    while( b )
    {
        ib.PB(b%10);
        b/=10;
    }
    lim = max(ia.size(),ib.size());
    while(ia.size()<lim) ia.PB(0);
    while(ib.size()<lim) ib.PB(0);
    reverse(ALL(ia));
    reverse(ALL(ib));
    tt++;
    return call( 0, 0, 0, 1, 0, 0, 0 );    // শুধু ০ টা আলাদা এড করছি
    //print( 0, 0, 0, 1, "" );
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    CLR(vis);
    tt=0;
    getI(t);
    FOR(ci,1,t)
    {
        int c;
        getI(c);
        cabs = absurb(c);
        //debug(cabs)

        ll a = (ll)ceil((double)c*0.95);
        ll b = (ll)floor((double)c*1.05);
        debug(a,b)
        got=0;
        int res = Cal(a, b);
        if(got) printf("absurd\n");
        else printf("not absurd\n");
    }

    return 0;
}



