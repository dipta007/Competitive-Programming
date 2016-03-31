//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define ms(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})

double const EPS=3e-8;
using namespace std;

#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

// For loop

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int MX = 1111111 ;
Long A[MX] , B[MX] ;
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being

    Long mn = -1 , mx = -1 ;
    Long n , m  , x ;
    n = II ;
    rep(i,n)
    {
        x = II ;
        A[i] = x ;
        if( mn == -1 || mn > x ) mn = x ;
        if( mx == -1 || x > mx ) mx = x ;
    }
    Long AA = 3*n ;
    mn -= 1 ;
    m = II ;
    Long BB = 0 ;
    rep(i,m)
    {
        x = II ;
        B[i] = x ;
        if ( x > mn ) BB += 3 ;
        else BB += 2 ;
    }
    Long tmp = AA - BB ;
    Long lft = 0 , rgt = 1e10 , mid ;
    while( lft <= rgt )
    {
        mid = ( lft + rgt )/2 ;
        Long a = 0 , b = 0 ;
        rep(i,n)
        {
            if( A[i] > mid ) a += 3 ;
            else a += 2 ;
        }
        rep(i,m)
        {
        if( B[i] > mid ) b += 3 ;
        else b += 2 ;
        }
        if( tmp <= ( a - b ) )
        {
            tmp = a - b ;
            AA = a ;
            BB = b ;
            rgt = mid - 1 ;
        }
        else
        {
            lft = mid + 1 ;
        }
    }
    printf("%I64d:%I64d\n",AA,BB);



    return 0;
}

