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

#ifdef dipta7
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

// 4 direction
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int adj[54][54];
int dis1[54][54];
pii v[2];
int dis2[54][54];
bool vis[54][54];
int r,c;
pii par[54][54];

pair < pii, pii > edge;

int bfs1(int x, int y)
{
    CLR(vis);
    CLR(dis1);
    queue <int> q;
    q.push(x);
    q.push(y);
    vis[x][y]=1;
    par[x][y] = pii(-1,-1);

    while(!q.empty())
    {
        int ux = q.front(); q.pop();
        int uy = q.front(); q.pop();

        if(ux==v[1].ff && uy==v[1].ss) return dis1[ux][uy];
        FOR(i,0,3)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            debug(vx,vy,adj[vx][vy],vis[vx][vy])
            if(vx>=0 && vy>=0 && vx<r && vy<c && adj[vx][vy]==0 && vis[vx][vy]==0)
            {
                vis[vx][vy]=1;
                dis1[vx][vy] = dis1[ux][uy]+1;
                q.push(vx);
                q.push(vy);
                debug("par",vx,vy,ux,uy)
                par[vx][vy] = pii(ux,uy);
            }
        }
    }
    return -1;
}

int bfs2(int x, int y)
{
    CLR(vis);
    CLR(dis2);
    queue <int> q;
    q.push(x);
    q.push(y);
    vis[x][y]=1;

    while(!q.empty())
    {
        int ux = q.front(); q.pop();
        int uy = q.front(); q.pop();

        debug(ux,uy)

        if(ux==v[0].ff && uy==v[0].ss) return dis2[ux][uy];
        FOR(i,0,3)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            debug(vx,vy,adj[vx][vy],vis[vx][vy],dis1[vx][vy], dis2[ux][uy])
            if(vx>=0 && vy>=0 && vx<r && vy<c && dis2[ux][uy]+1 != dis1[vx][vy] && adj[vx][vy]==0 && vis[vx][vy]==0)
            {
                if(dis1[ux][uy] == dis2[ux][uy]+1 && dis1[vx][vy]==dis2[ux][uy]) continue;
                vis[vx][vy]=1;
                dis2[vx][vy] = dis2[ux][uy]+1;
                q.push(vx);
                q.push(vy);
            }
        }
    }
    return -1;
}

int bfs3(int x, int y)
{
    CLR(vis);
    CLR(dis2);
    queue <int> q;
    q.push(x);
    q.push(y);
    vis[x][y]=1;

    while(!q.empty())
    {
        int ux = q.front(); q.pop();
        int uy = q.front(); q.pop();

        if(ux==v[0].ff && uy==v[0].ss) return dis2[ux][uy];
        FOR(i,0,3)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            if(ux==edge.ff.ff && uy==edge.ff.ss && vx == edge.ss.ff && vy==edge.ss.ss) continue;
            if(vx==edge.ff.ff && vy==edge.ff.ss && ux == edge.ss.ff && uy==edge.ss.ss) continue;
            if(vx>=0 && vy>=0 && vx<r && vy<c && adj[vx][vy]==0 && vis[vx][vy]==0)
            {
                vis[vx][vy]=1;
                dis2[vx][vy] = dis2[ux][uy]+1;
                q.push(vx);
                q.push(vy);
            }
        }
    }
    return -1;
}


void print(int x,int y)
{
    CLR(vis);
    int lx=x,ly=y;
    while(x!=-1)
    {
        vis[x][y]=1;
//        edge.ff.ff = x;
//        edge.ff.ss = y;
//        edge.ss.ff = par[x][y].ff;
//        edge.ss.ss = par[x][y].ss;

        int tx=x,ty=y;
        x = par[x][y].ff;
        y = par[tx][ty].ss;
        //debug("p",x,y)
    }
    FOR(i,0,r-1)
    {
        FOR(j,0,c-1)
        {
            if(vis[i][j]==0) dis1[i][j]=-1;
        }
    }
}

int main() {
    #ifdef dipta007
        READ("inJ.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    while(~getII(r,c))
    {
        debug(r,c)
        getchar();
        FOR(i,0,r-1)
        {
            string st;
            getline(cin,st);
            debug(st);
            FOR(j,0,c-1)
            {
                if(st[j]=='#') adj[i][j]=1;
                else if(st[j]=='.') adj[i][j]=0;
                else
                {
                    adj[i][j]=0;
                    v[st[j]-'1'].ff=i;
                    v[st[j]-'1'].ss=j;
                }
            }
        }

        int res = bfs1(v[0].ff, v[0].ss);
        debug(res);
        if(res==-1)
        {
            printf("NO\n");
            continue;
        }

//        print(v[1].ff,v[1].ss);
//        int flg=0;
//        FOR(i,0,3)
//        {
//            int x = v[0].ff + dx[i];
//            int y = v[0].ss + dy[i];
//            if(x>=0 && y>=0 && x<r && y<c && adj[x][y]==0 && dis1[x][y]==-1)
//            {
//                flg=1;
//            }
//        }
//        if(flg) printf("YES\n");
//        else printf("NO\n");
//        debug(par[3][1].ff, par[3][1].ss)
//        debug(par[2][1].ff, par[2][1].ss)
//        debug(par[1][1].ff, par[1][1].ss)
        print(v[1].ff, v[1].ss);
        debug("*")
        res = bfs2(v[1].ff, v[1].ss);
        debug(res)
        if(res==-1)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");

//        if(print(v[1].ff, v[1].ss)!=-1) printf("YES\n");
//        else printf("NO\n");

    }

    return 0;
}



