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

#ifdef dipta00
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

//LCA with Sparse Table
struct LCA{
    static const int NMAX = 30004; // Must be atleast twice the number of nodes
    static const int WIDTH = 20;
    int F[NMAX+10], L[NMAX+10], lst, DD[NMAX+10];
    ll D[NMAX+10];
    int idx [NMAX+10][WIDTH+4];
    int id [NMAX+10][WIDTH+4];
    vector<pii> *G;
    int power[NMAX + 4];

    void pre() {
        int h = 2;
        int now = 1;
        power[0] = 0;
        for(int i=0; i<=NMAX; i++) {
            power[i] = now;
            if(i == h) {
                now = h;
                h *= 2;
            }
        }
    }
    void build(vector<pii> *G, int u){
        pre();
        memset(F, -1, sizeof(F));
        this->G=G;
        D[u]=lst=0;
        dfs(u, -1);
        for(int h=1; h<=20; h++)
        {
            for(int i=0; i+(1<<h)<NMAX; i++)
            {
                int x = id[i][h];
                if(x != -1) x =id[x][h];
                id[i][h+1]=x;

                int hh = h - 1;
                idx[i][h]=argmin(idx[i][hh], idx[i+(1<<hh)][hh]);
            }
        }
    }
    void dfs(int u, int par){
        id[u][0] = u;
        id[u][1] = par;
        idx[lst][0] = u;
        F[u]=L[u]=lst++;
        for(auto v: G[u]){
            if(F[v.ff]==-1){
                D[v.ff]=D[u]+v.ss;
                DD[v.ff] = DD[u] + 1;
                dfs(v.ff, u);
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
    ll dist(int u, int v){
        trace(u, v, D[u], D[v], get(u,v));
        return D[u]+D[v]-2*D[get(u, v)];
    }
    int distK(int u, int v){
        return DD[u]+DD[v]-2*DD[get(u, v)];
    }

    int afterKup(int u, int k) {
        k--;
        while(k != 0) {
            int h = power[k];
            u = id[u][h];
            k -= h;
            trace(u, h);
        }
        return u;
    }

    int kth(int u, int v, int k) {
        int root = get(u, v);
        int ud = distK(u, root);
        int vd = distK(v, root);
        int unodes = ud + 1;
        trace(u, v, k, ud, vd, unodes);

        if(k > unodes + vd) return v;
        if(k <= unodes) {
            return afterKup(u, k);
        }
        else {
            k -= unodes;
            vd -= k;
            vd++;
            return afterKup(v, vd);
        }
    }
    // Helper Functions
    int bitWidth(int x){return 31-__builtin_clz(x);}
    int argmin(int x, int y){return DD[x]<DD[y]?x:y;}
} lca;

vector < pii > adj[10004];


int main() {
    #ifdef dipta007
        READ("in.txt");
       WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        int n;
        cin >> n;
        FOR(i,0,n) adj[i].clear();
        FOR(i, 1, n-1)
        {
            int u,v,w;
            cin >> u >> v >> w;
            adj[u].PB( MP(v, w) );
            adj[v].PB( MP(u, w) );
        }

        lca.build(adj, 1);

        string st;
        cin >> st;

        while(st != "DONE") {
            int x, y;
            cin >> x >> y;
            if(st[0] == 'D') {
                cout << lca.dist(x, y) << endl;
            }
            else {
                int k;
                cin >> k;
                cout << lca.kth(x, y, k) << endl;
            }
            cin >> st;
        }

        cout << endl;
    }

    return 0;
}


