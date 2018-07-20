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

/// 2 SAT (1 based index for variables)
/// Each variable can have two possible values (true or false)
/// Variables must satisfy a system of constraints on pairs of variables

namespace sat{
    #define MAX 1004
    bool visited[MAX * 2];
    vector <int> adj[MAX * 2], rev[MAX * 2];
    int n, m, l, dfs_t[MAX * 2], order[MAX * 2], parent[MAX * 2];

    inline int neg(int x){
        return ((x) <= n ? (x + n) : (x - n));
    }

    /// Call init once
    void init(int nodes){
        n = nodes, m = nodes * 2;
        for (int i = 0; i < MAX * 2; i++){
            adj[i].clear();
            rev[i].clear();
        }
    }

    /// Add implication, if a then b
    inline void add_implication(int a, int b){
        if (a < 0) a = n - a;
        if (b < 0) b = n - b;

        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    inline void rmv_implication(int a, int b)
    {
        if (a < 0) a = n - a;
        if (b < 0) b = n - b;

        FOR(i,0,(int)adj[a].size()-1)
            if(adj[a][i] == b)
                adj[a].erase(adj[a].begin() + i);
        FOR(i,0,(int)rev[b].size()-1)
            if(rev[b][i] == a)
                rev[b].erase(rev[b].begin() + i);
    }

    inline void add_or(int a, int b){
        add_implication(-a, b);
        add_implication(-b, a);
    }

    inline void add_xor(int a, int b){
        add_or(a, b);
        add_or(-a, -b);
    }

    inline void add_and(int a, int b){
        add_or(a, b);
        add_or(a, -b);
        add_or(-a, b);
    }

    inline void add_equal(int a, int b) {
        add_implication(a,b);
        add_implication(-a,-b);
    }

    /// force variable x to be true (if x is negative, force !x to be true)
    inline void force_true(int x){
        if (x < 0) x = n - x;
        add_implication(neg(x), x);
    }

    /// force variable x to be false (if x is negative, force !x to be false)
    inline void force_false(int x){
        if (x < 0) x = n - x;
        add_implication(x, neg(x));
    }

    inline void unforce_true(int x)
    {
        if(x < 0) x = n - x;
        rmv_implication(neg(x), x);
    }
    inline void unforce_false(int x)
    {
        if (x < 0) x = n - x;
        rmv_implication(x, neg(x));
    }

    inline void topsort(int i){
        visited[i] = true;
        int j, x, len = rev[i].size();

        for (j = 0; j < len; j++){
            x = rev[i][j];
            if (!visited[x]) topsort(x);
        }
        dfs_t[i] = ++l;
    }

    inline void dfs(int i, int p){
        parent[i] = p;
        visited[i] = true;
        int j, x, len = adj[i].size();

        for (j = 0; j < len; j++){
            x = adj[i][j];
            if (!visited[x]) dfs(x, p);
        }
    }

    void build(){
        int i, x;
        CLR(visited);
        for (i = m, l = 0; i >= 1; i--){
            if (!visited[i]){
                topsort(i);
            }
            order[dfs_t[i]] = i;
        }

        CLR(visited);
        for (i = m; i >= 1; i--){
            x = order[i];
            if (!visited[x]){
                dfs(x, x);
            }
        }
    }

    /// Returns true if the system is 2-satisfiable and returns the solution (nodes set to true) in vector res
    bool satisfy(vector <int>& res){
        build();
        CLR(visited);

        for (int i = 1; i <= m; i++){
            int x = order[i];
            if (parent[x] == parent[neg(x)]) return false;

            if (!visited[parent[x]]){
                visited[parent[x]] = true;
                visited[parent[neg(x)]] = false;
            }
        }

        res.clear();
        for (int i = 1; i <= n; i++){
            if (visited[parent[i]]) res.push_back(i);
        }
        return true;
    }
}

vi res;
vector < pair < pii, pii > > vp;

bool backtack(int in)
{
    if(in >= vp.size())
    {
        res.clear();
        if(sat::satisfy(res)) return true;
        return false;
    }

    int x = vp[in].ff.ss;
    int y = vp[in].ss.ff;
    int z = vp[in].ss.ss;
    if(vp[in].ff.ff == 1)
    {
        sat::force_true(x);
        if(backtack(in+1)) return true;
        sat::unforce_true(x);

        sat::force_true(y);
        if(backtack(in+1)) return true;
        sat::unforce_true(y);

        sat::force_true(z);
        if(backtack(in+1)) return true;
        sat::unforce_true(z);
    }
    else
    {
        sat::force_false(x);
        if(backtack(in+1)) return true;
        sat::unforce_false(x);

        sat::force_false(y);
        if(backtack(in+1)) return true;
        sat::unforce_false(y);

        sat::force_false(z);
        if(backtack(in+1)) return true;
        sat::unforce_false(z);
    }
    return false;
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
        vp.clear();
        int n,m,k;
        getIII(n,m,k);
        sat::init(n);
        FOR(i,1,m)
        {
            int tt, x, y;
            getIII(tt,x,y);
            switch(tt)
            {
            case 1:
                sat::add_or(x,y);
                break;
            case 2:
                sat::add_or(x, -y);
                break;
            case 3:
                sat::add_or(-x, -y);
                break;
            case 4:
                sat::add_xor(x, y);
                break;
            }
        }
        FOR(i,1,k)
        {
            int tt, x, y, z;
            getI(tt);
            getIII(x,y,z);
            vp.push_back(MP(MP(tt,x), MP(y,z)));
        }

        trace(sat::satisfy(res));
        pf("Case %d:", ci);
        if(backtack(0))
        {
            pf(" Possible %d", res.size());
            FOR(i,0,(int)res.size()-1) pf(" %d",res[i]);
            pf(".\n");
        }
        else pf(" Impossible.\n");
    }

    return 0;
}


