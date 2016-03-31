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

int main() {
//    READ("in.txt");
    //WRITE("out.txt");

    int x,y;
    while(~getII(x,y))
    {
        vector <pii> vp;
        vp.PB(pii(x,y));
        getII(x,y);
        vp.PB(pii(x,y));
        getII(x,y);
        vp.PB(pii(x,y));

        sort(ALL(vp));
        pii a=vp[0];
        pii b=vp[1];
        pii c=vp[2];

//        int cnt=0;
//        debug(a.ff,a.ss)
//        debug(b.ff,b.ss)
//        debug(c.ff,c.ss)
        if(a.ff==b.ff && b.ff==c.ff)
        {
            printf("1\n");
            continue;
        }
        else if(a.ss==b.ss && b.ss==c.ss)
        {
            printf("1\n");
            continue;
        }

        int cnt=3;
        if(a.ff==b.ff)
        {
            if(c.ss>=max(a.ss,b.ss) || c.ss<=min(a.ss,b.ss))
                cnt=2;
            else cnt=3;
        }
        if(a.ff==c.ff && cnt==3)
        {
            if(b.ss>=max(a.ss,c.ss) || b.ss<=min(a.ss,c.ss))
                cnt=2;
            else cnt=3;
        }
        if(b.ff==c.ff && cnt==3)
        {
            if(a.ss>=max(b.ss,c.ss) || a.ss<=min(b.ss,c.ss))
                cnt=2;
            else cnt=3;
        }
        if(a.ss==b.ss && cnt==3)
        {
            if(c.ff>=max(a.ff,b.ff) || c.ff<=min(a.ff,b.ff))
                cnt=2;
            else cnt=3;
        }
        if(a.ss==c.ss && cnt==3)
        {
            if(b.ff>=max(a.ff,c.ff) || b.ff<=min(a.ff,c.ff))
                cnt=2;
            else cnt=3;
        }
        if(b.ss==c.ss && cnt==3)
        {
            if(a.ff>=max(b.ff,c.ff) || a.ff<=min(b.ff,c.ff))
                cnt=2;
            else cnt=3;
        }

        if(cnt==3) cnt=3;


//        else if(a.ff==b.ff || a.ss==b.ss)
//            cnt+=1;
//        else cnt+=2;
//
//        if(b.ff==c.ff || b.ss==c.ss || cnt==2)
//            cnt+=1;
//        else cnt+=2;

        printf("%d\n",cnt);
    }


    return 0;
}


