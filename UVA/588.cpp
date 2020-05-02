//#include <algorithm>
//#include <bitset>
//#include <cassert>
//#include <cctype>
//#include <climits>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <fstream>
//#include <iostream>
//#include <iomanip>
//#include <iterator>
//#include <list>
//#include <map>
//#include <numeric>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <string>
//#include <utility>
//#include <vector>
#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getF(n)           scanf("%lf",&n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    ranL(a, b)         ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define    ranI(a, b)         ((((ll)rand() * rand()) % ((b) - (a) + 1)) + (a))
#define    ranF(a, b)         (((double)rand()/RAND_MAX)*((b) - (a)) + (a))
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    setInf(ar)         memset(ar,126,sizeof ar)
#define    ff 	              first
#define    ss 	              second
#define    sf                 scanf
#define    pf                 printf

typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector < int >     vi;
typedef    vector < vi >      vii;
typedef    pair < int, int>   pii;
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

#ifdef dipta007
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1)
{
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1<<" | ";
    __f(comma+1, args...);
}
#else
#define debug(args...)  /// Just strip off all debug tokens
#define trace(...) ///yeeeee
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const double PI = 2.0 * acos(0.0);

ll MIN()
{
    return INF;
}
template <typename T, typename... Args >
inline T MIN(T a, Args... args)
{
    return min(a, (T)MIN(args...));
}

ll MAX()
{
    return -INF;
}
template <typename T, typename... Args >
inline T MAX(T a, Args... args)
{
    return max(a, (T)MAX(args...));
}

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

inline int EQ (double x)
{
    return x < -EPS ? -1 : (x > EPS);
}
class point
{
public:
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    point(const point &p) : x(p.x), y(p.y)    {}
    double Magnitude()
    {
        return sqrt(x*x+y*y);
    }

    point operator+(const point &p) const
    {
        return point(x+p.x,y+p.y);
    }
    point operator-(const point &p) const
    {
        return point(x-p.x,y-p.y);
    }
    point operator*(double b) const
    {
        return point(x*b,y*b);
    }
    point operator/(double b) const
    {
        return point(x/b,y/b);
    }
    double cross(const point &u)
    {
        return x*u.y - y*u.x;
    }
};

double cross(point p, point q)
{
    return p.x*q.y-p.y*q.x;
}

typedef point Vector;
typedef vector<point> Polygon;

struct DirLine
{
    point p;
    Vector v;
    double ang;
    DirLine () {}
//    DirLine (point p, Vector v): p(p), v(v) { ang = atan2(v.y, v.x); }
    //adds the left of line p-q
    DirLine (point p, point q)
    {
        this->p = p;
        this->v.x = q.x-p.x;
        this->v.y = q.y-p.y;
        ang = atan2(v.y, v.x);
    }
    bool operator < (const DirLine& u) const
    {
        return ang < u.ang;
    }
};

#define maxp 104
struct halfplane {
    int n;
    DirLine li[maxp]; /// Input lines
    void init() {
        n = 0;
    }
    void push(point &p, point &q) {
        li[n++] = DirLine(p, q);
    }
    bool getIntersection(point p, Vector v, point q, Vector w, point& o)
    {
        if (EQ(cross(v, w)) == 0) return false;
        Vector u = p - q;
        double k = cross(w, u) / cross(v, w);
        o = p + v * k;
        return true;
    }
    bool onLeft(DirLine l, point p)
    {
        return EQ(l.v.cross(p-l.p)) >= 0;
    }
    int halfPlaneIntersection(point* poly)
    {
        sort(li, li + n);

        int first, last;
        point* p = new point[n];
        DirLine* q = new DirLine[n];
        q[first=last=0] = li[0];

        for (int i = 1; i < n; i++)
        {
            while (first < last && !onLeft(li[i], p[last-1])) last--;
            while (first < last && !onLeft(li[i], p[first])) first++;
            q[++last] = li[i];

            if (EQ(q[last].v.cross(q[last-1].v)) == 0)
            {
                last--;
                if (onLeft(q[last], li[i].p)) q[last] = li[i];
            }

            if (first < last)
                getIntersection(q[last-1].p, q[last-1].v, q[last].p, q[last].v, p[last-1]);
        }

        while (first < last && !onLeft(q[first], p[last-1])) last--;
        if (last - first <= 1)
        {
            delete [] p;
            delete [] q;
            return 0;
        }
        getIntersection(q[last].p, q[last].v, q[first].p, q[first].v, p[last]);

        int m = 0;
        for (int i = first; i <= last; i++) poly[m++] = p[i];
        delete [] p;
        delete [] q;
        return m;
    }
} th;

point p[104];

int main()
{
#ifdef dipta007
    //READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ci=1;
    while(cin >> n && n)
    {

        FOR(i,0,n-1)
        {
            int x, y;
            cin >> x >> y;
            p[i] = point(x, y);
        }

        th.init();
        FOR(i,0,n-1)
        {
            th.push(p[(i+1)%n], p[i]);
        }

        int sz = th.halfPlaneIntersection(p);
        trace(sz);

        cout << "Floor #" << ci++ << endl;
        if(sz == 0) cout << "Surveillance is impossible." << endl;
        else cout << "Surveillance is possible." << endl;
        cout << endl;
    }

    return 0;
}



