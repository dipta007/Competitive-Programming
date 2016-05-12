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
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
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
#define    bitCheck(N,in)    ((bool)(a&(1<<(k))))
#define    bitOff(N,in)      (a&(~(1<<(k))))
#define    bitOn(N,in)       (a|(1<<(k)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    iseq(a,b)          (fabs(a-b)<EPS)
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


struct edge
{
    int u,v,w;
    edge()
    {

    }
    edge(int x,int y,int z)
    {
        u=x,v=y,w=z;
    }
    bool operator < (const edge &p) const
    {
        return w < p.w;
    }
};

class UnionFind
{
private:
    vi p,rank;
public:
    UnionFind(int n)

    {
        rank.assign(n+1,0);
        p.assign(n+1,0);
        for(int i=0; i<=n; i++)
            p[i]=i;
    }
    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i]=findSet(p[i]));
    }
    bool isSameSet(int i,int j)
    {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i,int j)
    {
        if(!isSameSet(i,j))
        {
            int x=findSet(i);
            int y=findSet(j);
            if(rank[x]>rank[y]) p[y]=x;
            else
            {
                p[x]=y;
                if(rank[x]==rank[y])
                    rank[y]++;
            }
        }
    }
};

vector <edge> e;
int adjMatrix[204][204];

void floyd(int node)
{
    /// There is no path from I to J
    /// Then adjMatrix[i][j] = adjMatrix[j][i] = INF;

    for(int k=1;k<=node;k++)
    {
        for(int i=1;i<=node;i++)
        {
            for(int j=1;j<=node;j++)
            {
                adjMatrix[i][j] = min(adjMatrix[i][j], max(adjMatrix[i][k],adjMatrix[k][j]));
//                if(adjMatrix[i][k]+adjMatrix[k][j]<adjMatrix[i][j])
//                {
//                    adjMatrix[i][j] = adjMatrix[i][k]+adjMatrix[k][j];
//                }
            }
        }
    }
}


int MST(int node)
{
    sort(ALL(e));
    UnionFind uMst(node);

    FOR(i,0,node)
    {
        FOR(j,0,node)
        {
            adjMatrix[i][j]=INF;
        }
        adjMatrix[i][i]=0;
    }

    int cnt=0,sum=0;
    for(int i=0;i<e.size();i++)
    {
        int x=uMst.findSet(e[i].u);
        int y=uMst.findSet(e[i].v);
        if(x!=y)
        {
            adjMatrix[e[i].u][e[i].v]=e[i].w;
            adjMatrix[e[i].v][e[i].u]=e[i].w;
            cnt++;
            uMst.unionSet(x,y);
            sum += e[i].w;
            if(cnt==node-1) break;
        }
    }
    return sum;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007


    int n,m,q,flg=0,ci=1;
    while(~getIII(n,m,q))
    {

        if(!n && !m && !q) break;
        if(flg) printf("\n");
        flg=1;
        e.clear();
        FOR(i,1,m)
        {
            int x,y,w;
            getIII(x,y,w);
//            debug(x,y,w)
            e.PB(edge(x,y,w));
        }
        MST(n);
        floyd(n);
        printf("Case #%d\n",ci++);
        FOR(i,1,q)
        {
            int x,y;
            getII(x,y);
//            debug(x,y)
            if(adjMatrix[x][y]==INF) printf("no path\n");
            else printf("%d\n",adjMatrix[x][y]);
        }

    }

    return 0;
}



