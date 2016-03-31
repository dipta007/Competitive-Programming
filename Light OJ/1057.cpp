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

/// ********* debug template bt Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
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

const int MX = 24;
int grid[MX][MX];
int dist[MX][MX],visited[MX][MX];
int row,col;

int dx[]={-1,1,0,0,-1,-1,1,1};
int dy[]={0,0,-1,1,-1,1,1,-1};

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
};

int BFS2d(point src,point dest)
{
    CLR(visited);
    CLR(dist);
    dist[src.x][src.y]=0;
    visited[src.x][src.y]=1;
    queue <point> q;
    q.push(src);

    while(!q.empty())
    {
        point u=q.front();
        if(u.x==dest.x && u.y==dest.y)
        {
            return dist[dest.x][dest.y];
        }
        q.pop();
        for(int i=0;i<8;i++)
        {
            int X=u.x+dx[i];
            int Y=u.y+dy[i];
            if(X>=0 && X<row && Y>=0 && Y<col && visited[X][Y]==0)
            {
                visited[X][Y]=1;
                dist[X][Y]=dist[u.x][u.y]+1;
                q.push(point(X,Y));
            }
        }
    }
    return dist[dest.x][dest.y];
}

vector <point> vp;
int dp[(2<<15)+4][16];
int distance1[MX][MX];
int distance2[MX];
int totGold;
point src;

int call(int mask,int prev)
{
    //if(mask)

    if(__builtin_popcount(mask)==totGold)
        return distance2[prev];
    if(dp[mask][prev]!=-1) return dp[mask][prev];

    int res=INF;
    for(int i=0;i<totGold;i++)
    {
        if(check(mask,i)==0)
        {
            int cnt=distance1[prev][i]+call(Set(mask,i),i);
            res=min(res,cnt);
        }
    }
    return dp[mask][prev]=res;
}


int main() {

    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        //point src;
        int n,m;
        getII(n,m);
        getchar();
        row=n,col=m;
        CLR(grid);
        vp.clear();
        for(int i=0;i<n;i++)
        {
            string st;
            getline(cin,st);
            for(int j=0;j<m;j++)
            {
                if(st[j]=='x')
                {
                    src=point(i,j);
                }
                else if(st[j]=='g')
                {
                    grid[i][j]=1;
                    vp.PB(point(i,j));
                }
            }
        }
        //debug("*")
        CLR(distance1);
        for(int i=0;i<vp.size();i++)
        {
            //debug("p",vp[i].x,vp[i].y)
            for(int j=i+1;j<vp.size();j++)
            {
                int k = BFS2d(vp[i],vp[j]);
                //debug(i,j,k);
                distance1[i][j]=k;
                distance1[j][i]=k;
            }
        }
        for(int i=0;i<vp.size();i++)
        {
            int k= BFS2d(src,vp[i]);
            distance2[i]=k;
        }
        //debug("*")
        totGold = vp.size();
        int res=INF;

        SET(dp);
        for(int i=0;i<totGold;i++)
        {
            int cnt = distance2[i];
            cnt += call(Set(0,i),i);
            //cnt +=
            //debug(i,cnt,res)
            res = min(res,cnt);
        }
        if(res==INF) printf("Case %d: 0\n",ci);
        else
        printf("Case %d: %d\n",ci,res);
    }

    return 0;
}

