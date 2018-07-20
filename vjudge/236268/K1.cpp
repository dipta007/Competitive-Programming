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
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    ff 	              first
#define    ss 	              second
#define    sf                 scanf
#define    pf                 printf
typedef    long long          ll;
typedef    vector < int >     vi;
typedef    vector < vi >      vii;
typedef    pair < ll, ll>   pii;
typedef    unsigned long long ull;
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

#define M 1000004
bool marked[M];
vector <int> primes;

void sieve(int n)
{
    primes.push_back(2);
    for (int i = 3; i * i <= n; i += 2)
    {
        if (marked[i] == 0)
        {
            for (int j = i * i; j <= n; j += i + i)
            {
                marked[j] = 1;
            }
        }
    }
    int nn = n;
    for(int i=3; i<=nn; i+=2) if(marked[i] == 0) primes.push_back(i);
}

vector < vector < pii > > adj;
ll dist[10004][104];

struct data {
    ll cost, kk, ind;

    bool operator <(const data &b) const {
        if(cost < b.cost) return true;
        if(cost == b.cost)
            return kk > b.kk;
        return false;
    }
};

inline ll getProfit(ll cost, ll p)
{
    return (cost/p) + (p+p);
}

ll cal[M];
void pre()
{
    FOR(i,0,M-4) cal[i] = i;
    FOR(i,0,(int)primes.size()-1)
    {
        for(int j=primes[i]; j<=M-4; j+=primes[i])
        {
            cal[j] = min(cal[j], getProfit(j, primes[i]));
        }
    }
}

ll dj(int src, int dest, int k)
{
    FOR(i,0,10000) FOR(j,0,k) dist[i][j] = 1e18;
    FOR(i,0,k) dist[src][i] = 0;
    queue < data > pq;
    pq.push({0, k, src});
    ll mx = 1e18;
    while(!pq.empty())
    {
        auto u = pq.front(); pq.pop();
        if(u.ind == dest) mx = min(mx, u.cost);
        for(auto &v: adj[u.ind])
        {
            ll costNow = v.ss;
            if(u.cost + costNow < dist[v.ff][u.kk])
            {
                dist[v.ff][u.kk] = dist[u.ind][u.kk] + v.ss;
                pq.push({dist[v.ff][u.kk], u.kk, v.ff});
            }

            if(u.kk > 0)
            {
                if(u.cost + cal[costNow] < dist[v.ff][u.kk-1])
                {
                    dist[v.ff][u.kk-1] = dist[u.ind][u.kk] + cal[costNow];
                    pq.push({dist[v.ff][u.kk-1], u.kk-1, v.ff});
                }
            }
        }
    }
    if(mx == 1e18) mx = -1;
    return mx;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    sieve(M-4);
    pre();
    cin >> t;
    while(t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        adj.assign(n+4, vector <pii>());

        FOR(i,1,m)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        int s,d;
        cin >> s >> d;

        ll res = dj(s, d, k);
        cout << res << endl;
    }

    return 0;
}



