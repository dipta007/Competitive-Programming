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

#define Xaxis 1
#define Yaxis 2
#define point 3


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        pii a,b,c,d;
        getII(a.ff, a.ss);
        getII(b.ff, b.ss);
        getII(c.ff, c.ss);
        getII(d.ff, d.ss);

        int lineOf1, lineOf2;
        if(a.ff==b.ff && a.ss==b.ss)
        {
            lineOf1 = point;
        }
        else if(a.ff == b.ff)
        {
            debug("*")
            lineOf1 = Yaxis;
            if(a.ss < b.ss) swap(a,b);
        }
        else
        {
            lineOf1 = Xaxis;
            if(a.ff < b.ff) swap(a,b);
        }

        if(c.ff==d.ff && c.ss==d.ss)
        {
            lineOf2 = point;
        }
        else if(c.ff == d.ff)
        {
            lineOf2 = Yaxis;
            if(c.ss < d.ss) swap(c,d);
        }
        else
        {
            lineOf2 = Xaxis;
            if(c.ff < d.ff) swap(c,d);
        }

        swap(a,b);
        swap(c,d);

        debug(lineOf1, lineOf2)

        int ans=0;
        if(lineOf1 == lineOf2)
        {
            debug("**", lineOf1)
            if(lineOf1==point)
            {
                if(a==c && b==d) ans = 1;
            }
            else if(lineOf1==Xaxis)
            {
                if(a.ff >= c.ff && a.ff <= d.ff) ans = 1;
                else if(b.ff >= c.ff && b.ff <= d.ff) ans = 1;
                else if(c.ff >= a.ff && c.ff <= b.ff) ans = 1;
                else if(d.ff >= a.ff && d.ff <= b.ff) ans = 1;
                debug("*a",ans)
            }
            else
            {
                if(a.ss >= c.ss && a.ss <= d.ss) ans = 1;
                else if(b.ss >= c.ss && b.ss <= d.ss) ans = 1;
                else if(c.ss >= a.ss && c.ss <= b.ss) ans = 1;
                else if(d.ss >= a.ss && d.ss <= b.ss) ans = 1;
            }
        }
        else
        {
            if(lineOf1==point)
            {
                if(a.ff >= c.ff && a.ff <= d.ff && a.ss >= c.ss && a.ss <= d.ss) ans=1;
            }
            else if(lineOf2==point)
            {
                if(c.ff >= a.ff && c.ff <= b.ff && c.ss >= a.ss && c.ss <= b.ss) ans=1;
            }
            else if(a == c || a == d) ans = 1;
            else if(b == c || b == d) ans = 1;
        }

        if(ans) printf("yes\n");
        else printf("no\n");
    }


    return 0;
}


//3
//2 1 2 1
//3 1 3 1


