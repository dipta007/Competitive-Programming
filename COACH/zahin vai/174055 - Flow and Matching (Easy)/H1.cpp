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
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
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


/// Min-cost Max-flow using SPFA (Shortest Path Faster Algorithm)
/// 0 Based indexed for directed weighted graphs (for undirected graphs, just add two directed edges)

namespace mcmf{
    const int MAX = 20010;
//    const long long INF = INF;

    int cap[MAX], flow[MAX], cost[MAX], dis[MAX];
    int n, m, s, t, Q[1000010], adj[MAX], link[MAX], last[MAX], from[MAX], visited[MAX];

    void init(int source, int sink, int nodes){
        m = 0, n = nodes, s = source, t = sink;
        for (int i = 0; i <= n; i++) last[i] = -1;
    }

    void addedge(int u, int v, int c, int w){
        adj[m] = v, cap[m] = c, flow[m] = 0, cost[m] = +w, link[m] = last[u], last[u] = m++;
        adj[m] = u, cap[m] = 0, flow[m] = 0, cost[m] = -w, link[m] = last[v], last[v] = m++;
    }

    bool spfa(){
        int i, j, x, f = 0, l = 0;
        for (i = 0; i <= n; i++) visited[i] = 0, dis[i] = INF;

        dis[s] = 0, Q[l++] = s;
        while (f < l){
            i = Q[f++];
            for (j = last[i]; j != -1; j = link[j]){
                if (flow[j] < cap[j]){
                    x = adj[j];
                    if (dis[x] > dis[i] + cost[j]){
                        dis[x] = dis[i] + cost[j], from[x] = j;
                        if (!visited[x]){
                            visited[x] = 1;
                            if (f && rand() & 7) Q[--f] = x;
                            else Q[l++] = x;
                        }
                    }
                }
            }
            visited[i] = 0;
        }
        return (dis[t] != INF);
    }

    pair <int, int> solve(){
        int i, j;
        int mincost = 0, maxflow = 0;

        while (spfa()){
            int aug = INF;
            for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i]){
                aug = min(aug, cap[j] - flow[j]);
            }
            for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i]){
                flow[j] += aug, flow[j ^ 1] -= aug;
            }

            /// change here as per the problem
            maxflow += aug, mincost += aug * dis[t];
        }
        return make_pair(mincost, maxflow);
    }
}

int in[104][104], out[104][104];
int a[104][104];


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int r,c;
        getII(r,c);
        FOR(i,0,r-1)
        {
            FOR(j,0,c-1)
            {
                getI(a[i][j]);
            }
        }

//        mcmf::init(r*c + r*c + 4);

        int rc = r*c;
        int ind = 1;
        FOR(i,0,r-1)
        {
            FOR(j,0,c-1)
            {
                in[i][j] = ind;
                out[i][j] = rc + ind;
                ind++;
            }
        }

        mcmf::init(0,rc+rc+2, rc+rc+4);

//        mcmf::init(rc+rc+4);

        FOR(i,0,r-1)
        {
            FOR(j,0,c-1)
            {
                if(i==0 && j==0) mcmf::addedge(in[i][j], out[i][j], 2, -a[i][j]);
                else if(i==r-1 && j==c-1) mcmf::addedge(in[i][j], out[i][j], 2, -a[i][j]);
                else mcmf::addedge(in[i][j], out[i][j], 1, -a[i][j]);

                int x = i;
                int y = j+1;
                if(x>=0 && y>=0 && x<r && y<c)
                {
                    mcmf::addedge(out[i][j], in[x][y], 1, 0);
                }
                x = i+1;
                y = j;
                if(x>=0 && y>=0 && x<r && y<c)
                {
                    mcmf::addedge(out[i][j], in[x][y], 1, 0);
                }
            }
        }

        int sink = rc+rc+2;
        mcmf::addedge(0, in[0][0], INF, 0);
        mcmf::addedge(out[r-1][c-1], sink, INF, 0);
        pii p = mcmf::solve();
//        int kk = mcmf::mincost(0, sink);

        int kk = p.ff;
        kk += a[0][0] + a[r-1][c-1];

        printf("Case %d: %d\n",ci, -1*kk);
    }

    return 0;
}




