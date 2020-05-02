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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    F(i,L,R)	         for (int i = L; i < R; i++)
#define    FF(i,L,R) 	     for (int i = L; i <= R; i++)
#define    FR(i,L,R) 	     for (int i = L; i > R; i--)
#define    FRF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getC(n)           scanf("%c",&n)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double

#define    debug(a)     { cout << a <<endl; }
#define    debugI()     { cout << "*" <<endl; }
#define    debugII()    { cout << "**" <<endl; }
#define    debugIII()   { cout << "***" <<endl; }

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }


struct point { // Creates normal 2D point
	double x, y;
	point() {}
	point( double xx, double yy ) { x = xx, y = yy; }
};


bool insidePoly( point &p, point P[], int n ) {
	bool inside = false;
	for( int i = 0, j = n - 1; i < n; j = i++ )
		if( (( P[i].x < p.x ) ^ ( P[j].x < p.x )) &&
(P[i].y - P[j].y) * abs(p.x - P[j].x) < (p.y - P[j].y) * abs(P[i].x - P[j].x) )
			inside = !inside;
	return inside;
}



int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    point mp[10004][2];
    char ch;
    int n=0;
    while(~getC(ch))
    {
        if(ch=='*') break;
        point a,b;
        scanf("%lf %lf",&a.x,&a.y);
        scanf("%lf %lf",&b.x,&b.y);

        mp[n][0].x=a.x;
        mp[n][0].y=a.y;


        mp[n][1].x=b.x;
        mp[n][1].y=b.y;

        n++;
        getchar();
    }
    int ci=1;
    point p;
//    debug(n);
    while(~scanf("%lf %lf",&p.x,&p.y))
    {
        if(fabs(p.x-9999.9)<=EPS && fabs(p.y-9999.9)<=EPS) break;
        int flg=0;
        for(int i=0;i<n;i++)
        {
            if(p.x > mp[i][0].x+EPS && p.x+EPS < mp[i][1].x && p.y > mp[i][1].y+EPS && p.y+EPS < mp[i][0].y)
            {
                printf("Point %d is contained in figure %d\n",ci,i+1);
                flg=1;
            }
        }
        if(flg==0)
            printf("Point %d is not contained in any figure\n",ci);
        ci++;
    }


    return 0;
}

