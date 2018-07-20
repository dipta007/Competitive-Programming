#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
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

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

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
int t,n,m;

#define LOG 20
#define MAX 200010
namespace lca{
    long long sum[MAX];
    vector <int> ar[MAX], weight[MAX];
    int n, r, parent[MAX], depth[MAX], lg[MAX], dp[MAX][LOG], MX[MAX][LOG];
    int mx[MAX];

    void init(int nodes, int root){
        n = nodes, r = root, lg[0] = lg[1] = 0;
        for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
        for (int i = 0; i <= n; i++) ar[i].clear(), weight[i].clear();
    }

    void add_edge(int u, int v, int w){
        ar[u].push_back(v), weight[u].push_back(w);
        ar[v].push_back(u), weight[v].push_back(w);
    }

    int get(int a, int b){
        if (a == b) return 0;
        if (depth[a] < depth[b]) swap(a, b);

        int mx = 0;
        int diff = depth[a] - depth[b];
        for (int i = lg[diff]; i >= 0; i--){
            if ((depth[a] - (1 << i)) >= depth[b])
            {
                mx = max(mx, MX[a][i]);
                a = dp[a][i];
            }
        }
        trace(mx, a,b );
        if (a == b) return mx;

        for (int i = lg[depth[a]]; i >= 0; i--){
            if (dp[a][i] != dp[b][i]){
                mx = max(mx, MX[a][i]);
                mx = max(mx, MX[b][i]);
                trace(mx);
                a = dp[a][i];
                b = dp[b][i];
            }
        }

        if(a==b) return mx;
        mx = max(mx, MX[a][0]);
        mx = max(mx, MX[b][0]);
        return mx;
    }

    void dfs(int u, int p, int w){
        trace(u, p);
        int len = ar[u].size();
        parent[u] = p;
        mx[u] = w;
        for (int i = 0; i < len; i++){
            int v = ar[u][i];
            int w = weight[u][i];
            if (v != p){
                sum[v] = sum[u] + w;
                depth[v] = depth[u] + 1;
                dfs(v, u, w);
            }
        }
    }

    void build(){
        depth[r] = 0, sum[r] = 0;
        dfs(r, r, 0);

        for (int l = 0; l <= lg[n]; l++){
            for (int i = 0; i < n; i++){
                if (!l)
                {
                    dp[i][l] = parent[i];
                    MX[i][l] = mx[i];
                    trace(i, mx[i]);
                }
                else
                {
                    dp[i][l] = dp[dp[i][l - 1]][l - 1];
                    MX[i][l] = max(MX[i][l-1], MX[dp[i][l-1]][l-1]);
                }
            }
        }
    }
}

#define MAXN 100005
struct edge
{
	int u,v,w;
	bool operator < ( const edge& p ) const
	{
		return w < p.w;
	}
};
int pr[MAXN];
vector<edge>e;
int find(int r)
{
    if(pr[r]==r) return r;
    return pr[r]=find(pr[r]);
}
int mst(int n)
{
	sort(e.begin(),e.end());
	for(int i=0;i<=n;i++)pr[i]=i;

	int count=0,s=0;
	for(int i=0;i<(int)e.size();i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(u!=v)
		{
		    lca::add_edge(e[i].u, e[i].v, e[i].w);
			pr[u]=v;
			count++;
			s+=e[i].w;
			if(count==n-1) break;
		}
	}
	return s;
}


int main() {
    #ifdef dipta007
        READ("in.txt");
        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n,m;
        getII(n,m);
        lca::init(n, 0);
        e.clear();
        FOR(i,1,m)
        {
            edge ee;
            getIII(ee.u, ee.v, ee.w);
            ee.u--, ee.v--;
            e.push_back(ee);
        }

        mst(n);

        lca::build();

        int q;
        getI(q);
        printf("Case %d:\n", ci);
        FOR(tt,1,q)
        {
            int x, y;
            getII(x,y);
            x--, y--;
            printf("%d\n", lca::get(x,y));
        }
    }

    return 0;
}




