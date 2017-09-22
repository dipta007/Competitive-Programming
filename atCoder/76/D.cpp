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
vector < pii > v1,v2;
map <pii, int > mp;

ll MST(int node)
{
    sort(ALL(e));
    UnionFind uMst(node);

    ll cnt=0,sum=0;

    int i=0, j=0;
    while(1)
    {
        if(cnt==node-1) break;
        if(i<v1.size()-1 && j<v2.size()-1)
        {
            int xx = mp[ pii(v1[i].ff, v1[i].ss) ];
            int yy = mp[ pii(v1[i+1].ff, v1[i+1].ss) ];
            int x = uMst.findSet( xx );
            int y = uMst.findSet( yy );
            int w = abs(v1[i].ff - v1[i+1].ff);

            int xx1 = mp[ pii(v2[j].ff, v2[j].ss) ];
            int yy1 = mp[ pii(v2[j+1].ff, v2[j+1].ss) ];
            int x1 = uMst.findSet( xx );
            int y1 = uMst.findSet( yy );
            int w1 = abs(v2[j].ss - v2[j+1].ss);

            if(w<=w1 && x!=y)
            {
                cnt++;
                uMst.unionSet(xx, yy);
                sum += w;
                i++;

                debug(xx,yy,w);
            }
            else if(x1!=y1)
            {
                cnt++;
                uMst.unionSet(xx1, yy1);
                sum += w1;
                j++;
                debug(xx1,yy1,w1);
            }
        }
        else if(i<v1.size()-1)
        {
            int xx = mp[ pii(v1[i].ff, v1[i].ss) ];
            int yy = mp[ pii(v1[i+1].ff, v1[i+1].ss) ];
            int x = uMst.findSet( xx );
            int y = uMst.findSet( yy );
            int w = abs(v1[i].ff - v1[i+1].ff);
            if(x!=y)
            {
                cnt++;
                uMst.unionSet(xx, yy);
                sum += w;
                i++;
                debug(xx,yy,w);
            }
        }
        else if(j<v2.size()-1)
        {
            int xx = mp[ pii(v2[j].ff, v2[j].ss) ];
            int yy = mp[ pii(v2[j+1].ff, v2[j+1].ss) ];
            int x = uMst.findSet( xx );
            int y = uMst.findSet( yy );
            int w = abs(v2[j].ss - v2[j+1].ss);
            if(x!=y)
            {
                cnt++;
                uMst.unionSet(xx, yy);
                sum += w;
                j++;
                debug(xx,yy,w);
            }
        }
        else break;
    }

    for(int i=0;i<e.size();i++)
    {
        int x=uMst.findSet(e[i].u);
        int y=uMst.findSet(e[i].v);
        if(x!=y)
        {
            cnt++;
            uMst.unionSet(x,y);
            sum += e[i].w;
            if(cnt==node-1) break;
        }
    }
    return sum;
}


ll MST1(int node)
{
    sort(ALL(e));
    UnionFind uMst(node);

    ll cnt=0,sum=0;
    for(int i=0;i<e.size();i++)
    {
        int x=uMst.findSet(e[i].u);
        int y=uMst.findSet(e[i].v);
        debug(x,y,e[i].u, e[i].v,e[i].w)
        if(x!=y)
        {
            cnt++;
            uMst.unionSet(x,y);
            sum += e[i].w;
            if(cnt==node-1) break;
        }
    }
    return sum;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int n;
    while(~getI(n))
    {
        v1.clear();
        v2.clear();
        mp.clear();
        e.clear();

        int in = 1;
        FOR(i,1,n)
        {
            int x,y;
            getII(x,y);
            if(mp[ pii(x,y) ] != 0) continue;
            v1.PB( pii(x,y) );
            v2.PB( pii(y,x) );
            mp[ pii(x,y) ] = in++;
        }
        sort(ALL(v1));
        sort(ALL(v2));

        FOR(i,0,(int)v1.size()-2)
        {
            int x = mp[ pii(v1[i].ff, v1[i].ss) ];
            int y = mp[ pii(v1[i+1].ff, v1[i+1].ss) ];
            int w = min(abs(v1[i].ss-v1[i+1].ss) ,abs(v1[i].ff - v1[i+1].ff) );

            e.PB( edge(x,y,w) );
        }
        FOR(i,0,(int)v2.size()-2)
        {
            int x = mp[ pii(v2[i].ss, v2[i].ff) ];
            int y = mp[ pii(v2[i+1].ss, v2[i+1].ff) ];
            int w = min(abs(v2[i].ss-v2[i+1].ss) ,abs(v2[i].ff - v2[i+1].ff) );

            e.PB( edge(x,y,w) );
        }

        printf("%lld\n", MST1(v1.size()));
    }
    return 0;
}

