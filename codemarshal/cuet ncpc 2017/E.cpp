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
#define    pii 	 pair< ll, ll >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef dipta007
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

int n,p;


pii mul(pii a, pii b)
{
    pii pp;
    pp.ff = a.ff * b.ff;
    pp.ss = a.ss * b.ss;
    return pp;
}

pii add(pii a, pii b)
{
    pii pp;
    pp.ff = a.ff + b.ff;
    pp.ss = a.ss + b.ss;
    return pp;
}

pii berKoro(int in)
{
    pii upor,nich,jog;

    pii u1,u2,u3;

    u1.ff = (n-in) * p;
    u1.ss = n*100;

    u2.ff = (n-in)*(100-p);
    u2.ss = n*100;

    u3.ff = in;
    u3.ss = n;

    ll ulc = lcm(u1.ss, lcm(u2.ss, u3.ss));
    upor.ss= ulc;

    u1.ff = (ulc/u1.ss)*u1.ff;
    u2.ff = (ulc/u2.ss)*u2.ff;
    u3.ff = (ulc/u3.ss)*u3.ff;
    upor.ff = u1.ff+u2.ff+u3.ff;
//    debug(upor.ff, upor.ss)

    pii n1,n2,n3;

    n1.ff=1;
    n1.ss=1;

    n2.ff = (n-in)*(100-p);
    n2.ss = n*100;

    n3.ff = in;
    n3.ss = n;

    ll nlc = lcm(n1.ss, lcm(n2.ss,n3.ss));
    nich.ss = nlc;
//    debug(nlc,"nlc")
    n1.ff = (nlc/n1.ss)*n1.ff;
    n2.ff = (nlc/n2.ss)*n2.ff;
    n3.ff = (nlc/n3.ss)*n3.ff;
//    debug(n1.ff, n2.ff, n3.ff)
    nich.ff = n1.ff - n2.ff - n3.ff;
//    debug(nich.ff, nich.ss)

    jog.ff = upor.ff * nich.ss;
    jog.ss = upor.ss * nich.ff;
//
//    res.ff = res.ff + jog.ff;
//    res.ss = res.ss + jog.ss;

    return jog;
}

pii call1(int in)
{
    if(in>=n) return pii(1,1);

    pii upor,nich,jog;

    pii u1,u2,u3;

    u1.ff = (n-in) * p;
    u1.ss = n*100;

    u1 = mul(u1, call1(in+1));

    u2.ff = (n-in)*(100-p);
    u2.ss = n*100;

    u3.ff = in;
    u3.ss = n;

    ll ulc = lcm(u1.ss, lcm(u2.ss, u3.ss));
    upor.ss= ulc;

    u1.ff = (ulc/u1.ss)*u1.ff;
    u2.ff = (ulc/u2.ss)*u2.ff;
    u3.ff = (ulc/u3.ss)*u3.ff;
    upor.ff = u1.ff+u2.ff+u3.ff;
//    debug(upor.ff, upor.ss)

    pii n1,n2,n3;

    n1.ff=1;
    n1.ss=1;

    n2.ff = (n-in)*(100-p);
    n2.ss = n*100;

    n3.ff = in;
    n3.ss = n;

    ll nlc = lcm(n1.ss, lcm(n2.ss,n3.ss));
    nich.ss = nlc;
//    debug(nlc,"nlc")
    n1.ff = (nlc/n1.ss)*n1.ff;
    n2.ff = (nlc/n2.ss)*n2.ff;
    n3.ff = (nlc/n3.ss)*n3.ff;
//    debug(n1.ff, n2.ff, n3.ff)
    nich.ff = n1.ff - n2.ff - n3.ff;
//    debug(nich.ff, nich.ss)

    jog.ff = upor.ff * nich.ss;
    jog.ss = upor.ss * nich.ff;

    return jog;
}

pii call(int in)
{
    if(in>=n) return pii(1,1);

    pii ekhn = berKoro(in);
    pii p = call(in+1);

    p.ff = p.ff * ekhn.ff;
    p.ss = p.ss * ekhn.ss;
    return p;
}


int main()
{
#ifdef dipta007
    READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
//        ll n,p;
        getLL(n,p);

        pii res = MP(0,0);
        p=100-p;

        res = call1(0);
        ll gc = gcd(res.ff,res.ss);
        while(gc!=1)
        {
            res.ff /= gc;
            res.ss /= gc;
            gc = gcd(res.ff, res.ss);
        }
        printf("Case %d: %lld/%lld\n",ci,res.ff,res.ss);
        continue;
        FOR(i,0,n-1)
        {
            int in=i;
            pii upor,nich,jog;

            pii u1,u2,u3;

            u1.ff = (n-in) * p;
            u1.ss = n*100;

            u2.ff = (n-in)*(100-p);
            u2.ss = n*100;

            u3.ff = in;
            u3.ss = n;

            ll ulc = lcm(u1.ss, lcm(u2.ss, u3.ss));
            upor.ss= ulc;

            u1.ff = (ulc/u1.ss)*u1.ff;
            u2.ff = (ulc/u2.ss)*u2.ff;
            u2.ff = (ulc/u2.ss)*u2.ff;
            upor.ff = u1.ff+u2.ff+u3.ff;
            debug(upor.ff, upor.ss)

            pii n1,n2,n3;

            n1.ff=1;
            n1.ss=1;

            n2.ff = (n-in)*(100-p);
            n2.ss = n*100;

            n3.ff = in;
            n3.ss = n;

            ll nlc = lcm(n1.ss, lcm(n2.ss,n3.ss));
            nich.ss = nlc;
            debug(nlc,"nlc")
            n1.ff = (nlc/n1.ss)*n1.ff;
            n2.ff = (nlc/n2.ss)*n2.ff;
            n3.ff = (nlc/n3.ss)*n3.ff;
            debug(n1.ff, n2.ff, n3.ff)
            nich.ff = n1.ff - n2.ff - n3.ff;
            debug(nich.ff, nich.ss)


            jog.ff = upor.ff * nich.ss;
            jog.ss = upor.ss * nich.ff;

            res.ff = res.ff + jog.ff;
            res.ss = res.ss + jog.ss;
        }

    }

    return 0;
}



