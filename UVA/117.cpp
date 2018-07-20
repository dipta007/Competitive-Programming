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

vector < pii > adj[30];
int vis[30][30];
int deg[30];

int dj(int src, int dest)
{
    int dist[30];
    SET(dist);
    dist[src] = 0;
    priority_queue < pii, vector < pii >, greater< pii > > pq;
    pq.push(MP(0, src));
    while(!pq.empty())
    {
        pii p = pq.top(); pq.pop();
        int u = p.ss;
        if(u == dest) return p.ff;

        for(auto vp: adj[u])
        {
            int v = vp.ff;
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + vp.ss;
                pq.push(MP(dist[v], v));
            }
            else if(dist[v] > dist[u] + vp.ss)
            {
                dist[v] = dist[u] + vp.ss;
                pq.push(MP(dist[v], v));
            }
        }
    }
}

int res;

void euler(int u, int par = -1)
{
    trace(u, res);
    FOR(i,0,(int)adj[u].size()-1)
    {
        int v = adj[u][i].ff;
        int w = adj[u][i].ss;
        if(vis[u][v] == 0)
        {
            vis[u][v] = 1;
            vis[v][u] = 1;
            res += w;
            euler(v, u);
        }
    }
}

int main() {
    #ifdef dipta007
        READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    string st;
    while(cin >> st)
    {
        int o1, o2;
        o1 = o2 = -1;
        CLR(deg);
        FOR(i,0,25) adj[i].clear();
        CLR(vis);

        while(st != "deadend")
        {
            int u = st[0] - 'a';
            int v = st.back() - 'a';
            int w = st.size();

            adj[u].PB(MP(v,w));
            adj[v].PB(MP(u,w));

            deg[u]++;
            deg[v]++;

            cin >> st;
        }

        FOR(i,0,25)
        {
            debug(i, deg[i])
            if(deg[i]%2 == 1)
            {
                if(o1 != -1) o2 = i;
                else o1 = i;
            }
        }

        res = 0;
        if(o1 != -1)
        {
            int w = dj(o1, o2);
            res = w;
            adj[o1].PB(MP(o2, 0));
            adj[o2].PB(MP(o1, 0));
        }

        trace(o1, o2, res);
        FOR(i,0,25) if(deg[i]) { euler(i); break; }

        cout << res << endl;
    }

    return 0;
}


