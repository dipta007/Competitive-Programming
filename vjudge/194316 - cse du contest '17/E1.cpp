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


vii adj;

#define Left 1
#define Right 2

int vis[504];
int col[504];

int check2(int u)
{
    for(auto v: adj[u])
    {
        if(vis[v]==0) return 0;
    }
    return 1;
}

int check(int u)
{
//    CLR(vis);

    vis[u] = 1;
    for(auto v: adj[u])
    {
        vis[v]=1;
    }

    int flg = 1;
    for(auto v: adj[u])
    {
        flg = flg && check2(v);
    }
    return flg;
}

void dfs(int u, int cl)
{
    vis[u] = 1;
    col[u] = cl;

    for(auto v: adj[u])
    {
        if(vis[v]==0) dfs(v, !cl);
    }
}

int main() {
    #ifdef dipta007
        READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n,m;
        getII(n,m);
        adj.assign(n+4, vi());

        FOR(i,1,m)
        {
            int x,y;
            getII(x,y);
            adj[x].PB(y);
            adj[y].PB(x);
        }

        CLR(vis);
        int kk = check(1);

        /// alice nilo
        if(kk==1)
        {
            int flg = 1;
            FOR(i,1,n)
            {
                if(vis[i]==0)
                {
                    flg = flg && check2(i);
                }
            }
            if(flg) printf("YES\n");
            else printf("NO\n");
        }
        /// bob nilo
        else
        {
//            debug("*")
            int flg = 1;
            for(auto v: adj[1])
            {
                int now = check(v);
                if(now==0)
                {
                    flg = 0;
                }
                break;
            }
            if(flg==0)
            {
                printf("NO\n");
                continue;
            }

            vis[1] = 0;
            FOR(i,1,n)
            {
                if(vis[i]==0)
                {
                    flg = flg && check2(i);
                }
            }
            if(flg) printf("YES\n");
            else printf("NO\n");
        }

//        debug(kuhn.match(n));
//
//        CLR(vis);
//        dfs(1,0);
//
//        FOR(i,1,n) trace(i, col[i]);
//
//
////        kuhn.clear(n+4);
//
//        FOR(i,1,n)
//        {
//            if(col[i]==0)
//            {
//                for(auto v: adj[i])
//                {
//                    if(col[v]==1)
//                    {
//                        trace(i,v);
//                        kuhn.adj[i].PB(v);
////                        kuhn.adj[v].PB(i);
//                    }
//                }
//            }
//        }
//
//        if(kuhn.match(n) <= 1) printf("YES\n");
//        else printf("NO\n");
    }

    return 0;
}




