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


int MATMOD = 10;

struct matrix
{
    int a[34][34];
    int row, col;

    matrix(){};
    matrix(int n)
    {
        row = col = n;
        mem();
    }
    matrix(int r, int c)
    {
        row = r;
        col = c;
        mem();
    }

    void assign(int n)
    {
        row = col = n;
        mem();
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

    void identity()
    {
        mem();
        for ( int i = 0; i < row; i++ ) a[i][i] = 1;
    }
    void mem()
    {
        memset ( a, 0, sizeof a );
    }

    matrix operator * (const matrix &b )   ///Matrix Multiplication N^3
    {
        matrix res ( row, b.col );

        for ( int i = 0; i < row; i++ )
        {
            for ( int j = 0; j < b.col; j++ )
            {
                for ( int k = 0; k < col; k++ )
                {
                    res.a[i][j] += (a[i][k] * b.a[k][j]);
                    res.a[i][j] %= MATMOD;
                }
            }
        }
        return res;
    }

    matrix operator + (const matrix &b)
    {
        matrix res(row, col);
        FOR(i,0,row-1)
        {
            FOR(j,0,col-1)
            {
                res.a[i][j] = a[i][j] + b.a[i][j];
                res.a[i][j] %= MATMOD;
            }
        }
        return res;
    }

    matrix operator ^ (ll p)
    {
        matrix res(row);
        res.identity();

        matrix x = *this;
        //x.print();
        while ( p )
        {
            if ( p & 1 )
            {
                res = res * x;
            }
            x = x * x;
            //debug(p)
            p >>= 1;
        }
        //res.print();
        return res;
    }
};

/*
1. Assign MATMOD
2. Declare MAT win row and col.
*/
class MAT
{
public:
    matrix a[2][2];
    int row, col;
    int n;
    MAT() {}
    MAT(int r, int c, int nn)
    {
        row = r;
        col = c;
        //mem();
        n = nn;
        FOR(i,0,row-1)
        {
            FOR(j,0,col-1)
            {
                a[i][j].assign(n);
            }
        }
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
        for ( int i = 0; i < row; i++ ) a[i][i] = 1;
    }
    void mem()
    {
        memset ( a, 0, sizeof a );
    }

    #ifdef dipta007
    void print()   ///For debugging purpose
    {
        //printf( "********\n");
        for ( int i = 0; i < row; i++ )
        {
            for ( int j = 0; j < col; j++ )
                a[i][j].print();
        }
        //printf( "********\n");
    }
    #else
    void print(){}
    #endif
    MAT operator * (const MAT &b )   ///Matrix Multiplication N^3
    {
        MAT res ( row, b.col ,n);

//        ll x,y = (ll)MATMOD*MATMOD;
        for ( int i = 0; i < row; i++ )
        {
            for ( int j = 0; j < b.col; j++ )
            {
                for ( int k = 0; k < col; k++ )
                {
                    matrix now = (a[i][k] * b.a[k][j]);
                    res.a[i][j] = res.a[i][j] + now;
                }
            }
        }
        return res;
    }
    MAT operator ^ ( ll p )   ///Matrix Exponentiation
    {
        MAT res ( row, col , n);
        FOR(i,0,row-1) res.a[i][i].identity();
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
//    MAT operator ^ ( ll p )   ///Matrix Exponentiation
//    {
//        MAT res(row, col, n);
//        FOR(i,0,row-1)
//        {
//            FOR(j,0,col-1)
//            {
//                //debug(i,j);
////                a[i][j].print();
//                res.a[i][j] = a[i][j] ^ p;
//            }
//        }
//        return res;
//    }
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
        int n,k;
        getII(n,k);

        MAT lft(2,2,n);
        MAT rgt(2,1,n);

        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                int x;
                getI(x);
                lft.a[0][0].a[i][j] = x;
                rgt.a[0][0].a[i][j] = x;
//                rgt.a[1][0].a[i][j] = x;
            }
        }

        rgt.a[1][0].mem();
        lft.a[0][1].mem();
        lft.a[1][0].identity();
        lft.a[1][1].identity();

//        lft.print();
//        rgt.print();

//        lft.a[0][0].print();
//        lft.a[0][1].print();
//        lft.a[1][0].print();
//        lft.a[1][1].print();
//        rgt.a[0][0].print();
//        rgt.a[1][0].print();

        lft = lft ^ (k);
        lft.print();
        MAT res = lft * rgt;
//        res.print();

        printf("Case %d:\n",ci);
        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                printf("%d",res.a[1][0].a[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}



