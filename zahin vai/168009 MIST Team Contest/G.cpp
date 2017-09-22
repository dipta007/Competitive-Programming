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

struct triangle
{
    double x3, y3;
    double y23, x32, y31, x13;
    double det, minD, maxD;
    triangle(double x1, double y1, double x2, double y2, double a, double b)
    {
        x3 = a;
        y3 = b;
        y23 = y2 - y3;
        x32 = x3 - x2;
        y31 = y3 - y1;
        x13 = x1 - x3;
        det = y23 * x13 - x32 * y31;
        minD = min(det, 0.0);
        maxD = max(det, 0.0);
    }

    bool contains(double x, double y)
    {
        double dx = x - x3;
        double dy = y - y3;
        double a = y23 * dx + x32 * dy;
        if (a < minD || a > maxD)
            return false;
        double b = y31 * dx + x13 * dy;
        if (b < minD || b > maxD)
            return false;
        double c = det - a - b;
        if (c < minD || c > maxD)
            return false;
        return true;
    }
};

struct circle
{
    double x,y,r;
    circle(double a, double b, double c)
    {
        x = a;
        y = b;
        r = c;
    }

    bool contains(double a, double b)
    {
        double dis = (x-a)*(x-a) + (y-b)*(y-b);
        dis = sqrt(dis);
        if(dis + EPS < r || fabs(dis-r)<=EPS) return true;
        return false;
    }
};

struct square
{
    double x,y, l;
    square(double a, double b, double c)
    {
        x = a;
        y = b;
        l = c;
    }

    bool contains(double a, double b)
    {
        if(a>=x && a-x <=l && b>=y && b-y <= l) return true;
        return false;
    }
};

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        int n;
        cin >> n;
        vector < circle > vc;
        vector < triangle > vt;
        vector < square > vs;

        FOR(i,1,n)
        {
            char ch;
            cin >> ch;
            if(ch == 'C')
            {
                double x,y,z;
                cin >> x >> y >> z;
                vc.PB( circle(x,y,z) );
            }
            else if(ch == 'S')
            {
                double x,y,z;
                cin >> x >> y >> z;
                vs.PB( square(x,y,z) );
            }
            else
            {
                double x1,y1,x2,y2,x3,y3;
                cin >> x1 >> y1;
                cin >> x2 >> y2;
                cin >> x3 >> y3;
                vt.PB( triangle(x1,y1,x2,y2,x3,y3) );
            }
        }

        set < pii > st;
        FOR(i,-104, 104)
        {
            FOR(j,-104, 104)
            {
                FOR(k,0,(int)vc.size()-1)
                {
                    if(vc[k].contains(i,j)==true)
                    {
                        st.insert( MP(i,j) );
                    }
                }
                FOR(k,0,(int)vt.size()-1)
                {
                    if(vt[k].contains(i,j)==true)
                    {
                        st.insert( MP(i,j) );
                    }
                }
                FOR(k,0,(int)vs.size()-1)
                {
                    if(vs[k].contains(i,j)==true)
                    {
                        //debug(i,j)
                        st.insert( MP(i,j) );
                    }
                }
            }
        }
        cout << st.size() << endl;
    }

    return 0;
}


