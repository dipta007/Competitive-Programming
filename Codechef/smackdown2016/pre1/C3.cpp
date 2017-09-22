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
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
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

ll ext_gcd ( ll A, ll B, ll *X, ll *Y ){
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

bool linearDiophantine ( ll A, ll B, ll C, ll *x, ll *y ) {
    ll g = gcd ( A, B );
    //debug(g)
    if ( C % g != 0 ) return false; //No Solution

    //ll a = A / g, b = B / g, c = C / g;
    ll a=A,b=B,c=1;

    ext_gcd( a, b, x, y ); //Solve ax + by = 1

    if ( g < 0 ) { //Make Sure gcd(a,b) = 1
        a *= -1; b *= -1; c *= -1;
    }

    *x *= c; *y *= c; //ax + by = c
    ll gc=labs(g);
    if(*x<0)
    {
        ll ax = labs(*x);
        ll run = B/gc;
        ll rise = A/gc;
        ll k = ax/run;
        k++;
        *x += (k*run);
        *y -= (k*rise);
    }
    if(*y<0)
    {
        ll ay = labs(*y);
        ll run = B/gc;
        ll rise = A/gc;
        ll k = ay/rise;
        k++;
        *x -= (k*run);
        *y += (k*rise);
    }
    if(*x<0 || *y<0) return false;
    return true; //Solution Exists
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        ll a,b,c,d;
        getLL(a,b);
        getLL(c,d);
        ll low=0,high=labs(a-b);

        ll res=high;
        while(low<=high)
        {
            ll mid = (low+high)/2;
            ll x,y;
            if(a>=b && linearDiophantine(c,d,mid+a+b, &x, &y))
            {
                //debug("1",x,y)
                res=mid;
                high=mid-1;
            }
            else if(a<b && linearDiophantine(c, -d, mid+a-b, &x, &y))
            {
                res=mid;
                high=mid-1;
            }
            else if(b>=a && linearDiophantine(d,-c,mid+a-b, &x, &y))
            {
//                debug("2",x,y)
                res=mid;
                high=mid-1;
            }
            else if(b<a && linearDiophantine(d,-c,mid+b-a, &x, &y))
            {
//                debug("2",x,y)
                res=mid;
                high=mid-1;
            }
//            if(linearDiophantine(c,-d,b-a+mid, &x, &y))
//            {
//                debug(x,y,mid)
//                res = mid;
//                high = mid-1;
//            }
//            else if(linearDiophantine(c,-d,b-a-mid, &x, &y))
//            {
//                debug(x,y,mid)
//                res = mid;
//                high = mid-1;
//            }
//            else if(linearDiophantine(-c, d, a-b+mid, &x, &y))
//            {
//                res = a-b+mid;
//                high = mid-1;
//            }
//            else if(linearDiophantine(-c, d, a-b-mid, &x, &y))
//            {
//                res = a-b+mid;
//                high = mid-1;
//            }
            else
            {
                low=mid+1;
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}




