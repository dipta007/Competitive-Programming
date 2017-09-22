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
#define    UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
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

int MX = 3004;
//int adj[MX][MX];
vii adj;

struct data
{
    int a,b,c,d;
    data()
    {

    }
    data(int x,int y, int z,int u)
    {
        a=x;
        b=y;
        c=z;
        d=u;
    }
};

bool cmp(const data &a, const data &b)
{
    if(a.a<b.a) return true;
    if(a.a==b.a)
    {
        if(a.b<b.b) return true;
        if(a.b==b.b)
        {
            if(a.c<b.c) return true;
            if(a.c==b.c)
            {
                return a.d<b.d;
            }
        }
    }
    return false;
}


vector <data> vd;

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m;
    while(~getII(n,m))
    {
        vd.clear();
        adj.assign(n+4, vi());
        FOR(i,1,m)
        {
            int x,y;
            getII(x,y);
//            mat[x][y]=1;
//            mat[y][x]=1;
            adj[x].PB(y);
            adj[y].PB(x);
        }

        int a[n+4][n+4];
        CLR(a);
//        int r1,r2,r3,r4;
//        r1=r2=r3=r4=INF;
        FOR(i,1,n)
        {
            FOR(j,0,(int)adj[i].size()-1)
            {
                FOR(k,0,(int)adj[i].size()-1)
                {
                    if(j==k) continue;
                    int u = adj[i][j];
                    int v = adj[i][k];
                    if(a[u][v]!=0)
                    {
                        int v1 = i;
                        int v2 = u;
                        int v3 = a[u][v];
                        int v4 = v;
                        vd.PB(data(v1,v2,v3,v4));
                        vd.PB(data(v2,v3,v4,v1));
                        vd.PB(data(v3,v4,v1,v2));
                        vd.PB(data(v4,v1,v2,v3));
//                        if(v1<=r1 && v2<=r2 && v3<=r3 && v4<=r4)
//                        {
//                            r1=v1;
//                            r2=v2;
//                            r3=v3;
//                            r4=v4;
//                        }
//                        if(v2<=r1 && v3<=r2 && v4<=r3 && v1<=r4)
//                        {
//                            r1=v2;
//                            r2=v3;
//                            r3=v4;
//                            r4=v1;
//                        }
//                        if(v1<=r3 && v2<=r4 && v3<=r1 && v4<=r2)
//                        {
//                            r1=v3;
//                            r2=v4;
//                            r3=v1;
//                            r4=v2;
//                        }
//                        if(v1<=r4 && v2<=r1 && v3<=r2 && v4<=r3)
//                        {
//                            r1=v4;
//                            r2=v1;
//                            r3=v2;
//                            r4=v3;
//                        }
                        //debug(i,u,a[u][v],v);
                    }
                    a[u][v]=i;
                }
            }
        }

        sort(ALL(vd), cmp);

        if(vd.size()==0) printf("NO\n");
        else
        {
            printf("YES\n");
            printf("%d %d %d %d\n",vd[0].a,vd[0].b,vd[0].c,vd[0].d);
        }
    }

    return 0;
}



