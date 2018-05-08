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


class MincostMaxFlow
{
private:

	struct Edge
	{
		Edge(int s, int d, int cap, int cos): source(s), dest(d), residue(cap), cost(cos) { }
		int source, dest, residue, cost;
	};

	int N;
	vector< vector<int> > graph;
	vector<Edge> edges;

public:

	void init(int n)
	{
		clear();
		N = n;
		graph.resize(N);
	}

	/// cap = source to dest er capacity
	/// cap2 = dest to source er capacity
	/// bi directional e cap2 = cap
	void addEdge(int source, int dest, int cap, int cap2, int cos)
	{
		if (source >= N || dest >= N) { N = max(source,dest)+1; graph.resize(N); }
		graph[source].push_back(edges.size());
		graph[dest].push_back(edges.size()+1);
		edges.push_back(Edge(source, dest, cap, cos));
		edges.push_back(Edge(dest, source, cap2, -cos));
	}

	void clear() { N = 0; graph.clear(); edges.clear(); }

	/// <flow_size, flow_cost>
	pair<int, int> flow(int source, int dest)
	{
		int resFlow = 0, resCost = 0;
		vector<int> pot(N, INF);
		pot[source] = 0;

		for (int step = 0; step < N; ++step)
			for (int i = 0; i < edges.size(); ++i)
			{
				Edge & e = edges[i];
				if (e.residue > 0)
					pot[e.dest] = min(pot[e.dest], pot[e.source] + e.cost);
			}

		while (1)
		{
			vector<int> prev(N, -1), best(N, INF);
			prev[source] = -2;
			best[source] = 0;

			priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > manage;
			manage.push(make_pair(0, source));

			while (!manage.empty())
			{
				int node = manage.top().second, act = manage.top().first;
				manage.pop();
				if (best[node] < act) continue;

				for (int i = 0; i < graph[node].size(); ++i)
				{
					Edge & e = edges[graph[node][i]];
					int cost = best[node] + pot[node] - pot[e.dest] + e.cost;
					if (e.residue > 0 && cost < best[e.dest])
					{
						best[e.dest] = cost;
						prev[e.dest] = graph[node][i];
						manage.push(make_pair(best[e.dest], e.dest));
					}
				}
			}
			if (prev[dest] == -1) break;

			for (int i = 0; i < N; ++i)
			{
				if (best[i] == INF) pot[i] = INF;
				else if (pot[i] < INF) pot[i] += best[i];
			}

			int fl = INF, node = dest;
			while (prev[node] != -2)
			{
				fl = min(fl, edges[prev[node]].residue);
				node = edges[prev[node]].source;
			}

			node = dest;
			while (prev[node] != -2)
			{
				edges[prev[node]].residue -= fl;
				edges[prev[node]^1].residue += fl;
				resCost += fl * edges[prev[node]].cost;
				node = edges[prev[node]].source;
			}
			resFlow += fl;
		}

		return make_pair(resFlow, resCost);
	}
}mcmf;




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
        int n;
        getI(n);
        mcmf.init(n+n+1);
        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                int x;
                getI(x);
                mcmf.addEdge(i+1, j+n+1, 1, 0, -x);
            }
        }

        FOR(i,1,n) mcmf.addEdge(0, i, 1, 0, 0);
        FOR(j,n+1,n+n) mcmf.addEdge(j, n+n+1, 1, 0, 0);
        pii p = mcmf.flow(0,n+n+1);
        printf("Case %d: %d\n",ci,-p.ss);

    }

    return 0;
}



