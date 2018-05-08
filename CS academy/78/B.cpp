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
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define dipta00
#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
#else
    #define debug(args...)  /// Just strip off all debug tokens
    #define trace(...) ///yeeeee
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

/**
Procedure:
    1. Call preCalculate(MAX) once before all test cases
    2. Call build table once for each test case
    3. Call rmq(l, r) to get the result
Time Complexity = RMQ - O(1), build(N log N)
**/
ll arr[100004];
#define SIZE 300005
int height;
ll sparsemx[30][SIZE];
int b[100004];
int r[100004];

void preCalculate(int n)
{
    int xx = 1,rr=0;
    FOR(i,1,n)
    {
        if(i!=1 && !(i&(i-1)))
        {
            xx *= 2;
            rr ++;
        }
        b[i]=xx;
        r[i]=rr;
    }
}
int buildTable ( int n ) {
    ///Base Case
    for ( int i = 0; i < n; i++ ) {
        sparsemx[0][i] = arr[i];
        debug(arr[i])
    }
    ///Current power of 2 is cur
    ///power of 2 for previous row is prev
    int cur = 2, prev = 1;
    for ( int i = 1; i < 22; i++ ) {
        if ( cur > n ) {
            height = i;
            break;
        }
        for ( int j = 0; j < n; j++ ) {
            int k = j + prev;
            if ( k >= n ) k = n - 1;
            sparsemx[i][j] = max ( sparsemx[i-1][j], sparsemx[i-1][k]);
        }

        cur *= 2;
        prev *= 2;
    }
}
ll rmq ( int i, int j ) {
    if(i > j) return 0;
    int len = j - i + 1;
//    int row = height;
//    int two = pow ( 2, height );
//
//    while ( two > len ) {
//        two /= 2;
//        row--;
//    }
    int two = b[len];
    int row = r[len];

    ll res1 = max ( sparsemx[row][i], sparsemx[row][j-two+1] );
    return res1;
}

int a[100004];

ll get(int in, int n)
{
    int diff = (a[in-1] + a[in+1]) / 2;
    if(diff < a[in])
    {
        ll now = max(diff - a[in-1], a[in] - diff);
        now = max(now, rmq(0, in-2));
        now = max(now, rmq(in, n));
        return now;
    }
    else
    {
        ll now = max(diff - a[in-1], a[in] - diff);
        now = max(now, rmq(0, in-1));
        now = max(now, rmq(in+1, n));
        return now;
    }
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    preCalculate(100000);
    int n;
    while(~getI(n))
    {
        FOR(i,0,n-1) getI(a[i]);

        int maxy = 0;
        int in;
        FOR(i,0,n-2)
        {
            arr[i] = abs(a[i] - a[i+1]);
            debug(i, arr[i])
            if(arr[i] > maxy)
            {
                maxy =arr[i];
                in = i;
            }
        }

        buildTable(n-1);

        ll res = rmq(0, n-2);
        debug(res)
        FOR(i,1,n-2)
        {
            res = min(res, get(i, n-2));
            debug(i, res)
        }

        debug(res)
        FOR(i,1,n-2)
        {
            int in = i;
            ll kk = arr[in]/2 + arr[in] % 2;
            ll now = max(rmq(1, in-1), rmq(in+1, n-2));
            now = max(now, kk);
            res = min(res, now);
//            res = min(res, max(rmq(1, in-1), rmq(in+1, n-1)));
        }

        FOR(i,0,n-3)
        {
            int in = i;
            ll kk = arr[in]/2 + arr[in] % 2;
            ll now = max(rmq(0, in-1), rmq(in+1, n-3));
            now = max(now, kk);
            res = min(res, now);
        }
//        res = min(res, rmq(1,n-1));
//        res = min(res, rmq(0,n-2));
//        debug(res, in, rmq(0, in-1), rmq(in+1, n-1))
//        res = min(res, max(rmq(0, in-1), rmq(in+1, n-1)));

        printf("%lld\n", res);
    }

    return 0;
}


