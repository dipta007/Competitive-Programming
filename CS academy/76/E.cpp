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
//const int INF = 0x7f7f7f7f;
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
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define dipta00
#ifdef dipta
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

struct Edge{
	ll from,to,cap,flow,cost;
	Edge(ll from,ll to,ll cap,ll flow,ll cost):from(from),to(to),cap(cap),flow(flow),cost(cost) {}
};

const int MAXN=25000;
const int INF=1e9+4;

class MCMF{
public:
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[MAXN];
	bool inq[MAXN];
	ll d[MAXN],p[MAXN],a[MAXN];
	void init(int n)
	{
		this->n=n;
		edges.clear();
		for(int i=0;i<=n;++i) G[i].clear();
	}
	void addedge(ll from,ll to,ll cap,ll cap2, ll cost)
	{
		edges.push_back(Edge(from,to,cap,0,cost));

//		debug(from, to)
		edges.push_back(Edge(to,from,cap2,0,INF));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	bool spfa(ll &flow,ll& cost)
	{
		for(int i=0;i<n;++i) d[i]=(ll)INF+1,inq[i]=0;
		queue<ll> que;
		que.push(s);
		trace(s);
		inq[s]=1;d[s]=0;p[s]=0;a[s]=INF;
		while(!que.empty())
		{
			ll x=que.front();que.pop();
			debug(x)
			inq[x]=0;
			for(int i=0;i<G[x].size();++i)
			{
				Edge &e=edges[G[x][i]];
				trace(e.from, e.to);
//				if(e.to == 31)
                {
                    debug(e.cap, e.flow, d[e.to], d[x]+e.cost)
                }
				if(e.cap>e.flow && d[e.to]>d[x]+e.cost)
				{
					d[e.to]=d[x]+e.cost;
					p[e.to]=G[x][i];
					a[e.to]=min(a[x],e.cap-e.flow);
					if(!inq[e.to]) inq[e.to]=1,que.push(e.to);
				}
			}
		}
		debug(s, t, d[t])
		if(d[t]==INF) return 0;

		/// change here as per the problem
		flow+=a[t];
		cost+=d[t];
		ll u=t;
		debug(u,s)
		while(u!=s)
		{
//		    trace(u, s);
			edges[p[u]].flow+=a[t];
			edges[p[u]^1].flow-=a[t];
			u=edges[p[u]].from;
		}
		return 1;
	}
	ll mincost(int s,int t)
	{
		this->s=s;this->t=t;
		ll flow=0,cost=0;
		while(spfa(flow,cost));
		return cost;
	}
}mcmf;
// 8 direction
int dx[]={-1,1,0,0,-1,-1,1,1};
int dy[]={0,0,-1,1,-1,1,1,-1};


int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int r,c,sx,sy;
    while(~getII(r,c))
    {
        getII(sx, sy);

        int a[r+4][c+4];

        FOR(i,0,r+2)
        {
            FOR(j,0,c+2)
            {
                a[i][j] = INF;
            }
        }

        FOR(i,1,r)
        {
            FOR(j,1,c)
            {
                getI(a[i][j]);
            }
        }



        int in = 1;
        int mark[r+4][c+4];
        FOR(i,0,r+2) FOR(j,0,c+2) mark[i][j] = r*c + 1;
        FOR(i,1,r)
        {
            FOR(j,1,c)
            {
                mark[i][j] = in++;
            }
        }

//        debug(in)
        mcmf.init(r*c + 4);
        a[sx][sy] = 1e9+2;

        FOR(i,1,r)
        {
            FOR(j,1,c)
            {
                FOR(k,0,7)
                {
                    int x = dx[k] + i;
                    int y = dy[k] + j;

                    int u = mark[i][j];
                    int v = mark[x][y];

//                    debug(i, j)

                    mcmf.addedge(u, v, 1, 0, a[x][y]);
//                    if(v == 31) debug("SAd");
//                    debug("Asd")
                }
            }
        }

        int src = 0, sink = r*c+2;
//        FOR(i,1,r)
//        {
//            int u = mark[i][1];
//            mcmf.addedge(u, sink, 1, 0, 1e9+2);
//
//            u = mark[i][c];
//            mcmf.addedge(u, sink, 1, 0, 1e9+2);
//        }
//
//        FOR(i,1,c)
//        {
//            int u = mark[1][i];
//            mcmf.addedge(u, sink, 1, 0, 1e9+2);
//
//            u = mark[r][i];
//            mcmf.addedge(u, sink, 1, 0, 1e9+2);
//        }

        mcmf.addedge(r*c+1, sink, 1, 0, INF);
        mcmf.addedge(src, mark[sx][sy], 1, 0, INF);

        printf("%lld\n", mcmf.mincost(src, sink));
    }


    return 0;
}

