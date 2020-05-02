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
#define vlong ll
#define    pll   pair < ll, ll>
#define SQ(a) a*a

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

/*
1. Assign hull.n
2. Take input in hull.point
3. Call findHull()
4. Convex Hull is ready in hull.convex with hull.m points in it.
*/

pll g;

vlong triArea  ( const pll &a, const pll &b, const pll &c ) {
    vlong area = a.ff * b.ss + b.ff * c.ss + c.ff * a.ss;
	area -= a.ff * c.ss + b.ff * a.ss + c.ff * b.ss;
	return area;
}

vlong sqDist ( const pll &a, const pll &b ) {
	return ( SQ(a.ff-b.ff) + SQ(a.ss-b.ss ) );
}

bool convexCompare ( const pll &a, const pll &b ) {
	vlong area = triArea ( g, a, b );
	if ( area > 0 ) return true;
	else if ( area == 0 && sqDist ( g, a ) < sqDist ( g, b ) ) return true;
	else return false;
}

class ConvexHull {
	void convexSort() { ///CCW
        g = point[0];
        FOR(i,0,n-1) {
            if ( point[i].ff < g.ff ) g = point[i];
            else if ( point[i].ff == g.ff && point[i].ss < g.ss ) g = point[i];
        }
        sort ( point, point + n, convexCompare );
    }

    public:

    int n, m; ///N is number of points in polygon and M is number of points in convex hull

    #define PPP 100004
    pll point[PPP], convex[PPP];

    void findHull() {
		convexSort();

        if ( n == 1 ) {
            convex[0] = convex[1] = point[0];
            m = 1;
            return;
        }
        convex[0] = point[n-1]; convex[1] = point[0]; convex[2] = point[1];
        int cur = 3;
        for ( int i = 2; i < n; i++ ) {
            vlong area = triArea ( convex[cur-2], convex[cur-1], point[i] );
            if ( area > 0 ) {
                convex[cur] = point[i];
                cur++;
            }
            else if ( area == 0 ) { ///Take action depending on what is required
                /*Left Vertical Line gets omitted. Manually handle it*/
                /*convex[cur] = point[i];
                cur++;*/
                ///If extra point needs to be removed
                convex[cur-1] = point[i];
            }
            else {
                cur--;
                i--;
            }
        }
        m = cur - 1;
    }

}hull;


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    while(~getI(hull.n))
    {
        FOR(i,0,hull.n-1)
        {
            int x,y;
            getII(x,y);
            hull.point[i].ff = x;
            hull.point[i].ss = y;
        }
        hull.findHull();
        printf("%d\n",hull.m);
    }


    return 0;
}



