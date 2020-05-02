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

int call(int n)
{
    int ans=0;
    while(n)
    {
        ans += (n%10)*(n%10);
        n/=10;
    }
    return ans;
}

int main() {
    #ifdef dipta007
//        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int a,b;
    while(~getII(a,b))
    {
        if(a==0 && b==0) break;
        int sa=a,sb=b;
        if(sa==sb)
        {
            printf("%d %d 2\n",a,b);
            continue;
        }
        int c1=0,c2=0;
        int a1[1000],a2[1000];
        FOR(i,0,999) a1[i]=a2[i]=INF;

        int f1,f2;
        f1=0,f2=0;
        while(1)
        {
            int aa = call(a);
            int bb = call(b);


            if(a1[aa]!=INF) f1=1;
            if(a2[bb]!=INF) f2=1;
            if(aa==1) f1=1;
            if(bb==1) f2=1;

            //debug(aa,bb)

            c1++;
            c2++;


            debug("a",a,aa,c1)
            debug("b",b,bb,c2)



            a1[aa] = min(a1[aa], c1);
            a2[bb] = min(a2[bb], c2);



            if(a1[aa]!=INF && aa==sb)
            {
                debug(aa,a1[aa],a2[aa]);
                printf("%d %d %d\n",sa,sb,2+a1[aa]);
                break;
            }
            else if(bb==sa && a2[bb]!=INF)
            {
                debug(bb)
                printf("%d %d %d\n",sa,sb,2+a2[bb]);
                break;
            }
            else if(a1[bb]!=INF && a2[bb]!=INF)
            {
                debug(bb)
                printf("%d %d %d\n",sa,sb,2+a1[bb]+a2[bb]);
                break;
            }
            else if(a1[aa]!=INF && a2[aa]!=INF)
            {
                debug(aa,a1[aa],a2[aa]);
                printf("%d %d %d\n",sa,sb,2+a1[aa]+a2[aa]);
                break;
            }


            if(f1&&f2)
            {
                printf("%d %d 0\n",sa,sb);
                break;
            }


            a=aa;
            b=bb;
        }
    }

    return 0;
}



