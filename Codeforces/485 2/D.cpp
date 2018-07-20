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

int dist[104][100004];
vii adj;
int col[100004];
int dd[100004];
int k;

void bfs(int src)
{
    SET(dd);
    queue < int > q;
    q.push(src);
    dd[src] = 0;
    set < int > s;
    while(!q.empty())
    {
        int u = q.front(); q.pop();

        if(s.find(col[u]) == s.end())
            dist[col[u]][src] = dd[u];

        s.insert(col[u]);
        if(s.size() == k) return;

        for(auto v: adj[u])
        {
            if(dd[v] == -1)
            {
                dd[v] = dd[u] + 1;
                q.push(v);
            }
            else if(dd[v] > dd[u] + 1)
            {
                dd[v] = dd[u] + 1;
                q.push(v);
            }
        }
    }
}

void bfs(int n, int type)
{
    SET(dd);
    queue < int > q;
    FOR(i,1,n)
    {
        if(col[i] == type)
        {
            dist[type][i] = 0;
            q.push(i);
            dd[i] = 0;
        }
    }

    set < int > s;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        dist[type][u] = dd[u];

        for(auto v: adj[u])
        {
            if(dd[v] == -1)
            {
                dd[v] = dd[u] + 1;
                q.push(v);
            }
            else if(dd[v] > dd[u] + 1)
            {
                dd[v] = dd[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m,s;
    while(~getII(n,m))
    {
        getII(k,s);
        FOR(i,1,n) getI(col[i]);

        adj.assign(n+4, vi());
        FOR(i,1,m)
        {
            int x,y;
            getII(x,y);
            adj[x].PB(y);
            adj[y].PB(x);
        }

        FOR(i,1,k)
        {
            bfs(n, i);
        }

        FOR(i,1,n)
        {
            multiset < int > ss;
            FOR(j,1,k)
            {
                ss.insert(dist[j][i]);
            }


            int c = 0;
            int sum = 0;
            for(auto v: ss)
            {
                sum += v;
                c++;
                if(c == s) break;
            }

            if(i != 1) pf(" ");
            pf("%d",sum);
        }
        pf("\n");
    }

    return 0;
}


