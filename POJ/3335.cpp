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
//#include <bits/stdc++.h>
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
    /// det === cross
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

#define maxp 204

struct halfplane:public line
{
    double angle;
    halfplane(){}
    /// a-->b, left side (counter clockwise)
    halfplane(point _a,point _b)
    {
        a=_a;
        b=_b;
    }
    halfplane(line v)
    {
        a=v.a;
        b=v.b;
    }
    void calcangle()
    {
        angle=atan2(b.y-a.y,b.x-a.x);
    }
    bool operator<(const halfplane &b)const
    {
        return angle<b.angle;
    }
};
struct halfplanes
{
    int n;
    halfplane hp[maxp];
    point p[maxp];
    int que[maxp];
    int st,ed;
    void push(halfplane tmp)
    {
        hp[n++]=tmp;
    }
    void unique()
    {
        int m=1,i;
        for (i=1;i<n;i++)
        {
            if (EQ(hp[i].angle-hp[i-1].angle))hp[m++]=hp[i];
            else if (EQ(hp[m-1].b.sub(hp[m-1].a).cross(hp[i].a.sub(hp[m-1].a))>0))hp[m-1]=hp[i];
        }
        n=m;
    }
    bool halfplaneinsert()
    {
        int i;
        for (i=0;i<n;i++)hp[i].calcangle();
        sort(hp,hp+n);
        unique();
        que[st=0]=0;
        que[ed=1]=1;
        p[1]=hp[0].crossPoint(hp[1]);
        for (i=2;i<n;i++)
        {
            while (st<ed&&EQ((hp[i].b.sub(hp[i].a).cross(p[ed].sub(hp[i].a))))<0)ed--;
            while (st<ed&&EQ((hp[i].b.sub(hp[i].a).cross(p[st+1].sub(hp[i].a))))<0)st++;
            que[++ed]=i;
            if (hp[i].parallel(hp[que[ed-1]]))return false;
            p[ed]=hp[i].crossPoint(hp[que[ed-1]]);
        }
        while (st<ed&&EQ(hp[que[st]].b.sub(hp[que[st]].a).cross(p[ed].sub(hp[que[st]].a)))<0)ed--;
        while (st<ed&&EQ(hp[que[ed]].b.sub(hp[que[ed]].a).cross(p[st+1].sub(hp[que[ed]].a)))<0)st++;
        if (st+1>=ed)return false;
        return true;
    }
//    void getconvex(polygon &con)
//    {
//        p[st]=hp[que[st]].crossPoint(hp[que[ed]]);
//        con.n=ed-st+1;
//        int j=st,i=0;
//        for (;j<=ed;i++,j++)
//        {
//            con.p[i]=p[j];
//        }
//    }
};

point p[1004];

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        int n;
        cin >> n;
        ROF(i,n-1,0)
        {
            cin >> p[i].x >> p[i].y;
        }

        halfplanes th;
        th.n = 0;
        FOR(i,0,n-1)
        {
            th.push( halfplane(p[i], p[(i+1)%n] ) );
        }
        if(th.halfplaneinsert()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}


