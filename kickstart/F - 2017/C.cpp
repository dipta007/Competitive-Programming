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
#define    UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
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

int n;
int mat[100][100];
int ver = 4;

void dfs(int u, int lvl)
{
    if(lvl==0) return;
    FOR(i,1,ver)
    {
        if(u!=i)
        {
            mat[u][i]++;
            dfs(i, lvl-1);
        }
    }
}


ll call(int p)
{

}

int adjMatrix[104][104];

int MATMOD = 1000000007;
class MAT
{
public:
    int a[16][16];   ///Maximum dimension of the matrix, Set Long Long
    int row, col;
    MAT() {}
    MAT(int r, int c)
    {
        row = r;
        col = c;
        mem();
    }
    void assign ( int r, int c, int temp[] )
    {
        row = r;
        col = c;
        int in = 0;
        FOR(i,0,row-1)
        {
            FOR(j,0,col-1)
            {
                a[i][j] = temp[in++];
            }
        }
    }

    void identity()
    {
        mem();
        FOR(i,0,row-1) FOR(j,0,row-1) a[i][j] = adjMatrix[i][j];
    }
    void mem()
    {
        memset ( a, 0, sizeof a );
    }

    #ifdef dipta007
    void print()   ///For debugging purpose
    {
        printf( "********\n");
        for ( int i = 0; i < row; i++ )
        {
            for ( int j = 0; j < col; j++ )
                printf ( "%d ", a[i][j] );
            printf ( "\n" );
        }
        printf( "********\n");
    }
    #else
    void print(){}
    #endif
    MAT operator * (const MAT &b )   ///Matrix Multiplication N^3
    {
        MAT res ( row, b.col );

        ll x = LLONG_MAX,y = (ll)MATMOD*MATMOD;
        for ( int i = 0; i < row; i++ )
        {
            for ( int j = 0; j < b.col; j++ )
            {
                x=LLONG_MAX;
                for ( int k = 0; k < col; k++ )
                {
                    x = min(x, ((ll)a[i][k] + b.a[k][j]) );
                    //debug(x, y)
//                    if(x >= y) x -= y; ///Change here if no mod.
                }
                res.a[i][j] = x ;///% (ll)MATMOD; /// And here too
            }
        }
        return res;
    }
    MAT operator ^ ( ll p )   ///Matrix Exponentiation
    {
        MAT res ( row, col );
        res.identity();
        MAT x = *this;
        while ( p )
        {
            if ( p & 1 )
            {
                res = res * x;
            }
            x = x * x;
            p >>= 1;
        }
        return res;
    }
};



int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n,m,p;
        getIII(n,m,p);

        int node = n;

        FOR(i,0,n-1)
        {
            FOR(j,0,n-1) adjMatrix[i][j] = INF;
        }

//        FOR(i,0,n-1) adjMatrix[i][i] = 0;

        FOR(i,1,m)
        {
            int x,y,z;
            getIII(x,y,z);
            x--,y--;
            adjMatrix[x][y] = z;
            adjMatrix[y][x] = z;
        }

//        for(int k=0;k<node;k++)
//        {
//            for(int i=0;i<node;i++)
//            {
//                for(int j=0;j<node;j++)
//                {
//                    if(adjMatrix[i][k]+adjMatrix[k][j]<adjMatrix[i][j])
//                    {
//                        adjMatrix[i][j] = adjMatrix[i][k]+adjMatrix[k][j];
//                    }
//                }
//            }
//        }

//        FOR(i,0,n-1)FOR(j,0,n-1) debug(i,j,adjMatrix[i][j])

        MAT now(n,n);
        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                now.a[i][j] = adjMatrix[i][j];
            }
        }

        now.print();
        now = now ^ (p-1);

        now.print();

        ll res = 0;

//        FOR(i,0,n-1)
//        {
//            FOR(j,0,n-1)
//            {
//                if(i==j) continue;
//                res += now.a[i][j] * adjMatrix[i][j];
//            }
//        }
        FOR(i,0,n-1)
        {
            debug(i, 0, adjMatrix[i][0], now.a[i][0])
            res += now.a[i][0] * adjMatrix[i][0];
        }

        debug(res);
    }

    return 0;
}



