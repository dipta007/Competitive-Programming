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

int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
inline double sqr(double x) {
    return x*x;
}

struct point {
    double x,y;
    point() {}
    point(double _x,double _y):
        x(_x),y(_y) {};
    bool operator==(point a)const {
        return EQ(a.x-x)==0&&EQ(a.y-y)==0;
    }
    bool operator<(point a)const {
        return EQ(a.x-x)==0?EQ(y-a.y)<0:x<a.x;
    }
    double len() {
        return hypot(x,y);
    }
    double len2() {
        return x*x+y*y;
    }
    /// Eucladian distance
    double distance(point p) {
        return hypot(x-p.x,y-p.y);
    }
    point add(point p) {
        return point(x+p.x,y+p.y);
    }
    point operator+(const point &p) const {
        return point(x+p.x,y+p.y);
    }
    point sub(point p) {
        return point(x-p.x,y-p.y);
    }
    point operator-(const point &p) const {
        return point(x-p.x,y-p.y);
    }
    point mul(double b) {
        return point(x*b,y*b);
    }
    point operator*(double b) const {
        return point(x*b,y*b);
    }
    point div(double b) {
        return point(x/b,y/b);
    }
    point operator/(double b) const {
        return point(x/b,y/b);
    }
    double dot(point p) {
        return x*p.x+y*p.y;
    }
    double cross(point p) {
        return x*p.y-y*p.x;
    }
    double rad(point a,point b) {
        point p=*this;
        return fabs(atan2(fabs(a.sub(p).cross(b.sub(p))),a.sub(p).dot(b.sub(p))));
    }
    /// মূলবিন্দু (0,0)  থেকে r দুরত্তে  নতুন একটি বিন্দু তৈরী করে যা (০,০) এবং বর্তমান বিন্দুর সাথে co-linear
    point trunc(double r) {
        double l=len();
        if (!EQ(l))return *this;
        r/=l;
        return point(x*r,y*r);
    }
    ///rotate this point counter clockwise on the basis of point p
    point rotate(point p,double angle) {
        point v=this->sub(p);
        double c=cos(angle),s=sin(angle);
        return point(p.x+v.x*c-v.y*s,     p.y+v.x*s+v.y*c);
    }
    point rotleft() {
        return point(-y,x);
    }
    point rotright() {
        return point(y,-x);
    }
    /// Point in rectangle or not
    /// rectangle : a = leftDown , b = rightTop , c is in the rectangle or not
    // remove = (eql sign) if strictly in box needed
    bool in_box(point a,point b) {
        point c = *this;
        double lox = min(a.x, b.x), hix = max(a.x, b.x);
        double loy = min(a.y, b.y), hiy = max(a.y, b.y);
        return c.x >= lox && c.x <= hix && c.y >= loy && c.y <= hiy;
    }
};

