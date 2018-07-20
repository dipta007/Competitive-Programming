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
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    sf scanf
#define    pf printf
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define dipta00
#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
#else
    #define debug(args...)  /// Just strip off all debug tokens
    #define trace(...) ///yeeeee
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out


#define MAXN 100005
struct edge
{
	int u,v,w;
	bool operator < ( const edge& p ) const
	{
		return w > p.w;
	}
};
int pr[MAXN];
vector<edge>e;
vector < vector < pii > > adj;

int find(int r)
{
    if(pr[r]==r) return r;
    return pr[r]=find(pr[r]);
}
int mst(int n)
{
	sort(e.begin(),e.end());
	for(int i=1;i<=n;i++)pr[i]=i;

	int count=0,s=0;
	for(int i=0;i<(int)e.size();i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);
		int w = e[i].w;
		if(u!=v)
		{
		    int uu = e[i].u;
		    int vv = e[i].v;

		    adj[uu].PB(MP(vv,w));
		    adj[vv].PB(MP(uu,w));

//		    trace(uu, vv, w);
			pr[u]=v;
			count++;
			s+=e[i].w;
			if(count==n-1) break;
		}
	}
	return s;
}

//LCA with Sparse Table
struct LCA{
    static const int NMAX = 200100; // Must be atleast twice the number of nodes
    static const int WIDTH = 20;
    ll F[NMAX+10], L[NMAX+10], D[NMAX+10], lst;
    int idx [NMAX+10][WIDTH+2];
    vector< vector < pii > > G;
    void build(vector< vector < pii > > &G, int u){
        memset(F, -1, sizeof(F));
        this->G=G;
        D[u]=lst=0;
        dfs(u);
        for(int h=0; h<bitWidth(NMAX); h++)
            for(int i=0; i+(1<<h)<NMAX; i++)
                idx[i][h+1]=argmin(idx[i][h], idx[i+(1<<h)][h]);
    }
    void dfs(int u){
        idx[lst][0] = u;
        F[u]=L[u]=lst++;
        for(auto v: G[u]){
            if(F[v.ff]==-1){
                D[v.ff]=D[u]+v.ss;
                dfs(v.ff);
                idx[lst][0] = u;
                L[u]=lst++;
            }
        }
    }
    int get(int u, int v){
        int x = min(F[u], F[v]), y = max(L[u], L[v]);
        if(x == y) return u;
        if(x >  y) swap(x, y);
        int h = bitWidth(y - x);
        return argmin(idx[x][h], idx[y - (1<<h)][h]);
    }
    ll dist(int u, int v){return D[u]+D[v]-2*D[get(u, v)];}
    // Helper Functions
    int bitWidth(int x){return 31-__builtin_clz(x);}
    int argmin(int x, int y){return D[x]<D[y]?x:y;}
}lca;

bool vis[1004];
int dist[1004][1004];

int dfs(int u, int src, int mx)
{
    vis[u] = 1;

//    trace(src, u, mx);
    dist[src][u] = mx;


    for(auto v: adj[u])
    {
        if(vis[v.ff] == 0)
        {
            dfs(v.ff, src, min(mx, v.ss));
        }
    }
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);

    FOR(ci,1,t)
    {
        int n;
        getI(n);

        e.clear();

        int a[n+4][n+4];
        FOR(i,1,n)
        {
            FOR(j,1,n)
            {

                edge ee;
                getI(ee.w);
                a[i][j] = ee.w;
                ee.u = i;
                ee.v = j;
                e.push_back(ee);
            }
        }

        adj.assign(n+4, vector < pii >());
        mst(n);
//        lca.build(adj, 1);

        FOR(i,1,n)
        {
            CLR(vis);
            dfs(i,i,INF);
        }

//        FOR(i,1,n)
//        {
//            FOR(j,1,n) cout << dist[i][j] << " ";
//            cout << endl;
//        }

        ll res = 0;
        FOR(i,1,n)
        {
            FOR(j,1,n)
            {
                if(i == j) continue;
                ll now = dist[i][j];
                debug(i, j, now, a[i][j])
                res = res + (ll)(now - a[i][j]);
            }
        }
        pf("%lld\n", res);
    }

    return 0;
}


