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

#ifdef dipta
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

struct edge
{
    ll x,y,w;
};

const ll PINF = 6e18;
const ll NINF = -6e18;

vector <edge> ve;
ll dist[2004];
int dvis[2004];
ll tmpdst[2004];
int vis[2004];
int mark[2004];
vii adj;

void dfs(int u)
{
    mark[u]=1;
    dvis[u]=1;
    FOR(i,0,(int)adj[u].size()-1)
    {
        int v = adj[u][i];
        if(dvis[v]==0)
        {
            dfs(v);
        }
    }
}

void bellmanFord(int src,int n)
{

    int e = ve.size();
    CLR(dist);
    FOR(i,0,n)
    {
        dist[i]=PINF;
        vis[i]=0;
    }
    dist[src]=0;
    vis[src]=1;

    FOR(i,1,n-1)
    {
        FOR(j,0,e-1)
        {
            edge e = ve[j];
            ll u = e.x;
            ll v = e.y;
            ll weight = e.w;
//            debug(u,v,weight)
            dist[v] = min(dist[v], dist[u] == NINF ? NINF : dist[u]==PINF ? PINF : max(NINF, dist[u]+weight));
        }
    }

    FOR(i,1,n)
    {
        tmpdst[i] = dist[i];
    }
    CLR(dvis);
//    FOR(j,1,n-1)
    {
        FOR(i,0,e-1)
        {
            edge e = ve[i];
            ll u = e.x;
            ll v = e.y;
            ll weight = e.w;
            dist[v] = min(dist[v], dist[u] == NINF ? NINF : dist[u]==PINF ? PINF : max(NINF, dist[u]+weight));
//            if(dist[u]!=PINF && dist[u] == NINF ? NINF : dist[u]==PINF ? PINF : max(NINF, dist[u]+weight) < dist[v])
//            {
//                dist[v]=dist[u] == NINF ? NINF : dist[u]==PINF ? PINF : max(NINF, dist[u]+weight);
//                vis[v]=1;
//                debug(u,v)
//                mark[v]=1;
//                dfs(v);
//                /negetive
//            }
        }
    }

    FOR(i,1,n)
    {
        debug(tmpdst[i],dist[i])
        if(tmpdst[i]!=dist[i])
        {
            dfs(i);
            mark[i]=1;
        }
    }
}



int main() {
//    #ifdef dipta007
        READ("path.in");
        WRITE("path.out");
////    #endif // dipta007

    int n,m,s;
    while(~getIII(n,m,s))
    {
        ve.clear();
        adj.assign(n+4, vi());
        FOR(i,1,m)
        {
            ll x,y,z;
            getLLL(x,y,z);
            edge e;
            e.x = x;
            e.y = y;
            e.w = z;
            ve.PB(e);
            adj[x].PB(y);
        }
        CLR(mark);
        bellmanFord(s,n);
        CLR(vis);
        FOR(i,1,n)
        {
//            debug(i,mark[i])

            if(dist[i]==PINF) printf("*\n");
            else if(mark[i]==1 || dist[i]==NINF) printf("-\n");
            //else if(dist[i]==-2) printf("-\n");
            else printf("%lld\n",dist[i]);
        }
    }

    return 0;
}



