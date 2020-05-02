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

//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getF(n)           scanf("%lf",&n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    ranL(a, b)         ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define    ranI(a, b)         ((((ll)rand() * rand()) % ((b) - (a) + 1)) + (a))
#define    ranF(a, b)         (((double)rand()/RAND_MAX)*((b) - (a)) + (a))
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    ff 	              first
#define    ss 	              second
#define    sf                 scanf
#define    pf                 printf
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector < int >     vi;
typedef    vector < vi >      vii;
typedef    pair < int, int>   pii;
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

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
const int INF = 0x3f3f3f3f;
const double PI = 2.0 * acos(0.0);

ll MIN() { return INF; }
template <typename T, typename... Args >
inline T MIN(T a, Args... args) { return min(a, (T)MIN(args...)); }

ll MAX() { return -INF; }
template <typename T, typename... Args >
inline T MAX(T a, Args... args) { return max(a, (T)MAX(args...)); }

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

vi pre, post;
vii adj;

void preOrder(int u, int p)
{
    if(adj[u].size() == 0) return;
    int lft = adj[u][0];
    int rgt = adj[u][1];

    pre.PB(u);
    if(lft) preOrder(lft, u);
    if(rgt) preOrder(rgt, u);
}
void postOrder(int u, int p)
{
    if(adj[u].size() == 0) return;
    int lft = adj[u][0];
    int rgt = adj[u][1];

    if(lft) postOrder(lft, u);
    if(rgt) postOrder(rgt, u);
    post.PB(u);
}

int n, k;
map < int, int > mpPre, mpPost;
int vis[2004];
int mark[2004];
int tt;

void dfs(int u)
{
//    trace(u);
    if(vis[u] == 1) return;
    mark[u] = tt%k + 1;
    vis[u] = 1;

//    trace("sd");
    int kk = mpPre[u];
    dfs(post[kk]);
}

int main() {
    #ifdef dipta007
        READ("inB.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
//    trace(t);
    FOR(ci,1,t)
    {
        cin >> k >> n;
//        trace(n, k);
        adj.assign(n+4, vi());

        FOR(i,1,n)
        {
            int l, r;
            cin >> l >> r;
//            trace(l, r);
            adj[i].PB(l);
            adj[i].PB(r);
        }

        pre.clear();
        post.clear();
        preOrder(1, -1);
        postOrder(1, -1);

        mpPre.clear();
        mpPost.clear();
        FOR(i,0,n-1)
        {
//            trace(i, pre[i], post[i]);
            mpPre[ pre[i] ] = i;
            mpPost[ post[i] ] = i;
        }
//        trace("s");

        CLR(vis);
        CLR(mark);
        tt = 0;
        FOR(i,0,(int)pre.size()-1)
        {
            int now = pre[i];
            if(vis[now] == 0)
            {
                tt++;
                vis[now] = 1;
                mark[now] = tt%k + 1;
                dfs(post[i]);
            }
        }

        cout << "Case #" << ci << ":";
        if(tt < k) cout << " Impossible" << endl;
        else
        {
            FOR(i,1,n) cout << " " << mark[i];
            cout << endl;
        }
    }

    return 0;
}



