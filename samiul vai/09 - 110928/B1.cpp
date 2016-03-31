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


template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

//******************DELETE****************
#define shubha
#ifdef shubhashis
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

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

//int dist[4][12][12];
//bool visited[4][12][12];
int grid[12][12];
bool marked[12][12][12][12][12][12];
int dis[12][12][12][12][12][12];

int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};

int n;

bool check(int x,int y)
{
    if(x>=0 && y>=0 && x<n && y<n) return 1;
    return 0;
}

int BFS(int sx1, int sy1, int sx2, int sy2, int sx3, int sy3)
{
    marked[sx1][sy1][sx2][sy2][sx3][sy3]=1;
    dis[sx1][sy1][sx2][sy2][sx3][sy3]=0;
//    dist[0][sx1][sy1]=0;
//    dist[1][sx2][sy2]=0;
//    dist[2][sx3][sy3]=0;
    queue <int> q;
    q.push(sx1);
    q.push(sy1);
    q.push(sx2);
    q.push(sy2);
    q.push(sx3);
    q.push(sy3);

    while(!q.empty())
    {
        int x1 = q.front(); q.pop();
        int y1 = q.front(); q.pop();
        int x2 = q.front(); q.pop();
        int y2 = q.front(); q.pop();
        int x3 = q.front(); q.pop();
        int y3 = q.front(); q.pop();
//
//        if(x1==x2 && y1==y2) continue;
//        if(x1==x3 && y1==y3) continue;
//        if(x2==x3 && y2==y3) continue;

        if(grid[x1][y1]==2 && grid[x2][y2]==2 && grid[x3][y3]==2)
        {
            cout << x1 <<" " <<y1 <<" " <<x2 <<" " <<y2 <<" " <<x3 <<" " <<y3 <<" " <<endl;
            debug(x1,y1,x2,y2,x3,y3)
//            cout << dist[0][x1][y1] <<endl;
//            cout << dist[1][x2][y2] <<endl;
//            cout << dist[2][x3][y3] <<endl;
            int res = dis[sx1][sy1][sx2][sy2][sx3][sy3];
            return res;
        }

        debug(x1,y1,x2,y2,x3,y3)
        for(int i=0; i<4; i++)
        {
            int X1 = x1 + dx[i];
            int Y1 = y1 + dy[i];
            int X2 = x2 + dx[i];
            int Y2 = y2 + dy[i];
            int X3 = x3 + dx[i];
            int Y3 = y3 + dy[i];

//            if(X1==X2 && Y1==Y2) continue;
//            if(X1==X3 && Y1==Y3) continue;
//            if(X2==X3 && Y2==Y3) continue;

            int rx1,rx2,rx3,ry1,ry2,ry3,flg=0;
            int c1,c2,c3;
            c1=0,c2=0,c3=0; ///ager man ei ase era

            if(check(X1,Y1) && check(X2,Y2) && check(X3,Y3)) ///3 tai maze er modhe
            {
                if(marked[X1][Y1][X2][Y2][X3][Y3]) continue; ///3 tai age visit hoise
                else if(grid[X1][Y1]==0 && grid[X2][Y2]==0 && grid[X3][Y3]==0) continue; ///3 tai obstacle e
                else ///1 or 2 or 3 age 1 sathe visit hoi nai nd obstacle eou nai
                {
                    flg=1;
                    if(grid[X1][Y1])  ///obstacle nai
                    {
                        rx1=X1,ry1=Y1;
                        c1=1;
                    }
                    else    ///obstacle ase
                    {
                        rx1=x1,ry1=y1;
                    }

                    if(grid[X2][Y2])
                    {
                        rx2=X2,ry2=Y2;
                        c2=1;
                    }
                    else
                    {
                        rx2=x2,ry2=y2;
                    }

                    if(grid[X3][Y3])
                    {
                        rx3=X3,ry3=Y3;
                        c3=1;
                    }
                    else
                    {
                        rx3=x3,ry3=y3;
                    }
                }
            }
            else ///1 ta or ekadhik maze er baire
            {
                if(check(X1,Y1)==0 && check(X2,Y2)==0 && check(X3,Y3)==0) continue; ///sb maze er baire
                else
                {
                    flg=1;
                    if(check(X1,Y1)==0)
                    {
                        rx1=x1,ry1=y1;
                    }
                    else
                    {
                        rx1=X1,ry1=Y1;
                        c1=1;
                    }

                    if(check(X2,Y2)==0)
                    {
                        rx2=x2,ry2=y2;
                    }
                    else
                    {
                        rx2=X2,ry2=Y2;
                        c2=1;
                    }

                    if(check(X3,Y3)==0)
                    {
                        rx3=x3,ry3=y3;
                    }
                    else
                    {
                        rx3=X3,ry3=Y3;
                        c3=1;
                    }
                }
            }

            if(flg)
            {
                if(marked[rx1][ry1][rx2][ry2][rx3][ry3]) continue;
                if(rx1==rx2 && ry1==ry2)
                {
                    if(c1)
                    {
                        rx1=x1;
                        ry1=y1;
                    }
                    else
                    {
                        rx2=x2;
                        ry2=y2;
                    }
                }
                if(rx2==rx3 && ry2==ry3)
                {
                    if(c3)
                    {
                        rx3=x3;
                        ry3=y3;
                    }
                    else
                    {
                        rx2=x2;
                        ry2=y2;
                    }
                }
                if(rx1==rx3 && ry1==ry3)
                {
                    if(c1)
                    {
                        rx1=x1;
                        ry1=y1;
                    }
                    else
                    {
                        rx3=x3;
                        ry3=y3;
                    }
                }
                q.push(rx1);
                q.push(ry1);
                q.push(rx2);
                q.push(ry2);
                q.push(rx3);
                q.push(ry3);

//                dist[0][rx1][ry1] = min(dist[0][rx1][ry1],dist[0][x1][y1]+1);
//                dist[1][rx2][ry2] = min(dist[1][rx2][ry2],dist[1][x2][y2]+1);
//                dist[2][rx3][ry3] = min(dist[2][rx3][ry3],dist[2][x3][y3]+1);
//                dist[0][rx1][ry1] = dist[0][x1][y1]+1;
//                dist[1][rx2][ry2] = dist[1][x2][y2]+1;
//                dist[2][rx3][ry3] = dist[2][x3][y3]+1;
                dis[rx1][ry1][rx2][ry2][rx3][ry3]=dis[x1][y1][x2][y2][x3][y3]+1;
                //debug()

                marked[rx1][ry1][rx2][ry2][rx3][ry3]=1;
            }
        }
    }
    return -1;
}

