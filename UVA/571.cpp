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
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

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

int dp[1004][1004];
bool visited[1004][1004];
int a,b,n;
vector <string> vs;

int call(int i,int j)
{
    visited[i][j]=1;
    //debug(i,j)
    if(j==n)
    {
        for(int i=0;i<vs.size();i++)
        {
            printf("%s\n",vs[i].c_str());
        }
        printf("success\n");
        return 1;
    }

    int &ret = dp[i][j];
    if(ret!=-1) return ret;

    if(i==0 && visited[a][j]==0)
    {
        ///fill A
        vs.PB("fill A");
        if(call(a,j)) return  ret=1;
        vs.pop_back();
    }
    if(j==0 && visited[i][b]==0)
    {
        ///fill B
        vs.PB("fill B");
        if(call(i,b)) return ret=1;
        vs.pop_back();
    }

    ///pour A to B
    if(b-j>0)
    {
        int k = min(i, b-j);
        vs.PB("pour A B");
        if(visited[i-k,j+k]==0 && call(i-k,j+k)) return ret=1;
        vs.pop_back();
    }


    ///pour B to A
    if(a-i>0)
    {
        int k = min(a-i,j);
        vs.PB("pour B A");
        if(visited[i+k][j-k]==0 && call(i+k,j-k)) return ret=1;
        vs.pop_back();
    }

    ///empty A
    if(i>0 && visited[0][j]==0)
    {
        vs.PB("empty A");
        if(call(0,j)) return ret=1;
        vs.pop_back();
    }

    ///empty B
    if(j>0 && visited[i][0]==0)
    {
        vs.PB("empty B");
        if(call(i,0)) return ret=1;
        vs.pop_back();
    }

    return ret = 0;

}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    while(~getIII(a,b,n))
    {
        SET(dp);
        CLR(visited);
        vs.clear();
        call(0,0);
    }

    return 0;
}


