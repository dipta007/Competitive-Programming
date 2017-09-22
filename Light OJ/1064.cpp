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
#define    pii 	 pair< ll, ll >
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

ll dp[26][154];
int vis[26][154];
int n;

//pii add(pii a, pii b)
//{
//    pii d;
//    d.ff = a.ff + b.ff;
//    d.ss = a.ss + b.ss;
//    return d;
//}
//
//pii call(int in, int sum)
//{
//    if(in>=n)
//    {
//        if(sum==0) return pii(1,1);
//        else return pii(0,0);
//    }
//
//    if(vis[in][sum]==1) return dp[in][sum];
//    vis[in][sum]=1;
//
//    pii res = MP(0,0);
//    FOR(i,1,6)
//    {
//        if(sum-i>=0) res = add(res, call(in+1,sum-i));
//    }
//    res.ss *= 6;
//    return dp[in][sum] = res;
//}

ll call(int in, int sum)
{
    //if(sum<0) return 1;
    if(in>=n)
    {
        if(sum==0) return 1;
        else return 0;
    }

    if(vis[in][sum]==1) return dp[in][sum];
    vis[in][sum]=1;

    ll res = 0;
    FOR(i,1,6)
    {
        if(sum-i>=0) res += call(in+1,sum-i);
        else res += call(in+1, 0);
    }
    return dp[in][sum] = res;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
//    int cnt=0;
//    FOR(i,1,6)
//    {
//        FOR(j,1,6)
//        {
//            FOR(k,1,6)
//            {
//                if(i+j+k>=9) cnt++;
//            }
//        }
//    }
//    debug(cnt)
    getI(t);
    FOR(ci,1,t)
    {
        int x;
        CLR(vis);
        getII(n,x);
        ll kk = call(0,x);
        //debug(kk)
        pii res;
        res.ff = kk;
        res.ss = 1;
        FOR(i,1,n)
        {
            res.ss *= 6;
        }
        ll gc = gcd(res.ff, res.ss);
        while(gc!=1)
        {
            res.ff /= gc;
            res.ss /= gc;
            gc = gcd(res.ff, res.ss);
        }
        if(res.ss==1) printf("Case %d: %lld\n",ci,res.ff);
        else printf("Case %d: %lld/%lld\n",ci,res.ff,res.ss);
    }

    return 0;
}



