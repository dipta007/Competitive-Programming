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

int dx[]={-1,+1,0,0};
int dy[]={0,0,-1,+1};

string st[1004];
int r,c;
int visited[1004][1004],tot;
int dp[1004][1004];


int dfs(pii u)
{
    if(visited[u.ff][u.ss]==tot) return 0;
    visited[u.ff][u.ss]=tot;

    int res=1;
    for(int i=0;i<4;i++)
    {
        int X=u.ff-dx[i];
        int Y=u.ss-dy[i];
        if(X>=0 && Y>=0 && X<r && Y<c && st[X][Y]=='.')
        {
            res += dfs(pii(X,Y));
        }
    }
    return res;
}

int dfs2(pii u)
{
    if(visited[u.ff][u.ss]==tot) return 0;
    visited[u.ff][u.ss]=tot;
    if(dp[u.ff][u.ss]!=-1) return dp[u.ff][u.ss];

    int res=1;
    for(int i=0;i<4;i++)
    {
        int X=u.ff-dx[i];
        int Y=u.ss-dy[i];
        if(X>=0 && Y>=0 && X<r && Y<c && st[X][Y]=='.')
        {
            res += dfs(pii(X,Y));
        }
    }
    return res;
}

void dfs1(pii u,int cnt)
{
    if(dp[u.ff][u.ss]!=-1) return;
    dp[u.ff][u.ss]=cnt;
    for(int i=0;i<4;i++)
    {
        int X=u.ff-dx[i];
        int Y=u.ss-dy[i];
        if(X>=0 && Y>=0 && X<r && Y<c && st[X][Y]=='.')
        {
            dfs1(pii(X,Y),cnt);
        }
    }
}

//void dfs(pii u,int res)
//{
//    if(dp[u.ff][u.ss]!=-1) return;
//    dp[u.ff][u.ss]=res;
//    for(int i=0;i<4;i++)
//    {
//        int X=u.ff-dx[i];
//        int Y=u.ss-dy[i];
//        if(X>=0 && Y>=0 && X<r && Y<c && st[X][Y]=='.')
//        {
//            dfs(pii(X,Y),res);
//        }
//    }
//    return;
//}

int main() {
    READ("in.txt");
    WRITE("out.txt");
    tot=0;
    while(~getII(r,c))
    {
        getchar();
        for(int i=0;i<r;i++)
        {
            getline(cin,st[i]);
        }
        CLR(visited);
        SET(dp);
        tot=1;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(st[i][j]=='.' && visited[i][j]==0)
                {
                    int cnt=dfs(pii(i,j));
                    dfs1(pii(i,j),cnt);
                    debug(i,j,cnt)
                    //st[i][j]=(cnt%10)+48;
                }
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(st[i][j]=='*')
                {
                    int cnt=0;
                    tot++;
                    cnt=dfs2(pii(i,j));
                    debug(i,j);
                    st[i][j]=((cnt)%10)+48;
                }
            }
        }
//        for(int i=0;i<r;i++)
//        {
//            for(int j=0;j<c;j++)
//            {
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }
        for(int i=0;i<r;i++)
        {
            printf("%s\n",st[i].c_str());
        }
    }

    return 0;
}


