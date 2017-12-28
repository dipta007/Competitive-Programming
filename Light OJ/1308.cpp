
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

#define ARTNODE 10010
int cut[ARTNODE];

class ArticulationPoint {
    int disc[ARTNODE]; ///Discovery time of nodes
    int low[ARTNODE]; ///Lowest back edge extension
    int col[ARTNODE]; ///Color for marking node

    int cnt; ///Timer
    int cc; ///Color
    int root; ///Root of tree

    void tarjan ( int s, int p ) {
        disc[s] = low[s] = cnt++;
        col[s] = cc + 1;

        int child = 0; ///Needed for root only
        int art = 0;

        for ( int i = 0; i < adj[s].size(); ++i ) {

            int t = adj[s][i];
            if ( t == p ) continue; ///Don't go to parent

            if ( col[t] <= cc ) { ///New node. Discovery.
                child++;

                tarjan ( t, s );
                low[s]=min(low[s],low[t]); ///Update back edge extension for S

                if ( low[t] >= disc[s] ) { ///Back edge of T did not go above S
                    art++; ///S is articulation point for T
                }
            }
            else if ( col[t] == cc + 1 ) { ///Back Edge
                low[s]=min(low[s],disc[t]);
            }
        }

        if ( ( s == root && child > 1 ) || ( s != root && art ) ) {
            ///Edit in this block
            cut[s] = 1;
        }
    }

public:

    vector<int> adj[ARTNODE];

    void clear ( int n ) {
        cc += 3; ///cc is now 0. cc+1 is 1
        for (int i = 0; i <= n; i++ ) {
            adj[i].clear();
        }
    }

    void findArt( int n, int start = 0 ) {
        for ( int i = start; i <= n; i++ ) {
            if ( col[i] <= cc ) {
                root = i;
                tarjan ( i, -1 );
            }
        }
    }
}art;

int vis[ARTNODE];
vii adj;
ull nways, cuts, cnt, ans;
int tt;

void dfs(int u, int par)
{
    vis[u] = 1;
    cnt++;

    FOR(i, 0, (int)adj[u].size()-1)
    {
        int v = adj[u][i];

        if(vis[v]==0 && !cut[v])
        {
            dfs(v,u);
        }
        else if(vis[v]!=tt && cut[v])
        {
            cuts++;
            vis[v] = tt;
        }
    }

    if(par==-1) cuts += cut[u];
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);

    tt = 0;
    FOR(ci,1,t)
    {
        int n,m;
        getII(n,m);
        adj.assign(n+4, vi());
        art.clear(n+4);

        FOR(i,1,m)
        {
            int u,v;
            getII(u,v);
            art.adj[u].PB(v);
            art.adj[v].PB(u);

            adj[u].PB(v);
            adj[v].PB(u);
        }

        CLR(cut);
        art.findArt(n);
        CLR(vis);

        ans = 0;
        nways = 1;
        FOR(i,0,n-1)
        {
            if(!cut[i] && vis[i]==0)
            {
                tt++;
                cnt = cuts = 0;
                dfs(i, -1);

                debug(i, cuts, cnt)
                if(cuts < 2)
                {
                    ans ++;
                    nways *= cnt;
                }
            }
        }

        if(ans==1)
        {
            nways = (n*(n-1))/2;
            ans++;
        }

        printf("Case %d: %llu %llu\n",ci, ans, nways);
    }

    return 0;
}


