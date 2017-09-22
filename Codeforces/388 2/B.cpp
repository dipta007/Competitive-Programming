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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

struct point
{
    int x,y;
};

point P0;

inline int triArea2(const point &a, const point &b, const point &c) {
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

inline int sqDist(const point &a, const point &b) {
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

inline bool comp(const point &a, const point &b) {
    int d = triArea2(P0, a, b);
    if(d < 0) return false;
    if(!d && sqDist(P0, a) > sqDist(P0, b)) return false;
    return true;
}

inline bool cmp(const point &a, const point &b)
{
    if(a.x<b.x) return true;
    if(a.x==b.x) return a.y<b.y;
    return  false;
}

int check(point v[4])
{
    debug(v[3].x,v[3].y);
    map <pii, int> mp;
    FOR(i,0,3)
    {
        pii p = MP(v[i].x,v[i].y);
        if(mp[p]) return 0;
        mp[p]=1;
    }
//    sort(v,v+4,cmp);
//    P0 = v[0];
//    sort(v,v+4,comp);
    int cnt=0;
    FOR(a,0,3)
    {
        FOR(b,0,3)
        {
            FOR(c,0,3)
            {
                FOR(d,0,3)
                {
                    if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
                    {
                        double m1 = v[a].x + v[b].x;
                        m1 /= 2.0;
                        double m2 = v[a].y + v[b].y;
                        m2 /= 2.0;

                        double m11 = v[c].x + v[c].x;
                        m11 /= 2.0;
                        double m22 = v[d].y + v[d].y;
                        m22 /= 2.0;

                        if(m1==m11 && m2==m22) cnt++;
                    }
                }
            }
        }
    }
    debug(cnt)
    if(cnt==2) return 1;
    return 0;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    point a[4];
    FOR(i,0,2)
    {
        getII(a[i].x,a[i].y);
    }
    sort(a,a+3,cmp);
    int len = abs(a[0].x-a[1].x);
    if(len==0) len = abs(a[0].y-a[1].y);
    debug(len)
    vector < point > v;
    int cnt=0;
    FOR(i,0,2)
    {
        a[3].x = a[i].x-len;
        a[3].y = a[i].y-len;
        if(check(a))
        {
            v.PB(a[3]);
            cnt++;
        }

        a[3].x = a[i].x+len;
        a[3].y = a[i].y-len;
        if(check(a))
        {
            v.PB(a[3]);
            cnt++;
        }

        a[3].x = a[i].x-len;
        a[3].y = a[i].y+len;
        if(check(a))
        {
            v.PB(a[3]);
            cnt++;
        }

        a[3].x = a[i].x+len;
        a[3].y = a[i].y+len;
        if(check(a))
        {
            v.PB(a[3]);
            cnt++;
        }

        a[3].x = a[i].x;
        a[3].y = a[i].y+len;
        if(check(a))
        {
            v.PB(a[3]);
            cnt++;
        }

        a[3].x = a[i].x;
        a[3].y = a[i].y-len;
        if(check(a))
        {
            v.PB(a[3]);
            cnt++;
        }

        a[3].x = a[i].x+len;
        a[3].y = a[i].y;
        if(check(a))
        {
            v.PB(a[3]);
            cnt++;
        }

        a[3].x = a[i].x-len;
        a[3].y = a[i].y;
        if(check(a))
        {
            v.PB(a[3]);
            cnt++;
        }
    }
    printf("%d\n",v.size());
    FOR(i,0,(int)v.size()-1)
    {
        printf("%d %d\n",v[i].x,v[i].y);
    }

    return 0;
}



