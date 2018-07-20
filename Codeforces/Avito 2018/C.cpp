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
#define    sf scanf
#define    pf printf
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define dipta00
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
int ee;

int dfs(int u, int par)
{
    int ret = 1;
    for(auto v: adj[u])
    {
        if(v != par)
        {
            ret += dfs(v, u);
            break;
        }
    }

    debug(u)
    if(ee == -1)
    {
        ee = u;
    }
    return ret;
}

vector < pii > edges;

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(cin >> n)
    {
        adj.assign(n+4, vi());
        edges.clear();

        int in[n+4];
        CLR(in);

        FOR(i,1,n-1)
        {
            int x,y;
            cin >> x >> y;
            adj[y].PB(x);
            adj[x].PB(y);
            edges.PB(MP(x,y));
            in[x]++;
            in[y]++;
        }

        int flg = 0;
        FOR(i,1,n) if(in[i] == n-1) flg = 1;

        if(flg == 0)
        {
            int src = -1, endd = -1;
            FOR(i,1,n)
            {
                if(in[i] == 1)
                {
                    src = i;
                    break;
                }
            }

            if(src != -1)
            {
                int res = dfs(src, -1);
                if(res == n)
                {
                    flg = 1;
                    FOR(i,1,n)
                    {
                        if(in[i] == 1 && i!=src)
                        {
                            endd = i;
                            break;
                        }
                    }
                    cout << "Yes" << endl;
                    cout << 1 << endl;
                    cout << src << " " << endd <<  endl;
                }
                else
                {
                    int v = -1;
                    FOR(i,1,n) if(in[i] > 2)
                    {
                        v = i;
                        break;
                    }

                    if(v != -1)
                    {
                        int sum = 0;
                        edges.clear();
                        for(auto now: adj[v])
                        {
                            ee = -1;
                            sum += (dfs(now, v));

                            edges.PB(MP(v, ee));
                        }

                        if(sum == n-1)
                        {
                            cout << "Yes" << endl;
                            cout << edges.size() << endl;
                            FOR(i,0,(int)edges.size()-1)
                            {
                                cout << edges[i].ff << " " << edges[i].ss << endl;
                            }
                            flg = 1;
                        }
                    }
                }
            }
        }
        else if(flg == 1)
        {
            cout << "Yes" << endl;
            cout << n-1 << endl;
            FOR(i,0,n-2)
            {
                cout << edges[i].ff << " " << edges[i].ss << endl;
            }
        }

        if(flg == 0) cout << "No" << endl;
    }

    return 0;
}


