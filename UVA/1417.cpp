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
#define    SETI(ar)           memset(ar,126,sizeof ar)


#define printbits(x, n) cout << #x << " = " << x << " = " << bitset<n>(x) << endl /// Least significant n bits of x, n must be constant
#define tobinary(x) string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(min(63, __builtin_clzll(x)), 64)
#define lastbits(x, n) cout << string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(64 - n, 64) << endl
#define firstbits(x, n) cout << string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(min(63, __builtin_clzll(x)), 64).substr(0, n) << endl;

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
//Cycle contains which scc node belongs too.

int mx = 0;
int nmx = -1;
const int NODE = 50004;
int ver[NODE];

struct SCC{
    int num[NODE], low[NODE], col[NODE], cycle[NODE], st[NODE];
    int tail, cnt, cc, scc_cnt;
    vi adj[NODE];

    SCC():tail(0),cnt(0),cc(0) {}
    void clear () {
        cc += 3;
        FOR(i,0,NODE-1) adj[i].clear();
        tail = 0;
    }
    void tarjan ( int s ) {
        num[s] = low[s] = cnt++;
        col[s] = cc + 1;
        st[tail++] = s;
        FOR(i,0,(int)adj[s].size()-1) {
            int t = adj[s][i];
            if ( col[t] <= cc ) {
                tarjan ( t );
                low[s]=MIN(low[s],low[t]);
            }
            /*Back edge*/
            else if (col[t]==cc+1)
                low[s]=MIN(low[s],low[t]);
        }
        if ( low[s] == num[s] ) {
            scc_cnt++;
            int cnt = 1;
            ver[s] = 0;
            while ( 1 ) {
                ver[s]++;
                int temp=st[tail-1];
                tail--;
                col[temp] = cc + 2;
                cycle[temp] = s;
                if ( s == temp ) break;
                cnt ++;
            }
        }
    }

    int findSCC( int n, int strt = 0 ) {
        scc_cnt = 0;
        FOR(i,strt,n) {
            if ( col[i] <= cc ) {
                tarjan ( i );
            }
        }
        return scc_cnt;
    }

    void add_edge(int x, int y) {
        adj[x].PB(y);
    }

    void shrink( int n ) {
        FOR(i,0,n){
            FOR(j,0,(int)adj[i].size()-1){
                adj[i][j] = cycle[adj[i][j]]; ///Careful. This will create self-loop. Just ignore i->i edges when processing.
            }
        }
        FOR(i,0,n){
            if ( cycle[i] == i ) continue;
            int u = cycle[i];
            FOR(j,0,(int)adj[i].size()-1){
                int v = adj[i][j];
                adj[u].PB ( v );
            }
            adj[i].clear();
        }
        FOR(i,0,n){ ///Not always necessary
            sort ( ALL(adj[i]) );
            UNIQUE(adj[i]);
        }
    }
} scc;


int ch[NODE];

int dfs(int u, int p)
{
    if(ch[u] != -1) return ch[u];
    ch[u] = ver[u];
    FOR(i,0,(int)scc.adj[u].size()-1)
    {
        int v = scc.adj[u][i];
        if(v == p || v == u) continue;
        ch[u] += dfs(v, u);
    }
    return ch[u];
}

int in[NODE], out[NODE];

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
        scc.clear();
        FOR(i,1,n)
        {
            int u, v;
            cin >> u >> v;
            scc.add_edge(u, v);
        }

        scc.findSCC(n, 1);
        FOR(i,1,n) trace(i, scc.cycle[i], ver[i]);
        scc.shrink(n);
        CLR(in);
        CLR(out);
        FOR(i,0, n)
        {
            trace("node", i);
            FOR(j,0,(int)scc.adj[i].size()-1)
            {
                int v = scc.adj[i][j];
                if(i == v) continue;
                trace(i, v);
                out[i]++;
                in[v]++;
            }
        }

        mx = -1;
        nmx = -1;
        SET(ch);
        FOR(i,1,n) {
            if(in[i] == 0) {
                int kk = dfs(i, -1);
                trace(i, kk, mx, nmx);
                if(kk > mx) {
                    mx = kk;
                    nmx = i;
                }
            }
        }

        trace(nmx, mx);
        FOR(i,1,n)
        {
            if(scc.cycle[i] == nmx) {
                cout << "Case " << ci << ": " << i << endl;
                break;
            }
        }
    }

    return 0;
}


