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
#define    bitCheck(N,in)    ((bool)(a&(1<<(k))))
#define    bitOff(N,in)      (a&(~(1<<(k))))
#define    bitOn(N,in)       (a|(1<<(k)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
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

const int inf = 2000000000; // a large value as infinity

int n; // the number of items in the sequence
int Sequence[10004]; // the sequence of integers
int L1[10004]; // the sequence of integers
int L2[10004]; // L[] as described in the algorithm
int I[10004]; // I[] as described in the algorithm

int LisNlogK() { // which runs the NlogK LIS algorithm
    int i; // auxilary variable for iteration

    I[0] = -inf; // I[0] = -infinite
    for( i = 1; i <= n; i++ ) // observe that i <= n are given
        I[i] = inf; // I[1 to n] = infinite

    int LisLength = 0; // keeps the maximum position where a data is inserted

    for( i = 0; i < n; i++ ) { // iterate left to right
        int low, high, mid; // variables to perform binary search
        low = 0; // minimum position where we to put data in I[]
        high = LisLength; // the maximum position

        while( low <= high ) { // binary search to find the correct position
            mid = ( low + high ) / 2;
            if( I[mid] < Sequence[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }
        L1[i]=low;
        // observe the binary search carefully, when the binary search ends
        // low > high and we put our item in I[low]
        I[low] = Sequence[i];
        if( LisLength < low ) // LisLength contains the maximum position
            LisLength = low;
    }

    return LisLength; // return the result
}

int LdsNlogK() { // which runs the NlogK LIS algorithm
    int i; // auxilary variable for iteration

    I[0] = -inf; // I[0] = -infinite
    for( i = 1; i <= n; i++ ) // observe that i <= n are given
        I[i] = inf; // I[1 to n] = infinite

    int LisLength = 0; // keeps the maximum position where a data is inserted

    for( i = 0; i < n; i++ ) { // iterate left to right
        int low, high, mid; // variables to perform binary search
        low = 0; // minimum position where we to put data in I[]
        high = LisLength; // the maximum position

        while( low <= high ) { // binary search to find the correct position
            mid = ( low + high ) / 2;
            if( I[mid] < Sequence[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }
        L2[i]=low;
        // observe the binary search carefully, when the binary search ends
        // low > high and we put our item in I[low]
        I[low] = Sequence[i];
        if( LisLength < low ) // LisLength contains the maximum position
            LisLength = low;
    }

    return LisLength; // return the result
}


int main() {
    #ifdef dipta007
        READ("in.txt");
        WRITE("out.txt");
    #endif // dipta007

    while(~getI(n))
    {
        FOR(i,0,n-1)
        {
            getI(Sequence[i]);
        }
        int lis = LisNlogK();
        reverse(Sequence,Sequence+n);
        LdsNlogK();
        reverse(L2,L2+n);
        int ans=1;
        FOR(i,0,n-1)
        {
            debug(i,L1[i],L2[i])
            int k = min(L1[i],L2[i]);
            if(L1[i]==1 || L2[i]==1) continue;
            if((k-1)*2+1>ans)
            {
                ans = (k-1)*2+1;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}



