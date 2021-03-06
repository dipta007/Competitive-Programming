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
const int INF = 10000;
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

/// ********** FASTER one *******************///
namespace mf
{
    const int MAXN = 10004;
    struct edge {
        int a, b, cap, flow ;
        edge(int _a,int _b,int _c,int _d) {
            a=_a,b=_b,cap=_c,flow=_d;
        }
    } ;

    int INF = 1500000001 ;

    int n, s, t, d [ MAXN*2 ] , ptr [ MAXN*2 ] , q [ MAXN*2*10 ] ;
    vector < edge > e ;
    vector < int > g [ MAXN * 2 ] ;

    void addEdge ( int a, int b, int cap ,int cap2) {
        edge e1 =edge( a, b, cap, 0 ) ; /// forward cap
        edge e2 =edge( b, a, cap2 , 0 ) ; /// backward cap change here if needed
        g [ a ] . push_back ( ( int ) e. size ( ) ) ;
        e. push_back ( e1 ) ;
        g [ b ] . push_back ( ( int ) e. size ( ) ) ;
        e. push_back ( e2 ) ;
    }

    bool bfs ( ) {
        int qh = 0 , qt = 0 ;
        q [ qt ++ ] = s ;
        memset ( d, -1 , sizeof d ) ;
        d [ s ] = 0 ;
        while ( qh < qt && d [ t ] == - 1 ) {
            int v = q [ qh ++ ] ;
            for ( size_t i = 0 ; i < g [ v ] . size ( ) ; ++ i ) {
                int id = g [ v ] [ i ] ,
                    to = e [ id ] . b ;
                if ( d [ to ] == - 1 && e [ id ] . flow < e [ id ] . cap ) {
                    q [ qt ++ ] = to ;
                    d [ to ] = d [ v ] + 1 ;
                }
            }
        }
        return d [ t ] != - 1 ;
    }

    int dfs ( int v, int flow ) {
        if ( ! flow )  return 0 ;
        if ( v == t )  return flow ;
        for ( ; ptr [ v ] < ( int ) g [ v ] . size ( ) ; ++ ptr [ v ] ) {
            int id = g [ v ] [ ptr [ v ] ] ,
                to = e [ id ] . b ;
            if ( d [ to ] != d [ v ] + 1 )  continue ;
            int pushed = dfs ( to, min ( flow, e [ id ] . cap - e [ id ] . flow ) ) ;
            if ( pushed ) {
                e [ id ] . flow += pushed ;
                e [ id ^ 1 ] . flow -= pushed ;
                return pushed ;
            }
        }
        return 0 ;
    }

    ll dinic ( ) {
        ll flow = 0 ;
        for ( ;; ) {
            if ( !bfs () )  break ;
            memset ( ptr, 0 , sizeof ptr ) ;
            while ( int pushed = dfs ( s, INF ) ) {
                flow += (ll)pushed ;
                if(pushed == 0)break;
            }
        }
        return flow ;
    }

    void init(int src, int dest , int nodes){
        e.clear();
        FOR(i,0,n+n) g[i].clear();
        n = nodes; s = src; t = dest;
    }
};


int main() {
    #ifdef dipta007
        READ("in.txt");
        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        map <int, int> in,out;
        int n,d;
        getII(n,d);

//        mf::init(0, 204, 210);
        FOR(i,1,n)
        {
            in[i] = i;
            out[i] = 100+i;
        }
//        getchar();
        vector < pii > a,b;
        FOR(i,1,n)
        {
            char ch;
            int d;
            scanf(" %c%*c%d",&ch,&d);
            if(ch=='B')
            {
//                mf::addEdge(in[i], out[i], INF, 0);
                a.PB(MP(d,i));
            }
            else
            {
//                mf::addEdge(in[i], out[i], 1, 0);
                b.PB(MP(d,i));
            }
        }

        int low = 0, high = 1000000000;
        int res= -1;
        while(low <= high)
        {
            int mid = (low + high) / 2;


            int sink = 204;
            mf::init(205, 204, 210);
            FOR(i,0,(int)a.size()-1)
            {
                mf::addEdge(in[a[i].ss], out[a[i].ss], INF, 0);
                if(a[i].ff <= mid)
                {
                    mf::addEdge(0, in[a[i].ss], INF, 0);
                }
                if((d-a[i].ff) <= mid)
                {
                    mf::addEdge(out[a[i].ss], sink, INF, 0);
                }
            }
            FOR(i,0,(int)b.size()-1)
            {
                mf::addEdge(in[b[i].ss], out[b[i].ss], 1, 0);
                if(b[i].ff <= mid)
                {
                    mf::addEdge(0, in[b[i].ss], INF, 0);
                }
                if((d-b[i].ff) <= mid)
                {
                    mf::addEdge(out[b[i].ss], sink, INF, 0);
                }
            }

            FOR(i,0,(int)a.size()-1)
            {
                FOR(j,0, (int)a.size()-1)
                {
                    if(i==j) continue;

                    if(abs(a[i].ff-a[j].ff) <= mid)
                    {
                        mf :: addEdge(out[a[i].ss], in[a[j].ss], INF, 0);
                    }
                }
            }

            FOR(i,0,(int)b.size()-1)
            {
                FOR(j,0, (int)b.size()-1)
                {
                    if(i==j) continue;

                    if(abs(b[i].ff-b[j].ff) <= mid)
                    {
                        mf :: addEdge(out[b[i].ss], in[b[j].ss], INF, 0);
                    }
                }
            }

            FOR(i,0,(int)a.size()-1)
            {
                FOR(j,0,(int)b.size()-1)
                {
                    if(abs(a[i].ff- b[j].ff) <= mid)
                    {
                        mf::addEdge(out[a[i].ss], in[b[j].ss], INF, 0);
                        mf::addEdge(out[b[j].ss], in[a[i].ss], INF, 0);
                    }
                }
            }

            if(d <= mid) mf::addEdge(0, 204, INF, 0);
            mf::addEdge(205, 0, 2, 0);

            int kk = mf::dinic();
//            debug(low, mid, high, kk)

            if(kk==2)
            {
                high = mid - 1;
                res = mid;
            }
            else low = mid + 1;
        }
        printf("Case %d: %d\n",ci, res);
    }

    return 0;
}



