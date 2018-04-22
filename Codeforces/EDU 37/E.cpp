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
#include <unordered_map>
using namespace std;
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

#define dipta007
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

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

vii adj;
int vis[200004];
int in[200004];
int mark[200004];
set < int > s;
int n;

int dfs(int u)
{
    vis[u] = 1;
    int ret = 1;
    int in = 1;
    s.erase(u);
    set <int, int> :: iterator it;
    // for(it = s.begin(); it!=s.end(); it++)
    for(auto v: s)
    {
        // int v = *it;
        // debug(u,v, binary_search(ALL(adj[u]), v) , vis[v])
        if(binary_search(ALL(adj[u]), v) == false && vis[v]==0)
        {
            ret += dfs(v);
        }
        if(s.size()==0) break;
    }
    return ret;
}


int tt = 0;
int bfs(int x)
{
    queue <int> q;
    q.push(x);
    int ret = 1;
    vis[x] = 1;
    s.erase(x);

    while(!q.empty())
    {
        vi tmp;
        int u= q.front(); q.pop();
        tt++;
        for(auto v: adj[u]) mark[v] = tt;

        for(auto v: s)
        {
            if(mark[v]!=tt && vis[v]==0)
            {
                vis[v] = 1;
                tmp.PB(v);
                q.push(v);
                ret ++;
            }
        }

        for(auto v: tmp) s.erase(v);
    }

    return ret;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

   int m;
   while(~getII(n,m))
   {
       adj.assign(n+4, vi());

       CLR(in);
       FOR(i,1,m)
       {
           int x,y;
           getII(x,y);
           in[x]++, in[y]++;
           adj[x].PB(y);
           adj[y].PB(x);
       }

       FOR(i,1,n)
       {
           sort(ALL(adj[i]));
       }

       FOR(i,1,n) s.insert(i);

       CLR(vis);
       CLR(mark);
       int total = n;
       vi v;
       FOR(i,1,n)
       {
           // debug(i, vis[i])
           if(vis[i] == 0)
           {
               int kk = bfs(i);
               // int kk = 1;
               total -= kk;
               v.PB(kk);
           }

           if(total == 0) break;
       }

       if(total > 0) v.PB(total);
       sort(ALL(v));

       printf("%d\n", (int)v.size());
       FOR(i,0,(int)v.size()-1)
       {
           if(i) printf(" ");
           printf("%d", v[i]);
       }
       printf("\n");

   }

    return 0;
}
