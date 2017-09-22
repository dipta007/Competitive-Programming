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
const int INF = 999999;
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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

#define MAXN 100002
int dp[MAXN][2];
int burn[MAXN];
int par[MAXN];
vii adj;

int f(int u, int isGuard)
{
    debug(u)
    if (adj[u].size() == 1)
        return isGuard;
    if (dp[u][isGuard] != -1)
        return dp[u][isGuard];

    int sum = 0;
    if(burn[u]==0)
    {
        if(isGuard==1)
        {
            int ans1=0,ans0=0;
            for (int i = 0; i < (int)adj[u].size(); i++)
            {
                int v = adj[u][i];
                if (v != par[u])
                {
                    ans1 += f(v, 1);
                }
            }
            for (int i = 0; i < (int)adj[u].size(); i++)
            {
                int v = adj[u][i];
                if (v != par[u])
                {
                    ans0 += f(v, 0);
                }
            }
            sum += min(ans0, ans1);
        }
        else
        {
            /// ei point e boshailam
            int ans1 = 0;
            for (int i = 0; i < (int)adj[u].size(); i++)
            {
                int v = adj[u][i];
                if (v != par[u])
                {
                    ans1 += f(v,1);
                }
            }

            /// ei point e na boshai
            /// er neighbour gula te boshailam
            int sum2 = INF;
            int in = 0;
            while(in<adj[u].size())
            {
                int sum3 = 0;

                FOR(i,0,(int)adj[u].size()-1)
                {
                    int v = adj[u][i];
                    if(v==par[u] && in==i)
                    {
                        sum3 = INF;
                        break;
                    }
                    if(v == par[u]) continue;
                    if(adj[v].size()==1)
                    {
                        if(i==in) sum3 += 1;
                    }
                    FOR(j,0,(int)adj[v].size()-1)
                    {
                        int vv = adj[v][j];
                        if(vv == par[v]) continue;
                        if(i==in) sum3 += f(vv,1);
                        else sum3 += min(f(vv,1) , f(vv,0));
                    }
                }

                sum2 = min(sum2, sum3);

                in++;
            }

            sum += min(ans1, sum2);
        }
    }
    return dp[u][isGuard] = sum + isGuard;
}

int f(int u, int isGuard, int prevGuard)
{
    if (adj[u].size() == 0)
        return 0;
    if (dp[u][isGuard] != -1)
        return dp[u][isGuard];
    int sum = 0;

//    debug(u)
    if(burn[u])
    {
        if(isGuard)
        {
            for (int i = 0; i < (int)adj[u].size(); i++)
            {
                int v = adj[u][i];
                if (v != par[u])
                {
                    sum += min(f(v, 1, isGuard), f(v, 0, isGuard));
                }
            }
        }
        else
        {
            if(prevGuard)
            {
                for (int i = 0; i < (int)adj[u].size(); i++)
                {
                    int v = adj[u][i];
                    if (v != par[u])
                    {
                        sum += min(f(v, 1, isGuard), f(v, 0, isGuard));
                    }
                }
            }
            else
            {
                for (int i = 0; i < (int)adj[u].size(); i++)
                {
                    int v = adj[u][i];
                    if (v != par[u])
                    {
                        sum += f(v, 1, isGuard);
                    }
                }
            }
        }
    }
    else
    {
        FOR(i,0,(int)adj[u].size()-1)
        {
            int v = adj[u][i];
            if(v!=par[u])
            {
                sum += min(f(v,1,isGuard), f(v,0,isGuard));
            }
        }
    }
    debug(u,sum,isGuard);

    return dp[u][isGuard] = sum + isGuard;
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(~getI(n))
    {
        adj.assign(n+4, vi());
        CLR(burn);
        FOR(i,1,n-1)
        {
            int p, b;
            getII(p,b);
            par[i] = p;
            adj[p].PB(i);
            adj[i].PB(p);
            burn[i]=(int)(b==0);
        }

        SET(dp);
        int ans = min(f(0,0,0) , f(0,1,1));
        debug(f(0,0,0), f(0,1,1));
        printf("%d\n",ans);
        continue;
//
//        int ans = INF;
//        int ans1 = 0;
//        FOR(i,0,(int)adj[0].size()-1)
//        {
//            int v = adj[0][i];
//            ans1 += f(v,1);
//            debug("a",ans1)
//        }
//        int ans0 = 0;
//        FOR(i,0,(int)adj[0].size()-1)
//        {
//            int v = adj[0][i];
//            ans0 += f(v,0);
//            debug("a",ans0)
//        }
//        ans = min(ans0, ans1);
//        printf("%d\n",ans);
    }


    return 0;
}



