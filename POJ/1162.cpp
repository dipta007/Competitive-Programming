//#include <algorithm>
//#include <bitset>
//#include <cassert>
//#include <cctype>
//#include <climits>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <fstream>
//#include <iostream>
//#include <iomanip>
//#include <iterator>
//#include <list>
//#include <map>
//#include <numeric>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <string>
//#include <utility>
//#include <vector>
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

#define LOG 20
#define MAX 100010
namespace lca{
    long long sum[MAX];
    vector <int> ar[MAX], weight[MAX];
    int n, r, parent[MAX], depth[MAX], lg[MAX], dp[MAX][LOG];
    int MX[MAX][LOG], MN[MAX][LOG], Wx[MAX], Wn[MAX];

    void init(int nodes, int root){
        n = nodes, r = root, lg[0] = lg[1] = 0;
        for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
        for (int i = 0; i <= n; i++) ar[i].clear(), weight[i].clear();
    }

    void add_edge(int u, int v, int w){
        ar[u].push_back(v), weight[u].push_back(w);
        ar[v].push_back(u), weight[v].push_back(w);
    }

    pii get(int a, int b){
        if (a == b) return MP(0,0);
        if (depth[a] < depth[b]) swap(a, b);

        int mx = 0, mn = INF;

        int diff = depth[a] - depth[b];
        for (int i = lg[diff]; i >= 0; i--){
            if ((depth[a] - (1 << i)) >= depth[b])
            {
                mx = max(mx, MX[a][i]);
                mn = min(mn, MN[a][i]);
                trace(a, MN[a][i], dp[a][i], i);
                a = dp[a][i];
            }
        }
        if (a == b) return MP(mx, mn);
        trace("sd");

        for (int i = lg[depth[a]]; i >= 0; i--){
            if (dp[a][i] != dp[b][i]){
                mx = max(mx, MX[a][i]);
                mn = min(mn, MN[a][i]);
                mx = max(mx, MX[b][i]);
                mn = min(mn, MN[b][i]);
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        if(a==b) return MP(mx, mn);

        mx = max(mx, MX[a][0]);
        mn = min(mn, MN[a][0]);
        mx = max(mx, MX[b][0]);
        mn = min(mn, MN[b][0]);

        return MP(mx, mn);
    }

    void dfs(int u, int p, int w){
        int len = ar[u].size();
        parent[u] = p;
        if(w == 0)
        {
            Wx[u] = 0;
            Wn[u] = INF;
        }
        else
        {
            Wx[u] = w;
            Wn[u] = w;
        }
        trace(u, Wx[u], Wn[u]);
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
                    MX[i][l] = Wx[i];
                    MN[i][l] = Wn[i];

                    trace(i, l, MX[i][l], MN[i][l]);
                }
                else
                {
                    dp[i][l] = dp[dp[i][l - 1]][l - 1];
                    MX[i][l] = max(MX[i][l-1], MX[dp[i][l-1]][l-1]);
                    MN[i][l] = min(MN[i][l-1], MN[dp[i][l-1]][l-1]);
                    trace(i, l, MX[i][l], MN[i][l], dp[i][l]);
                }
            }
        }
    }
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n;
        getI(n);
        lca::init(n, 0);
        FOR(i,1,n-1)
        {
            int u,v,w;
            getIII(u,v,w);
            u--, v--;
            lca::add_edge(u,v,w);
        }

        lca::build();

        int q;
        getI(q);
        pf("Case %d:\n", ci);
        FOR(i,1,q)
        {
            int x,y;
            getII(x,y);
            x--, y--;
            pii res = lca::get(x, y);
            pf("%d %d\n", res.ss, res.ff);
        }
    }

    return 0;
}


