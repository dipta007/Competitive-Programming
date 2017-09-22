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
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
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


int src,dest;

int dist1[504];
int dist2[504];
int dist[504];
int done[504][504];
int n,m;

vector < vector < pii  > > adj,adj2;

void dj1(int src)
{
    SET(dist1);
    priority_queue < pii > p;
    p.push(pii(-0,src));
    dist1[src]=0;

    while(!p.empty())
    {
        pii u = p.top(); p.pop();

        FOR(i,0,(int)adj[u.ss].size()-1)
        {
            pii v = adj[u.ss][i];
            if(dist1[v.ff]==-1)
            {
                dist1[v.ff] = -u.ff + v.ss;
                p.push(pii(-dist1[v.ff], v.ff));
                continue;
            }
            if(-u.ff + v.ss < dist1[v.ff])
            {
                dist1[v.ff] = -u.ff + v.ss;
                p.push(pii(-dist1[v.ff], v.ff));
            }
        }
    }
}

void dj2(int src)
{
    SET(dist2);
    priority_queue < pii > p;
    p.push(pii(-0,src));
    dist2[src]=0;

    while(!p.empty())
    {
        pii u = p.top(); p.pop();

        FOR(i,0,(int)adj2[u.ss].size()-1)
        {
            pii v = adj2[u.ss][i];
            if(dist2[v.ff]==-1)
            {
                dist2[v.ff] = -u.ff + v.ss;
                p.push(pii(-dist2[v.ff], v.ff));
                continue;
            }
            if(-u.ff + v.ss < dist2[v.ff])
            {
                dist2[v.ff] = -u.ff + v.ss;
                p.push(pii(-dist2[v.ff], v.ff));
            }
        }
    }
}

void check(int shrt)
{
    CLR(done);
    FOR(i,0,n)
    {
        FOR(j,0,(int)adj[i].size()-1)
        {
            pii p = adj[i][j];
            if(dist1[i] + p.ss + dist2[p.ff] == shrt)
            {
                //debug(i,p.ff)
                done[i][p.ff] = 1;
            }
        }
    }
}

int dj3(int src)
{
    SET(dist1);
    priority_queue <pii> p;
    p.push(pii(-0,src));
    dist1[src]=0;

    while(!p.empty())
    {
        pii u = p.top(); p.pop();
        if(u.ss == dest) return dist1[dest];

        FOR(i,0,(int)adj[u.ss].size()-1)
        {
            pii v = adj[u.ss][i];
            if(done[u.ss][v.ff])
            {
                //debug("bad", u.ss,v.ff);
                continue;
            }

            if(dist1[v.ff]==-1)
            {
                dist1[v.ff] = -u.ff + v.ss;
                p.push(pii(-dist1[v.ff], v.ff));
                continue;
            }
            if(-u.ff + v.ss < dist1[v.ff])
            {
                dist1[v.ff] = -u.ff + v.ss;
                p.push(pii(-dist1[v.ff], v.ff));
            }
        }
    }
    return dist1[dest];
}



int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    while(~getII(n,m))
    {
        if(n==0 && m==0) break;
        getII(src,dest);
        adj.assign(n+4, vector < pii > ());
        adj2.assign(n+4, vector < pii > ());
        FOR(i,1,m)
        {
            int x,y,z;
            getIII(x,y,z);
            adj[x].PB(pii(y,z));
            adj2[y].PB(pii(x,z));
        }
        dj1(src);
        dj2(dest);
        check(dist1[dest]);
        int kk = dj3(src);
        printf("%d\n",kk);
    }

    return 0;
}



