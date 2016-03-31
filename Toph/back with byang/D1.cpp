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

//******************DELETE****************
#define shubha
#ifdef shubhashis
#define debug(args...) {dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

/// ********* debug template bt Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p )
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v )
{
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ )
    {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v )
{
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ )
    {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v )
{
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ )
    {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;
//******************DELETE****************

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N=N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}




struct point
{
    int x,y;
    point()
    {

    }
    point(int a,int b)
    {
        x=a,y=b;
    }
    bool operator <(const point &c) const
    {
//        if(x==c.x)
//        {
//            return y<=c.y;
//        }
        return x<c.x;
    }
};

//const int MX = 1004;


//void BFS2d(point src)
//{
//    //CLR(visited);
//    //dist[src.x][src.y]=0;
////    visited[src.x][src.y]=1;
//    visited[src]=1;
//    queue <point> q;
//    q.push(src);
//
//    int moveNo;
//    while(!q.empty())
//    {
//        point u=q.front();
//        q.pop();
//        if(flg==0)
//        {
//            flg=1;
//            for(int i=0; i<len; i++)
//            {
//                int X=u.x+dx[i];
//                int Y=u.y+dy[i];
//                point p=point(X,Y);
//                if(X>=minR && X<=row && Y>=minC && Y<=col && visited[p]==0)
//                {
//                    debug(X,Y,minR,row,minC,col,visited[p],grid[p])
//                    visited[p]=1;
//                    //dist[X][Y]=dist[u.x][u.y]+1;
//                    q.push(p);
//                    if(grid[p]==1)
//                    {
//                        cnt++;
//                        flg=0;
//                    }
//                }
//            }
//        }
//        else
//        {
//
//        }
//    }
//    //return dist[dest.x][dest.y];
//}
//
//void DFS(point u,int moveNo)
//{
//    debug(u.x,u.y,moveNo);
//    if(grid[u]==1 && moveNo!=-1)
//    {
//        grid[u]=0;
//        cnt++;
//        DFS(u,-1);
//    }
//    visited[MP(u,moveNo)]=1;
//
//    if(moveNo==-1)
//    {
//        for(int j=0;j<len;j++)
//        {
//            int X=u.x+dx[j];
//            int Y=u.y+dy[j];
//            point p=point(X,Y);
//            if(X>=minR && X<=row && Y>=minC && Y<=col && visited[MP(p,j)]==0)
//            {
//                DFS(p,j);
//            }
//        }
//    }
//    else
//    {
//        int i=moveNo;
//        int X=u.x+dx[i];
//        int Y=u.y+dy[i];
//        point p=point(X,Y);
//        if(X>=minR && X<=row && Y>=minC && Y<=col && visited[MP(p,i)]==0)
//        {
//            DFS(p,moveNo);
//        }
//    }
////    for(int j=0;j<AdjList[u].size();j++)
////    {
////        int v=AdjList[u][j];
////        if(visited[v]==DFS_WHITE)
////        {
////            DFS(v);
////        }
////    }
//}

point dest;

map <point,bool> visited;
//map <point,bool> grid;
int row,col,minR,minC,len,cnt;

vi dx,dy;


int DFS1(point u,int moveNo)
{
    visited[u]=1;
    debug(u.x,u.y,dest.x,dest.y);
    if(u.x==dest.x && u.y==dest.y) return 1;
    int i=moveNo;
    int X=u.x+dx[i];
    int Y=u.y+dy[i];
    point p=point(X,Y);
    int res=0;
    if(X>=minR && X<=row && Y>=minC && Y<=col && visited[p]==0)
    {
        res = res || DFS1(p,moveNo);
    }
    return res;
}

vector <point> coin;

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int p,k,xx,yy;
    while(~getII(p,k))
    {
        visited.clear();
        //grid.clear();
        coin.clear();
        dx.clear();
        dy.clear();
        getII(xx,yy);
        for(int i=0; i<p; i++)
        {
            int x,y;
            getII(x,y);
            coin.PB(point(x,y));
//            grid[point(x,y)]=1;
//            debug(x,y,grid[point(x,y)]);
        }
        minR=minC=INF;
        row=col=-INF;
        for(int i=0; i<k; i++)
        {
            int x,y;
            getII(x,y);
            minR=min(minR,x);
            row=max(row,x);
            minC=min(minC,y);
            col=max(col,y);
            dx.PB(x);
            dy.PB(y);
        }
        len=dx.size();
        cnt=0;
        point tmp=point(xx,yy);
        int flg=1;
        for(int i=0;i<p && flg;i++)
        {
            int fg=0;
            for(int j=0;j<len;j++)
            {
                visited.clear();
                dest=coin[i];
                int res=DFS1(tmp,j);
                if(res==1)
                {
                    fg=1;
                    break;
                }
            }
            debug(i,fg)
            if(fg==0) flg=0;
            tmp=coin[i];
        }
//        BFS2d(point(xx,yy));
//        DFS(point(xx,yy),-1);
//        debug(cnt);
        if(flg) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}



