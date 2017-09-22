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
const int INF = 60000;
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

int adj1[100][100];

int adj2[100][100];

void floydWarshall1(int node)
{
    /// There is no path from I to J
    /// Then adj1[i][j] = adj1[j][i] = INF;

    for(int k=1;k<node;k++)
    {
        for(int i=1;i<node;i++)
        {
            for(int j=1;j<node;j++)
            {
                if(adj1[i][k]+adj1[k][j]<adj1[i][j])
                {
                    adj1[i][j] = adj1[i][k]+adj1[k][j];
                }
            }
        }
    }
}
void floydWarshall2(int node)
{
    /// There is no path from I to J
    /// Then adj1[i][j] = adj1[j][i] = INF;

    for(int k=1;k<node;k++)
    {
        for(int i=1;i<node;i++)
        {
            for(int j=1;j<node;j++)
            {
                if(adj2[i][k]+adj2[k][j]<adj2[i][j])
                {
                    adj2[i][j] = adj2[i][k]+adj2[k][j];
                }
            }
        }
    }
}


int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int n;
    int t;
    getI(t);
    FOR(ci,1,t)
    {
        getI(n);
        getchar();
        int c=1;
        FOR(i,0,26)
        {
            FOR(j,0,26)
            {
                if(i==j) adj1[i][j]=0;
                else adj1[i][j]=INF;
                if(i==j) adj2[i][j]=0;
                else adj2[i][j]=INF;
            }
        }
        map <char, int> mp;
        FOR(i,1,n)
        {
            char a,b;
            scanf("%c %c ",&a,&b);
            if(mp[a]==0) mp[a]=c++;
            if(mp[b]==0) mp[b]=c++;
            adj1[mp[a]][mp[b]]=1;
            adj1[mp[b]][mp[a]]=1;
        }
        floydWarshall1(c);
        int m;
        getI(m);
        getchar();
        FOR(i,1,m)
        {
            char a,b;
            scanf("%c %c ",&a,&b);
            if(mp[a]==0) mp[a]=c++;
            if(mp[b]==0) mp[b]=c++;
            adj2[mp[a]][mp[b]]=1;
            adj2[mp[b]][mp[a]]=1;
        }
        //debug("*")
        floydWarshall2(c);
        int flg=1;
        FOR(i,1,c-1)
        {
            FOR(j,1,c-1)
            {
                //debug(i,j,adj1[i][j],adj2[i][j])
                if(adj1[i][j]<INF && adj2[i][j]==INF)
                {
                    flg=0;
                    break;
                }
                if(adj2[i][j]<INF && adj1[i][j]==INF)
                {
                    flg=0;
                    break;
                }
            }
            if(!flg) break;
        }
        if(flg) printf("YES\n");
        else printf("NO\n");
        if(ci<t) printf("\n");
    }

    return 0;
}




