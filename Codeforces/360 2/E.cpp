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
const int INF = 100004;
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

int vis[504][504];
int dp[504][504];
int pri[504][504];
int n;
int a[504];
vi v;
set <int> res;
int tc=0;


void call(int in, int sum)
{
    if(in>=v.size())
    {
        res.insert(sum);
        return ;
    }
//    int &ret = dp1[in][sum];
    int &vt = vis[in][sum];
    if(vt==tc) return;
    vt=tc;
    call(in+1, sum+v[in]);
    call(in+1, sum);
}

void print(int in, int make)
{
    //debug(in,make,pri[in][make])
    if(in>=n)
    {
        //debug("vi",v.size(),make)
        if(make==0)
        {
            tc++;
            call(0,0);
        }
        return;
    }
    int kk = pri[in][make];
    if(kk==3)
    {
        v.PB(a[in]);
        print(in+1,make-a[in]);
        v.pop_back();
        print(in+1, make);
    }
    else if(kk==1)
    {
        print(in+1, make);
    }
    else
    {
        v.PB(a[in]);
        print(in+1, make-a[in]);
        v.pop_back();
    }
}

int call1(int in, int make)
{
    //debug(in,make)
    if(in>=n)
    {
        if(make==0)
        {
//            v.clear();
//            print(0,k);
            return 1;
        }
        return 0;
    }
    int &ret = dp[in][make];
    if(ret!=-1) return ret;

    int o1,o2;
    o1=o2=0;
    o1=call1(in+1, make);
    if(make-a[in]>=0) o2=call1(in+1,make-a[in]);

    if(o1==1 && o2==1) pri[in][make]=3;
    else if(o1==1) pri[in][make]=1;
    else if(o2==1) pri[in][make]=2;
    return ret = max(o1,o2);
}



int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int k;
    while(~getII(n,k))
    {
        v.clear();
        res.clear();
        FOR(i,0,n-1) getI(a[i]);
        SET(dp);
        int kk = call1(0,k);

        CLR(vis);
        tc=0;
        print(0,k);

        printf("%d\n",res.size());
        set<int> :: iterator i;
        for(i=res.begin();i!=res.end();i++)
        {
            if(i!=res.begin()) printf(" ");
            printf("%d",*i);
        }
        printf("\n");
    }

    return 0;
}



