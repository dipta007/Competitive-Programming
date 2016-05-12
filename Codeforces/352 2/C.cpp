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

struct data
{
    int x,y;
    double d;
    data()
    {
    }
    data(int i,int j,double dd)
    {
        x=i;
        y=j;
        d=dd;
    }
};

//bool cmp(const data &a, const data &b)
//{
//    if(a.x<b.x) return true;
//    if(a.x==b.x) return a.y<b.y;
//    return false;
//}

bool cmp1(const data &a, const data &b)
{
    if(a.d > b.d+EPS) return true;
    return false;
}

double dist(ll ax,ll ay,ll bx,ll by)
{
    return sqrt( (double) ( (ax-bx)*(ax-bx) + (ay-by)*(ay-by) ) );
}

vector <data> vd;
//vector <pii> vp;

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    double ax,ay,bx,by,rx,ry;

    while(~getF(ax))
    {
        vd.clear();
        getF(ay);
        getF(bx);
        getF(by);
        getF(rx);
        getF(ry);

        int n;
        getI(n);

        double res = 0.0;
        FOR(i,0,n-1)
        {
            int x,y;
            getII(x,y);
            //vp.PB(pii(x,y));
            vd.PB(data(x,y,dist( (ll)x, (ll)y, (ll)rx, (ll)ry )));

            res += (vd[i].d + vd[i].d);
        }
        sort(ALL(vd),cmp1);

        vector <pair <double,int> > vpa,vpb;

        FOR(i,0,n-1)
        {
            double d = dist( (ll)vd[i].x, (ll)vd[i].y, ax, ay);
            double rd = dist( (ll)vd[i].x, (ll)vd[i].y, rx, ry);
            double ab = fabs(vd[i].d - d);
            if(rd>vd[i].d+EPS) vpa.PB(MP(-1,i));
            else vpa.PB( MP(ab,i) );
        }
        FOR(i,0,n-1)
        {
            double d = dist( (ll)vd[i].x, (ll)vd[i].y, bx, by);
            double rd = dist( (ll)vd[i].x, (ll)vd[i].y, rx, ry);
            double ab = fabs(vd[i].d - d);
            if(rd>vd[i].d+EPS) vpb.PB(MP(-1,i));
            else vpb.PB( MP(ab,i) );
        }

        sort(ALLR(vpa));
        sort(ALLR(vpb));

        if(vpa[0].ss == vpb[0].ss)
        {
            double res1 = res - vpa[0].ff - vpb[1].ff;
            double res2 = res - vpa[1].ff - vpb[0].ff;
            res = min(res1,res2);
        }
        else
        {
            //debug(vpa[0].ff,vpb[0].ff)
            res = res - vpa[0].ff - vpb[0].ff;
        }
//        }
//        debug(res)
//        debug(vd[0].x,vd[0].y);
//        debug(vd[1].x,vd[1].y);
//
//        double res1 = dist((ll)ax, (ll)ay, (ll)vd[0].x, (ll)vd[0].y) - vd[0].d;
//        res1 += dist((ll)bx, (ll)by, (ll)vd[1].x, (ll)vd[1].y) - vd[1].d;
//        res1 += res;
//
//        double res2 = dist((ll)ax, (ll)ay, (ll)vd[1].x, (ll)vd[1].y) - vd[1].d;
//        res2 += dist((ll)bx, (ll)by, (ll)vd[0].x, (ll)vd[0].y) - vd[0].d;
//        res2 += res;
//
//        debug(res1,res2)

        printf("%.12lf\n",res);

//
//        vd.PB(data(ax,ay,));
//        vd.PB(data(bx,by,1));
//        sort(ALL(vd),cmp);
//        int ia=-1,ib=-1;
//        FOR(i,0,(int)vd.size()-1)
//        {
//            if(vd[i].flg==1)
//            {
//                if(ia==-1) ia=i;
//                else ib=i;
//            }
//        }
//        if(abs(ia-ib)==1)
//        {
//            double res=0.0;
//            if(ia!=0)
//            {
//                res += dist((ll)vd[ia].x,(ll)vd[ia].y,(ll)vd[ia-1].x,(ll)vd[ia-1].y);
//                res += dist((ll)rx,(ll)ry,(ll)vd[ia-1].x,(ll)vd[ia-1].y);
//            }
//            ROF(i,ia-1,0)
//            {
//
//            }
//        }

    }

    return 0;
}



