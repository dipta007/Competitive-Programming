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

#define M 1000004
bool marked[M];

bool isPrime(int n) {
  if (n < 2) return 1;
  if (n == 2) return 0;
  if (n % 2 == 0) return 1;
  return marked[n];
}

void sieve(int n) {
  for (int i = 3; i * i <= n; i += 2) {
    if (marked[i] == 0) {
      for (int j = i * i; j <= n; j += i + i) {
        marked[j] = 1;
      }
    }
  }
}

int vis[100004];
int vis1[100004];
int color[100004];
//vii pri[2];
//int dp[2004][2];
int cnt[2];
vi res;
vii adj;

int dfs(int u, int clr)
{
    vis[u]=1;
    color[u] = clr;
    cnt[clr]++;
    FOR(i,0,(int)adj[u].size()-1)
    {
        int v = adj[u][i];
        if(vis[v]==0)
        {
            dfs(v, !clr);
        }
        else if(color[v]==clr)
        {
            color[v]=2;
        }
    }
}

void dfs1(int u, int clr)
{
    vis1[u]=1;
    debug(u,color[u],clr)
    if(color[u]==clr || color[u]==2)
    {
        debug(u)
        res.PB(u);
    }
    FOR(i,0,(int)adj[u].size()-1)
    {
        int v = adj[u][i];
        if(vis1[v]==0)
        {
            dfs1(v, clr);
        }
    }
}



int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    sieve(M-2);
    int n;
    while(~getI(n))
    {
        adj.assign(n+4, vi());
//        pri[0].assign(n+4, vi());
//        pri[1].assign(n+4, vi());
        res.clear();
        CLR(vis);
        CLR(vis1);
        CLR(color);
//        SET(dp);

        int a[n];
        map <int, int> mp, rev;
        int in =1;
        FOR(i,0,n-1)
        {
            getI(a[i]);
            mp[a[i]]=in;
            rev[in++]=a[i];
        }
        FOR(i,0,n-1)
        {
            FOR(j,i+1,n-1)
            {
                int kk = a[i] + a[j];
                if(isPrime(kk)==0)
                {
                    if(mp[a[i]]==0)
                    {
                        mp[a[i]]=in;
                        rev[in++]=a[i];
                    }
                    if(mp[a[j]]==0)
                    {
                        mp[a[j]]=in;
                        rev[in++]=a[j];
                    }

                    adj[mp[a[i]]].PB(mp[a[j]]);
                    adj[mp[a[j]]].PB(mp[a[i]]);
                    debug(kk, a[i], a[j])
                }
            }
        }

        res.clear();
        FOR(i,0,n-1)
        {
            if(vis[mp[a[i]]]==0)
            {
                CLR(cnt);
                dfs(mp[a[i]], 0);

                //debug("*")
                debug("cnt", a[i],cnt[0], cnt[1])
                if(cnt[0] > cnt[1])
                {
                    dfs1(mp[a[i]], 1);
                }
                else
                {
                    dfs1(mp[a[i]], 0);
                }
            }
        }
        printf("%d\n",res.size());
        FOR(i,0,(int)res.size()-1)
        {
            if(i) printf(" ");
            printf("%d",rev[res[i]]);
        }
        if(res.size()>0) printf("\n");
    }

    return 0;
}




