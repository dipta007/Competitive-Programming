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

/*
1. Assign MATMOD
2. Declare MAT win row and col.
*/
int MATMOD = 10007;
class MAT
{
public:
    int a[100][100];   ///Maximum dimension of the matrix, Set Long Long
    int row, col;
    MAT() {}
    MAT(int r, int c)
    {
        row = r;
        col = c;
        mem();
    }
    void assign ( int r, int c)
    {
        mem();
        row = r;
        col = c;
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
}lft;


// horse
int dx[] = {-2,-2,2,2,-1,-1,1,1};
int dy[] = {1,-1,-1,1,2,-2,-2,2};
int nodes = 0;
int id[7][7][7][7];

void gen()
{
    FOR(a,0,5)
    {
        FOR(b,a+1,5)
        {
            FOR(c,0,5)
            {
                FOR(d,c+1,5)
                {
                    if(c-2 == a || c+2==a || c-2==b || c+2==b) continue;
                    if(d-2 == a || d+2==a || d-2==b || d+2==b) continue;

                    id[a][b][c][d] = nodes++;
                }
            }
        }
    }
    lft.assign(nodes, nodes);

    FOR(a,0,5)
    {
        FOR(b,a+1,5)
        {
            FOR(c,0,5)
            {
                FOR(d,c+1,5)
                {
                    if(c-2 == a || c+2==a || c-2==b || c+2==b) continue;
                    if(d-2 == a || d+2==a || d-2==b || d+2==b) continue;

                    FOR(e,0,5)
                    {
                        FOR(f,e+1,5)
                        {
                            if(e-2 == c || e+2==c || e-2==d || e+2==d) continue;
                            if(f-2 == c || f+2==c || f-2==d || f+2==d) continue;
                            if(e-1 == a || e+1==a || e-1==b || e+1==b) continue;
                            if(f-1 == a || f+1==a || f-1==b || f+1==b) continue;

                            int m1 = id[a][b][c][d];
                            int m2 = id[c][d][e][f];

                            lft.a[m1][m2] = 1;
                        }
                    }
                }
            }
        }
    }
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

//    int t;
//    int node = 1;
//    map <string, int> mp;
//    MAT lft(150,150);
//    FOR(m1,0,(1<<6)-1)
//    {
//        if(bitCount(m1) !=2) continue;
//        FOR(m2, 0, (1<<6)-1)
//        {
//            if(bitCount(m2) != 2) continue;
//            FOR(m3, 0, (1<<6)-1)
//            {
//                if(bitCount(m3) != 2) continue;
//
//
//                string tmp = "", tmp1 = "";
//                FOR(i,0,5) tmp += (bitCheck(m1, i)==1 ? "1" : "0");
//                FOR(i,0,5)
//                {
//                    tmp += (bitCheck(m2, i)==1 ? "1" : "0");
//                    tmp1 += (bitCheck(m2, i)==1 ? "1" : "0");
//                }
//                FOR(i,0,5) tmp1 += (bitCheck(m3, i)==1 ? "1" : "0");
//
//                int adj[6][3];
//                int in = 0;
//                FOR(i,0,1)
//                {
//                    FOR(j,0,5)
//                    {
//                        adj[j][i] = (int) (tmp[in++] - '0');
//                    }
//                }
//
//                int flg = 1;
//                FOR(i,0,5)
//                {
//                    if(bitCheck(m3,i) == 0) continue;
//                    FOR(j,0,7)
//                    {
//                        int x = i + dx[j];
//                        int y = 2 + dy[j];
//
//                        if(x >=0 && y>=0 && x<6 && y<2 && adj[x][y])
//                        {
//                            flg = 0;
//                            break;
//                        }
//                    }
//                    if(flg==0) break;
//                }
//
//                if(flg)
//                {
//                    if(mp[tmp]==0) mp[tmp] = node++;
//                    if(mp[tmp1]==0) mp[tmp1] = node++;
//
//                    lft.a[mp[tmp]][mp[tmp1]]=1;
//                }
//            }
//        }
//    }
    nodes = 0;
    gen();
    debug(nodes);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n;
        getI(n);
        if(n==1)
        {
            printf("15\n");
            continue;
        }
        MAT res = lft ^ (n-2);
        ll sum = 0;
        debug(res.row, res.col)
        FOR(i,0,res.row-1)
        {
            FOR(j,0,res.col-1)
            {
                sum += res.a[i][j];
                sum %= MATMOD;
            }
        }
        printf("%d\n",sum);

    }

    return 0;
}



