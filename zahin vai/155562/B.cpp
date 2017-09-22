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
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 unsigned long long
#define    ull 	 unsigned long long
#define    pll   pair < ll, ll >

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

class Fraction {
    ll num, denom;

    void simplify() {
        ll g = gcd ( num, denom );
        num /= g;
        denom /= g;
        if ( denom < 0 ) {
            num *= -1;
            denom *= -1;
        }
    }

public:

    ///First deal with initiation of the class
    Fraction () {
        num = 0;
        denom = 1;
    }
    Fraction ( ll a, ll b ) {
        num = a;
        denom = b;
        simplify();
    }
    Fraction ( ll x ) {
        num = x;
        denom = 1;
    }
    Fraction ( pll x ) {
        num = x.ff;
        denom = x.ss;
        simplify();
    }
    Fraction ( const Fraction &b ) {
        num = b.num;
        denom = b.denom;
    }
    void operator = ( ll x ) {
        num = x;
        denom = 1;
    }
    void operator = ( pll x ) {
        num = x.ff;
        denom = x.ss;
        simplify();
    }
    void operator = ( Fraction b ) {
        num = b.num;
        denom = b.denom;
    }

    ///Basic Arithmetic operations
    Fraction operator - () { ///Negation
        return Fraction( -num, denom );
    }
    Fraction operator + ( Fraction b ) { ///Addition
        Fraction res;
        res.denom = abs( lcm(denom,b.denom) );
        res.num = (res.denom/denom)*num + (res.denom/b.denom)*b.num;
        res.simplify();
        return res;
    }
    Fraction operator - ( Fraction b ) { ///Subtraction
        return (*this) + (-b);
    }
    Fraction operator * ( Fraction b ) {
        Fraction res ( b.num / gcd(b.num,denom), b.denom / gcd(b.denom,num) );
        res.num *= num / gcd(num,b.denom);
        res.denom *= denom / gcd(denom,b.num);
        res.simplify();
        return res;
    }
    Fraction operator / ( Fraction b ) { ///Division
        Fraction rev ( b.denom, b.num );
        if ( rev.denom < 0 ) {
            rev.denom *= -1;
            rev.num *= -1;
        }
        return (*this)*rev;
    }

    ///Basic Arithmetic Operations overloaded
    void operator += ( Fraction b ) {
        *this = *this + b;
    }
    void operator -= ( Fraction b ) {
        *this = *this - b;
    }
    void operator *= ( Fraction b ) {
        *this = *this * b;
    }
    void operator /= ( Fraction b ) {
        *this = *this / b;
    }

    ///Comparison
    bool operator == ( Fraction b ) {
        if ( num == b.num && denom == b.denom ) return true;
        else return false;
    }
    bool operator < ( Fraction b ) {
        if ( num * b.denom < b.num * denom ) return true;
        else return false;
    }
    bool operator > ( Fraction b ) {
        return ( b < *this );
    }
    bool operator <= ( Fraction b ) {
        if ( *this == b || *this < b ) return true;
        else return false;
    }
    bool operator >= ( Fraction b ) {
        return ( b <= *this );
    }

    ///Output
    void print() {
        if(denom==1) printf("%llu\n",num);
        else printf ( "%llu/%llu\n",num, denom );
    }

    Fraction getAbs() {
      return Fraction(abs(num),denom);
    }
};

Fraction dp[30][300];
bool vis[30][300];
Fraction pp(1,6);
int x,n;

Fraction call(int in, int koto)
{
    if(in>=n)
    {
        if(koto >= x) return 1.0;
        return 0.0;
    }
    if(vis[in][koto]) return dp[in][koto];
    vis[in][koto] = 1;
    Fraction res;
    FOR(i,1,6)
    {
        res += pp * call(in+1, koto+i);
    }
    dp[in][koto]=res;
    return res;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int k;
    while(~getII(n,k))
    {
        if(n==0 && k==0) break;
        x = k;
        CLR(vis);
        Fraction res = call(0, 0);
        res.print();
    }
    return 0;
}


