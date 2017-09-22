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

int n,m;
int d[100004];
int a[100004];
int zero[100004];

bool check(int x)
{
    int rest = zero[x];
    if(d[x]==0) rest--;

    int restPlusXm = x;

    int pass[m+4];
    CLR(pass);
    int cnt=0;
    int neg=0;
    debug("suru", x);
    ROF(i,x,0)
    {
        int kk = zero[i];
        if(d[i]==0) kk--;
        rest = min(rest, kk);
        restPlusXm = min(restPlusXm,i);

        int sub = d[i]-1;
        debug(i,sub,pass[sub],a[sub],rest,restPlusXm,neg)
        if(sub>=0 && pass[sub]==1)
        {
            neg--;
            continue;
        }
        if(sub>=0 && pass[sub]==0)
        {
            if(a[sub]<=rest)
            {
                pass[sub]=1;
                rest -= a[sub];
                restPlusXm -= a[sub];
                cnt++;
            }
            else if(a[sub]<=restPlusXm)
            {
                pass[sub]=1;
                neg += (a[sub]- rest);
                restPlusXm -= a[sub];
                rest -= a[sub];
                cnt++;
            }
            //debug(sub)
        }
    }
    debug(x,cnt,m,neg)
    if(cnt==m && neg<=0) return 1;
    return 0;
//    return (cnt==m);
}

bool checkC(int x)
{
//    int bakiSub = m;
//    if(d[x]!=0) bakiSub--;
//    int rest = (x-bakiSub);

    int pass[m+4];
    CLR(pass);
    int cnt=0;
    debug("suru", x);

    int bakiSub=m,rest=x+1;
    ROF(i,x,0)
    {
        if(d[i]!=0 && pass[d[i]-1]==0) bakiSub--;
        rest = min(rest, (x-bakiSub));

        int sub = d[i]-1;
        //debug(i,sub,pass[sub],a[sub],rest)
        if(sub>=0 && pass[sub]==0)
        {
            if(a[sub]<=rest)
            {
                pass[sub]=1;
                rest -= a[sub];
                cnt++;
                bakiSub--;
            }
        }
    }
//    debug(x,cnt,m,neg)
    if(cnt==m) return 1;
    return 0;
//    return (cnt==m);
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("in.txt");
    #endif // dipta007

    while(~getII(n,m))
    {
        FOR(i,0,n-1)
        {
            getI(d[i]);
            if(i)
            {
                if(d[i]==0) zero[i] = zero[i-1]+1;
                else zero[i] = zero[i-1];
            }
            else
            {
                if(d[i]==0) zero[i] = 1;
                else zero[i]=0;
            }
        }
        FOR(i,0,m-1)
        {
            getI(a[i]);
        }
        int low = 0, high = n-1, res=-1;
        while(low<=high)
        {
            int mid = (low+high)/2LL;
            //debug(mid)
            if(checkC(mid)==1)
            {
                high = mid-1;
                res = mid+1;
            }
            else low=mid+1;
        }
        printf("%d\n",res);
    }

    return 0;
}



