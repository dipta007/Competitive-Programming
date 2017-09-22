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


int bit[100004];
const int N = 1 << 17;
int n;

void update ( int x, int v ) {
    while ( x < n+1 ) {
        bit[x] += v;
        x += x & (-x);
    }
}

int query ( int x ) {
    int res = 0;
    while ( x ) {
        res += bit[x];
        x -= x & (-x);
    }
    return res;
}
int GetMax(int L, int R)  // [L, R) i.e. L <= i < R
{
    int res = INF;
    for (L += N, R += N; L < R; L >>= 1, R >>= 1) {
        if (L & 1) {
            res = max(res, bit[L]);
            L++;
        }
        if (R & 1) {
            R--;
            res = max(res, bit[R]);
        }
    }
    return res;
}

struct kadane //Structure for 1D-Kadane Algorithm
{
    int l,r;
    ll sum;
    kadane()
    {
        l=-1,r=-1,sum=0;
    }
};


int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    while(~getI(n))
    {
        int a[n+1];
        FOR(i,1,n)
        {
            getI(a[i]);
            update(i, a[i]);
        }

        int maxR = n;
        int maxL = 1;
        ll maxRes = INF;

        FOR(i,1,n)
        {
            int x;
            getI(x);
            a[x]=-INF;

            if(x<=maxR && x>=maxL)
            {
                kadane curr, maxy;
                curr.l = 1;
                FOR(j,1,n)
                {
                    if(curr.sum<0)
                    {
                        curr.sum=a[j];
                        curr.l=j;
                        curr.r=j;
                    }
                    else
                    {
                        curr.sum = curr.sum + (ll)a[j];
                        //debug(curr.sum)
                        curr.r=j;
                    }

                    if(curr.sum > maxy.sum)
                    {
                        maxy = curr;
                    }
                    //debug(curr.sum,a[j])
                }

                if(curr.sum > maxy.sum)
                {
                    maxy = curr;
                }
                //debug(maxy.sum , "mm")

                maxL = maxy.l;
                maxR = maxy.r;
                maxRes = maxy.sum;
            }
            printf("%lld\n",maxRes);
        }
    }

    return 0;
}



