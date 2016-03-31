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
#define shubhashs
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

int adj[204][204],visited[204][204],dist[204][204],dest,fire;
int r,c;

int BFS(point s)
{
    CLR(dist);
    dest=-1,fire=-1;
    CLR(visited);
    dist[s.x][s.y]=0;
    visited[s.x][s.y]=1;
    queue <point> q;
    q.push(s);
    int flg=0;
    while(!q.empty())
    {
        point u=q.front();
        q.pop();
        debug("point",u.x,u.y);
        for(int i=0;i<4;i++)
        {
            int X=u.x+dx[i];
            int Y=u.y+dy[i];
            if(X<r && X>=0 && Y<c && Y>=0 && visited[X][Y]==0 && adj[X][Y]!=1)
            {
                if(adj[X][Y]==2)
                {
                    dist[X][Y]=dist[u.x][u.y]+1;
                    point o;
                    o.x=X;
                    o.y=Y;
                    q.push(o);
                }
                else if(adj[X][Y]==3 && flg!=-1)
                {
                    dest=dist[X][Y]=dist[u.x][u.y]+1;

//                    debug("*");
                    flg=1;
                }
                else{
                    fire=dist[X][Y]=dist[u.x][u.y]+1;
                    flg=-1;
//                    debug(u.x,u.y,X,Y);
                }
                visited[X][Y]=1;
            }
        }
        if(dest!=-1 && fire!=-1)
        {
            if(dest<fire) return 1;
            else return -1;
        }
    }
    if(fire!=-1) return -1;
    if(dest!=-1) return 1;
}



int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        //int r,c;
        getII(r,c);
        char st[r][c];
        getchar();
        for(int i=0;i<r;i++)
        {
            gets(st[i]);
        }
        CLR(adj);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(st[i][j]=='#') adj[i][j]=1;
                else if(st[i][j]=='.') adj[i][j]=2;
                else if(st[i][j]=='J') adj[i][j]=3;
                else adj[i][j]=4;
                //cout<<adj[i][j] << " ";
            }
//            cout << endl;
        }
//        point y;
//        y.x=r-1;y.y=1;
//        debug(BFS(y))
//        break;
        int res=INF;
        int flg=0;
        for(int i=0;i<c && res!=0;i++)
        {
            if(adj[0][i]==2)
            {
                point p;
                p.x=0;p.y=i;
                flg=BFS(p);
                if(flg!=-1) res=_min(dest,res);
                debug("    ",flg);
            }
            if(adj[0][i]==3) res=0;
        }
        for(int i=0;i<c && res!=0;i++)
        {
            if(adj[r-1][i]==2)
            {
                point p;
                p.x=r-1;p.y=i;
                flg=BFS(p);
                if(flg!=-1) res=_min(dest,res);
                debug("*",flg);
            }
            if(adj[r-1][i]==3) res=0;
        }
        for(int i=0;i<r && res!=0;i++)
        {
            if(adj[i][0]==2)
            {
                point p;
                p.x=i;p.y=0;
                flg=BFS(p);
                if(flg!=-1) res=_min(dest,res);
                debug("**",flg);
            }
            if(adj[i][0]==3) res=0;
        }
        debug(flg);
        for(int i=0;i<r && res!=0;i++)
        {
            if(adj[i][c-1]==2)
            {
                point p;
                p.x=i;p.y=c-1;
                flg=BFS(p);
                if(flg!=-1) res=_min(dest,res);
                debug("***",i,flg);
            }
            if(adj[i][c-1]==3) res=0;
        }
        if(res!=INF) printf("Case %d: %d\n",ci,res+1);
        else printf("Case %d: IMPOSSIBLE\n",ci);

    }

    return 0;
}
