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
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

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

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n,d,h;
    while(~getIII(n,d,h))
    {
        int md = d;
        if(h*2<d)
        {
            printf("-1\n");
            continue;
        }
        vector <pii> vp;

        int tot=n-1;
        int par=1;
        int node=2;
        int end1=0,end2=0;
        for(int i=0;i<h;i++)
        {
            vp.PB(pii(par,node));
            if(i==h-1) end1=node;
            par = node;
            node = node+1;
        }
        d -= h;
        tot -= h;

        par=1;
        int flg=0;
        for(int i=0;i<d;i++)
        {
            flg=1;
            vp.PB(pii(par,node));
            if(i==d-1) end2=node;
            par = node;
            node = node+1;
        }
        tot -= d;

        for(int i=2;i<end1 && tot;i++)
        {
            vp.PB(pii(i,node));
            tot--;
            node ++;
        }
        for(int i=end1+1;i<end2 && tot;i++)
        {
            vp.PB(pii(i,node));
            node ++;
            tot--;
        }
//
//        par=1;
//        for(int i=0;i<tot;i++)
//        {
//            vp.PB(pii(par,node));
//            node ++;
//        }
//        node--;
        if(md!=1 && flg)
        {
            for(int i=1;tot>0;tot--)
            {
                vp.PB(pii(1,node));
                node++;
//                debug(node,tot)
            }
        }
        else if(md!=1)
        {
            for(;tot;tot--)
            {
                vp.PB(pii(2,node));
                node++;
            }
        }
        node--;
        if(tot!=0 || node!=n || vp.size()!=n-1)
        {
//            debug(tot,node,vp.size())
            printf("-1\n");
            continue;
        }

        for(int i=0;i<n-1;i++)
        {
            printf("%d %d\n",vp[i].ff,vp[i].ss);
        }
    }

    return 0;
}



