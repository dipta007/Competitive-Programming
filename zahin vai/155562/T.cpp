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

double dp1[104][104][104];
double dp2[104][104][104];
double dp3[104][104][104];
int vis1[104][104][104];
int vis2[104][104][104];
int vis3[104][104][104];


double call1(int r, int s, int p)
{
    if(p==0 && s==0)
    {
        if(r>0) return 1.0;
        return 0.0;
    }
    if(r==0) return 0.0;

    double &ret = dp1[r][s][p];
    if(vis1[r][s][p]) return ret;
    vis1[r][s][p]=1;

    double allPair = r*s + r*p + s*p;

    ret = 0.0;
    if(s>0) ret += (double)(r*s)/(allPair) * call1(r,s-1,p);
    if(r>0) ret += (double)(r*p)/(allPair) * call1(r-1,s,p);
    if(p>0) ret += (double)(s*p)/(allPair) * call1(r,s,p-1);

    return ret;
}

double call2(int r, int s, int p)
{
    if(r==0 && p==0)
    {
        if(s>0) return 1.0;
        return 0.0;
    }
    if(s==0) return 0.0;

    double &ret = dp2[r][s][p];
    if(vis2[r][s][p]) return ret;
    vis2[r][s][p]=1;

    double allPair = r*s + r*p + s*p;

    ret = 0.0;
    if(s>0) ret += (double)(r*s)/(allPair) * call2(r,s-1,p);
    if(r>0) ret += (double)(r*p)/(allPair) * call2(r-1,s,p);
    if(p>0) ret += (double)(s*p)/(allPair) * call2(r,s,p-1);

    return ret;
}

double call3(int r, int s, int p)
{
    if(r==0 && s==0)
    {
        if(p>0) return 1.0;
        return 0.0;
    }
    if(p==0) return 0.0;

    double &ret = dp3[r][s][p];
    if(vis3[r][s][p]) return ret;
    vis3[r][s][p]=1;

    double allPair = r*s + r*p + s*p;

    ret = 0.0;
    if(s>0) ret += (double)(r*s)/(allPair) * call3(r,s-1,p);
    if(r>0) ret += (double)(r*p)/(allPair) * call3(r-1,s,p);
    if(p>0) ret += (double)(s*p)/(allPair) * call3(r,s,p-1);

    return ret;
}



int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int r,s,p;
    CLR(vis1);
    CLR(vis2);
    CLR(vis3);
    while(~getIII(r,s,p))
    {
//        debug(call1(r,s,p))
        printf("%.12lf %.12lf %.12lf\n",call1(r,s,p),call2(r,s,p),call3(r,s,p));
    }

    return 0;
}



