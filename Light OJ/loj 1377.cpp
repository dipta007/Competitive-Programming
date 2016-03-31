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

struct point
{
    int x,y;
};

// 4 direction
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int adj[204][204],visited[204][204],dist[204][204];
int flg,flgg;

int BFS(point s)
{
    CLR(visited);
    CLR(dist);
    visited[s.x][s.y]=1;
    queue <point> q;
    q.push(s);
    while(!q.empty())
    {
        point u=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int X=u.x+dx[i];
            int Y=u.y+dy[i];
            if(adj[X][Y]==1 && visited[X][Y]==0)
            {
                dist[X][Y]=dist[u.x][u.y]+1;
                visited[X][Y]=1;
                point p;
                p.x=X;p.y=Y;
                q.push(p);
            }
            else if(adj[X][Y]==3 && visited[X][Y]==0)
            {
                dist[X][Y]=dist[u.x][u.y]+1;
                adj[X][Y]=6;
                visited[X][Y]=1;
                return dist[X][Y];
            }
            else if(adj[X][Y]==4 && visited[X][Y]==0 && flg==2)
            {
                dist[X][Y]=dist[u.x][u.y]+1;
                visited[X][Y]=1;
                flgg=1;
                return dist[X][Y];
            }
            else if(adj[X][Y]==5 && visited[X][Y]==0 && flg==1)
            {
                dist[X][Y]=dist[u.x][u.y]+1;
                visited[X][Y]=1;
                return dist[X][Y];
            }
            else if(adj[X][Y]==6 && visited[X][Y]==0)
            {
                dist[X][Y]=dist[u.x][u.y]+1;
                flgg=1;
                return dist[X][Y]+1;
            }
        }
    }
    return -1;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        int m,n;
        getII(m,n);
        getchar();
        char st[m][n];
        for(int i=0;i<m;i++)
        {
            gets(st[i]);
        }
        point src,dest;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(st[i][j]=='.') adj[i][j]=1;
                else if(st[i][j]=='#') adj[i][j]=2;
                else if(st[i][j]=='*') adj[i][j]=3;
                else if(st[i][j]=='P') {adj[i][j]=4;src.x=i;src.y=j;}
                else if(st[i][j]=='D') {adj[i][j]=5;dest.x=i;dest.y=j;}
            }
        }

        flg=1;
        int k=BFS(src);
        if(k==-1)
        {
            printf("Case %d: impossible\n",ci);
            continue;
        }
        flg=2;
        flgg=0;
        int l=BFS(dest);
        if(l==-1)
        {
            printf("Case %d: impossible\n",ci);
            continue;
        }
        debug(k,l);
        if(flgg) printf("Case %d: %d\n",ci,k+l+1);
        else printf("Case %d: %d\n",ci,l);
    }

    return 0;
}

