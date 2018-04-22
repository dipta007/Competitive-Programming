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
#define    SZ(c)             (int)c.size()
#define    PB(x)             push_back(x)

#define    F(i,L,R)          for (int i = L; i < R; i++)
#define    FF(i,L,R)         for (int i = L; i <= R; i++)
#define    FR(i,L,R)         for (int i = L; i > R; i--)
#define    FRF(i,L,R)        for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()

#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getC(n)           scanf("%c",&n)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
#define    ui    unsigned int
#define    us    unsigned short
#define    ld    long double

#define    debug(a)     { cout << a <<endl; }
#define    debugI()     { cout << "*" <<endl; }
#define    debugII()    { cout << "**" <<endl; }
#define    debugIII()   { cout << "***" <<endl; }

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

ll dp[1000004];

//ll nCr(int n,int r)
//{
//    if(r==0) return 1;
//    if(r==1) return n;
//    if(n==r) return 1;
//    return nCr(n-1,r)+nCr(n-1,r-1);
//}

ll mod=1000003;

pair<ll,ll> extendedEuclid(int a, int b)   // returns x, y jekhane, ax + by = gcd(a,b)
{
    if(b == 0)
        return pair<ll,ll>(1, 0);
    else
    {
        pair<ll,ll> d = extendedEuclid(b, a % b);
        return pair<ll,ll>(d.ss, d.ff - d.ss * (a / b));
    }
}


ll modularInverse(int a, int n) {   // returns a er modular Inverse ; n dara mod kore
  pair<ll,ll> ret = extendedEuclid(a, n);
  return ((ret.ff % n) + n) % n;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    SET(dp);
    dp[0]=dp[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        dp[i]=(i%mod*dp[i-1]%mod)%mod;
    }
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        int a,b;
        getII(a,b);
        ll c=dp[a];
        ll d=(dp[a-b]%mod*dp[b]%mod)%mod;
//        debug(c);
//        debug(d);
        ll e=modularInverse(d,mod);
        ll f=(c%mod*e%mod)%mod;
//        debug(e);
//        debug(f);
        printf("Case %d: %lld\n",ci,f);
    }

    return 0;
}
