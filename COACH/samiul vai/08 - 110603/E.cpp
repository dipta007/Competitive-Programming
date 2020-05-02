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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    rep(i,n)          for(i=1;i<=n;i++)
#define    repI(i,n)         for(i=0;i<n;i++)
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
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
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


template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

//******************DELETE****************
#define shubhashis
#ifdef shubhashis
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

int bitOn(int N,int pos)
{
    return N=N | (1<<pos);
}
int bitOff(int N,int pos)
{
    return N=N & ~(1<<pos);
}
bool bitCheck(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

int grid[12][12],dist[12][12];
int visited[12][12],n,maxy;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int sx,sy;

int BFS(int sxx,int syy,int in)
{
    if(in==maxy) return 0;

    visited[sxx][syy]=in;
    dist[sxx][syy]=0;
    queue <int> q;
    q.push(sxx);
    q.push(syy);

    while(!q.empty())
    {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
//        debug(x,y)
        for(int i=0;i<4;i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];

            if(X>=0 && Y>=0 && X<n && Y<n && grid[X][Y] && (grid[X][Y]==1 || grid[X][Y]<=in) && visited[X][Y]!=in)
            {
                visited[X][Y]=in;
                dist[X][Y]= dist[x][y]+1;
                q.push(X);
                q.push(Y);
                if(grid[X][Y]==in)
                {
                    sx=X,sy=Y;
                    return dist[X][Y];
                }
            }
        }
    }
//    debug(in)
    return -1;
}

int main() {
//    READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        getI(n);
        getchar();
        maxy=0;
        for(int i=0;i<n;i++)
        {
            string st;
            getline(cin,st);
            for(int j=0;j<n;j++)
            {
                if(st[j]=='.') grid[i][j]=1;
                else if(st[j]=='#') grid[i][j]=0;
                else
                {
                    grid[i][j]=(st[j]-'A')+2;
//                    debug(grid[i][j],i,j)
                    maxy=max(maxy,grid[i][j]);
                    if(st[j]=='A')
                    {
                        sx=i;
                        sy=j;
                    }
                }
            }
        }
        maxy++;
        int res = 0;
        CLR(visited);
        for(int i=3;i<maxy;i++)
        {
//            debug(sx,sy)
            int k=BFS(sx,sy,i);
//            debug(k);
            if(k==-1)
            {
                res=-1;
                break;
            }
            res += k;
        }
        printf("Case %d: ",ci);
        if(res==-1) printf("Impossible\n");
        else printf("%d\n",res);
    }

    return 0;
}



