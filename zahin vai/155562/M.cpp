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

#ifdef dipta00
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
vii adj;
double dp[104][10004];
int vis[104][10004];
int r;

double call(int d, int make)
{
    if(make<0) return 0.0;
    if(d==0)
    {
        return 1.0;
        return 0.0;
    }
    debug(d,make)
    double &ret = dp[d][make];
    if(vis[d][make]) return ret;
    vis[d][make]=1;

    ret=0.0;
    //FOR(j,1,d)
    {
        FOR(i,1,r)
        {
            if(d-1>=0) ret += (1.0/r) * call(d-1, make-i);
        }
    }
    debug(d,make,ret)
    return ret;
}

int adjMatrix[104][104];

void floydWarshall(int node)
{
    /// There is no path from I to J
    /// Then adjMatrix[i][j] = adjMatrix[j][i] = INF;

    FOR(i,0,node)
    {
        FOR(j,0,node)
        {
            if(i==j) adjMatrix[i][i]=0;
            else if(adjMatrix[i][j]==-1) adjMatrix[i][j]=10000;
        }
    }

    for(int k=0;k<node;k++)
    {
        for(int i=0;i<node;i++)
        {
            for(int j=0;j<node;j++)
            {
                if(adjMatrix[i][k]+adjMatrix[k][j]<adjMatrix[i][j])
                {
                    adjMatrix[i][j] = adjMatrix[i][k]+adjMatrix[k][j];
                }
            }
        }
    }
}


int main() {
    #ifdef dipta007
        READ("in.txt");
        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n;
        getII(n,r);
        getchar();
        SET(adjMatrix);
        FOR(i,0,n-1)
        {
            string st;
            getline(cin,st);
            FOR(j,0,n-1)
            {
                if(st[j]=='Y')
                {
                    adjMatrix[i+1][j+1]=1;
                    adjMatrix[j+1][i+1]=1;
                }

            }
        }

        floydWarshall(n+1);
        CLR(vis);

        int c;
        getI(c);
        CLR(vis);
        printf("Case %d\n",ci);
        FOR(i,1,c)
        {
            int mm;
            getIII(src,dest,mm);
            int dis = adjMatrix[src][dest];
            double tot = 0;
//            FOR(i,1,mm) tot += call(dis,i);
            tot = call(dis,mm);
            debug(dis, tot)
            printf("%.6lf\n",tot);
        }
        printf("\n");
    }

    return 0;
}



