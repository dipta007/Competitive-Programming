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

int n;
ll a[200004];
bool vis[200004];
ll res[200004];
vii adj;


void dfs(int u, ll gc, ll small)
{
    vis[u] = 1;
    //if(small!=-1)
    //{
//    sob = gcd(sob, )
    ll now = gcd(gc, (ll)a[u]); /// ekhn er ta k nie gcd
    ll tmp = gcd(gc, (ll)small); /// ager ta k nie, ekhn er ta k bad die
    if(now > tmp)
    {
        gc = now;
        small = min(small, (ll)a[u]);
    }
    else if(tmp > now)
    {
        gc = tmp;
        small = a[u];
    }
    else
    {
        gc = now;
        small = min(small, (ll)a[u]);
    }
    //}
//    gc = gcd(gc, (ll)a[u]);
    debug(u,gc)
    res[u] = gc;

    FOR(i,0,(int)adj[u].size()-1)
    {
        int v = adj[u][i];
        if(vis[v]==0)
        {
            dfs(v, gc, small);
        }
    }
}

//void dfs(int u, ll gc, ll small, ll sob)
//{
//    vis[u] = 1;
//
//    sob = gcd(sob, (ll)a[u]);           /// sob nie gcd
//    ll now = gcd(gc, (ll)a[u]);     /// ekhn er ta k nie gcd
//    ll tmp = gcd(gc, (ll)small);    /// ager ta k nie, ekhn er ta k bad die
//
//    gc = max(sob, max(now, tmp));
//    small = min((ll)a[u], small);
//
//    res[u] = gc;
//
//    FOR(i,0,(int)adj[u].size()-1)
//    {
//        int v = adj[u][i];
//        if(vis[v]==0)
//        {
//            dfs(v, gc, small, sob);
//        }
//    }
//}

void dfs(int u, ll gc, ll small, ll sob)
{
    vis[u] = 1;

    if(a[u] < small)
    {
        gc = gcd(gc, small);
        small = a[u];
    }
    else
    {
        gc = gcd(gc, a[u]);
    }
    sob = gcd(sob, a[u]);

//    sob = gcd(sob, (ll)a[u]);           /// sob nie gcd
//    ll now = gcd(gc, (ll)a[u]);     /// ekhn er ta k nie gcd
//    ll tmp = gcd(gc, (ll)small);    /// ager ta k nie, ekhn er ta k bad die

//    gc = max(sob, max(now, tmp));
//    small = min((ll)a[u], small);

    res[u] = max(gc, sob);
    debug(u, gc, sob, small)

    FOR(i,0,(int)adj[u].size()-1)
    {
        int v = adj[u][i];
        if(vis[v]==0)
        {
            dfs(v, gc, small, sob);
        }
    }
}

void dfs(int u, ll gc)
{
    vis[u] = 1;

    if(gc!=0) gc = gcd(gc, (ll)a[u]);
    else gc = a[u];
    res[u] = max(res[u], gc);

    FOR(i,0,(int)adj[u].size()-1)
    {
        int v = adj[u][i];
        if(vis[v]==0)
        {
            dfs(v, gc);
        }
    }
}


int main()
{
#ifdef dipta007
    //READ("in.txt");
//        WRITE("out.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    while(~getI(n))
    {
        FOR(i,1,n)
        {
            getL(a[i]);
        }

        adj.assign(n+4, vi());
        FOR(i,1,n-1)
        {
            int x,y;
            getII(x,y);
            adj[x].PB(y);
            adj[y].PB(x);
        }

        CLR(vis);
        dfs(1, a[1], a[1], a[1]);

        CLR(vis);
        a[1] = 0;
        dfs(1, a[1]);

        FOR(i,1,n)
        {
            if(i!=1) printf(" ");
            printf("%lld",res[i]);
        }
        printf("\n");
    }

    return 0;
}



