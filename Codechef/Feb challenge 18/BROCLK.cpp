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
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    pll                pair < ll, ll >

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define dipta007
#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
#else
    #define debug(args...)  /// Just strip off all debug tokens
    #define trace(...) ///yeeeee
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

class Fraction {
public:
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
        printf ( "%lld/%lld %lf\n",num, denom, num/(denom-0.0) );
    }

    Fraction getAbs() {
      return Fraction(abs(num),denom);
    }
};

Fraction sqrt(Fraction tmp)
{

}

struct point {
    Fraction x,y;
    point() {}
    point(Fraction _x, Fraction _y)
    {
        x = _x, y = _y;
    }
    point(ll _x,ll _y)
    {
        x = Fraction(_x,1);
        y = Fraction(_y,1);
    }
    bool operator==(point a)const {
        // return ((x==a.x) && (y==a.y);
    }
    Fraction distance(point p) {
        return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);
    }

    point sub(point p) {
        return point(x-p.x,y-p.y);
    }
    point rotate(point p,double angle) { //rotate this point counter clockwise on the besis of point p
        point v=this->sub(p);
        v.x.print();
        v.y.print();
        double c=cos(angle),s=sin(angle);
        return point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
    void output()
    {
        cout << "X:" << endl;
        x.print();
        cout << "Y:" << endl;
        y.print();
    }
};

// find angle of <ABC
// angle find in radiant for  degree use x*180/PI
double find_angle(point A, point B, point C) {
    Fraction x = B.distance(C);
    Fraction y = C.distance(A);
    Fraction z = A.distance(B);
    // return -1;

    Fraction tmp = (z*z + x*x - y*y)/(Fraction(2)*z*x);
    // tmp.print();
    return acos((double)tmp.num / tmp.denom);
    // return acos((z*z + x*x - y*y)/(Fraction(2)*z*x));
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

   int t;
   cin >> t;

   FOR(ci,1,t)
   {
       ll i,d,t;
       cin >> i >> d >> t;

       // double b = (i*i - d*d);
       //
       // double ang = find_angle(point(0.0, i), point(0.0, 0.0), point(b, d));
       //
       // ang = ang * t;
       // debug(ang*180.0 / PI)
       //
       // ang = 60.0*PI / 180.0;
       double angcc = 5.23599;
       point p(0.0,i);
       point tmp = p.rotate(point(0,0), angcc);
       tmp.output();
       // debug(ang*180.0 / PI)
   }

    return 0;
}
