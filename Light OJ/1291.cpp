#include <bits/stdc++.h>
using namespace std;

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
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
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    sf scanf
#define    pf printf
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

#define dipta00
#ifdef dipta0
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
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

int t, n, m;

#define BRIDGENODE 10010
int isBridge[20004];
vector< pair<int,int> > adj[BRIDGENODE]; ///Enter target and edge number as pair

class BridgeFinding {
    int disc[BRIDGENODE]; ///Discovery time of nodes
    int low[BRIDGENODE]; ///Lowest back edge extension
    int col[BRIDGENODE]; ///Color for marking node

    int cnt; ///Timer
    int cc = 1; ///Color

    void tarjan ( int s, int parentEdge ) {
        disc[s] = low[s] = cnt++;
        col[s] = cc + 1;

        for ( int i = 0; i < adj[s].size(); ++i ) {

            int t = adj[s][i].ff;
            int edgeNumber = adj[s][i].ss;
            if ( edgeNumber == parentEdge ) continue; ///Don't use the same edge from parent

            if ( col[t] <= cc ) { ///New node. Discovery.

                tarjan ( t, edgeNumber );
                low[s]=min(low[s],low[t]); ///Update back edge extension for S

                if ( low[t] > disc[s] ) { ///Back edge of T did not go above S
                    ///This edge is Bridge
                    ///Do whatever you need
                    isBridge[edgeNumber] = 1;
                }
            }
            else if ( col[t] == cc + 1 ) { ///Back Edge
                low[s]=min(low[s],disc[t]);
            }
        }
    }

public:


    void clear ( int n ) {
        CLR(isBridge);
        cnt = 1;
        cc += 3; ///cc is now 0. cc+1 is 1
        for (int i = 0; i <= n; i++ ) {
            adj[i].clear();
        }
    }

    void findBridge( int n, int start = 0 ) {
        for ( int i = start; i <= n; i++ ) {
            if ( col[i] <= cc ) {
                tarjan ( i, -1 );
            }
        }
    }
}bridge;
/**
Procedure:
    1. Call UnionFind(Max Node)
    2. Call findSet(i) to find set number of i
    3. Call isSameSet(x,y) to find if they are in same set
    4. Call unionSet(x,y) to make them united
    5. Call numDisjointSets() to get the number of disjoint set
    6. Call sizeOfSet(x) to get the size of set of x
Time Complexity = O(N)
**/
class UnionFind
{
private:
    vi p, rank, setSize;
    int numSets;
public:
    UnionFind(int N)
    {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            numSets--;
            int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
            if (rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    int numDisjointSets()
    {
        return numSets;
    }
    int sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }
};

int deg[BRIDGENODE];

int main() {
    #ifdef dipta007
        READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n,m;
        getII(n,m);
        bridge.clear(n+4);
        int ee = 1;
        FOR(i,1,m)
        {
            int u, v;
            getII(u,v);
            adj[u].PB( MP(v, ee) );
            adj[v].PB( MP(u, ee++) );
        }

        bridge.findBridge(n+4);

        UnionFind helper(n+4);

        FOR(i,0,n-1)
        {
            FOR(j,0,(int)adj[i].size()-1)
            {
                pii p = adj[i][j];
                if(isBridge[p.ss] == 0)
                {
                    debug(i, p.ff);
                    helper.unionSet(i, p.ff);
                }
            }
        }


        CLR(deg);
        FOR(i,0,n-1)
        {
            FOR(j,0,(int)adj[i].size()-1)
            {
                pii p = adj[i][j];
                if(isBridge[p.ss] == 1)
                {
                    isBridge[p.ss] = 0;
                    int u = helper.findSet(i);
                    int v = helper.findSet(p.ff);

                    debug(i, p.ff, u, v);

                    deg[u]++;
                    deg[v]++;
                }
            }
        }

        int kk = 0;
        FOR(i,0,n-1) kk += ( deg[i] == 1 ) ;

        pf("Case %d: %d\n",ci, (int)ceil(kk / 2.0));
    }

    return 0;
}


