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


const double EPS = 1e-12;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)          freopen(f, "w", stdout)

#define    MP(x, y)          make_pair(x, y)
#define    SZ(c)             (int)c.size()
#define    PB(x)             push_back(x)

#define    F(i,L,R)          for (int i = L; i < R; i++)
#define    FF(i,L,R)         for (int i = L; i <= R; i++)
#define    FR(i,L,R)         for (int i = L; i > R; i--)
#define    FRF(i,L,R)        for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()

#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%I64d",&a)
#define    getLL(a,b)        scanf("%I64d%I64d",&a,&b)
#define    getLLL(a,b,c)     scanf("%I64d%I64d%I64d",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getL(n)           scanf("%I64d",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
#define    ui    unsigned int
#define    us    unsigned short
#define    ld    long double


template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

//******************DELETE****************
#define shubhash
#ifdef shubhashis
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Justrip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************


double line(double x1,double y1,double x2,double y2,double x3,double y3)
{
//    double k1=(x2-x1)*(y3-y1);
//    double k2=(y2-y1)*(x3-x1);
//    double k = (k1-k2);
//    return k;
    double k1=(x2-x1)*(y3-y1);
    double k2=(y2-y1)*(x3-x1);
    double k = (k1-k2);
    return k;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    double x2,y2;
    ll a,b;

    debug(line(2,2,4,0,3,1));
    while(~getLL(a,b))
    {
        if(b==0)
        {
            printf("%.12lf\n",(double)a/2.0);
            continue;
        }
//        if(a!=0 && b==0)
//        {
//            printf("-1\n");
//            continue;
//        }

//        if(b==0)
//        {
//            if(a==0) printf("%.12lf\n",(double)1.00);
//
//        }

        x2=(double)a;
        y2=(double)b;

        double low=0.0,high=x2;
        double mid;
        double x1,y1,x3,y3;
        int flg=0;

        while(fabs(high-low)>EPS && !flg)
        {
            mid=(high+low)/2.0;
            int k=x2/mid;
            if(k%2==0)
            {
                x1=mid*k;
                y1=0;
                x3=mid*(k+1);
                y3=mid;
            }
            else
            {
                x1=mid*k;
                y1=mid;
                x3=mid*(k+1);
                y3=0;
            }
            double res=line(x1,y1,x3,y3,x2,y2);
            debug("ager",res);
            if(res>EPS) low=mid;
            else if(res<EPS) high=mid;
            if(fabs(res)<=EPS) flg=1;
            debug(res)
        }
        debug(flg,low,mid,high);
        if(low==EPS || fabs(low-1000000000.0)<=EPS || !flg) printf("-1\n");
        else printf("%.12lf\n",low/2.0);
    }

    return 0;
}

