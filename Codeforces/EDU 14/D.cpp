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


//int val;

//int dfs(int x, int par)
//{
////    debug(x,val,adj[x].size())
//    int k=INF;
//    if(res[x]==-1) k=x;
//
//    FOR(i,0,(int)adj[x].size()-1)
//    {
//        int v = adj[x][i];
//        if(v==par) continue;
//        //if(res[v]!=-1) continue;
//        //if(v>=x) continue;
//        k = dfs(v,x);
//
//    }
//
//    if(res[x]==-1)
//    {
//       k = min(k,x);
//    }
//    return k;
//}


vii adj;

int res[1000004];
int mp[1000004];
int a[1000004];

bitset <1000004> vis;

int bfs(int src)
{
    queue <int> q;
    q.push(src);
    vis.set(src);
    int k = INF;
    if(res[src]==-1) k=src;

    vi val,ind;

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        val.PB(a[u]);
        ind.PB(u);
        if(res[u]==-1) k = min(k,u);

        FOR(i,0,(int)adj[u].size()-1)
        {
            int v = adj[u][i];
            //if(v==u) continue;
            if(vis.test(v)==0)
            {
                q.push(v);
                vis.set(v);
            }
        }
    }
    sort(ALL(ind));
    sort(ALLR(val));
    FOR(i,0,(int)val.size()-1)
    {
        res[ind[i]]=val[i];
    }
    return k;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int n,m;
    while(~getII(n,m))
    {
        FOR(i,0,n-1)
        {
            int x;
            getI(x);
            a[i]=x;
            res[i]=x;
            mp[x]=i;
        }
        adj.assign(n+4, vi());
        FOR(ik,1,m)
        {
            int x,y;
            getII(x,y);
            x--;y--;
            adj[x].PB(y);
            adj[y].PB(x);
        }
        vis.reset();
        ROF(i,n,1)
        {
            if(vis.test(mp[i])==0) bfs(mp[i]);
        }

        FOR(i,0,n-1)
        {
            if(i) printf(" ");
            printf("%d",res[i]);
        }
        printf("\n");
    }

    return 0;
}



