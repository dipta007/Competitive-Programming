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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    rep(i,n)          for(i=1;i<=n;i++)
#define    repI(i,n)         for(i=0;i<n;i++)
#define    F(i,L,R)	         for (int i = L; i < R; i++)
#define    FF(i,L,R) 	     for (int i = L; i <= R; i++)
#define    FR(i,L,R) 	     for (int i = L; i > R; i--)
#define    FRF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double


template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

//******************DELETE****************
#define shubhashis
#ifdef shubhashis
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

int bitOn(int N,int pos)
{
    return N=N | (1<<pos);
}
int bitOff(int N,int pos)
{
    return N=N & ~(1<<pos);
}
bool bitCheck(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

struct data
{
    int in;
    double val;
};

vector <data> res;

bool cmp(const data &a,const data &b)
{
    if(a.val>b.val+EPS) return true;
    if(fabs(a.val-b.val)<=EPS)
    {
        return a.in<b.in;
    }
    return false;
}

void calc(double x,double y,double z,int in)
{
    double k = pow(y,z);
    ll ik = (ll)round(k*10.0);
    //debug(k,ik)
    k=(double)ik/10.0;

    data d;
    d.val=pow(x,k);
    ik=(ll)round(d.val*10.0);
    d.val=(double)ik/10.0;
    d.in=in;

    res.PB(d);
}

void calc1(double x,double y,double z,int in)
{
    double k = y*z;
//    double k = pow(x,y);
    ll ik = (ll)round(k*10.0);
    k=(double)ik/10.0;

    data d;
//    d.val=pow(k,z);
    d.val=pow(x,k);
    ik=(ll)round(d.val*10.0);
    d.val=(double)ik/10.0;
    d.in=in;

    res.PB(d);
}

string st[] = {"x^y^z","x^z^y", "(x^y)^z","(x^z)^y","y^x^z","y^z^x", "(y^x)^z","(y^z)^x","z^x^y","z^y^x", "(z^x)^y","(z^y)^x"};

int main() {
//    READ("in.txt");
    //WRITE("out.txt");

    double a,b,c;
    while(~getF(a))
    {
        getF(b);
        getF(c);
//        vector <pair<double,char> > vp;
//        vp.PB(MP(a,'x'));
//        vp.PB(MP(b,'y'));
//        vp.PB(MP(c,'z'));

        res.clear();

        calc(a,b,c,1);
        calc(a,c,b,2);
        calc(b,a,c,5);
        calc(b,c,a,6);
        calc(c,a,b,9);
        calc(c,b,a,10);

        calc1(a,b,c,3);
        calc1(a,c,b,4);
        calc1(b,a,c,7);
        calc1(b,c,a,8);
        calc1(c,a,b,11);
        calc1(c,b,a,12);

        sort(ALL(res),cmp);

//        for(int i=0;i<12;i++)
//        {
//            debug(res[i].val,res[i].in)
//        }
//
//        debug(res[0].in)

        printf("%s\n",st[res[0].in-1].c_str());

//        if(id1>=id2)
//        {
//            printf("%c^%c^%c\n",vp[0].ss,vp[1].ss,vp[2].ss);
//        }
//        else
//        {
//            printf("(%c^%c)^%c\n",vp[0].ss,vp[1].ss,vp[2].ss);
//        }

    }

    return 0;
}