/// -1 -> Right Turn
///  1 -> Left Turn
///  0 -> Straight Line / Co-linear
int turn( point O , point A , point B) { //
    double res = (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    if( res < 0 ) return -1 ; // O->A->B is a right turn
    if( res > 0 ) return  1 ; // O->A->B is a left turn
    return 0; // O->A->B is a straight line / co-linear
}

//Find if C is between A and B or B and A
bool pointBetween ( point a, point b, point c ) {
    if ( min(a.x,b.x) <= c.x && c.x <= max(a.x,b.x) && min(a.y,b.y) <= c.y && c.y <= max(a.y,b.y) ) return true;
    else return false;
}

struct line {
    point a,b;
    line() {}
    line(point _a,point _b) {
        a=_a;
        b=_b;
    }
    bool operator==(line v) {
        return (a==v.a)&&(b==v.b);
    }
    ///inclination angle
    /// The angle between the line and x-axis,
    line(point p,double angle) {
        a=p;
        if (EQ(angle-PI/2)==0) {
            b=a.add(point(0,1));
        } else {
            b=a.add(point(1,tan(angle)));
        }
    }
    /// ax+by+c=0
    line(double _a,double _b,double _c) {
        if (EQ(_a)==0) {
            a=point(0,-_c/_b);
            b=point(1,-_c/_b);
        } else if (EQ(_b)==0) {
            a=point(-_c/_a,0);
            b=point(-_c/_a,1);
        } else {
            a=point(0,-_c/_b);
            b=point(1,(-_c-_a)/_b);
        }
    }
    void adjust() {
        if (b<a)swap(a,b);
    }
    double length() {
        return a.distance(b);
    }
    /// Straight tilt(inclination angle) angle 0 <= angle <180
    double angle() {
        double k=atan2(b.y-a.y,b.x-a.x);
        if (EQ(k)<0)k+=PI;
        if (EQ(k-PI)==0)k-=PI;
        return k;
    }
    /** Points and line segments between
         1 Counter clockwise
         2 in a clockwise
         3 parallel
    **/
    int relation(point p) {
        int c=EQ(p.sub(a).cross(b.sub(a)));
        if (c<0)return 1;
        if (c>0)return 2;
        return 3;
    }
    bool pointonseg(point p) {
        return EQ(p.sub(a).cross(b.sub(a)))==0&&EQ(p.sub(a).dot(p.sub(b)))<=0;
    }
    bool parallel(line v) {
        return EQ(b.sub(a).cross(v.b.sub(v.a)))==0;
    }
    /// If the point is int / ll use the below one, in the last of this page
    bool segmentIntersection ( line l )
    {
        point c = l.a;
        point d = l.b;
        ll s1 = turn( a, b, c );
        ll s2 = turn( a, b, d );
        ll s3 = turn( c, d, a );
        ll s4 = turn( c, d, b );

        if(s1 != s2 && s3 != s4) return true;
        if ( s1 == 0 && pointBetween ( a, b, c ) ) return true;
        else if ( s2 == 0 && pointBetween ( a, b, d ) ) return true;
        else if ( s3 == 0 && pointBetween ( c, d, a ) ) return true;
        else if ( s4 == 0 && pointBetween ( c, d, b ) ) return true;

        return false;
    }
    /**
        Need to be tested these
        2 coincides
        1 Normal Intersects
        0 Not intersect/disjoint
    **/
    int segCrossSeg(line v)
    {
        int d1=EQ(b.sub(a).cross(v.a.sub(a)));
        int d2=EQ(b.sub(a).cross(v.b.sub(a)));
        int d3=EQ(v.b.sub(v.a).cross(a.sub(v.a)));
        int d4=EQ(v.b.sub(v.a).cross(b.sub(v.a)));
        if ((d1^d2)==-2&&(d3^d4)==-2)return 2;
        return (d1==0&&EQ(v.a.sub(a).dot(v.a.sub(b)))<=0||
                d2==0&&EQ(v.b.sub(a).dot(v.b.sub(b)))<=0||
                d3==0&&EQ(a.sub(v.a).dot(a.sub(v.b)))<=0||
                d4==0&&EQ(b.sub(v.a).dot(b.sub(v.b)))<=0);
    }
    /// Use this one
    bool lineCrossSegD(line v)
    {
        point p = crossPoint(v);
        return pointBetween(a, b, p);
    }
    /**
        2 norms intersect
        1 non-standard intersection
        0 disjoint / not intersect
    **/
    int lineCrossSeg(line v) { //*this seg,  v line
        int d1=EQ(b.sub(a).cross(v.a.sub(a)));
        int d2=EQ(b.sub(a).cross(v.b.sub(a)));
        if ((d1^d2)==-2)return 2;
        return (d1==0||d2==0);
    }
    /**
        0 Parallel
        1 coincides
        2 intersect
    **/
    int lineCrossLine(line v) {
        if ((*this).parallel(v)) {
            return v.relation(a)==3;
        }
        return 2;
    }
    point crossPoint(line v) {
        double a1=v.b.sub(v.a).cross(a.sub(v.a));
        double a2=v.b.sub(v.a).cross(b.sub(v.a));
        return point((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
    }
    double disPointToLine(point p) {
        return fabs(p.sub(a).cross(b.sub(a)))/length();
    }
    /// To get only the minimum distance
    double disPointToSeg(point p) {
        if (EQ(p.sub(b).dot(a.sub(b)))<0||EQ(p.sub(a).dot(b.sub(a)))<0) {
            return min(p.distance(a),p.distance(b));
        }
        return disPointToLine(p);
    }
    /// To get the minimum distance & point call it
    double disPointToSeg(point p, point &res) {
        if (EQ(p.sub(b).dot(a.sub(b)))<0||EQ(p.sub(a).dot(b.sub(a)))<0) {
            double pa = p.distance(a);
            double pb = p.distance(b);
            if(pa+EPS < pb)
            {
                res = a;
                return pa;
            }
            else
            {
                res = b;
                return pb;
            }
        }
        res = lineProg(p);
        return disPointToLine(p);
    }
    /// Intersection point between Perpendicular line from p and this line
    /// Have to check before if there is any intersection or not
    point lineProg(point p) {
        return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a))/b.sub(a).len2()));
    }
    point symmetryPoint(point p) {
        point q=lineProg(p);
        return point(2*q.x-p.x,2*q.y-p.y);
    }
};

