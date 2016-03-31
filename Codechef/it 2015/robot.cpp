
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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    F(i,L,R)	         for (int i = L; i < R; i++)
#define    FF(i,L,R) 	     for (int i = L; i <= R; i++)
#define    FR(i,L,R) 	     for (int i = L; i > R; i--)
#define    FRF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d %d", &a, &b)
#define    getIII(a,b,c)     scanf("%d %d %d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld %lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double


template< class T > inline T _abs(T n) { return ( (n) < 0 ? -(n) : (n) ); }
template< class T > inline T _max(T a, T b) { return ( ! ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _min(T a, T b) { return ( ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _swap(T &a, T &b) { T temp=a;a=b;b=temp;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd( (b), ( (a) % (b) ) ) ; }
template< class T > inline T lcm(T a, T b) { return ( (a) / gcd( (a), (b) ) * (b) ); }


//******************DELETE****************
#define shubhashis
#ifdef shubhashis
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************


//int BFS(point s)
//{
//    //CLR(visited);
//    //visited[s.x][s.y]=1;
//    queue <point> q;
//    if(adj[s.x][s.y]==0) q.push(s);
//    while(!q.empty())
//    {
//        point p=q.front();
//        if(p.x==m && p.y==n) {cnt=(cnt+1)%mod;}
//        q.pop();
//        for(int i=0;i<2;i++)
//        {
//            int X=p.x+dx[i];
//            int Y=p.y+dy[i];
//            if(adj[X][Y]==0 && X>=1 && Y>=1 && X<=m && Y<=n)
//            {
//                //visited[X][Y]=1;
//                point v;
//                v.x=X;v.y=Y;
//                q.push(v);
//            }
//        }
//    }
//}


struct point
{
    int x,y;
};
int adj[1004][1004],cnt,visited[1004][1004];
int dx[]={1,0};
int dy[]={0,1};
int mod=1000000007;
int m,n;
int dp[1004][1004];


int dfs(point s)
{
    if(s.x==m && s.y==n)
    {
        dp[s.x][s.y]=1;
        return 1;
    }
    int res=0;
    visited[s.x][s.y]=1;
    for(int i=0;i<2;i++)
    {
        point p;
        p.x=s.x+dx[i];
        p.y=s.y+dy[i];
        if(adj[p.x][p.y]==0 && p.x>=1 && p.x<=m && p.y>=1 && p.y<=n)
        {
            if(visited[p.x][p.y]==1)
            {
                res=(res+dp[p.x][p.y])%mod;
            }
            else if(visited[p.x][p.y]==0)
            {
                int k=dfs(p);
                res=(res+k)%mod;
            }
        }
    }
    dp[s.x][s.y]=res%mod;
    return dp[s.x][s.y];
}



int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int p;
    while(~getIII(m,n,p))
    {
        CLR(adj);
        for(int i=0;i<p;i++)
        {
            int x,y;
            getII(x,y);
            adj[x][y]=1;
        }
        point src;
        src.x=1;
        src.y=1;
        cnt=0;
        CLR(visited);
        CLR(dp);
        if(adj[1][1]==0)
        {
            dfs(src);
        }
            printf("%d\n",(dp[1][1]%mod));
    }

    return 0;
}
