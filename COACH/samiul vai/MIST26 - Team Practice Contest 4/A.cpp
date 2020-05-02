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
#define    pii 	 pair< ll, int >
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

int dx[] = {-2,-2,2,2,-1,-1,1,1};
int dy[] = {1,-1,-1,1,2,-2,-2,2};
pii dp[404][404];
bool vis[404][404];
int n,a[404][404];
int pri[404][404];

pii add(pii a, pii b)
{
    pii d;
    d.ff = a.ff + b.ff;
    d.ss = a.ss + b.ss;
    return d;
}

pii call(int x, int y,int px, int py)
{
    if(vis[x][y]) return dp[x][y];
    pii res;
    res.ff = -1;
    res.ss = -1;
    int flg=0;
    int sx,sy;
    FOR(i,0,7)
    {
        int X = x+dx[i];
        int Y = y+dy[i];
        if(X<0 || Y<0 || X>=n || Y>=n) continue;
        if(a[X][Y]<a[x][y]) continue;
        if(X==px && Y==py) continue;


        debug(x,y,X,Y,a[X][Y])
        flg=1;
        pii d = add(pii(a[X][Y],1), call(X,Y,x,y));
        if(d.ss>res.ss)
        {
            res=d;
            pri[x][y]=i;
            sx=X,sy=Y;
        }
//        else if(d.ff==res.ff && d.ss<res.ss)
//        {
//            res=d;
//            pri[x][y]=i;
//            sx=X,sy=Y;
//        }
        else if(d.ss==res.ss &&  a[X][Y]<a[sx][sy])
        {
            res=d;
            pri[x][y]=i;
            sx=X,sy=Y;
        }
    }
    if(flg==0)
    {
        pri[x][y]=100;
        return pii(0,0);
    }
    dp[x][y]=res;

    vis[x][y]=1;
    return res;
}

void print(int x,int y)
{
    int kk = pri[x][y];
    printf("%d\n",a[x][y]);
    if(kk==100) return;
    //debug(x,y,kk)
    print(x+dx[kk],y+dy[kk]);
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    while(~getI(n))
    {
        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                getI(a[i][j]);
            }
        }
        CLR(vis);
        pii res;
        res.ff = -1;
        res.ss = -1;
        int sx,sy;
        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                pii d = add( pii(a[i][j],1),call(i,j,-1,-1) );
                if(d.ss>res.ss)
                {
                    res=d;
                    sx=i,sy=j;
                }
//                else if(d.ff==res.ff && d.ss<res.ss)
//                {
//                    res=d;
//                    sx=i,sy=j;
//                }
                else if(d.ss==res.ss &&  a[i][j]<a[sx][sy])
                {
                    res=d;
                    sx=i,sy=j;
                }
            }
        }
//        debug(sx,sy,res.ff)
        printf("%d\n",res.ss);
        print(sx,sy);
    }

    return 0;
}



