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
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
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
#define    iseq(a,b)          (fabs(a-b)<EPS)
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

ll ext_gcd ( ll A, ll B, ll *X, ll *Y ){
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

struct linearDiphontine
{
    ll a, b, c, x, y, run, rise;
    char solution;

    char solve ()
    {
        if ( a == 0 && b == 0 )
        {
            if ( c == 0 )
            {
                //Infinite solutions. Anything works
                return solution = 'i';
            }
            else return solution = '0'; //No solution
        }
        if ( a == 0 || b == 0 )
        {
            //Vertical or Horizontal Line
            if ( !a )
            {
                if ( c % b != 0 ) return solution = '0'; /// No Solution
                run = 1;
                rise = 0;
                return solution = 'h'; /// ( anything, c / b )
            }
            else
            {
                if ( c % a != 0 ) return solution = '0'; ///No Solution
                run = 0;
                rise = 1;
                return solution = 'v'; /// ( c / a , anything )
            }
        }

        ///Existence of solution
        ll g = ext_gcd( a, b, &x, &y );
        if ( c % g != 0 )
        {
            //No solution
            return solution = '0';
        }

        ///Simplification of equation
        a /= g;
        b /= g;
        c /= g;

        ///Bezout's Identity to Original Equation
        ext_gcd ( a, b, &x, &y );
        x *= c;
        y *= c;

        ///run and rise calculation
        run = b;
        rise = -a;
        if ( run < 0 )
        {
            run *= -1;
            rise *= -1;
        }

        return solution = '1';
    }

    ///Move solution near to vertical line x = p
    void moveNearVerticalLine( int p )
    {
        if ( run == 0 ) return; /// Both are vertical
        ll jump = ( p - x ) / run;
        x += jump * run;
        y += jump * rise;

        if ( x < p )   ///Keep solution on right of the line
        {
            x += run;
            y += rise;
        }
    }

    void moveNearHorizontalLine( int p )
    {
        if ( rise == 0 ) return; /// Both are horizontal
        ll jump = ( p - y ) / rise;
        x += jump * run;
        y += jump * rise;

        if ( y < p )   ///Keep solution above the line
        {
            if ( rise > 0 )
            {
                x += run;
                y += rise;
            }
            else
            {
                x -= run;
                y -= rise;
            }
        }
    }
};

int main()
{
#ifdef dipta007
    READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        ll a,b,c;
        getLLL(a,b,c);

        ll x1,y1,x2,y2;
        getLL(x1,y1);
        getLL(x2,y2);

        linearDiphontine ld;
        ld.a = a;
        ld.b = b;
        ld.c = c;
        ld.solve();

        ld.moveNearHorizontalLine(x1);
        ll x = ld.x;
        ll y = ld.y;
        ll run = ld.run;
        ll rise = ld.rise;

        ll xx = abs(x2-x)/run;
        ll yy = (y2-y)/(rise);
        debug(xx,yy)
        printf("Case %d: %d\n",ci,min(xx,yy));

    }

    return 0;
}



