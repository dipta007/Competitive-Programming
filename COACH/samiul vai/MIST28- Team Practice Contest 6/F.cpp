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
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
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


const double eps = 1e-11, pi = 2 * acos( 0.0 );


struct point { // Creates normal 2D point
	double x, y;
	point() {}
	point( double xx, double yy ) { x = xx, y = yy; }
};
inline double isleft( point p0, point p1, point p2 ) {
	return( ( p1.x - p0.x ) * ( p2.y - p0.y ) - ( p2.x - p0.x ) * ( p1.y - p0.y ) );
}
inline double sq_Distance( point a, point b ) {
	return ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y );
}
inline bool eq(double a, double b) { return fabs( a - b ) < eps; } //two numbers are equal

// compare Function for qsort in convex hull
point Firstpoint;
int cmp(const void *a,const void *b) {
	double x,y;
	point aa,bb;
	aa = *(point *)a;
	bb = *(point *)b;
	x = isleft( Firstpoint, aa, bb );
	if( x > eps ) return -1;
	else if( x < -eps ) return 1;
	x = sq_Distance( Firstpoint, aa );
	y = sq_Distance( Firstpoint, bb );
	if( x + eps < y ) return -1;
	return 1;
}

// 'P' contains all the points, 'C' contains the convex hull
// 'nP' = total points of 'P', 'nC' = total points of 'C'
void ConvexHull( point P[], point C[], int &nP, int &nC ) {
	int i, j, pos = 0; // Remove duplicate points if necesary
	for( i = 1; i < nP; i++ )
		if( P[i].y < P[pos].y || ( eq( P[i].y, P[pos].y ) && P[i].x > P[pos].x + eps ) )
			pos = i;
	swap( P[pos], P[0] );
	Firstpoint = P[0];
	qsort( P + 1, nP - 1, sizeof( point ), cmp );
	C[0] = P[0]; C[1] = P[1];
	i = 2, j = 1;
	while( i < nP ) {
		if( isleft( C[j-1], C[j], P[i] ) > -eps ) C[++j] = P[i++];
		else j--;
	}
	nC = j + 1;
}

point p[1004],c[1004];


int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int n,dis;
    while(~getII(n,dis))
    {
        FOR(i,0,n-1)
        {
            getF(p[i].x);
            getF(p[i].y);
        }
        int cn;
        ConvexHull(p,c,n,cn);
        //debug(cn);
        double peri=0;
        FOR(i,1,cn-1)
        {
            peri += sqrt(sq_Distance(p[i],p[i-1]));
        }
        peri += sqrt(sq_Distance(p[cn-1],p[0]));
        cout << peri << endl;
        double res = 2*PI*dis;
        printf("%.0lf\n",peri+res);
    }

    return 0;
}



