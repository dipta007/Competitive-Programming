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

template <typename T> class Vector2D
{
private:
    T x;
    T y;

public:
    explicit Vector2D(const T& x=0, const T& y=0) : x(x), y(y) {}
    Vector2D(const Vector2D<T>& src) : x(src.x), y(src.y) {}
    virtual ~Vector2D() {}

    // Accessors
    inline T X() const
    {
        return x;
    }
    inline T Y() const
    {
        return y;
    }
    inline T X(const T& x)
    {
        this->x = x;
    }
    inline T Y(const T& y)
    {
        this->y = y;
    }

    // Vector arithmetic
    inline Vector2D<T> operator-() const
    {
        return Vector2D<T>(-x, -y);
    }

    inline Vector2D<T> operator+() const
    {
        return Vector2D<T>(+x, +y);
    }

    inline Vector2D<T> operator+(const Vector2D<T>& v) const
    {
        return Vector2D<T>(x+v.x, y+v.y);
    }

    inline Vector2D<T> operator-(const Vector2D<T>& v) const
    {
        return Vector2D<T>(x-v.x, y-v.y);
    }

    inline Vector2D<T> operator*(const T& s) const
    {
        return Vector2D<T>(x*s, y*s);
    }

    // Dot product
    inline T operator*(const Vector2D<T>& v) const
    {
        return x*v.x + y*v.y;
    }

    // l-2 norm
    inline T norm() const
    {
        return sqrt(x*x + y*y);
    }

    // inner angle (radians)
    static T angle(const Vector2D<T>& v1, const Vector2D<T>& v2)
    {
        return acos( (v1 * v2) / (v1.norm() * v2.norm()) );
    }
};

ll sqDis(pii a, pii b)
{
    return (a.ff-b.ff)*(a.ff-b.ff)+(a.ss-b.ss)*(a.ss-b.ss);
}

double angleBetweenLinesInRadians(pii line1Start, pii line1End, pii line2Start, pii line2End)
{
    double angle1 = atan2(line1Start.ss-line1End.ss, line1Start.ff-line1End.ff);
    double angle2 = atan2(line2Start.ss-line2End.ss, line2Start.ff-line2End.ff);
    double result = (angle2-angle1) * 180 / 3.14;
    if (result<0)
    {
        result+=360;
    }
    return result;
}

int main()
{
#ifdef dipta007
    READ("in.txt");
    WRITE("out.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    Vector2D<double> p1(50,50);
    Vector2D<double> p3(50,100);
    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int p,x,y;
        getIII(p,x,y);

        double degI = p*360.0;
        degI /= 100.0;

        ll r2 = sqDis(MP(50,50), MP(100,50));


        printf("Case #%d: ",ci);
        if(sqDis(MP(50,50), MP(x,y)) > r2)
        {
            printf("white\n");
            continue;
        }


        Vector2D<double> p2(x,y);
        double rad = Vector2D<double>::angle(p2-p1, p3-p1);
        double deg = rad * 180.0 / PI;

        //deg = angleBetweenLinesInRadians(MP(50,50), MP(50,100), MP(x,y), MP(50,50));
        if(x<50)
        {
            deg = 180.0 + ( 180.0-deg);
        }
        //debug(deg,degI)
        if(deg>degI+EPS)
        {
            printf("white\n");
            continue;
        }
        printf("black\n");
    }


    return 0;
}



