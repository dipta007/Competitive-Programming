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

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const double PI = 2.0 * acos(0.0);

ll MIN() { return INF; }
template <typename T, typename... Args >
inline T MIN(T a, Args... args) { return min(a, (T)MIN(args...)); }

ll MAX() { return -INF; }
template <typename T, typename... Args >
inline T MAX(T a, Args... args) { return max(a, (T)MAX(args...)); }

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

/**
    Description: Takes in two general simple polygons
                 (not necessarily convex) and computes the area of
                 their intersection.

    Complexity:  O(n^2) worst case

    Procedure:
        1. See the main function for more clarification
**/


#define EPS 1e-8

// 1 for clockwise ordering of points, -1 for counter-clockwise
#define ORDER 1

struct Point
{
    double x, y;

    bool operator < (const Point &p) const
    {
        return (y + EPS < p.y) || ((y - EPS < p.y) && (x + EPS < p.x));
    }
    bool operator == (const Point &p) const
    {
        return !(*this < p) && !(p < *this);
    }

    double cross(Point p) {
        return x*p.y-y*p.x;
    }
};

struct Triangle
{
    Point p[3];
};

//2D cross product of vectors a->b, c->d
inline double cross(const Point &a, const Point &b, const Point &c, const Point &d)
{
    return ((b.x - a.x)*(d.y - c.y) - (d.x - c.x)*(b.y - a.y));
}

// This function classifies p as either being "left of" [-1],
// "right of" [+1] or "on" [0] the line a -> b.

int leftRight(const Point &a, const Point &b, const Point &p)
{
    double res = cross(a, b, a, p);

    if (res > EPS)
        return -1;
    else if (res < -EPS)
        return 1;
    return 0;
}

// This function returns non-zero if point b in the sequence a->b->c
// is a concave point or zero if it is convex.
// (If inside angle >= 180 deg, concave, otherwise convex)
int isConcave(Point &a, Point &b, Point &c)
{
    return (ORDER*leftRight(a, b, c) <= 0);
}

// This function returns non-zero if point p is located on or
// inside the triangle <a b c>.
int isInsideTriangle(Point &a, Point &b, Point &c, Point &p)
{
    int r1 = leftRight(a, b, p);
    int r2 = leftRight(b, c, p);
    int r3 = leftRight(c, a, p);
    return ((ORDER*r1 >= 0) && (ORDER*r2 >= 0) && (ORDER*r3 >= 0));
}

// Takes in a list of n ordered points forming the polygon P, and
// a vector of n-2 triangles in T.  P is modified during the
// triangulation. (n >= 3)

void triangulate(list<Point> &P, vector<Triangle> &T)
{
    list<Point>::iterator a, b, c, q;
    Triangle t;

    T.clear();
    if (P.size() < 3) return;

    for (a=b=P.begin(), c=++b, ++c; c != P.end(); a=b, c=++b, ++c)
    {
        if (!isConcave(*a, *b, *c))
        {
            for (q = P.begin(); q != P.end(); q++)
            {
                if (q == a)
                {
                    ++q;
                    ++q;
                    continue;
                }
                if (isInsideTriangle(*a, *b, *c, *q)) break;
            }
            if (q == P.end())
            {
                t.p[0] = *a;
                t.p[1] = *b;
                t.p[2] = *c;
                T.push_back(t);

                P.erase(b);
                b = a;
                if (b != P.begin()) b--;
            }
        }
    }
}

//Finds the pt of intersection between line segments a->b and c->d
//Returns 1 if there is one point of intersection, stored in p.
//Returns 0 if there is no point of intersection, or infinitely many
int isectLineSegs(Point &a, Point &b, Point &c, Point &d, Point &p)
{
    double r, s, dn, n1, n2;

    n1 =  cross(c, d, c, a);
    n2 = -cross(a, b, a, c);
    dn =  cross(a, b, c, d);

    if ((dn > EPS) || (dn < -EPS))
    {
        r = n1/dn;
        s = n2/dn;
        if ((-EPS < r) && (r < 1+EPS) &&
                (-EPS < s) && (s < 1+EPS))
        {
            p.x = a.x + r*(b.x - a.x);
            p.y = a.y + r*(b.y - a.y);
            return 1;
        }
    }
    return 0;
}

double areaPoly(vector<Point> &P)
{
    double area = 0.0;
    vector<Point>::iterator p, q;

    for (p = P.end()-1, q = P.begin(); q != P.end(); p = q++)
    {
        area += p->x*q->y - p->y*q->x;
    }
    return area/2.0;
}

Point P0;

bool radialLessThan(const Point &a, const Point &b)
{
    return (ORDER == leftRight(P0, a, b));
}

double isectAreaTriangles(Triangle &a, Triangle &b)
{
    vector<Point> P;
    vector<Point>::iterator s, e, ne;
    Point p;
    Triangle T[2] = { a, b };
    int i, j, r, t, u, v;
    double area = 0;

    P.clear();

    for(r=1, t=0; t < 2; r = t++) for(i = 2, j = 0; j < 3; i = j++)
        {
            if(isInsideTriangle(T[r].p[0],T[r].p[1],T[r].p[2],T[t].p[i]))
                P.push_back(T[t].p[i]);
            for (u = 2, v = 0; v < 3; u = v++)
                if(isectLineSegs(T[t].p[i],T[t].p[j],T[r].p[u],T[r].p[v],p))
                    P.push_back(p);
        }

    if (!P.empty())
    {
        s = P.begin();
        e = P.end();
        sort(s, e);
        ne = unique(s, e);
        P.erase(ne, e);

        if (P.size() >= 3)
        {
            P0 = P[0];
            sort(s+1, ne, radialLessThan);
            area = areaPoly(P);
        }
    }
    return area;
}

double isectAreaGpoly(list<Point> &P, list<Point> &Q)
{
    double area = 0.0;
    vector<Triangle> S, T;
    vector<Triangle>::iterator s, t;

    triangulate(P, S);
    triangulate(Q, T);

    for (s = S.begin(); s != S.end(); s++)
        for (t = T.begin(); t != T.end(); t++)
            area += isectAreaTriangles(*s, *t);

    return -ORDER*area;
}
double getArea(vector <Point> &p)
{
    double sum=0;
    int i;
    int n = p.size();
    for (i=0; i<n; i++)
    {
        sum += p[i].cross(p[(i+1)%n]);
    }
    return fabs(sum)/2;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(1)
    {
        int ff = 1;
        int n, i, j;
        Point p;
        list<Point> P[2];
        vector < Point> vp[2];

        double sum = 0.0;
        for (j = 0; j < 2; j++)
        {
            getI(n);
            if(j==0 && n==0)
            {
                ff = 0;
                break;
            }
            P[j].clear();
            vp[j].clear();

            for (i = 0; i < n; i++)
            {
                getF(p.x);
                getF(p.y);
                P[j].push_back(p);
                vp[j].PB(p);
            }

            sum += getArea(vp[j]);
        }
        if(!ff) break;
        printf("%8.2f", sum - 2.0 * isectAreaGpoly(P[0],P[1]));
    }
    pf("\n");

    return 0;
}


