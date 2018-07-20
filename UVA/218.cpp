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
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

/*
    ConvexHull : Graham's Scan O(n lg n), integer implementation
    P[]: holds all the points, C[]: holds points on the hull
    np: number of points in P[], nc: number of points in C[]
    to handle duplicate, call makeUnique() before calling convexHull()
    call convexHull() if you have np >= 3
    to remove co-linear points on hull, call compress() after convexHull()
*/

struct point
{
    double x,y;
    /// Eucladian distance
    double distance(point p) {
        return hypot(x-p.x,y-p.y);
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

bool equal(double a, double b)
{
    return fabs(a-b) < EPS;
}

#define MAX 10004
point P[MAX], C[MAX], P0;

inline double sqDist(const point &a, const point &b) {
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

inline bool comp(const point &a, const point &b) {
    ll d = turn(P0, a, b);
    if(d < 0) return false;
    if(!d && sqDist(P0, a) > EPS + sqDist(P0, b)) return false;
    return true;
}

inline bool normal(const point &a, const point &b) {
    return (equal(a.x, b.x) ? a.y+EPS < b.y : a.x+EPS < b.x);
}

inline bool issame(const point &a, const point &b) {
    return (equal(a.x, b.x) && equal(a.y, b.y));
}

inline void makeUnique(int &np) {
    sort(&P[0], &P[np], normal);
    np = unique(&P[0], &P[np], issame) - P;
}

void convexHull(int &np, int &nc) {
    int i, j, pos = 0;
    for(i = 1; i < np; i++)
        if(P[i].y+EPS<P[pos].y || (equal(P[i].y, P[pos].y) && P[i].x+EPS<P[pos].x))
            pos = i;
    swap(P[0], P[pos]);
    P0 = P[0];
    sort(&P[1], &P[np], comp);
    for(i = 0; i < 3; i++) C[i] = P[i];
    for(i = j = 3; i < np; i++) {
            trace(P[i].x, P[i].y);
        while(j>=2 && turn(C[j-2], C[j-1], P[i]) < 0) j--;
        C[j++] = P[i];
    }
    nc = j;
}

///পলিগন এর পরিধি return করে
double getcircumference(int n)
{
    double sum=0;
    for (int i=0; i<n; i++)
    {
        sum += C[i].distance(C[(i+1)%n]);
    }
    return sum;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, ci=1;
    while(cin >> n)
    {
        if(!n) break;
        if(ci > 1) cout << endl;
        FOR(i,0,n-1)
        {
            cin >> P[i].x >> P[i].y;
        }
        int nn;
        if(n > 3)
        {
            convexHull(n, nn);
            reverse(C, C+nn);
        }
        else
        {
            FOR(i,0,n-1) C[i] = P[i];
            nn = n;
        }

        cout << "Region #" << ci++ << ":" << endl;
        cout << setprecision(1) << fixed;
        FOR(i,0,nn-1)
        {
            cout << "(" << C[i].x << "," << C[i].y << ")-";
        }
        cout << "(" << C[0].x << "," << C[0].y << ")" << endl;
        cout << setprecision(2) << fixed;
        cout << "Perimeter length = " << getcircumference(nn) << endl;
    }

    return 0;
}