struct circle {
    point p;
    double r;
    circle() {}
    circle(point _p,double _r):
        p(_p),r(_r) {};
    circle(double x,double y,double _r):
        p(point(x,y)),r(_r) {};
    /// Circumcircle of triangle
    circle(point a,point b,point c) {
        p=line(a.add(b).div(2),a.add(b).div(2).add(b.sub(a).rotleft())).crossPoint(line(c.add(b).div(2),c.add(b).div(2).add(b.sub(c).rotleft())));
        r=p.distance(a);
    }
    /// Over a b two o'clock two circles of radius r
    // Not tested
    int getcircle(point a,point b,double r,circle&c1,circle&c2) {
        circle x(a,r),y(b,r);
        int t=x.pointCrossCircle(y,c1.p,c2.p);
        if (!t)return 0;
        c1.r=c2.r=r;
        return t;
    }
    /// U is tangent to the straight line through the point q circle radius r1
    // Not tested
    int getcircle(line u,point q,double r1,circle &c1,circle &c2)
    {
        double dis=u.disPointToLine(q);
        if (EQ(dis-r1*2)>0)return 0;
        if (EQ(dis)==0)
        {
            c1.p=q.add(u.b.sub(u.a).rotleft().trunc(r1));
            c2.p=q.add(u.b.sub(u.a).rotright().trunc(r1));
            c1.r=c2.r=r1;
            return 2;
        }
        line u1=line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
        line u2=line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
        circle cc=circle(q,r1);
        point p1,p2;
        if (!cc.pointCrossLine(u1,p1,p2))cc.pointCrossLine(u2,p1,p2);
        c1=circle(p1,r1);
        if (p1==p2)
        {
            c2=c1;return 1;
        }
        c2=circle(p2,r1);
        return 2;
    }
    /// Both the line u, v radius r1 of the circle tangent
    // Not tested
    int getcircle(line u,line v,double r1,circle &c1,circle &c2,circle &c3,circle &c4)
    {
        if (u.parallel(v))return 0;
        line u1=line(u.a.add(u.b.sub(u.a).rotleft().trunc(r1)),u.b.add(u.b.sub(u.a).rotleft().trunc(r1)));
        line u2=line(u.a.add(u.b.sub(u.a).rotright().trunc(r1)),u.b.add(u.b.sub(u.a).rotright().trunc(r1)));
        line v1=line(v.a.add(v.b.sub(v.a).rotleft().trunc(r1)),v.b.add(v.b.sub(v.a).rotleft().trunc(r1)));
        line v2=line(v.a.add(v.b.sub(v.a).rotright().trunc(r1)),v.b.add(v.b.sub(v.a).rotright().trunc(r1)));
        c1.r=c2.r=c3.r=c4.r=r1;
        c1.p=u1.crossPoint(v1);
        c2.p=u1.crossPoint(v2);
        c3.p=u2.crossPoint(v1);
        c4.p=u2.crossPoint(v2);
        return 4;
    }
    /// Do not intersect with both circle cx, cy tangent circle radius r1,
    // Not tested
    int getcircle(circle cx,circle cy,double r1,circle&c1,circle&c2)
    {
        circle x(cx.p,r1+cx.r),y(cy.p,r1+cy.r);
        int t=x.pointCrossCircle(y,c1.p,c2.p);
        if (!t)return 0;
        c1.r=c2.r=r1;
        return t;
    }
    /// Triangle inscribed circle
    circle(point a,point b,point c,bool t) {
        line u,v;
        double m=atan2(b.y-a.y,b.x-a.x),n=atan2(c.y-a.y,c.x-a.x);
        u.a=a;
        u.b=u.a.add(point(cos((n+m)/2),sin((n+m)/2)));
        v.a=b;
        m=atan2(a.y-b.y,a.x-b.x),n=atan2(c.y-b.y,c.x-b.x);
        v.b=v.a.add(point(cos((n+m)/2),sin((n+m)/2)));
        p=u.crossPoint(v);
        r=line(a,b).disPointToSeg(p);
    }
    bool operator==(circle v) {
        return ((p==v.p)&&EQ(r-v.r)==0);
    }
    bool operator<(circle v)const {
        return ((p<v.p)||(p==v.p)&&EQ(r-v.r)<0);
    }
    double area() {
        return PI*sqr(r);
    }
    double circumference() {
        return 2*PI*r;
    }
    /// 0 outside the circle
    /// 1 on the circle
    /// 2 inside the circle
    int relation(point b) {
        double dst=b.distance(p);
        if (EQ(dst-r)<0)return 2;
        if (EQ(dst-r)==0)return 1;
        return 0;
    }
    int relationSeg(line v) {
        double dst=v.disPointToSeg(p);
        if (EQ(dst-r)<0)return 2;
        if (EQ(dst-r)==0)return 1;
        return 0;
    }
    int relationLine(line v) {
        double dst=v.disPointToLine(p);
        if (EQ(dst-r)<0)return 2;
        if (EQ(dst-r)==0)return 1;
        return 0;
    }
    /// Relation between 2 circles
    // 5 way off / are away from
    // 4 circumscribed /outer cutting
    // 3 intersect
    // 2-cut inside/inscribed
    // 1 contains / includes
    int relationCircle(circle v) {
        double d=p.distance(v.p);
        if (EQ(d-r-v.r)>0)return 5;
        if (EQ(d-r-v.r)==0)return 4;
        double l=fabs(r-v.r);
        if (EQ(d-r-v.r)<0&&EQ(d-l)>0)return 3;
        if (EQ(d-l)==0)return 2;
        if (EQ(d-l)<0)return 1;
    }
    /// V line intersects this circle on p1 & p1 point
    int pointCrossLine(line v,point &p1,point &p2)
    {
        if (!(*this).relationLine(v))return 0;
        point a=v.lineProg(p);
        double d=v.disPointToLine(p);
        d=sqrt(r*r-d*d);
        if (EQ(d)==0)
        {
            p1=a;
            p2=a;
            return 1;
        }
        p1=a.sub(v.b.sub(v.a).trunc(d));
        p2=a.add(v.b.sub(v.a).trunc(d));
        return 2;
    }
    /// if circle are intersect
    int pointCrossCircle(circle v,point &p1,point &p2) {
        int rel=relationCircle(v);
        if (rel==1||rel==5)return 0;
        double d=p.distance(v.p);
        double l=(d+(sqr(r)-sqr(v.r))/d)/2;
        double h=sqrt(sqr(r)-sqr(l));
        p1=p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotleft().trunc(h)));
        p2=p.add(v.p.sub(p).trunc(l).add(v.p.sub(p).rotright().trunc(h)));
        if (rel==2||rel==4) {
            return 1;
        }
        return 2;
    }
    // Too little to do tangent to the circle (point and circle first crossermine the relationship)
    int tangentline(point q,line &u,line &v) {
        int x=relation(q);
        if (x==2)return 0;
        if (x==1) {
            u=line(q,q.add(q.sub(p).rotleft()));
            v=u;
            return 1;
        }
        double d=p.distance(q);
        double l=sqr(r)/d;
        double h=sqrt(sqr(r)-sqr(l));
        u=line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotleft().trunc(h))));
        v=line(q,p.add(q.sub(p).trunc(l).add(q.sub(p).rotright().trunc(h))));
        return 2;
    }
    /// circle circle intersection area
    double areaCircle(circle v) {
        int rel=relationCircle(v);
        if (rel>=4)return 0.0;
        if (rel<=2)return min(area(),v.area());
        double d=p.distance(v.p);
        double hf=(r+v.r+d)/2.0;
        double ss=2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d));
        double a1=acos((r*r+d*d-v.r*v.r)/(2.0*r*d));
        a1=a1*r*r;
        double a2=acos((v.r*v.r+d*d-r*r)/(2.0*v.r*d));
        a2=a2*v.r*v.r;
        return a1+a2-ss;
    }
    /// Circle Intersection Area
    /*
    This code assumes the circle center and radius to be integer.
    Change this when necessary.
    */
    inline double commonArea(const circle &b) {
        int dsq = p.distance(b.p);
        double d = sqrt((double)dsq);
        if(sqr(r + b.r) <= dsq) return 0;
        if(r >= b.r && sqr(r-b.r) >= dsq) return PI * b.r * b.r;
        if(r <= b.r && sqr(b.r-r) >= dsq) return PI * r * r;
        double angleA = 2.0 * acos((r * r + dsq - b.r * b.r) / (2.0 * r * d));
        double angleB = 2.0 * acos((b.r * b.r + dsq - r * r) / (2.0 * b.r * d));
        return 0.5 * (r * r * (angleA - sin(angleA)) + b.r * b.r * (angleB - sin(angleB)));
    }
    /// Haven't used it yet
    double areaTriangle(point a,point b)
    {
        if (EQ(p.sub(a).cross(p.sub(b))==0))return 0.0;
        point q[5];
        int len=0;
        q[len++]=a;
        line l(a,b);
        point p1,p2;
        if (pointCrossLine(l,q[1],q[2])==2)
        {
            if (EQ(a.sub(q[1]).dot(b.sub(q[1])))<0)q[len++]=q[1];
            if (EQ(a.sub(q[2]).dot(b.sub(q[2])))<0)q[len++]=q[2];
        }
        q[len++]=b;
        if (len==4&&(EQ(q[0].sub(q[1]).dot(q[2].sub(q[1])))>0))
            swap(q[1],q[2]);
        double res=0;
        int i;
        for (i=0;i<len-1;i++)
        {
            if (relation(q[i])==0||relation(q[i+1])==0)
            {
                double arg=p.rad(q[i],q[i+1]);
                res+=r*r*arg/2.0;
            }
            else
            {
                res+=fabs(q[i].sub(p).cross(q[i+1].sub(p))/2.0);
            }
        }
        return res;
    }
};


