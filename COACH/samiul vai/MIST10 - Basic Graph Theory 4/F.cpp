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


int dist(pair <double,double> x, pair<double,double> y)
{
    return (x.ff-y.ff)*(x.ff-y.ff) + (x.ss-y.ss)*(x.ss-y.ss);
}

struct edge
{
    int u,v;
    int w;
    edge()
    {

    }
    edge(int x,int y,int  z)
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
vector <vector <pii> > adjlist;
int dest;

int MST(int node)
{
    sort(ALL(e));
    UnionFind uMst(node);

    int cnt=0,sum=0;
//    adjlist.assign(node+4, vector<pii>());
    for(int i=0;i<e.size();i++)
    {
        int x=uMst.findSet(e[i].u);
        int y=uMst.findSet(e[i].v);
        if(x!=y)
        {
            cnt++;
            uMst.unionSet(x,y);
//            adjlist[e[i].u].PB(pii(e[i].v,e[i].w));
//            adjlist[e[i].v].PB(pii(e[i].u,e[i].w));
            sum = max(sum,e[i].w);
//            debug(sum,e[i].u,e[i].v,e[i].w)
            if(uMst.isSameSet(0,1)==1) return sum;
            if(cnt==node-1) break;
        }
    }
    return sum;
}

//bool visited[1004];
//int dest;
//
//int bfs(int src)
//{
//    CLR(visited);
//    visited[src]=1;
//    queue <int> q;
//    q.push(src);
//    int maxy=-INF;
//    while(!q.empty())
//    {
//        int u = q.front(); q.pop();
//        debug(u)
//        FOR(i,0,adjlist[u].size()-1)
//        {
//            pii v = adjlist[u][i];
//            if(visited[v.ff]) continue;
//            visited[v.ff]=1;
//            maxy = max(maxy,v.ss);
//            q.push(v.ff);
//            if(v.ff==dest) return maxy;
//        }
//    }
//}

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int n,ci=1;
    while(~getI(n) && n)
    {
        e.clear();
        vector < pair<double,double> > vp;
        FOR(i,1,n)
        {
            int x,y;
            getII(x,y);
            vp.PB(MP(x,y));
        }
        FOR(i,0,n-1)
        {
            FOR(j,i+1,n-1)
            {
                e.PB(edge(i,j,dist(vp[i],vp[j])));
            }
        }
        dest = n-1;
        double res = MST(n);
//        double res = (double)bfs(0);
//        debug(res)
        res = sqrt(res);

        printf("Scenario #%d\n",ci++);
        printf("Frog Distance = %.3lf\n\n",res);
    }

    return 0;
}



