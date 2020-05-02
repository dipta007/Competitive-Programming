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

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef dipta007
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

/*
1. Assign MATMOD
2. Declare MAT win row and col.
*/

ll MATMOD = 1000000000 + 7;
struct MAT
{
    ll a[4][4];///Maximum dimension of the matrix
    int row, col;
    MAT() {}
    MAT(int r, int c)
    {
        row = r;
        col = c;
        mem();
    }
    void assign ( int r, int c )
    {
        row = r;
        col = c;
        mem();
    }
    bool isIdentity()
    {
        return a[0][0] == 1 && a[1][0] == 0 && a[0][1] == 0 && a[1][1] == 1;
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
    void print()   ///For debugging purpose
    {
        printf( "********\n");
        for ( int i = 0; i < row; i++ )
        {
            for ( int j = 0; j < col; j++ ) printf ( "%llu ", a[i][j] );
            printf ( "\n" );
        }
    }
    MAT operator * ( MAT b )   ///Matrix Multiplication N^3
    {
        MAT res ( row, b.col );

        for ( int i = 0; i < row; i++ )
        {
            for ( int j = 0; j < b.col; j++ )
            {
                for ( int k = 0; k < col; k++ )
                    res.a[i][j] = ( res.a[i][j] + a[i][k] * b.a[k][j] ) % MATMOD; ///Change here if no mod.
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
            debug("p",p)
            if ( p & 1 )
            {
                res = res * x;
            }
            x = x * x;
            p >>= 1;
        }
        return res;
    }

    MAT operator + ( MAT b )
    {
        MAT c(row, col);
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                c.a[i][j] = (a[i][j] + b.a[i][j]) % MATMOD;
        return c;
    }
};


MAT A,fibo;

#define mx 100004
int arr[mx];
struct info
{
    MAT sum;
    MAT prop;
} tree[mx*4];

info call(info a,info b)
{
    info tmp;
    tmp.sum = a.sum + b.sum;
    tmp.prop.assign(2,2);
    tmp.prop.identity();
    return tmp;
}

void init(int node,int b,int e)
{
    if(b==e)
    {
        debug(b,arr[b])
        if(arr[b]==1)
        {
            tree[node].sum = A ^ arr[b];
            tree[node].sum.assign(1,2);
            tree[node].sum.a[0][0] = tree[node].sum.a[0][1] = 1;
        }
        else if(arr[b]==2)
        {
            tree[node].sum.assign(1,2);
            tree[node].sum.a[0][0] = 1;
            tree[node].sum.a[0][1] = 2;
        }
        else
        {
            arr[b] -= 1;
            tree[node].sum = fibo * (A^arr[b]);
        }
        tree[node].prop.assign(2,2);
        tree[node].prop.identity();
        return;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=call(tree[Left],tree[Right]);
}

void propagate(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].prop.identity();
        return;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    ///update propagation
    MAT prop = tree[node].prop;
    tree[Left].prop = tree[Left].prop * tree[node].prop;
    tree[Right].prop = tree[Right].prop * tree[node].prop;
    tree[node].prop.identity();
    ///update tree[left].sum
    tree[Left].sum = tree[Left].sum * prop;
    ///update tree[right].sum
    tree[Right].sum = tree[Right].sum * prop;
}

ll query(int node,int b,int e,int i,int j) ///range i theke j
{
    if (i > e || j < b)return 0;
    if(tree[node].prop.isIdentity()==false)propagate(node,b,e);
    if(b>=i && e<=j)
    {
        ///do something
        return tree[node].sum.a[0][0];
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    ll p1 = query(Left,b,mid,i,j);
    ll p2 = query(Right,mid+1,e,i,j);
    return  (p1+p2)%MATMOD;

}

void update(int node,int b,int e,int i,int j, MAT newVal)
{
    if(tree[node].prop.isIdentity()==false)propagate(node,b,e);
    if (i > e || j < b)	return;
    if (b >= i && e <= j)
    {
        tree[node].prop = tree[node].prop * newVal;
        tree[node].sum = tree[node].sum * newVal;
        ///do something
        return;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    update(Left,b,mid,i,j,newVal);
    update(Right,mid+1,e,i,j,newVal);
    tree[node]=call(tree[Left],tree[Right]);
}



int main()
{
#ifdef dipta007
    //READ("in.txt");
//        WRITE("in.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    A.assign(2,2);
    A.a[0][0] = 0;
    A.a[0][1] = A.a[1][0] = A.a[1][1] = 1;
    fibo.assign(1,2);
    fibo.a[0][0] = fibo.a[0][1] = 1;

    int n,q;
    while(~getII(n,q))
    {
        FOR(i,1,n)
        {
            getI(arr[i]);
        }
        init(1,1,n);

        FOR(i,1,q)
        {
            int tt,l,r;
            getIII(tt,l,r);
            if(tt==1)
            {
                int x;
                getI(x);
                MAT val = A ^ x;
                debug("*")
                update(1,1,n,l,r,val);
            }
            else
            {
                printf("%lld\n",query(1,1,n,l,r));
            }
        }
    }


    return 0;
}