struct polygon {
    int n;
    #define maxp 5004
    point p[maxp];
    line l[maxp];
    polygon()
    {
        n = 0;
    }
    void add(point q)
    {
        p[n++] = q;
    }
    void getline()
    {
        for (int i = 0; i < n; i++)
        {
            l[i] = line( p[i] , p[(i+1)%n] );
        }
    }
    struct cmp
    {
        point p;
        cmp(const point &p0){p=p0;}
        bool operator()(const point &aa,const point &bb)
        {
            point a=aa,b=bb;
            int d=EQ(a.sub(p).cross(b.sub(p)));
            if (d==0)
            {
                return EQ(a.distance(p)-b.distance(p))<0;
            }
            return d>0;
        }
    };
    void norm()
    {
        point mi=p[0];
        for (int i=1;i<n;i++)mi=min(mi,p[i]);
        sort(p,p+n,cmp(mi));
    }
    void getconvex(polygon &convex)
    {
        int i,j,k;
        sort(p,p+n);
        convex.n=n;
        for (i=0;i<min(n,2);i++)
        {
            convex.p[i]=p[i];
        }
        if (n<=2)return;
        int &top=convex.n;
        top=1;
        for (i=2;i<n;i++)
        {
            while (top&&convex.p[top].sub(p[i]).cross(convex.p[top-1].sub(p[i]))<=0)
                top--;
            convex.p[++top]=p[i];
        }
        int temp=top;
        convex.p[++top]=p[n-2];
        for (i=n-3;i>=0;i--)
        {
            while (top!=temp&&convex.p[top].sub(p[i]).cross(convex.p[top-1].sub(p[i]))<=0)
                top--;
            convex.p[++top]=p[i];
        }
    }
    /**
                    বিন্দুটা পলিগন এর কোথায় আছে তা return করে
                    3 পলিগনের একটা বিন্দু
                    2 পলিগন এর লাইন এর উপর অবস্থিত
                    1 পলিগন এর ভিতরে অবস্থিত
                    0 পলিগন এর বাইরে অবস্থিত
    **/
    int relationpoint(point q)
    {
        int i,j;
        for (i=0; i<n; i++)
        {
            if (p[i]==q)return 3;
        }
        getline();
        for (i=0; i<n; i++)
        {
            if (l[i].pointonseg(q))return 2;
        }
        int cnt=0;
        for (i=0; i<n; i++)
        {
            j=(i+1)%n;
            point a = q - p[j];
            point b = p[i] - p[j];
            int k=EQ(a.cross(b));
            int u=EQ(p[i].y-q.y);
            int v=EQ(p[j].y-q.y);
            if (k>0&&u<0&&v>=0)cnt++;
            if (k<0&&v<0&&u>=0)cnt--;
        }
        return cnt!=0;
    }

