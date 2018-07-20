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

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
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
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    sf scanf
#define    pf printf
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

#ifdef dipta00
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
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

int t, n, m;

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
    /// Eucladian distance
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
};

struct line {
    point a,b;
    line() {}
    line(point _a,point _b) {
        a=_a;
        b=_b;
    }
    point crosspoint(line v) {
        double a1=v.b.sub(v.a).cross(a.sub(v.a));
        double a2=v.b.sub(v.a).cross(b.sub(v.a));
        return point((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
    }
};
inline ll triArea2(const point &a, const point &b, const point &c) {
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

//Find if C is between A and B or B and A
bool pointBetween ( point a, point b, point c ) {
    if ( min(a.x,b.x) <= c.x && c.x <= max(a.x,b.x) && min(a.y,b.y) <= c.y && c.y <= max(a.y,b.y) ) return true;
    else return false;
}
/**
    Segment intersection in 2D integer space.
    P1, p2 makes first segment, p3, p4 makes the second segment
**/
bool segmentIntersection ( point a, point b, point c, point d ) {

    ll s1 = triArea2( a, b, c );
    ll s2 = triArea2( a, b, d );
    ll s3 = triArea2( c, d, a );
    ll s4 = triArea2( c, d, b );

    if ( s1 < 0 ) s1 = -1; else if ( s1 > 0 ) s1 = 1;
    if ( s2 < 0 ) s2 = -1; else if ( s2 > 0 ) s2 = 1;
    if ( s3 < 0 ) s3 = -1; else if ( s3 > 0 ) s3 = 1;
    if ( s4 < 0 ) s4 = -1; else if ( s4 > 0 ) s4 = 1;

    if ( s1 * s2 > 0 || s3 * s4 > 0 ) return false;

    if ( s1 && s2 && s3 && s4 ) return true;
    if ( s1 == 0 && pointBetween ( a, b, c ) ) return true;
    else if ( s2 == 0 && pointBetween ( a, b, d ) ) return true;
    else if ( s3 == 0 && pointBetween ( c, d, a ) ) return true;
    else if ( s4 == 0 && pointBetween ( c, d, b ) ) return true;

    return false;
}

line l[2004];
int ind[2004];
int mark[2004];

int get(point &p, int in = -1)
{
    double mn = INF;
    int index = -1;
    FOR(i,0,n-1)
    {
        if(i == in) continue;
        if(segmentIntersection(p, point(p.x, 0), l[i].a, l[i].b) == true)
        {
            point now = l[i].crosspoint( line(p, point(p.x, -100)));
            if(now.y < p.y)
            {
                double dis = now.distance(p);
                trace(p.x, p.y, dis, mn, i);
                if(dis+EPS < mn)
                {
                    mn = dis;
                    index = i;
                }
            }
        }
    }

    if(in == -1) return (index == -1) ? p.x : ind[index];

    trace(p.x, p.y, index);
    if(index == -1)
    {
        mark[in] = 1;
        index = p.x;
    }
    return index;
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        CLR(mark);
        CLR(ind);
        cin >> n;
        FOR(i,0,n-1)
        {
            cin >> l[i].a.x >> l[i].a.y;
            cin >> l[i].b.x >> l[i].b.y;
        }

        FOR(i,0,n-1)
        {
            if(l[i].a.y < l[i].b.y)
            {
                ind[i] = get(l[i].a, i);
            }
            else
            {
                ind[i] = get(l[i].b, i);
            }
            trace(i, ind[i]);
        }

        FOR(i,0,n-1)
        {
            int x = i;
            trace(i, mark[i]);
            while(mark[x] == 0) x = ind[x];
            mark[i] = 1;
            ind[i] = ind[x];

            trace(i, ind[i]);
        }

        int q;
        cin >> q;
        FOR(i,0,q-1)
        {
            point p;
            cin >> p.x >> p.y;
            cout << get(p) << endl;
        }
        if(ci < t) cout << endl;
    }

    return 0;
}