int main()
{
    READ("in.txt");
//    WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1; ci<=t; ci++)
    {
        getI(n);
        getchar();
        int x1,x2,x3,y1,y2,y3;
        vector <pii> vp;
        for(int i=0; i<n; i++)
        {
            string st;
            getline(cin,st);
            for(int j=0; j<n; j++)
            {
                if(st[j]=='A')
                {
                    grid[i][j]=1;
                    x1 = i;
                    y1 = j;
                }
                else if(st[j]=='B')
                {
                    grid[i][j]=1;
                    x2 = i;
                    y2 = j;
                }
                else if(st[j]=='C')
                {
                    grid[i][j]=1;
                    x3 = i;
                    y3 = j;
                }
                else if(st[j]=='.')
                {
                    grid[i][j]=1;
                }
                else if(st[j]=='X')
                {
                    vp.PB(pii(i,j));
                    grid[i][j]=2;
                }
                else grid[i][j]=0;
            }
        }

        CLR(marked);
//        for(int i=0;i<12;i++)
//        {
//            for(int j=0;j<12;j++)
//            {
//                dist[0][i][j]=INF;
//                dist[1][i][j]=INF;
//                dist[2][i][j]=INF;
//            }
//        }
        debug(x1,y1,x2,y2,x3,y3)
        int res = BFS(x1,y1,x2,y2,x3,y3);
        if(res==-1)
            printf("Case %d: trapped\n",ci);
        else
            printf("Case %d: %d\n",ci,res);

    }

    return 0;
}



