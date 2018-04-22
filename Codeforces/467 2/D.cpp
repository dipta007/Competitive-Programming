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

#define dipta0
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
///****************** template ends here ****************

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

vii adj;
enum Color {WHITE, GRAY, BLACK};

short int color[100004];
bool cycleN[100004];

bool DFSUtil(int u)
{
    color[u] = GRAY;

    for(auto v: adj[u])
    {
        if (color[v] == GRAY)
        {
            cycleN[u] = 1;
            return true;
        }
        if (color[v] == WHITE && DFSUtil(v))
        {
            cycleN[u] = 1;
            return true;
        }
    }
    color[u] = BLACK;

    return false;
}

bool isCyclic(int n)
{
    CLR(color);

    int flg = 0;
    for (int i = 1; i <=n; i++)
        if (color[i] == WHITE)
           if (DFSUtil(i) == true)
           {
                flg = 1;
//               return true;
           }


    return flg;
}


bool dp[100004][2];
int path[100004][2];
bool vis[100004][2];

int dfs(int u, int ff)
{
//    debug(u, ff, adj[u].size())
    if(adj[u].size() == 0) return false;

    if(vis[u][ff]) return dp[u][ff];

    if(ff==0) dp[u][ff] = false;
    else dp[u][ff] = true;

    vis[u][ff] = 1;

    for(auto v: adj[u])
    {
        if(ff == 0 && dfs(v, !ff) == false)
        {
            debug(u, ff, v)
            path[u][ff] = v;
            return dp[u][ff] = true;
        }
        else if(ff == 1 && dfs(v, !ff) == true)
        {
            debug(u, ff, v)
            path[u][ff] = v;
            return dp[u][ff] = false;
        }
    }

    if(ff == 1) return dp[u][ff] = true;
    return dp[u][ff] = false;
}

vi v;
void pathPrint(int u, int ff)
{
    v.PB(u);
    if(adj[u].size()==0) return;
    int kk = path[u][ff];
    pathPrint(kk, !ff);
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m;
    while(~getII(n,m))
    {
        adj.assign(n+4, vi());
        FOR(i,1,n)
        {
            int kk;
            getI(kk);
            FOR(j,1,kk)
            {
                int x;
                getI(x);
                debug(i, x)
                adj[i].PB(x);
            }
        }

        int s;
        getI(s);
        CLR(cycleN);

        int cycle = isCyclic(n);

        CLR(vis);
        int win = dfs(s, 0);
        if(win)
        {
            printf("Win\n");
            v.clear();
            pathPrint(s, 0);

            FOR(i,0,(int)v.size()-1)
            {
                if(i) printf(" ");
                printf("%d",v[i]);
            }
            printf("\n");
        }
        else if(cycle && cycleN[s] == 1)
        {
            printf("Draw\n");
        }
        else printf("Lose\n");
    }

    return 0;
}