    /**
        Need to be tested these
        1 Line coincides
        2 Intersect or parallel to the side
        0 No intersect
    **/
    int relationLine(line u)
    {
        int i,j,k=0;
        getline();
        for (i=0;i<n;i++)
        {
            if (l[i].segCrossSeg(u)==2)return 1;
            if (l[i].segCrossSeg(u)==1)k=1;
        }
        if (!k)return 0;
        vector<point>vp;
        for (i=0;i<n;i++)
        {
            if (l[i].segCrossSeg(u))
            {
                if (l[i].parallel(u))
                {
                    vp.push_back(u.a);
                    vp.push_back(u.b);
                    vp.push_back(l[i].a);
                    vp.push_back(l[i].b);
                    continue;
                }
                vp.push_back(l[i].crossPoint(u));
            }
        }
        sort(vp.begin(),vp.end());
        int sz=vp.size();
        for (i=0;i<sz-1;i++)
        {
            point mid=vp[i].add(vp[i+1]).div(2);
            if (relationpoint(mid)==1)return 1;
        }
        return 2;
    }
    /**
        Polygons and circles Relations
        0 part outside the circle
        A tangent to the circle of an edge
        2 is completely inside the circle
    **/
    int relationCircle(circle c)
    {
        getline();
        int i,x=2;
        if (relationpoint(c.p)!=1)return 0;
        for (i=0;i<n;i++)
        {
            if (c.relationSeg(l[i])==2)return 0;
            if (c.relationSeg(l[i])==1)x=1;
        }
        return x;
    }

