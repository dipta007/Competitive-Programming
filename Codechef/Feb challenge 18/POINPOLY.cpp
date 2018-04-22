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

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define dipta00
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
    void input() {
        scanf("%lf%lf",&x,&y);
    }
    void output() {
        printf("%.2f %.2f\n",x,y);
    }
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
    double distance(point p) {
        return hypot(x-p.x,y-p.y);
    }
    point add(point p) {
        return point(x+p.x,y+p.y);
    }
    point sub(point p) {
        return point(x-p.x,y-p.y);
    }
    point mul(double b) {
        return point(x*b,y*b);
    }
    point div(double b) {
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
    point trunc(double r) { // মূলবিন্দু (0,0)  থেকে r দুরত্তে  নতুন একটি বিন্দু তৈরী করে যা (০,০) এবং বর্তমান বিন্দুর সাথে co-linear
        double l=len();
        if (!EQ(l))return *this;
        r/=l;
        return point(x*r,y*r);
    }
    point rotate(point p,double angle) { //rotate this point counter clockwise on the besis of point p
        point v=this->sub(p);
        double c=cos(angle),s=sin(angle);
        return point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }
    point rotleft() {
        return point(-y,x);
    }
    point rotright() {
        return point(y,-x);
    }
    bool in_box(point a,point b) { // rectangle : a = leftDown , b = rightTop , c is in the rectangle or not
        point c = *this;
        double lox = min(a.x, b.x), hix = max(a.x, b.x);
        double loy = min(a.y, b.y), hiy = max(a.y, b.y);
        return c.x >= lox && c.x <= hix && c.y >= loy && c.y <= hiy; // remove = (eq) if strictly in box need
    }


};

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
    //inclination angle
    line(point p,double angle) {
        a=p;
        if (EQ(angle-PI/2)==0) {
            b=a.add(point(0,1));
        } else {
            b=a.add(point(1,tan(angle)));
        }
    }
    //ax+by+c=0
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
    void input() {
        a.input();
        b.input();
    }
    void adjust() {
        if (b<a)swap(a,b);
    }
    double length() {
        return a.distance(b);
    }
    double angle() { // Straight tilt(inclination angle) angle 0 <= angle <180
        double k=atan2(b.y-a.y,b.x-a.x);
        if (EQ(k)<0)k+=PI;
        if (EQ(k-PI)==0)k-=PI;
        return k;
    }
    /*
     Points and line segments between
         1 Counter clockwise
         2 in a clockwise
         3 parallel
        */
    int relation(point p) {
        int c=EQ(p.sub(a).cross(b.sub(a)));
        if (c<0)return 1;
        if (c>0)return 2;
        return 3;
    }
    int relation(point a, point b, point c) ///a-b line c er sathe relation
    {
        int cc=EQ(c.sub(a).cross(b.sub(a)));
        if (cc<0)return 1;
        if (cc>0)return 2;
        return 3;
    }
    bool pointonseg(point p) {
        return EQ(p.sub(a).cross(b.sub(a)))==0&&EQ(p.sub(a).dot(p.sub(b)))<=0;
    }
    bool parallel(line v) {
        return EQ(b.sub(a).cross(v.b.sub(v.a)))==0;
    }
    /*
     2 norms intersect
     1 non-standard intersection
     0 disjoint / not intersect
    */
    int segcrossseg(line v) {
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
    int linecrossseg(line v) { //*this seg,  v line
        int d1=EQ(b.sub(a).cross(v.a.sub(a)));
        int d2=EQ(b.sub(a).cross(v.b.sub(a)));
        if ((d1^d2)==-2)return 2;
        return (d1==0||d2==0);
    }
    /* 0 Parallel
       1 coincides
       2 intersect */
    int linecrossline(line v) {
        if ((*this).parallel(v)) {
            return v.relation(a)==3;
        }
        return 2;
    }

    point crosspoint(line v) {
        double a1=v.b.sub(v.a).cross(a.sub(v.a));
        double a2=v.b.sub(v.a).cross(b.sub(v.a));
        return point((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
    }
    double dispointtoline(point p) {
        return fabs(p.sub(a).cross(b.sub(a)))/length();
    }
    double dispointtoseg(point p) {
        if (EQ(p.sub(b).dot(a.sub(b)))<0||EQ(p.sub(a).dot(b.sub(a)))<0) {
            return min(p.distance(a),p.distance(b));
        }
        return dispointtoline(p);
    }
    point lineprog(point p) {
        return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a))/b.sub(a).len2()));
    }
    point symmetrypoint(point p) {
        point q=lineprog(p);
        return point(2*q.x-p.x,2*q.y-p.y);
    }

};

