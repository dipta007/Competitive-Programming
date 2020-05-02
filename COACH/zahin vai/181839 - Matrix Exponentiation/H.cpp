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

#ifdef dipta00
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
int MATMOD = 1000000007;
class MAT
{
public:
    int a[40][40];   ///Maximum dimension of the matrix, Set Long Long
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
        for ( int i = 0; i < row; i++ ) a[i][i] = 1;
    }
    void mem()
    {
        memset ( a, 0, sizeof a );
    }

    #ifdef dipta00
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

        ll x,y = (ll)MATMOD*MATMOD;
        for ( int i = 0; i < row; i++ )
        {
            for ( int j = 0; j < b.col; j++ )
            {
                x=0;
                for ( int k = 0; k < col; k++ )
                {
                    x += ((ll)a[i][k] * b.a[k][j]);
                    //debug(x, y)
                    if(x >= y) x -= y; ///Change here if no mod.
                }
                res.a[i][j] = x % (ll)MATMOD; /// And here too
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

map < string, int > mp;

string rev(string st)
{
    string tmp = st;
    reverse(ALL(tmp));
    return tmp;
}

bool check(string a, string b)
{
    //debug(a,b)
    int in = 0;
    FOR(i,0,6)
    {
        if(a[i]=='1')
        {
            for(int j=0;j<=6;j++)
            {
                //debug(in)
                if(b[j]=='1')
                {
                    if(i==j+1 || i==j-1)
                    {
                        b[j] = '0';
                        break;
                    }
                }
                if(j==6) return 0;
            }
        }
    }
    return 1;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int in = 1;
    vector < string > v;
    FOR(i,0,(1<<7))
    {
        if(bitCount(i)!=4) continue;

        string st = "";
        FOR(j,0,6)
        {
            if(bitCheck(i,j)==1) st += "1";
            else st += "0";
        }

        v.PB(st);

        if(mp[st]==0)
        {
            mp[st] = in;
            in++;
        }
    }

    MAT rgt(35,35);
    //rgt.print();

    FOR(i,0,34)
    {
        FOR(j,0,34)
        {
            //if(i==j) continue;

            if(check(v[i], v[j]))
            {
                //debug(i,j)
                int x = mp[v[i]];
                int y = mp[v[j]];

                x--, y--;

                rgt.a[x][y] += 1;
            }
        }
    }

//    FOR(i,0,18)
//    {
//        FOR(j,0,18)
//        {
//            rgt.a[i][j] /= 2;
//        }
//    }

    rgt.print();

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n;
        getI(n);
        string st = "";
        FOR(i,1,7) st += "0";

        FOR(i,1,7)
        {
            int x;
            getI(x);
            if(x!=0) st[i-1] = '1';
        }

//        FOR(i,0,34)
//        {
//           if(check(st, v[i]))
//           {
//               debug(v[i])
//               int x = mp[st] - 1;
//               int y = mp[v[i]] - 1;
//
//               debug(x,y, rgt.a[x][y])
//           }
//        }

        debug(st, mp[st])

        MAT lft(1, 35);

        lft.a[0][mp[st]-1] = 1;

        MAT rr = rgt ^ (n-1);
        MAT res = lft * rr;

        res.print();

        int sum = 0;
        FOR(i,0,34)
        {
            sum += res.a[0][i];
            sum %= MATMOD;
        }
        printf("Case %d: %d\n",ci,sum);
    }

    return 0;
}

/// http://www.suhendry.net/blog/?p=593


