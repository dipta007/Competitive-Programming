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

int max4(int a,int b, int c, int d)
{
    return max(a, max(b, max(c,d)));
}

#define SIZE 504
int arr[SIZE][SIZE];

int sparse[22][SIZE][SIZE], height;
int buildTable ( int n ) {

    ///Base Case
    for ( int i = 0; i < n; i++ ) {
        for(int j=0; j<n; j++)
        {
            sparse[0][i][j] = arr[i][j];
        }
    }

    ///Current power of 2 is cur
    ///power of 2 for previous row is prev
    int cur = 2, prev = 1;
    for ( int i = 1; i < 22; i++ ) {
        if ( cur > n ) {
            height = i;
            break;
        }
        for(int r=0; r<n; r++)
        {
            for(int c=0; c<n; c++)
            {
                int ki = r+prev;
                int kj = c+prev;
                if(ki>=n) ki = n-1;
                if(kj>=n) kj = n-1;
                sparse[i][r][c] = max4( sparse[i-1][r][c], sparse[i-1][ki][c], sparse[i-1][r][kj], sparse[i-1][ki][kj]);
            }
        }

        cur *= 2;
        prev *= 2;
    }
}

int rmq ( int i, int j , int s) {
    int len = s;

    int row = height;
    int two = pow ( 2, height );

    while ( two > len ) {
        two /= 2;
        row--;
    }

    int res = max4 ( sparse[row][i][j], sparse[row][i][j+s-two], sparse[row][i+s-two][j], sparse[row][i+s-two][j+s-two] );
    return res;
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
        int n,q;
        getII(n,q);
        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                getI(arr[i][j]);
//                debug(arr[i][j])
            }
        }
        buildTable(n);
        printf("Case %d:\n",ci);
        FOR(i,1,q)
        {
            int x,y,s;
            getIII(x,y,s);
            x--,y--;
            printf("%d\n",rmq(x,y,s));
        }
    }

    return 0;
}




