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
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
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


#define SIZE 5004

#define MAX 5004
ll arr[MAX];
int height;
pair <ll, int> sparsemx[30][SIZE];
int b[100004];
int r[100004];

#define pli pair <ll ,int>
pli max(pli a, pli b)
{
    if(a.ff > b.ff) return a;
    else return b;
}

int buildTable ( int n ) {

    ///Base Case
    for ( int i = 0; i < n; i++ ) {
        sparsemx[0][i].ff = arr[i];
        sparsemx[0][i].ss = i;
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

/// call once before all test cases
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

/// 0 indexed
pli rmq ( int i, int j ) {
    int len = j - i + 1;

    int two = b[len];
    int row = r[len];

    return max ( sparsemx[row][i], sparsemx[row][j-two+1] );
}



int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(~getI(n))
    {
        preCalculate(n+4);
        arr[0]=0;
        FOR(i,1,n)
        {
            getL(arr[i]);
            if(i) arr[i] += arr[i-1];
            debug(i, arr[i])
        }
        buildTable(n+1);

        ll maxy= LONG_LONG_MIN;
        int dd0,dd1,dd2;
        FOR(d0,0,n)
        {
            FOR(d1,d0, n)
            {
                int d2 = rmq(d1,n).ss;
                debug(d0,d1,d2)

                ll now = arr[d0] - (arr[d1] - arr[d0]) + (arr[d2] - arr[d1]) - (arr[n] - arr[d2]);

//                debug(d0,d1,d2,now, maxy)
                if(now > maxy)
                {
                    maxy = now;
                    dd0 = d0;
                    dd1 = d1;
                    dd2 = d2;
                }
            }
        }

//        debug(maxy)

        printf("%d %d %d\n",dd0,dd1,dd2);
    }

    return 0;
}



