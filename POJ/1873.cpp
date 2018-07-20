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

bitset<20> bitGet(int a) {
    bitset <20> bb(a);
    return bb;
}

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

int t, n, m;

struct point
{
    ll x,y;
    /// Eucladian distance
    double distance(point p) {
        return hypot(x-p.x,y-p.y);
    }
};

#define MAX 20
point P[MAX], C[MAX], P0;

inline ll triArea2(const point &a, const point &b, const point &c) {
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

inline ll sqDist(const point &a, const point &b) {
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

inline bool comp(const point &a, const point &b) {
    ll d = triArea2(P0, a, b);
    if(d < 0) return false;
    if(!d && sqDist(P0, a) > sqDist(P0, b)) return false;
    return true;
}

void convexHull(int &np, int &nc) {
    int i, j, pos = 0;
    for(i = 1; i < np; i++)
        if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x<P[pos].x))
            pos = i;
    swap(P[0], P[pos]);
    P0 = P[0];
    sort(&P[1], &P[np], comp);
    for(i = 0; i < 3; i++) C[i] = P[i];
    for(i = j = 3; i < np; i++) {
        while(triArea2(C[j-2], C[j-1], P[i]) < 0) j--;
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
        sum += C[i].distance(P[(i+1)%n]);
    }
    return sum;
}


vector < point > vp;
vector < int > v, l;
int totLen[(1<<15)+4];
int totVal[(1<<15)+4];
double circum[(1<<15)+4];

int getAllLen(int mask)
{
    int len = 0;
    FOR(i,0,n-1)
        if(bitCheck(mask, i) == 1)
        {
            len += l[i];
        }
    return len;
}

double getCircum(int mask)
{
    int in = 0;
    FOR(i,0,n-1)
    {
        if(bitCheck(mask, i) == 0)
            P[in++] = vp[i];
    }
    int nn = in;
    if(in > 3) convexHull(in, nn);
    else
    {
        FOR(i,0,in) C[i] = P[i];
    }
    return getcircumference(nn);
}

int getVal(int mask)
{
    int len = 0;
    FOR(i,0,n-1)
        if(bitCheck(mask, i) == 1)
        {
            len += v[i];
        }
    return len;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int b;
    int flg = 0, ci=1;
    while(~getI(n))
    {
        if(!n) break;

        if(flg) pf("\n");
        flg = 1;

        vp.clear();
        l.clear();
        v.clear();

        FOR(i,1,n)
        {
            point p;
            getLL(p.x, p.y);
            int a, b;
            getII(a,b);
            vp.PB(p);
            v.PB(a);
            l.PB(b);
        }

        FOR(mask,0,(1<<n)-1)
        {
            totLen[mask] = getAllLen(mask);
            totVal[mask] = getVal(mask);
        }

        int mn = INF;
        int resMask;
        double extra;
        FOR(mask, 0, (1<<n)-1)
        {
            int tot = totVal[mask];
            if(tot > mn) continue;

            int woodAse = totLen[mask];
            double woodLagbe = getCircum(mask);
            if(!((double)woodAse < woodLagbe))
            {
                if(tot < mn)
                {
                    mn = tot;
                    resMask = mask;
                    extra = woodAse - woodLagbe;
                }
                else if(tot == mn && bitCount(mask) < bitCount(resMask))
                {
                    mn = tot;
                    resMask = mask;
                    extra = woodAse - woodLagbe;
                }
            }
        }
        pf("Forest %d\n", ci++);
        pf("Cut these trees:");
        FOR(i,0,n-1) if(bitCheck(resMask, i) == 1) pf(" %d", i+1);
        pf("\n");
        pf("Extra wood: %.2f\n", extra);
    }



    return 0;
}


