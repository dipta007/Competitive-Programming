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

int n;
int a[54];
int d1,d2,d3;
vi b,v;
int dp1[54][900];
int dp2[54][900];

int call2(int in, int sum)
{
    if(in>=b.size())
    {
        if(sum==d1)
        {
            return 1;
        }
        return 0;
    }

    int &ret = dp2[in][sum];
    if(ret!=-1) return ret;

    int o1,o2;
    o1=o2=0;
    o1 = call2(in+1, sum+b[in]);
    o2 = call2(in+1, sum);

    return ret = o1||o2;
}


int call1(int in, int sum, string st)
{
    if(in>=n)
    {
        if(sum==d1)
        {
            debug(sum,d1)
            int in=0;
            b.clear();
            FOR(i,0,n-1)
            {
                if(in<v.size() && v[in]==a[i]) in++;
                else b.PB(a[i]);
            }
            debug(b.size(),b[0],b[1],b[2],"%")
            SET(dp2);
            return call2(0,0);
        }
        return 0;
    }


    int &ret = dp1[in][sum];
    if(ret!=-1) return ret;

    int o1,o2;
    o1=o2=0;
    v.PB(a[in]);
    o1 = call1(in+1, sum+a[in]);
    v.pop_back();
    o2 = call1(in+1, sum);

    return ret = o1||o2;
}

int main() {
    #ifdef dipta007
//        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        getI(n);
        int sum=0;
        FOR(i,0,n-1)
        {
            getI(a[i]);
            sum += a[i];
        }
        printf("Case %d: ",ci);
        if(sum%3!=0)
        {
            printf(":(\n");
            continue;
        }
        int div = sum/3;
        d1=sum/3;
        d2=d1+d1;
        d3=d1+d1+d1;
        sort(a,a+n);
        SET(dp1);
        int kk = call1(0,0);
        if(kk) printf("Eid Makes Happy Everyone\n");
        else printf(":(\n");
    }


    return 0;
}



