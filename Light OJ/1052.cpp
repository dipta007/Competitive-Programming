#include <bits/stdc++.h>
using namespace std;

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
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
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    sf scanf
#define    pf printf
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
#else
    #define debug(args...)  /// Just strip off all debug tokens
    #define trace(...) ///yeeeee
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

int t, n, m;

/**
Procedure:
    1. Assign MATMOD
    2. Assign row, col, a[][]
    Or, Call assign(r,c, temp[] )
    3. Use ^ to get the power of matrix
Time Complexity = O(row * col * col)
Space Complexity = O(row * col)
**** MUST HAVE AT LEAST ONE POSITIVE NUMBER
**/
const int MX = 4;
int MATMOD = 1000000007;
class MAT
{
public:
    int a[MX][MX]; /// Set ll if needed
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
        for ( int i = 0; i < row; i++ )
            a[i][i] = 1;
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
    void print() {}
#endif
    MAT operator * (const MAT &b )
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
                    if(x >= y)
                        x -= y; ///Change here if no mod.
                }
                res.a[i][j] = x % (ll)MATMOD; /// And here too
            }
        }
        return res;
    }
    MAT operator ^ ( ll p )
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

ll getNthFibo(int n, ll a=1, ll b=1)
{
    if(n == 1) return a%MATMOD;
    else if(n == 2) return b%MATMOD;
    else if(n == 3) return (a+b)%MATMOD;
    else
    {
        MAT left;
        int tmp[] = {1,1,1,0};
        left.assign(2, 2, tmp);
        left = left ^ (n-2);
        ll res = (b * left.a[0][0]) % MATMOD + (a * left.a[0][1]) % MATMOD;
        res %= MATMOD;
        return res;
    }
}

ll bigmod ( ll b, ll p, ll m ) {
    ll res = 1 % m, x = b % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}

ll MOD(ll x)
{
    return (x%MATMOD + MATMOD)%MATMOD;
}

void solveEqn(ll x1, ll y1, ll c1, ll x2, ll y2, ll c2, ll &x, ll &y)
{
    ll determinant = x1 * y2 - y1 * x2;
    trace(determinant, determinant==0);
    if(determinant != 0)
    {
        x = ((c1*y2) - (y1*c2));
        y = ((c2*x1) - (x2*c1));
        debug(x, y, determinant);
        if(x%determinant || y%determinant)
        {
            x = -1, y= -1;
            return;
        }
        x /= determinant;
        y /= determinant;
        trace(x, y);
        if(x <0 || y<0)
        {
            x = -1, y = -1;
            return;
        }
    }
    else
    {
        trace("sad");
        x = -1, y = - 1;
    }
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n, X, m, Y, k;
        getII(n, X);
        getII(m, Y);
        getI(k);

        ll x, y;
        solveEqn(getNthFibo(n), getNthFibo(n+1), X, getNthFibo(m), getNthFibo(m+1), Y, x, y);

        trace(x,y);
        pf("Case %d: ", ci);
        if(x < 0)
        {
            pf("Impossible\n");
            continue;
        }

        pf("%lld\n", getNthFibo(k, x+y, y+x+y));
    }

    return 0;
}


