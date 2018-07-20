#include <bits/stdc++.h>
using namespace std;

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
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
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    sf scanf
#define    pf printf
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

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

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************


int t, n, m;

#define MAXN 100005
struct edge
{
	ll u,v,w;
	bool operator < ( const edge& p ) const
	{
		return w < p.w;
	}
};
int pr[MAXN];
vector<edge>e;
int inmst[3004][3004];
vector < vector < pii > > adj, mstG;

int find(int r)
{
    if(pr[r]==r) return r;
    return pr[r]=find(pr[r]);
}
ll mst(int n)
{
	sort(e.begin(),e.end());
	CLR(inmst);

	for(int i=0;i<=n;i++)pr[i]=i;

	mstG.assign(n+4, vector < pii > ());

	ll count=0,s=0;
	for(int i=0;i<(int)e.size();i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(u!=v)
		{
		    mstG[e[i].u].PB( MP(e[i].v, e[i].w));
		    mstG[e[i].v].PB( MP(e[i].u, e[i].w));

		    inmst[e[i].u][e[i].v] = 1;
		    inmst[e[i].v][e[i].u] = 1;

			pr[u]=v;
			count++;
			s+=e[i].w;
			if(count==n-1) break;
		}
	}
	return s;
}

ll alternative[3004][3004];
vi tour;
int vis[3004];

void dfs(int u, int par, int vv)
{
    if(vis[u] || u == vv) return;
    vis[u] = 1;
    tour.PB(u);
    for(auto v: mstG[u])
    {
        trace(u, v.ff, par, vv);
        if(v.ff != par)
        {
            dfs(v.ff, u, vv);
        }
    }
}

void solve(int n)
{
    FOR(i,0,n) FOR(j,0,n) alternative[i][j] = INF;
    FOR(u,0, n-1)
    {
        for(auto v: mstG[u])
        {
            tour.clear();
            CLR(vis);
            dfs(v.ff, -1, u);

            FOR(i, 0, (int)tour.size() - 1)
            {
                int uu = tour[i];
                trace(u, v.ff, uu);
                for(auto p: adj[uu])
                {
                    int vv = p.ss;
                    ll ww = p.ff;


                    if(uu == u && vv == v.ff) continue;
                    if(uu == v.ff && vv == u) continue;
                    if(vis[vv]) continue;

                    trace(vv, ww);
                    alternative[u][v.ff] = min(alternative[u][v.ff], ww);
                    alternative[v.ff][u] = min(alternative[v.ff][u], ww);
                    break;
                }
            }
        }
    }
}

ll G[3004][3004];


int main() {
    #ifdef dipta007
//        READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m;
    while(~getII(n,m))
    {
        trace("sadsad", n, m);
        if(!n && !m) break;

        adj.assign(n+4, vector < pii > ());
        e.clear();
        CLR(G);

        FOR(i,1,m)
        {
            int u,v,w;
            getIII(u,v,w);

            adj[u].PB(MP(w,v));
            adj[v].PB(MP(w,u));

            edge ee;
            ee.u = u, ee.v = v, ee.w = w;
            e.PB(ee);

            G[u][v] = G[v][u] = w;
        }

        FOR(i,0,n-1) sort(ALL(adj[i]));

        ll now = mst(n);
        solve(n);
        trace(now);

        int q;
        getI(q);

        ll sum = 0;
        FOR(i,1,q)
        {
            ll u,v,w;
            getLLL(u,v,w);

            if(inmst[u][v] == 0)
            {
                sum += now;
            }
            else
            {
                trace(G[u][v], w, alternative[u][v]);
                ll kk = min(now - G[u][v] + w, now - G[u][v] + alternative[u][v]);
                sum += kk;
            }

            debug(sum)
        }

        pf("%.4f\n", (double)sum / q);
    }

    return 0;
}


