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
#include <iterator>ac
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

ll adjMatrix[104][104];

void floydWarshall(int node)
{
    /// There is no path from I to J
    /// Then adjMatrix[i][j] = adjMatrix[j][i] = INF;

    for(int k=1;k<=node;k++)
    {
        for(int i=1;i<=node;i++)
        {
            for(int j=1;j<=node;j++)
            {
                if(adjMatrix[i][k]+adjMatrix[k][j]<adjMatrix[i][j])
                {
                    adjMatrix[i][j] = adjMatrix[i][k]+adjMatrix[k][j];
                }
            }
        }
    }
}

ll dp[5004][104];
vector <pii> vp;
int kk;

ll call(int in, int now)
{
    if(in>=kk)
    {
        return 0;
    }

    //debug(in)
    ll &ret = dp[in][now];
    if(ret!=-1) return ret;

    ret = LONG_LONG_MAX;

    {
        ll gas = adjMatrix[now][vp[in].ff];
        gas += adjMatrix[vp[in].ff][vp[in].ss];
        ret = gas + call(in+1, vp[in].ss);
    }

    if(in<kk-1)
    {
        ll gas = adjMatrix[now][vp[in].ff];
        gas += adjMatrix[vp[in].ff][vp[in+1].ff];
        gas += adjMatrix[vp[in+1].ff][vp[in].ss];
        gas += adjMatrix[vp[in].ss][vp[in+1].ss];
        ret = min(ret, gas+call(in+2, vp[in+1].ss));
    }
    //debug(in,ret)

    return ret;
}

int main() {
    #ifdef dipta007
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);


    int t;
    getI(t);
    FOR(ci,1,t)
    {
        vp.clear();
        int n,m,k;
        getIII(n,m,k);
        kk=k;
        FOR(i,0,n) FOR(j,0,n) adjMatrix[i][j]=10000000000000000LL;
        FOR(i,0,n) adjMatrix[i][i]=0;
        FOR(i,1,m)
        {
            int x,y,z;
            getIII(x,y,z);
            adjMatrix[x][y] = min(adjMatrix[x][y], (ll)z);
            adjMatrix[y][x] = min(adjMatrix[y][x], (ll)z);
        }
        floydWarshall(n);
//        FOR(i,1,n)
//        {
//            FOR(j,1,n)
//            {
//                debug(i,j,adjMatrix[i][j])
//            }
//        }
        FOR(i,1,k)
        {
            int s,d;
            getII(s,d);
            vp.PB(pii(s,d));
        }
        //if(res>=INF) res=-1;
        SET(dp);
        ll res = call(0, 1);
        if(res>=10000000000000000LL) res=-1;
        printf("Case #%d: %lld\n",ci,res);
    }

    return 0;
}



