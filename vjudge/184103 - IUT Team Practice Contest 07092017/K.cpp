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

vii adj;
int vis[100004];
int clr[100004];

int dfs(int u, int color)
{
    vis[u] = 1;
    clr[u] = color;

    for(auto &v: adj[u])
    {
        if(vis[v]==1 && color == clr[v])
        {
            clr[u] = 2;
            break;
        }
    }

    for(auto &v: adj[u])
    {
        if(vis[v]==0)
        {
            dfs(v, !color);
        }
    }
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(~getI(n))
    {
        int in[n+n+4];
        CLR(in);
        adj.assign(n+n+4, vi());


        set <int> s;
        FOR(i,1,n)
        {
            int x;
            getI(x);
            s.insert(x);
            adj[i].PB(x);
            in[x]++;
        }
        FOR(i,n+1,n+n)
        {
            int x;
            getI(x);
            s.insert(x);
            adj[i].PB(x);
            in[x]++;
        }

        priority_queue < pii > pq;
        FOR(i,1,n+n)
        {
            pq.push( MP(-in[i], i));
            //cout << i << " " << in[i] << endl;
        }

        vi vv;
        map <int, bool> mp, kn;
        while(!pq.empty())
        {
            pii p = pq.top();
            pq.pop();
//            debug(p.ss, p.ff, mp[p.ss],s.size())

            if(mp[p.ss]) continue;

            int flg = 1;
            FOR(i,0,(int)adj[p.ss].size()-1)
            {
                int v = adj[p.ss][i];
                if(kn[v]==1)
                {
                    flg =0;
                    break;
                }
            }

            if(flg==0) continue;

            {
                for(auto &x: adj[p.ss])
                {
                    mp[x] = 1;
                }
                vv.PB(p.ss);
                kn[p.ss] = 1;
            }
        }

//        CLR(vis);
//        FOR(i,1,n+n)
//        {
//            if(vis[i]==0)
//            {
//                dfs(i,0);
//            }
//        }
//        vi v;
//        FOR(i,1,n+n)
//        {
//            if(clr[i]==0)
//            {
//                v.PB(i);
//            }
//        }
        FOR(i,0,vv.size()-1)
        {
            if(i) printf(" ");
            printf("%d",vv[i]);
        }
        printf("\n");
    }

    return 0;
}



