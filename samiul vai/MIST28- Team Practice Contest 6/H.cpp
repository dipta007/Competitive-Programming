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

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
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

#ifdef dipta007
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
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

const int NX = 70 ;

ll dp[2][2][NX];
int vis[2][2][NX];
int lim, tt ;
vector < int > inp ;
vi vv;
ll b;

ll DP( int pos, int isSmall,int isStart)
{
    if( pos == lim ) return 1 ;
    ll &ret = dp[isSmall][isStart][pos];
    int &v = vis[isSmall][isStart][pos];
    if( v == tt ) return ret ;
    v = tt ;
    int ses = isSmall ? b-1 : inp[pos];
    int i ;
    ret = 0 ;
    if( !isStart )  // আগেই নাম্বার বসানো শুরু করে দিছি
        for ( i = 0 ; i < (int)vv.size() ; i++ )
        {
            if(vv[i]>ses) break;
            ret += DP( pos + 1, isSmall | vv[i] < inp[pos],0);
        }
    else
    {
        for ( i = 0 ; i <(int) vv.size() ; i++ )
        {
            if(vv[i]==0) continue;
            if(vv[i]>ses) break;
            ret += DP( pos + 1, isSmall | vv[i] < inp[pos],0);
        }
        ret += DP( pos + 1, 1,1);
    }
    return ret ;
}

ll Cal( ll x , ll b)
{
    inp.clear();
    while( x )
    {
        inp.PB(x%b);
        x/=b;
    }
    reverse(inp.begin(),inp.end()); // সুবিধার জন্য রিভারস করে নিচ্ছি , এইটা করতেই হবে
    lim = inp.size();
    tt++;
    return DP( 0, 0, 1 );    // শুধু ০ টা আলাদা এড করছি
}


int main()
{
#ifdef dipta007
    READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007

    ll d,h;
    tt =0;
    CLR(vis);
    while(~getLLL(d,h,b))
    {
        getchar();
        string st;
        getline(cin,st);
        vv.clear();
        if(d==-1 && d==h && h==b && st=="*") break;

        FOR(i,0,b-1)
        {
            if(st[i]=='S') vv.PB(i);
        }
        debug(vv.size())
        ll r1 = Cal(h,b);
        ll r2 = Cal(d-1,b);
        debug(r2,r1);
        printf("%lld\n",r1-r2);

    }

    return 0;
}



