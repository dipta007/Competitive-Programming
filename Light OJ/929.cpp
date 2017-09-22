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


int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int adjMatrix[1004][1004];
int dist[1004][1004];
int r,c;

int djkastra(int sx,int sy)
{
    FOR(i,0,r-1) FOR(j,0,c-1) dist[i][j]=INF;
    dist[sx][sy]=adjMatrix[sx][sy];
    priority_queue < pair< int, pii > , vector< pair< int, pii > >, greater< pair< int, pii > > > pq;
    pq.push(MP(dist[sx][sy],pii(sx,sy)));

    while(!pq.empty())
    {
        pair <int, pii > u = pq.top(); pq.pop();
        debug(u.ff,u.ss.ff,u.ss.ss)
        FOR(i,0,3)
        {
            int X = u.ss.ff + dx[i];
            int Y = u.ss.ss + dy[i];

//            debug("*",X,Y)
            if(X>=0 && X<r && Y>=0 && Y<c)
            {
//                debug("**",X,Y)
                if(dist[u.ss.ff][u.ss.ss] + adjMatrix[X][Y] < dist[X][Y])
                {
                    debug(X,Y,dist[X][Y], u.ss.ff,u.ss.ss,dist[u.ss.ff][u.ss.ss], adjMatrix[X][Y])
                    dist[X][Y] = dist[u.ss.ff][u.ss.ss] + adjMatrix[X][Y] ;
                    debug("***",X,Y,dist[X][Y])
                    pq.push(MP(dist[X][Y],pii(X,Y)));
                }
            }
        }
    }
    return dist[r-1][c-1];
}


int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        getII(r,c);
        FOR(i,0,r-1)
        {
            FOR(j,0,c-1)
            {
                getI(adjMatrix[i][j]);
            }
        }
        int res = djkastra(0,0);
        printf("%d\n",res);
    }

    return 0;
}



