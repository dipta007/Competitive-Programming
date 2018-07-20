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
int comp;
vii adj;
int dist[2][100004];

int bfs(int src, int in)
{
    dist[in][src] = 0;
    queue < int > q;
    q.push(src);

    int ind, mx = -1, chain = 0;
    comp = 1;
    while(!q.empty())
    {
        int u = q.front(); q.pop();

        chain = max(chain, dist[in][u] + 1);
        if(dist[in][u] > mx)
        {
            mx = dist[in][u];
            ind = u;
        }
        FOR(i,0,(int)adj[u].size()-1)
        {
            int v = adj[u][i];
            if(dist[in][v] == -1)
            {
                comp++;
                dist[in][v] = dist[in][u] + 1;
                q.push(v);
            }
            else if(dist[in][v] > dist[in][u] + 1)
            {
                dist[in][v] = dist[in][u] + 1;
                q.push(v);
            }
        }
    }

    if(in == 0) return chain;
    else return ind;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n, m;
        getII(n,m);

        adj.assign(n+4, vi());
        FOR(i,1,m)
        {
            int x,y;
            getII(x,y);
            adj[x].PB(y);
            adj[y].PB(x);
        }

        SET(dist);
        int mxSz = -1, mxChain = -1;

        vector < pii > v;
        FOR(i,1,n)
        {
            if(dist[0][i] == -1)
            {
                int furthest = bfs(i, 1);
                int chainSz = bfs(furthest, 0);
                mxSz = max(mxSz, comp);
                mxChain = max(mxChain, chainSz);

                v.PB(MP(chainSz, comp));
                trace(i, furthest, chainSz, comp, mxSz, mxChain);
            }
        }

        sort(ALLR(v));

        int q;
        getI(q);
        pf("Case %d:\n", ci);
        FOR(i,1,q)
        {
            int k;
            getI(k);
            if(k > mxSz) pf("impossible\n");
            else
            {
                debug(k, mxChain)
                if(k <= mxChain) pf("%d\n", k-1);
                else
                {
                    FOR(i,0,(int)v.size()-1)
                    {
                        if(v[i].ss >= k)
                        {
                            pf("%d\n", v[i].ff-1 + ((k - v[i].ff) * 2) );
                            break;
                        }
                    }
                }

            }
        }
    }


    return 0;
}


