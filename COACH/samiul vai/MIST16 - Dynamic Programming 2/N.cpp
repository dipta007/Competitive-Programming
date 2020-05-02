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

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)          freopen(f, "w", stdout)
#define    MP(x, y)          make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R)        for (int i = L; i <= R; i++)
#define    ROF(i,L,R)        for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()
#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(N,in)    ((bool)(a&(1<<(k))))
#define    bitOff(N,in)      (a&(~(1<<(k))))
#define    bitOn(N,in)       (a|(1<<(k)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long

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

int a[104];
pii dp[104][104][3];
bool visited[104][104][3];
pii pri[104][104][3];
vi v[2];

pii add(pii a, pii b)
{
    pii c;
    c.ff = a.ff + b.ff;
    c.ss = a.ss + b.ss;
    return c;
}

pii call(int low, int high,int f)
{
    if(low>high)
    {
        return pii(0,0);
    }

    pii &ret = dp[low][high][f];
    if(visited[low][high][f]!=0) return ret;
    visited[low][high][f]=1;

    int s=0;
    pii s1 = pii(-INF, -INF);
    FOR(i,low,high)
    {
        s+=a[i];
        if(f==0)
        {
            pii res = add( pii(s,0), call(i+1,high,!f) );
            if(res.ff>s1.ff)
            {
                    debug("vit",low,high,res.ff,res.ss,i)
                pri[low][high][f]=pii(1,i);
                s1=res;
            }
        }
        else
        {
            pii res = add( pii(0,s), call(i+1,high,!f) );
            if(res.ss>s1.ss)
            {
        //            debug("vit",low,high,res,i)
                pri[low][high][f]=pii(1,i);
                s1=res;
            }
        }
    }
    s=0;
    ROF(i,high,low)
    {
        s+=a[i];
        if(f==0)
        {
            pii res = add( pii(s,0), call(i+1,high,!f) );
            if(res.ff>s1.ff)
            {
        //            debug("vit",low,high,res,i)
                pri[low][high][f]=pii(1,i);
                s1=res;
            }
        }
        else
        {
            pii res = add( pii(0,s), call(i+1,high,!f) );
            if(res.ss>s1.ss)
            {
        //            debug("vit",low,high,res,i)
                pri[low][high][f]=pii(1,i);
                s1=res;
            }
        }
    }
    debug(low,high,f,s1.ff,s1.ss,pri[low][high][f].ff,pri[low][high][f].ss)
    return ret = s1;
}

void printPath(int low,int high,int f)
{
    if(low>high) return;

    pii p = pri[low][high][f];
    debug("path",low,high,f,p.ff,p.ss);
    if(p.ff==1)
    {
        int s=0;
        FOR(i,low,high)
        {
            s+=a[i];
            if(i==p.ss)
            {
                v[f].PB(s);
                printPath(i+1,high,!f);
                break;
            }
        }
    }
    else
    {
        int s=0;
        ROF(i,high,low)
        {
            s+=a[i];
            if(i==p.ss)
            {
                v[f].PB(s);
                printPath(low,i-1,!f);
                break;
            }
        }
    }
}

int diff()
{
    int c1,c2;
    c1=c2=0;
    FOR(i,0,(int)v[0].size()-1)
    {
        debug("1",v[0][i]);
        c1 += v[0][i];
    }
    FOR(i,0,(int)v[1].size()-1)
    {
        debug("2",v[1][i])
        c2 += v[1][i];
    }
    return abs(c1-c2);
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n;
        getI(n);
        int sum=0;
        FOR(i,0,n-1)
        {
            getI(a[i]);
            sum += a[i];
        }
        CLR(visited);
        v[0].clear();
        v[1].clear();
        pii res = call(0,n-1,0);
        printPath(0,n-1,0);
        printf("Case %d: %d\n",ci,diff());
    }

    return 0;
}