    /// convex or concave
    bool isconvex()
    {
        bool s[3];
        memset(s,0,sizeof(s));
        int i,j,k;
        for (i = 0; i < n ; i++)
        {
            j = (i+1)%n;
            k = (j+1)%n;
            point a = p[j] - p[i];
            point b = p[k] - p[i];
            s[ EQ ( a.cross(b) ) + 1 ] = 1;
            if ( s[0] && s[2] )return 0;
        }
        return 1;
    }
    ///পলিগন এর পরিধি return করে
    double getcircumference()
    {
        double sum=0;
        for (int i=0; i<n; i++)
        {
            sum += p[i].distance(p[(i+1)%n]);
        }
        return sum;
    }
    ///পলিগন এর ক্ষেত্রফল return করে
    double getArea(bool signedArea = false)
    {
        double sum=0;
        int i;
        for (i=0; i<n; i++)
        {
            sum += p[i].cross(p[(i+1)%n]);
        }
        if(signedArea == false) return fabs(sum)/2;
        else return sum / 2.0;
    }
    ///পলিগন এর বিন্দুগুলা clock wise order(1) না anti clock wise order(0) এ আছে তা return করে
    bool getDirection()
    {
        double sum=0;
        int i;
        for (i=0; i<n; i++)
        {
            sum += p[i].cross(p[(i+1)%n]);
        }
        if (EQ(sum)>0)return 1;
        return 0;
    }
    ///পলিগন circle এর intersection ক্ষেত্রফল return করে
    double areaCircle(circle c)
    {
        int i,j,k,l,m;
        double ans=0;
        for (i=0; i<n; i++)
        {
            int j=(i+1)%n;
            point a = p[j] - c.p;
            point b = p[i] - c.p;
            if (EQ(a.cross(b))>=0)
            {
                ans+= c.areaTriangle(p[i],p[j]);
            }
            else
            {
                ans-= c.areaTriangle(p[i],p[j]);
            }
        }
        return fabs(ans);
    }
    /// returns center of polygon / convex
    point centerPoly()
    {
        double area = getArea();
        double factor = 1.0 / (6 * area);
        double cx = 0, cy = 0;
        int i,sz = n;
        for( i = 0 ; i < sz ; i++)
        {
            point cur = p[i] , next = p[(i + 1) % sz];
            cx += (cur.x + next.x) * (cur.x * next.y - cur.y * next.x);
            cy += (cur.y + next.y) * (cur.x * next.y - cur.y * next.x);
        }
        cx *= factor;
        cy *= factor;
        return point(cx, cy);
    }
    /// strictly should be true if p needs to be strictly contained on the polygon
    /// not on the edges
    bool containsInPoly(point P, bool strictly)
    {
        int mid, low = 1, high = n-1, idx = 1;

        while(low <= high)
        {
            mid = (low + high) >> 1;
            if(turn(p[0], P, p[mid]) > 0) low = mid + 1;
            else idx = mid, high = mid - 1;
        }

        if(!strictly && line(p[0], p[n-1]).pointonseg(P)) return true;
        if(!strictly && line(p[idx], p[idx-1]).pointonseg(P)) return true;
        if(idx == 1 || turn(p[0], P, p[n-1]) == 0) return false;
        return (turn(p[idx], P, p[idx-1]) < 0);
    }
};


int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci, 1, t)
    {
        int n;
        cin >> n;
        polygon poly;
        FOR(i,1,n)
        {
            point p;
            cin >> p.x >> p.y;
            poly.add(p);
        }

        circle c;
        cin >> c.p.x >> c.p.y;
        double p;
        cin >> p;

        double polyArea = poly.getArea();
        double need = (polyArea * p)/100.0;
        double low = 0, high = 1000;
        double res = -1;
        int loop = 16;
        while(loop--)
        {
            double mid = (low + high) / 2.0;

            c.r = mid;
            double cmnArea = poly.areaCircle(c);
//            trace(cmnArea, need, low, mid, high);
            if(cmnArea+EPS < need)
            {
                low = mid;
            }
            else
            {
                high = mid;
                res = mid;
            }
        }

        cout << "Case " << ci << ": " << (int)round(res) << endl;
    }

    return 0;
}



