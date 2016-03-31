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

int r,c,adj[16][16],flg;
int res;

bool check(int x,int y)
{
    if(x>=0 && x<r && y>=0 && y<c && adj[x][y]==1) return 1;
    return 0;
}

bool vis[16][16][3][1004];

int koiGhor(int x,int y)
{
    int cnt=1;
    int rowLeft=x,rowRight=x,colDown=y,colUp=y;
    while(1)
    {
        rowLeft--,rowRight++,colDown--,colUp++;
        if(check(rowLeft,y) && check(rowRight,y) && check(x,colDown) && check(x,colUp))
        {
            cnt++;
        }
        else break;
    }
    return cnt;
}

void call(int x,int y,int cnt,int tmp)
{
//    if(vis[x][y][cnt][tmp]==1) return;
//    vis[x][y][cnt][tmp]=1;
//    debug(x,y,cnt,tmp,adj[x][y])
    if(cnt>=2)
    {
        flg=1;
        res=max(res,tmp);
        return;
    }
    if(x>=r)
    {
        return;
    }
    if(y>=c)
    {
        call(x+1,0,cnt,tmp);
        return;
    }
    if(adj[x][y]==0 || adj[x][y]==3)
    {
        call(x,y+1,cnt,tmp);
        return;
    }
    call(x,y+1,cnt,tmp);

    int koita=koiGhor(x,y);

    for(int k=koita;k>=1;k--)
    {
        for(int i=x,l=1;l<=k;l++,i++)
        {
            adj[i][y]=3;
        }
        for(int i=x,l=1;l<=k;l++,i--)
        {
            adj[i][y]=3;
        }
        for(int i=y,l=1;l<=k;l++,i++)
        {
            adj[x][i]=3;
        }
        for(int i=y,l=1;l<=k;l++,i--)
        {
            adj[x][i]=3;
        }
        int ans=k+(k-1)*3;
        call(x,y+1,cnt+1,tmp*ans);
        for(int i=x,l=1;l<=k;l++,i++)
        {
            adj[i][y]=1;
        }
        for(int i=x,l=1;l<=k;l++,i--)
        {
            adj[i][y]=1;
        }
        for(int i=y,l=1;l<=k;l++,i++)
        {
            adj[x][i]=1;
        }
        for(int i=y,l=1;l<=k;l++,i--)
        {
            adj[x][i]=1;
        }
    }
}

int main() {
//    READ("in.txt");
    //WRITE("out.txt");

    while(~getII(r,c))
    {
        CLR(vis);
        getchar();
        CLR(adj);
        for(int i=0;i<r;i++)
        {
            string st;
            getline(cin,st);
            for(int j=0;j<c;j++)
            {
                if(st[j]=='G') adj[i][j]=1;
            }
        }
        flg=0;
        res=-INF;
//        for(int i=0;i<r;i++)
//        {
//            for(int j=0;j<c;j++)
//            {
//                if(adj[i][j]==1)
//                {
//                    call(i,j,0,1);
//                }
//            }
//        }
        call(0,0,0,1);
        if(flg) printf("%d\n",res);
        else printf("0\n");

    }

    return 0;
}


