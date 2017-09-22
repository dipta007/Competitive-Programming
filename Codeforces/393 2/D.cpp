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
vi v;
int dp[100004];
int dp1[100004];
int pri[100004];

int bin_src(int val)
{
    int low = 0,high=n-1;
    int res=-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(v[mid]<=val)
        {
            res=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return res;
}
int bin_src1(int val)
{
    int low = 0,high=n-1;
    int res=-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(v[mid]<val)
        {
            low=mid+1;
        }
        else
        {
            res=mid;
            high=mid-1;
        }
    }
    return res;
}

int call(int in)
{
    if(in>=n) return 0;

    int &ret = dp[in];
    if(ret!=-1) return ret;

    int o1 = 20 + call(in+1);

    int pos = bin_src(v[in]+90-1);
    int o2 =  50+call(pos+1);

    pos = bin_src(v[in]+1440-1);
    int o3 =  120+call(pos+1);

    if(o1<=o2 && o1<=o3) pri[in]=1;
    else if(o2<=o1 && o2<=o3) pri[in]=2;
    else pri[in]=3;

    return ret=min(o1, min(o2,o3));
}

int call1(int in)
{
    if(in<0) return 0;

    int &ret = dp1[in];
    if(ret!=-1) return ret;

    int o1 = 20 + call1(in-1);

    int pos = bin_src1(v[in]-90+1);
    int o2 =  50+call1(pos-1);

    pos = bin_src1(v[in]-1440+1);
    int o3 =  120+call1(pos-1);

    if(o1<=o2 && o1<=o3) pri[in]=1;
    else if(o2<=o1 && o2<=o3) pri[in]=2;
    else pri[in]=3;

    return ret=min(o1, min(o2,o3));
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    while(~getI(n))
    {
        FOR(i,1,n)
        {
            int x;
            getI(x);
            v.PB(x);
        }
        //SET(dp);
        SET(dp1);
//        call(0);
        call1(n-1);
        int sum=0;
//        FOR(i,0,n-1)
//        {
//            debug(dp[i],dp1[i],pri[i])
//        }

        FOR(i,0,n-1)
        {
            printf("%d\n",dp1[i]-sum);
            sum += (dp1[i]-sum);
        }
    }

    return 0;
}



