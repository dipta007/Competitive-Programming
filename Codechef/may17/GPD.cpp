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

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef dipta007
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

int min_answer,max_answer;
map <int, int> key, mp;


int dfs(int u)
{
    min_answer = min(min_answer , key[u] ^ k);
    max_answer = min(max_answer , key[u] ^ k);
    vis[u]=1;

    FOR(i,0,(int)adj[u].size()-1)
    {
        int v = adj[u][i];
        if(vis[v]==0)
        {
            dfs(u);
        }
    }
}

int main()
{
#ifdef dipta007
    //READ("in.txt");
//        WRITE("in.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,q;
    while( cin >> n >> q )
    {
        int r, key;
        cin >> r >> key[r];

        int in =1;
        mp[r] = in;
        rev[in++] = r;

        for (i = 0; i < N - 1; i++)
        {
            cin >> u >> v >> k;
            if(mp[u]==0)
            {
                mp[u] = in;
                rev[in++] = u;
            }
            if(mp[v]==0)
            {
                mp[v] = in;
                rev[in++] = v;
            }
            u = mp[u];
            v = mp[v];

            adj[u].PB(v);
            adj[v].PB(u);
            key[u] = k;
        }

        int last_answer = 0;

        for (i = 0; i < Q; i++)
        {
            cin >> t;

            // find real value of t
            t ^= last_answer;

            if (t == 0)
            {
                cin >> v >> u >> k;

                // find real values for u, v, and k
                u ^= last_answer;
                v ^= last_answer;
                k ^= last_answer;

                if(mp[u]==0)
                {
                    mp[u] = in;
                    rev[in++] = u;
                }
                if(mp[v]==0)
                {
                    mp[v] = in;
                    rev[in++] = v;
                }
                u = mp[u];
                v = mp[v];

                key[u] = k;
                adj[v].PB(u);
                adj[u].PB(v);
            }
            else
            {
                cin >> v >> k;

                // find real values for v, and k
                v ^= last_answer;
                k ^= last_answer;

                // compute the requested values
                min_answer =
                int max_answer = ...

                // update last_answer
                last_answer = min_answer ^ max_answer;
            }
        }
    }
    return 0;
}


