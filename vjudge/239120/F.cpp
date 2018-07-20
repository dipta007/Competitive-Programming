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

map <int, string> rev;
map <string, int> mp;
int deg[304];
int vis[304];
vii adj;

void dfs(int in, int d)
{
    vis[in] = 1;
    deg[in] = d;
    for(auto v: adj[in])
    {
        if(vis[v] == 0)
        {
            dfs(v, d+1);
        }
    }
}

void bfs(int src)
{
    int d = 0;
    deg[src] = 0;
    queue < int > q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(auto v: adj[u])
        {
            if(vis[v] == 0)
            {
                vis[v] = 1;
                deg[v] = deg[u] + 1;
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
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        int n;
        cin >> n;
        adj.assign(304, vi());
        mp.clear();
        rev.clear();
        int in = 1;
        FOR(i,1,n)
        {
            string a, b, c;
            cin >> a >> b >> c;

            int aa, bb, cc;
            if(mp[a] == 0) mp[a] = in++;
            if(mp[b] == 0) mp[b] = in++;
            if(mp[c] == 0) mp[c] = in++;

            aa = mp[a];
            bb = mp[b];
            cc = mp[c];

            rev[aa] = a;
            rev[bb] = b;
            rev[cc] = c;

            adj[aa].push_back(bb);
            adj[bb].push_back(aa);

            adj[aa].push_back(cc);
            adj[cc].push_back(aa);

            adj[cc].push_back(bb);
            adj[bb].push_back(cc);
        }

        SET(deg);
        CLR(vis);
        bfs(mp["Ahmad"]);

        vector < pair < int, string > > v;
        FOR(i, 1, in-1)
        {
            pair < int, string > p;
            if(deg[i] == -1) p.ff = INF;
            else p.ff = deg[i];
            p.ss = rev[i];

            v.PB(p);
        }
        sort(ALL(v));

        cout << v.size() << endl;
        FOR(i,0,(int)v.size()-1)
        {
            cout << v[i].ss << " ";
            if(v[i].ff == INF) cout << "undefined" << endl;
            else cout << v[i].ff << endl;
        }
    }

    return 0;
}


