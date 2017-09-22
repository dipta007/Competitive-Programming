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
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
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
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
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
///****************** template ends here ****************
int t,n,m;
int dp[16][10004];
int pri[16][10004];
//int mark[15][10005];
//int tc;
//bool dp2[501][501][501];
int arr[]={1,2,5,10,20,50,100,200,500,1000,2000,5000,10000};
//double arr[]={.01,.02,.05,.1,.2,.5,1,2,5,10,20,50,100};
//set<int> ans;
int call(int pos,int sum)
{
    int &ret=dp[pos][sum];
    if(pos==13)
    {
        return ret=(sum==0);
    }
    if(ret!=-1)return ret;
    int ans=0;
    int o1,o2;
    o1=o2=0;
    o1=call(pos+1,sum);
    if(sum-arr[pos]>=0) o2=call(pos,sum-arr[pos]);
    if(o1&o2)
    {
        pri[pos][sum]=3;
    }
    else if(o1)
    {
        pri[pos][sum]=1;
    }
    else
    {
        pri[pos][sum]=2;
    }
    return ret=o1|o2;
}

typedef map<pair<pii,int>,int> unmp;
map<pair<pii,int>,int> dp2;


int dpcall(int in,int sum, int sum1)
{
    if(sum1==m) return 1;
    //if(sum1>m) return 2;
    if(in>=13)
    {
        if(sum1==m) return 1;
        return 2;
    }

    if(dp2.find(MP(MP(in,sum),sum1))!=dp2.end())return dp2[MP(MP(in,sum),sum1)];

    int ans = 1;
    if(pri[in][sum]==3)
    {
        int tmp = dpcall(in+1,sum,sum1);
        if(tmp==1) ans&=1;
        else ans=0;

        tmp = dpcall(in,sum-arr[in],sum1+arr[in]);
        if(tmp==1) ans&=1;
        else ans=0;
    }
    else if(pri[in][sum]==1)
    {
        int tmp = dpcall(in+1,sum,sum1);
        if(tmp==1) ans&=1;
        else ans=0;
    }
    else
    {
        int tmp = dpcall(in,sum-arr[in],sum1+arr[in]);
        if(tmp==1) ans&=1;
        else ans=0;
    }
    return dp2[MP(MP(in,sum),sum1)]=(ans==1?1:2);
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//    READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    getI(t);
    rep(cs,t)
    {
        double x,y;
        getF(x);
        getF(y);
        n=x*100;
        m=y*100;

        SET(dp);
        //dp2.clear();
        for(int i=1;i<=n-m;i++)
        {

            int k = call(0,n-i);
            debug(k)
            if(k==0) continue;
            int ans=dpcall(0,n-i,0);
            debug(i,ans)
            if(ans==1)
            {
                double res=(double)i/100.0;
//                debug(res)
                printf("Case #%d: %.2f\n",cs,res);
                break;
            }

        }

    }


    return 0;
}
