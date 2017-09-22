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

#define piii pair < int, pii >

int dest;
vector <vector < pii > > adj;
int dist[1004][104];
//int tank[1004];
int fuelTk[1004];

int dj(int src,int cap)
{
    SET(dist);
    //SET(tank);
    priority_queue < piii > pq;
    pq.push(MP(-0,MP(src,0))); ///cost, vertex, tank
    dist[src][0]=0;
    //tank[src]=0;

    while(!pq.empty())
    {
        piii u = pq.top(); pq.pop();
        //debug(u.ff,u.ss.ff,u.ss.ss,dist[dest])
        if(u.ss.ff==dest) return -u.ff;
        FOR(i,0,(int)adj[u.ss.ff].size()-1)
        {
            pii v = adj[u.ss.ff][i];
            int mini = max(v.ss - u.ss.ss,0);
            //debug(u.ss.ff,v.ff,mini)
            FOR(j,mini,(int)cap-u.ss.ss)
            {
                int cost = j * fuelTk[u.ss.ff];
                //debug(u.ss.ff,cost,j)
                int tankEthakbe = j + u.ss.ss - v.ss;
                if(dist[v.ff][tankEthakbe]==-1)
                {
//                    tank[v.ff]=tankEthakbe;
                    dist[v.ff][tankEthakbe] = -u.ff + cost;
                    pq.push(MP(-dist[v.ff][tankEthakbe], MP(v.ff, tankEthakbe)));
                    continue;
                }
                if(-u.ff + cost < dist[v.ff][tankEthakbe])
                {
                    dist[v.ff][tankEthakbe] = -u.ff + cost;
                    pq.push(MP(-dist[v.ff][tankEthakbe], MP(v.ff, tankEthakbe)));
                }
            }
        }
    }
    return dist[dest][0];
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        WRITE("out.txt");
    #endif // dipta007

    int n,m;
    while(~getII(n,m))
    {
        FOR(i,0,n-1)
        {
            getI(fuelTk[i]);
        }
        adj.assign(n+4, vector <pii> ());
        FOR(i,0,m-1)
        {
            int x,y,z;
            getIII(x,y,z);
            adj[x].PB(pii(y,z));
            adj[y].PB(pii(x,z));
        }
        int q;
        getI(q);
        FOR(cc,1,q)
        {
            int s,d,c;
            getIII(c,s,d);
            dest = d;
            int kk = dj(s,c);
            if(kk==-1)
            {
                printf("impossible\n");
                continue;
            }
            printf("%d\n",kk);
        }
    }

    return 0;
}




