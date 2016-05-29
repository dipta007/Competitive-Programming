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
#include <unordered_map>
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
//
unordered_map <ll,int> dp;
unordered_map <ll, bool> vis;
ll vag[] = {2,3,4,5,6};

int call(ll n)
{
    //debug(n)
    if(n==0) return 0;
    if(vis[n]==1) return dp[n];
    vis[n]=1;

//    set <int> gr;
    bool gr[100];
    CLR(gr);
    FOR(i,0,4)
    {
        int kk = call((ll)n/vag[i]);
        //if(kk>=100) debug(kk)
        gr[kk]=1;
//        gr.insert(kk);
    }
    int cnt = 0;
    while(gr[cnt]) cnt++;
    return dp[n]=cnt;
}

int main() {
    #ifdef dipta007
        READ("out.txt");
        WRITE("outD1.txt");
    #endif // dipta007

    int t;
    getI(t);

    vector <ll> v;
    ll k=1;
    ll in=1;
    int koto=1;
    for(int i=0;;i++)
    {
        if(koto==3)
        {
            v.PB(in/2);
            in += v[i];
            koto =(koto+1)%4;
        }
        else
        {
            v.PB(in);
            in += v[i];
            koto =(koto+1)%4;
        }
        if(i) v[i]+=v[i-1];
        //debug(v[i]);
        if(v[i]>=1000000000000000000)
        {
            //debug(i)
            break;
        }
        //k++;
    }
    //debug(v.size())
    sort(ALL(v));
    int xorr[]={1,2,3,0};

    FOR(ci,1,t)
    {
        int n;
        getI(n);
        int res = 0;
//        FOR(i,0,4)
//        {
//            ll x =
//        }
        FOR(i,0,n-1)
        {
            ll x;
            getL(x);
            int k = lower_bound(ALL(v),x) - v.begin();
            //debug(k)
            int kk = k%4;
            //debug(xorr[kk])
            res = res ^ xorr[kk];
        }
        if(res) printf("Henry\n");
        else printf("Derek\n");
    }

    return 0;
}




