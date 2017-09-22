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



int arr[100004];
int b[100004];
int r[100004];
#define SIZE 300005
int sparse[30][SIZE], height;
int sparsemx[30][SIZE];
void buildTable ( int n ) {

    ///Base Case
    for ( int i = 0; i < n; i++ ) {
        sparse[0][i] = arr[i];
        sparsemx[0][i] = arr[i];
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
            sparse[i][j] = min ( sparse[i-1][j], sparse[i-1][k]);
            sparsemx[i][j] = max ( sparsemx[i-1][j], sparsemx[i-1][k]);
        }

        cur *= 2;
        prev *= 2;
    }
}

/// call once before all test cases
void preCalculate()
{
    int xx = 1,rr=0;
    FOR(i,1,100001)
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
int rmq ( int i, int j ) {
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

    int res = min ( sparse[row][i], sparse[row][j-two+1] );
    int res1 = max ( sparsemx[row][i], sparsemx[row][j-two+1] );
    return res1-res;
}


int main() {

    int t;
    getI(t);
    preCalculate();
    FOR(ci,1,t)
    {
        int n, k;
        getII(n,k);
        FOR(i,0,n-1)
        {
            getI(arr[i]);
        }
        buildTable(n);
        int low = 0;
        ll cnt=0;
        FOR(i,0,n-1)
        {
            while(rmq(low,i)>=k) low++;
//            debug(low, i, rmq(low,i))
            ll kk = i - low + 1;
//            cout << i << " " << kk << " " <<low << endl;
            cnt += kk;
        }
        printf("%lld\n",cnt);
    }

    return 0;
}


