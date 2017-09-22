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

/*
1. Assign MATMOD
2. Declare MAT win row and col.
*/

ll MATMOD = 1000000000 + 7;
struct MAT{
    ll a[7][7];///Maximum dimension of the matrix
    int row, col;
    MAT(){}
    MAT(int r, int c){
        row = r;
        col = c;
        mem();
    }
    void assign ( int r, int c ) {
        row = r;
        col = c;
    }

    void identity(){
        mem();
        for ( int i = 0; i < row; i++ ) a[i][i] = 1;
    }
    void mem(){
        memset ( a, 0, sizeof a );
    }
    void print() { ///For debugging purpose
        printf( "********\n");
        for ( int i = 0; i < row; i++ ){
            for ( int j = 0; j < col; j++ ) printf ( "%llu ", a[i][j] );
            printf ( "\n" );
        }
    }
    MAT operator * ( MAT b ) { ///Matrix Multiplication N^3
        MAT res ( row, b.col );

        for ( int i = 0; i < row; i++ ){
            for ( int j = 0; j < b.col; j++ ){
                for ( int k = 0; k < col; k++ )
                    res.a[i][j] = ( res.a[i][j] + a[i][k] * b.a[k][j] ) % MATMOD; ///Change here if no mod.
            }
        }
        return res;
    }
    MAT operator ^ ( ll p ) { ///Matrix Exponentiation
        MAT res ( row, col ); res.identity();
        MAT x = *this;
        while ( p ){
            if ( p & 1 ){
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
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        ll a1,b1,c1,a2,b2,c2;
        getLLL(a1,b1,c1);
        getLLL(a2,b2,c2);
        ll f0,f1,f2,g0,g1,g2;
        getLLL(f0,f1,f2);
        getLLL(g0,g1,g2);
        getL(MATMOD);

        f0 %= MATMOD;
        f1 %= MATMOD;
        f2 %= MATMOD;
        g0 %= MATMOD;
        g1 %= MATMOD;
        g2 %= MATMOD;

        MAT coef(6,6);
        coef.a[0][0]=a1;
        coef.a[0][1]=b1;
        coef.a[0][5]=c1;
        coef.a[3][2]=c2;
        coef.a[3][3]=a2;
        coef.a[3][4]=b2;
        coef.a[1][0]=1;
        coef.a[2][1]=1;
        coef.a[4][3]=1;
        coef.a[5][4]=1;

        MAT init(6,1);
        init.a[0][0]=f2;
        init.a[1][0]=f1;
        init.a[2][0]=f0;
        init.a[3][0]=g2;
        init.a[4][0]=g1;
        init.a[5][0]=g0;

        int q;
        getI(q);
        printf("Case %d:\n",ci);
        FOR(i,1,q)
        {
            int x;
            getI(x);
            //debug(g2,MATMOD,g2%MATMOD,x==2)
            if(x==0) printf("%lld %lld\n",f0, g0);
            else if(x==1) printf("%lld %lld\n",f1, g1);
            else if(x==2) printf("%lld %lld\n",f2, g2);
            else
            {
                //debug(g2)
                MAT xx = coef ^ (x-2);
                MAT res = xx * init;
                //xx.print();
                //res.print();
                printf("%lld %lld\n",res.a[0][0], res.a[3][0]);
            }
        }
    }

    return 0;
}



