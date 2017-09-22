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

#ifdef dipta0073
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
vi v,vv;
int dp[54][1680];
int pri[54][1680];
int vis[54][1680];
int tt;

int call(int in, int sum)
{
    //if(sum<0) return 0;
    //if(flg==1) debug(in,sum, v.size())
    if(in>=n)
    {
        if(sum==0) return 1;
        return 0;
    }
    int &ret = dp[in][sum];
    if(vis[in][sum]==tt) return ret;
    vis[in][sum]==tt;

    int o1,o2;
    o1=o2=0;
    if(sum-v[in]>=0) o1= call(in+1, sum-v[in]);
    o2=call(in+1,sum);
    //if(flg==2)
    {
        if(o1==1 && o2==1) pri[in][sum]=3;
        else if(o1==1) pri[in][sum]=1;
        else pri[in][sum]=2;
    }

    return ret = o1||o2;
}

int call1(int in, int sum)
{
    //if(sum<0) return 0;
    debug("2nd", in,sum, vv.size(), vis[in][sum], tt)
    if(in>=vv.size())
    {
        debug(in,sum)

        if(sum==0) return 1;
        return 0;
    }
    int &ret = dp[in][sum];
    if(vis[in][sum]==tt) return ret;
    vis[in][sum]==tt;

    int o1,o2;
    o1=o2=0;
    if(sum-vv[in]>=0) o1= call1(in+1, sum-vv[in]);
    o2=call1(in+1,sum);
    debug(o1,o2)

    return ret = o1||o2;
}

int got=0;

int print(int in, int sum)
{
    if(got) return 1;
    if(in>=n)
    {
        //debug("pri", call1(0,d1), vis[0][d1], dp[0][d1],tt, d1,d2, vv.size(),tt);
        tt++;
        if(call1(0,d1))
        {
            got=1;
            return 1;
        }
        return 0;
    }
    int kk = pri[in][sum];
    int aa,bb;
    aa=bb=0;
    if(kk==3)
    {
        vv.PB(a[in]);
        aa=print(in+1, sum-a[in]);
        vv.pop_back();
        bb=print(in+1, sum);
    }
    else if(kk==1)
    {
        vv.PB(a[in]);
        aa=print(in+1, sum-a[in]);
        vv.pop_back();
    }
    else
    {
        bb=print(in+1, sum);
    }
    return aa||bb;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    tt=0;
    CLR(vis);
    FOR(ci,1,t)
    {
        tt++;
        getI(n);
        int sum=0;
        v.clear();
        vv.clear();
        FOR(i,0,n-1)
        {
            getI(a[i]);
            v.PB(a[i]);
            sum += a[i];
        }
        printf("Case %d: ",ci);
        if(sum%3!=0)
        {
            printf("Lov-e Pap Pap-e Polti\n");
            continue;
        }
        int div = sum/3;
        d1=sum/3;
        d2=d1+d1;
        d3=d1+d1+d1;
        sort(a,a+n);
        sort(ALL(v));
//        SET(dp);
        got=0;
        int kk = call(0,d2);
        kk = print(0,d2);
        if(kk) printf("Eid Makes Happy Everyone\n");
        else printf("Lov-e Pap Pap-e Polti\n");
    }


    return 0;
}




