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

// 4 direction
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int visitedA[10];
int visiteda[10];
char adj[104][104];
int dist[104][104];
int visited[104][104];

struct point
{
    int x,y;
};

point dest;
int n;

int BFS(point s)
{
    CLR(visitedA);
    CLR(visiteda);
    CLR(visited);
    CLR(dist);
    if(adj[s.x][s.y]>='A' && adj[s.x][s.y]<='J')
    {
        char k=adj[s.x][s.y];
        int l=k-'A';
        visitedA[l]=1;
    }
    else if(adj[s.x][s.y]>='a' && adj[s.x][s.y]<='j')
    {
        char k=adj[s.x][s.y];
        int l=k-'a';
        visiteda[l]=1;
    }
    visited[s.x][s.y]=1;
    queue <point> q;
    q.push(s);
    while(!q.empty())
    {
        point u=q.front();
        debug(u.x,u.y);
        if(u.x==n-1 && u.y==n-1) return dist[u.x][u.y];
        q.pop();
        for(int i=0;i<4;i++)
        {
            int X=u.x+dx[i];
            int Y=u.y+dy[i];
            char k=adj[X][Y];
            int l;
            if(visited[X][Y]==0)
            {
                if(k>'A' && k<='J')
                {
                    l=k-'A';
                    if(visiteda[l]==0)
                    {
                        visitedA[l]=1;
                        point p;
                        p.x=X;p.y=Y;
                        q.push(p);
                        dist[X][Y]=dist[u.x][u.y]+1;
                    }
                }
                else if(k>'a' && k<='j')
                {
                    l=k-'a';
                    if(visitedA[l]==0)
                    {
                        visiteda[l]=1;
                        point p;
                        p.x=X;p.y=Y;
                        q.push(p);
                        dist[X][Y]=dist[u.x][u.y]+1;
                    }
                }
                visited[X][Y]=1;
            }
        }
    }
    return -1;
}

int mini;

int dfs(point s,string st)
{
    visited[s.x][s.y]=1;
    if(s.x==n-1 && s.y==n-1)
    {
        int len=st.size();
        CLR(visitedA);
        CLR(visiteda);
        int flg=1;
        for(int i=0;i<len && flg;i++)
        {
            if(st[i]>='A' && st[i]<='J')
            {
                int l=st[i]-'A';
                if(visiteda[l]==1)
                {
                    flg=0;
                }
                else visitedA[l]=1;
            }
            else if(st[i]>='a' && st[i]<='j')
            {
                int l=st[i]-'a';
                if(visitedA[l]==1)
                {
                    flg=0;
                }
                else visiteda[l]=1;
            }
        }
        if(flg) mini=_min(mini,len);
    }
    for(int i=0;i<4;i++)
    {
        int X=s.x+dx[i];
        int Y=s.y+dy[i];
        if(visited[X][Y]==0)
        {
            point p;p.x=X;p.y=Y;
            dfs(p,st+adj[X][Y]);
        }
    }
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    while(~getI(n))
    {
        getchar();
        CLR(adj);
        for(int i=0;i<n;i++)
        {
            gets(adj[i]);
        }
        point src;
        src.x=0;src.y=0;
        dest.x=n-1,dest.y=n-1;
        mini=INF;
        CLR(visited);
        dfs(src,"");
        int res=mini;
        if(res==INF) printf("-1\n");
        else printf("%d\n",res);
    }

    return 0;
}

