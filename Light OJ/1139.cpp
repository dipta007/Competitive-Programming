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

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)          freopen(f, "w", stdout)
#define    MP(x, y)          make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)        for (int i = L; i <= R; i++)
#define    ROF(i,L,R)        for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(N,in)    ((bool)(a&(1<<(k))))
#define    bitOff(N,in)      (a&(~(1<<(k))))
#define    bitOn(N,in)       (a|(1<<(k)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef dipta007
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

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

struct state
{
    int ar[3][3];
    int blankX,blankY;
    int prevX,prevY;
    int g;
    int h;
    int f;
};

int countH(state a)
{
    int dist = 0;
    FOR(i,0,2)
    {
        FOR(j,0,2)
        {
            int val = a.ar[i][j] - 1;
            if(val==-1) continue;

            dist += abs((val/3)-i) + abs((val%3)-j);
        }
    }
    return dist;
}

int found;

int searchForIDA_star(state a, int g, int bound)
{
    int h = a.h;
    int f = g + h;
    if(f > bound) return f;
    if(h==0)
    {
        found = 1;
        return 0;
    }
    int mini = INF;
    state u = a;
    FOR(i,0,3)
    {
        int X = u.blankX + dx[i];
        int Y = u.blankY + dy[i];

        if(X>=0 && Y>=0 && X<3 && Y<3 && !(X==u.prevX && Y==u.prevY))
        {
            state v = u;
            swap( v.ar[v.blankX][v.blankY] , v.ar[X][Y] );

            v.h = countH(v);
            v.prevX = v.blankX;
            v.prevY = v.blankY;
            v.blankX = X;
            v.blankY = Y;
            v.g = v.g + 1;
            v.f = v.g + v.h;

            int t = searchForIDA_star(v, v.g, bound);
            if(found==1) return 0;
            if(t<mini) mini=t;
        }
    }
    return mini;
}


int IDA_star(state src)
{
    int bound = src.h;
    while(1)
    {
        int t = searchForIDA_star(src, 0, bound);
        if(found == 1) return bound;
        if(t==INF) return -1;
        bound = t;
    }
    return -1;
}

bool isSolvable(state a)
{
    vi v;
    FOR(i,0,2)
    {
        FOR(j,0,2)
        {
            if(a.ar[i][j]==0) continue;
            v.PB(a.ar[i][j]);
        }
    }
    int cnt=0;
    FOR(i,0,8)
    {
        if(v[i]!=i+1)
        {
            FOR(j,i+1,8)
            {
                if(v[j]==i+1)
                {
                    swap(v[i],v[j]);
                    cnt++;
                }
            }
        }
    }
    return cnt%2;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        state s;
        FOR(i,0,2)
        {
            FOR(j,0,2)
            {
                getI(s.ar[i][j]);
                if(s.ar[i][j]==0)
                {
                    s.blankX=i;
                    s.blankY=j;
                }
            }
        }
        s.prevX = -1;
        s.prevY = -1;
        s.g = 0;
        s.h = countH(s) ;
        s.f = s.g + s.h ;
        printf("Case %d: ",ci);
        if(isSolvable(s))
        {
            printf("impossible\n");
            continue;
        }
        found=0;
        //debug(s.g,s.h)
        int res = IDA_star(s);

        printf("%d\n",res);
    }

    return 0;
}

