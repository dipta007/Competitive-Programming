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

struct node {
    int x, y, next, cap, cost;
};

/**
1. Clear graph
2. Add edge
3. Assign source and sink
4. Pass highestNumberOfNode to maxFlow() or minCostMaxFlow()
*/
///Try to make size of edge array as large possible
const int NODE=110,EDGE=50001;
struct FLOW {
    int source, sink;

    int head[NODE];
    void clear() {
        e = 0;
        SET(head);
    }
    node edge[EDGE]; int e;
    ///cap holo max koto flow deoa jabe
    ///cap2 holo koto flow deoa hoise
    void addEdge ( int u, int v, int cap, int cap2, int cost ) {
        edge[e].x = u; edge[e].y = v; edge[e].cap = cap; edge[e].cost = cost;
        edge[e].next = head[u]; head[u] = e; e++;
        edge[e].x = v; edge[e].y = u; edge[e].cap = cap; edge[e].cost = -cost;
        edge[e].next = head[v]; head[v] = e; e++;
    }

    int vis[NODE], q[NODE], now[NODE];
    bool bfs ( ) {
        memset ( vis, -1, sizeof vis );
        vis[source] = 0;
        int ini = 0, qend = 0;
        q[qend++] = source;

        while ( ini < qend && vis[sink] == -1 ) {
                debug(ini)
            int s = q[ini++];
            int i;
            for (i=head[s];i!=-1;i= edge[i].next){
                debug(i, edge[i].next)
                int t = edge[i].y;
                if ( vis[t] == -1 && edge[i].cap){
                    vis[t] = vis[s] + 1;
                    q[qend++] = t;
                }
            }
        }
        if ( vis[sink] != -1 ) return true;
        else return false;
    }
    int dfs ( int s, int f ) {
        if ( f == 0 ) return 0;
        if ( s == sink ) return f;
        for ( int &i=now[s];i!=-1;i=edge[i].next){
            int t = edge[i].y;
            if ( vis[s] + 1 != vis[t] ) continue;
            int pushed=dfs(t,min(f,edge[i].cap));
            if ( pushed ) {
                edge[i].cap -= pushed;
                edge[i^1].cap += pushed;
                return pushed;
            }
        }
        return 0;
    }

    int maxFlow ( int highestNumberOfNode, int flow ) {
        int res = 0;
        while ( 1 ) {
                debug(flow)
            if ( flow == 0 ) break;
            if ( bfs () == false ) break;
            debug("*")
            int i;
            for ( i=0;i<=highestNumberOfNode;i++)now[i]= head[i];
            while (int pushed=dfs(source,flow ) ) {
                res += pushed; ///Can overflow depending on Max Flow
                flow -= pushed;
            }
        }
        return res;
    }

    int inq[NODE], par[NODE], record[NODE];
    int minCostFlow ( int highestNumberOfNode ) {
//        SET(inq);
        int res = 0, i, j, k, fl = 0;
        while ( 1 ) {
                debug("&&")
            for ( i = 1; i <= highestNumberOfNode; i++ ) vis[i] = INF;
            vis[source] = 0;
            deque < int > dq;
            dq.PB ( source );
            while ( !dq.empty() ) {
                int s = dq.front(); dq.pop_front();
                debug(s)
                inq[s] = 0;
                for ( i = head[s]; i != -1; i = edge[i].next ) {
                    int t = edge[i].y;
                    if ( edge[i].cap ) {
                        if ( vis[s] + edge[i].cost < vis[t] ) {
                            vis[t] = vis[s] + edge[i].cost;
                            par[t] = s;
                            record[t] = i;
                            if ( inq[t] == 0 ) {
                                inq[t] = 1;
                                if ( dq.empty() == false && vis[dq.front()] > vis[t] )
                                    dq.push_front( t );
                                else dq.PB ( t );
                            }
                        }
                    }
                }
            }

//            if ( vis[sink] > 0 ) break; ///Cost Getting minimized, Change Here
            if ( vis[sink] == INF ) break; //Flow getting maximized. Either this, or the one above

            fl++; ///Total flow
            res += vis[sink]; ///Cost of Flow
            for ( i = sink; i != source; i = par[i] ) { //Travel from sink to source
                int t = record[i]; //Record which edge was used to travel to t
                edge[t].cap--;
                edge[t^1].cap++;
            }
        }

        return res; ///Min cost of max flow
    }

}graph;


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        graph.clear();

        int n;
        getI(n);
        vi a,b;
        FOR(i,1,n)
        {
            int x;
            getI(x);
            a.PB(x);
        }
        FOR(i,1,n)
        {
            int x;
            getI(x);
            b.PB(x);
        }
        sort(ALL(a));
        sort(ALL(b));

        graph.source = n+n+2;
        graph.sink = n+n+1;
        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                if(a[i] > b[j])
                {
                    graph.addEdge(i+1,n+j+1,1,0,2);
                }
                else if(a[i]==b[j])
                {
                    graph.addEdge(i+1,n+j+1,1,0,1);
                }
                else graph.addEdge(i+1, n+j+1, 1, 0 , 0);
            }
        }
        FOR(i,1,n)
        {
            graph.addEdge(n+n+2,i,1,0,0);
        }
        FOR(i,n+1,n+n)
        {
            graph.addEdge(i,n+n+1, 1, 0, 0);
        }
        debug("*")

        printf("Case %d: %d\n",ci, graph.minCostFlow(n+n+2));
    }

    return 0;
}


