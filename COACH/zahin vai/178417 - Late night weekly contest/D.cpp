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

int dp[304][304][304];
int dp1[304][304];

int call(int x, int y, int z)
{
    if(x==0 && y==0 && z==0) return 0;

    int &ret = dp[x][y][z];
    if(ret!=-1) return ret;

    FOR(i,1,x)
    {
        if(!call(x-i,y,z)) return ret = 1;
    }
    FOR(i,1,y)
    {
        if(!call(x,y-i,z)) return ret = 1;
    }
    FOR(i,1,z)
    {
        if(!call(x,y,z-i)) return ret = 1;
    }

    int kk = min(x,min(y,z));
    FOR(i,1,kk)
    {
        if(!call(x-i, y-i, z-i)) return ret =1;
    }
    return ret=0;
}
int call(int x, int y)
{
    if(x==0 && y==0) return 0;

    int &ret = dp1[x][y];
    if(ret!=-1) return ret;

    FOR(i,1,x)
    {
        if(!call(x-i,y)) return ret = 1;
    }
    FOR(i,1,y)
    {
        if(!call(x,y-i)) return ret = 1;
    }

    int kk = min(x,y);
    FOR(i,1,kk)
    {
        if(!call(x-i, y-i)) return ret =1;
    }
    return 0;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    SET(dp);
    SET(dp1);
//    int nn = 40;
//    FOR(i,1,nn) FOR(j,1,nn) FOR(k,1,nn)
//    {
//        if(call(i,j,k)==0) debug(i,j,k)
//    }
//    call(300,300,300);
    while(~getI(n))
    {
        if(n==1)
        {
            int x;
            getI(x);
            if(x) printf("BitLGM\n");
            else printf("BitAryo\n");
        }
        else if(n==2)
        {
            int x,y;
            getII(x,y);
//            SET(dp);
            int kk = call(x,y);
            if(kk) printf("BitLGM\n");
            else printf("BitAryo\n");
//            if(x==y) printf("BitLGM\n");
//            else printf("BitAryo\n");
        }
        else
        {
//            SET(dp);
//            int a[3];
//            getIII(a[0],a[1],a[2]);
//            sort(a,a+3);
//            if(a[2]-a[1] == a[0]) printf("BitAryo\n");
//            else printf("BitLGM\n");
            int x,y,z;
            getIII(x,y,z);
//            debug(dp[x][y][z]);
            int kk = x^y^z;
            if(kk) printf("BitLGM\n");
            else printf("BitAryo\n");
        }
    }


    return 0;
}



