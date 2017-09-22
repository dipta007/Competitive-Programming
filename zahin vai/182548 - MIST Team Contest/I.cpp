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
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
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

double logg(double x, double a)
{
    if(x<EPS)
    {
        if(a<EPS) return 1;
        return -10000.0;
    }
    return a*log10(x);
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int s;
    while(~getI(s))
    {
        int a,b,c;
        getIII(a,b,c);

        double low1 = 0.0, high1 = (double)s;
        double y1,y2;
        int c1 = 444;
        while(c1--)
        {
            double m11 = (low1 * 2.0 + high1) / 3.0; /// X er 1 ta vag

            int c2 = 444;
            double low2 = 0.0, high2 = ((double)s-m11);
            while(c2--)
            {
                /// Y er 2 ta
                double m12 = (low2 * 2.0 + high2) / 3.0;
                double m22 = (low2 + high2 * 2.0) / 3.0;

                double z1 = (double)s-m11-m12;
                double z2 = (double)s-m11-m22;

                double now1 = logg(m11, a) + logg(m12, b) + logg(z1, c);
                double now2 = logg(m11, a) + logg(m22, b) + logg(z2, c);

                if(now1 > now2+EPS)
                {
                    high2 = m22;
                }
                else
                {
                    low2 = m12;
                }
            }
            y1 = (low2 + high2) / 2.0;
            double z1 = (double)s-y1-m11;
            double now1 = logg(m11, a) + logg(y1, b) + logg(z1, c);

            double m21 = (low1 + high1 * 2.0) / 3.0;
            c2 = 444;
            low2 = 0.0, high2 = ((double)s-m21);
            while(c2--)
            {
                double m12 = (low2 * 2.0 + high2) / 3.0;
                double m22 = (low2 + high2 * 2.0) / 3.0;

                double z1 = (double)s-m21-m12;
                double z2 = (double)s-m21-m22;

                double now1 = logg(m21, a) + logg(m12, b) + logg(z1, c);
                double now2 = logg(m21, a) + logg(m22, b) + logg(z2, c);

                if(now1 > now2+EPS)
                {
                    high2 = m22;
                }
                else
                {
                    low2 = m12;
                }
            }
            y2 = (low2 + high2) / 2.0;
            double z2 = (double)s-y2-m21;
            double now2 = logg(m21, a) + logg(y2, b) + logg(z2, c);

            if(now1 > now2 + EPS)
            {
                high1 = m21;
            }
            else
            {
                low1 = m11;
            }
        }
        double xx = (low1 + high1)/2.0;
        double yy = (y1+y2)/2.0;
        double zz = (double)s-xx-yy;
        printf("%.10lf %.10lf %.10lf\n",xx,yy,zz);
        debug((low1+high1)/2.0, low1, high1,y1,y2)


//        double maxy = -1000;;
//        double xx,yy,zz;
//        FOR(x,0,s)
//        {
//            FOR(y,0,s-x)
//            {
//                int z = s - x - y;
//                if(x<0 || y<0 || z<0) continue;
//                double now = logg(x,a) + logg(y,b) + logg(z,c);
//
//
//                debug(now, x,y,z)
//                if(now > maxy + EPS)
//                {
//                    maxy = now;
//                    xx = x;
//                    yy = y;
//                    zz = z;
//                }
//            }
//        }
//        debug(logg(7.2,a) + logg(1.8,b) + logg(0,c))
//        debug(logg(xx,a) + logg(yy,b) + logg(zz,c))
//        printf("%.10lf %.10lf %.10lf\n",xx,yy,zz);
    }

    return 0;
}