inline int triArea2(const point &a, const point &b, const point &c) {
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}


inline bool inConvexPoly(point *C, int nc, const point &p) {
    int st = 1, en = nc - 1, mid;
    while(en - st > 1) {
        mid = (st + en)>>1;
        if(triArea2(C[0], C[mid], p) < 0) en = mid;
        else st = mid;
    }
    if(triArea2(C[0], C[st], p) < 0) return false;
    if(triArea2(C[st], C[en], p) < 0) return false;
    if(triArea2(C[en], C[0], p) < 0) return false;
    return true;
}

#define mxP 1000000001
point p[100004];
vector <point> vp;

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

   int t;
   getI(t);

   FOR(ci,1,t)
   {
       int n;
       getI(n);

       ll miniX = INF;
       ll maxyX = -INF;
       FOR(i,0,n-1)
       {
           cin >> p[i].x >> p[i].y;
           miniX = min(miniX, (ll)p[i].x);
           maxyX = max(maxyX, (ll)p[i].x);
       }

       ll nowX = miniX + 1;

       pii uporLine, nichLine;
       ll uporPointY = -INF, nichPointY = -INF;

       line ver = line(point(nowX, -mxP), point(nowX, mxP));
       FOR(i,0,n-1)
       {
           int a = i;
           int b = (i+1)%n;

           if(p[a].x > p[b].x) swap(a,b);

           line l = line(p[a], p[b]);

           debug(a,b, ver.segcrossseg(l))
           if(ver.segcrossseg(l) == 2)
           {
               debug(a,b)
               point intersectingPoint = ver.crosspoint(l);
               if(uporPointY==-INF)
               {
                   uporPointY = intersectingPoint.y;
                   uporLine = MP(a,b);
               }
               else
               {
                   nichPointY = intersectingPoint.y;
                   nichLine = MP(a,b);
               }
           }
       }

       if(uporPointY < nichPointY)
       {
           swap(uporPointY, nichPointY);
           swap(uporLine, nichLine);
       }

       // debug(nowX,uporPointY);
       // debug(nowX,nichPointY);

       int make = n/10;
       // make = 64;
       vp.clear();



       FOR(i,nichPointY+1, uporPointY-1)
       {
           vp.PB(point(nowX, i));
           // debug("sad", nowX, i)
           make--;

           if(make == 0) break;
       }

       while(make > 0 && nowX < maxyX-1)
       {
           nowX ++;
           ver = line(point(nowX, -mxP), point(nowX, mxP));

           if(ver.segcrossseg(line(p[uporLine.ff], p[uporLine.ss])) != 2)
           {
               uporLine.ff = uporLine.ss;
               uporLine.ss --;

               if(uporLine.ss < 0) uporLine.ss += n;
               uporLine.ss %= n;


           }

           point interSectingPoint = ver.crosspoint(line(p[uporLine.ff], p[uporLine.ss]));
           uporPointY = interSectingPoint.y;

           if(ver.segcrossseg(line(p[nichLine.ff], p[nichLine.ss])) != 2)
           {
               nichLine.ff = nichLine.ss;
               nichLine.ss ++;

               nichLine.ss %= n;


           }

           interSectingPoint = ver.crosspoint(line(p[nichLine.ff], p[nichLine.ss]));
           nichPointY = interSectingPoint.y;

           debug(nowX, nichPointY, uporPointY, nichLine.ff, nichLine.ss, uporLine.ff, uporLine.ss)


           FOR(i,nichPointY+1, uporPointY-1)
           {
               vp.PB(point(nowX, i));
               make--;
               if(make==0) break;
           }
       }

       if(make > 0)
       {
           printf("-1\n");
           continue;
       }

       // int ans = n/10;
       // vp.clear();
       // pii prev = p[0];
       // FOR(i,0,n-1)
       // {
       //     //debug(i)
       //     //if(i%10 == 9)
       //     {
       //         ll x = prev.ff + p[i].ff;
       //         ll y = prev.ss + p[i].ss;
       //         x/=2;
       //         y/=2;
       //
       //         if(inConvexPoly(p, n, MP(x,y)) == 1)
       //         {
       //             vp.PB(MP(x,y));
       //             ans--;
       //
       //             if(ans == 0) break;
       //         }
       //     }
       // }
       //
       // FOR(i,0,(int)vp.size()-1)
       // {
       //     printf("%d %.0f %.0f %d\n",i, vp[i].x, vp[i].y, inConvexPoly(p, n, vp[i]));
       // }
       FOR(i,0,(int)vp.size()-1)
       {
           printf("%.0f %.0f\n", vp[i].x, vp[i].y);
       }
   }

    return 0;
}
