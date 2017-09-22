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

#ifdef dipta007
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

// 4 direction
int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};

string st[27];
int r,c;
int vis[40][40];

void dfs(int x, int y, char c)
{
    vis[x][y] = 1;
    st[x][y]=c;

    FOR(i,0,3)
    {
        int vx = x + dx[i];
        int vy = y + dy[i];
        if(vx>=0 && vy>=0 && vx<r && vy<c && vis[vx][vy]==0 && st[vx][vy]=='?')
        {
            dfs(vx,vy,c);
        }
    }
}

int main()
{
#ifdef dipta007
    READ("in.txt");
//        WRITE("out.txt");
#endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        cin >> r >> c;
        FOR(i,0,r-1)
        {
            cin >> st[i];
        }
        int que = 0;
        FOR(i,0,r-1)
        {
            FOR(j,0,c-1)
            {
                if(st[i][j]=='?') que++;
            }
        }

        CLR(vis);
        FOR(i,0,r-1)
        {
            FOR(j,0,c-1)
            {
                if(st[i][j]!='?')
                {
                    int rr=0;
                    FOR(k,j+1,c-1)
                    {
                        if(st[i][k]=='?')
                        {
                            rr++;
                        }
                        else break;
                    }
                    int rr1=0;
                    ROF(k,j-1,0)
                    {
                        if(st[i][k]=='?')
                        {
                            rr1++;
                        }
                        else break;
                    }
                    int cc = 0;
                    FOR(k,i+1,r-1)
                    {
                        if(st[k][j]=='?')
                        {
                            cc++;
                        }
                        else break;
                    }
                    int cc1 = 0;
                    ROF(k,i-1,0)
                    {
                        if(st[k][j]=='?')
                        {
                            cc1++;
                        }
                        else break;
                    }

                    debug(i,j,rr,rr1,cc,cc1,st[i][j]);
                    if(rr+rr1 ==1)
                    {
                        FOR(k,1,cc)
                        {
                            st[i+k][j] = st[i][j];
                        }
                        FOR(k,1,cc1)
                        {
                            st[i-k][j] = st[i][j];
                        }
                    }
                    else if(cc+cc1==1)
                    {
                        FOR(k,1,rr)
                        {
                            st[i][j+k] = st[i][j];
                        }
                        FOR(k,1,rr1)
                        {
                            st[i][j-k] = st[i][j];
                        }
                    }
                    else
                    {
                        int tot = min(rr+rr1, cc+cc1);
                        rr = rr - (tot-rr1);
                        cc = cc - (tot-cc1);

                        FOR(k,1,cc)
                        {
                            st[i+k][j] = st[i][j];
                        }
                        FOR(k,1,cc1)
                        {
                            st[i-k][j] = st[i][j];
                        }
                        FOR(k,1,rr)
                        {
                            st[i][j+k] = st[i][j];
                        }
                        FOR(k,1,rr1)
                        {
                            st[i][j-k] = st[i][j];
                        }
                    }


                }
            }
        }
//        while(que)
//        {
//            FOR(i,0,r-1)
//            {
//                FOR(j,0,c-1)
//                {
//                    if(st[i][j]=='?')
//                    {
//                        char ch='?';
//                        FOR(k,0,3)
//                        {
//                            int x = i+dx[k];
//                            int y = j+dy[k];
//                            if(x>=0 && y>=0 && x<r && y<c && st[x][y]!='?')
//                            {
//                                ch = st[x][y];
//                                break;
//                            }
//                        }
//                        if(ch!='?') que--;
//                        st[i][j]=ch;
//                    }
//                }
//            }
//        }

//        FOR(i,0,r-1)
//        {
//            FOR(j,0,c-1)
//            {
//                if(st[i][j]=='?')
//                {
//                    char ch='?';
//                    FOR(k,0,3)
//                    {
//                        int x = i+dx[k];
//                        int y = j+dy[k];
//                        if(x>=0 && y>=0 && x<r && y<c && st[x][y]!='?')
//                        {
//                            ch = st[x][y];
//                            break;
//                        }
//                    }
//                    st[i][j]=ch;
//                }
//            }
//        }
        cout << "Case #" << ci << ":" << endl;
        FOR(i,0,r-1)
        {
            cout << st[i] << endl;
        }
    }

    return 0;
}



