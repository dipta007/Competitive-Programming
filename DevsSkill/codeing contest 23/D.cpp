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
const int INF = 2000000000000000000LL;
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


struct point
{
    ll x,y,i;
    bool operator <(const point &b) const
    {
        if(x == b.x) return y < b.y;
        return x < b.x;
    }
    bool operator ==(const point &b) const
    {
        return (x==b.x && y==b.y);
    }
};

point i1, i2;
#define MAX 100004
int flag[MAX];

inline ll sq(const ll &x) {
    return x*x;
}

inline ll sqdist(const point &a, const point &b) {
    return sq(a.x-b.x) + sq(a.y-b.y);
}

double ans;
inline ll closestPair(point *X, point *Y, int n) {
    if(n == 1) return INF;
    if(n == 2)
    {
        ll now = sqdist(X[0], X[1]);
        if(now < ans)
        {
            ans = now;
            i1 = X[0];
            i2 = X[1];
            if(i2 < i1) swap(i1, i2);
        }
        else if(now == ans)
        {
            point p1 = X[0];
            point p2 = X[1];
            if(p2 < p1) swap(p1, p2);
            if(p1 < i1)
            {
                i1 = p1, i2 = p2;
            }
            else if(p1 == i1 && p2 < i2)
            {
                i1 = p1, i2 = p2;
            }
        }
        return now;
    }

    int i, j, k, n1, n2, ns, m = n >> 1;
    point Xm = X[m-1], *XL, *XR, *YL, *YR, *YS;
    ll lt, rt, dd;

    XL = new point[m], YL = new point[m];
    XR = new point[m+1], YR = new point[m+1];
    YS = new point[n];

    for(i = 0; i < m; i++) XL[i] = X[i], flag[X[i].i] = 0;
    for(; i < n; i++) XR[i - m] = X[i], flag[X[i].i] = 1;
    for(i = n2 = n1 = 0; i < n; i++) {
        if(!flag[Y[i].i]) YL[n1++] = Y[i];
        else YR[n2++] = Y[i];
    }

    lt = closestPair(XL, YL, n1);
    rt = closestPair(XR, YR, n2);
    dd = min(lt, rt);

    for(i = ns = 0; i < n; i++)
        if(sq(Y[i].x - Xm.x) < dd)
            YS[ns++] = Y[i];
    for(j = 0; j < ns; j++)
        for(k = j + 1; k < ns && sq(YS[k].y - YS[j].y) < dd; k++)
        {
            ll now = sqdist(YS[j], YS[k]);
            dd = min(dd, now);
            if(now < ans)
            {
                ans = now;
                i1 = YS[j];
                i2 = YS[k];
                if(i2 < i1) swap(i1, i2);
            }
            else if(now == ans)
            {
                point p1 = YS[j];
                point p2 = YS[k];
                if(p2 < p1) swap(p1, p2);
                if(p1 < i1)
                {
                    i1 = p1, i2 = p2;
                }
                else if(p1 == i1 && p2 < i2)
                {
                    i1 = p1, i2 = p2;
                }
            }
        }

    delete[] XL; delete[] XR;
    delete[] YL; delete[] YR;
    delete[] YS;

    return dd;
}

point x[100004];
point y[100004];

bool cmpx(const point &a, const point &b)
{
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
bool cmpy(const point &a, const point &b)
{
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n;
        getI(n);
        FOR(i,0,n-1)
        {
            ll xx, yy;
            getLL(xx,yy);
            x[i].x = y[i].x = xx;
            x[i].y = y[i].y = yy;
            x[i].i = y[i].i = i;
        }

        sort(x, x+n, cmpx);
        sort(y, y+n, cmpy);

        ans = 2000000000000000000LL;
        ll dd = closestPair(x, y, n);
        if(i2 < i1) swap(i1, i2);
        cout << dd << " " << i1.x << " " << i1.y << " " << i2.x << " " << i2.y << endl;
//        trace(closestPair(x, y, n), i1, i2);
    }

    return 0;
}


