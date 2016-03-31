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
#define    getL(n)           scanf("%I64d",&n)
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

struct data
{
    int x,y;
};

bool cmp(const data &a,const data &b)
{
    if(a.x<b.x) return true;
    else if(a.x==b.x)
    {
        if(a.y<b.y) return true;
    }
    return false;
}

bool cmp1(const data &a,const data &b)
{
    if(a.y<b.y) return true;
    else if(a.y==b.y)
    {
        if(a.x<b.x) return true;
    }
    return false;
}

inline int sq_Distance( data a, data b ) {
	return ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y );
}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n;
    while(~getI(n))
    {
        data a[n];
        for(int i=0;i<n;i++)
        {
            getII(a[i].x,a[i].y);
        }
        sort(a,a+n,cmp1);
        int basey=a[0].y;
        sort(a,a+n,cmp);
        int basex=a[0].x;
//        debug(basCe);
        int maxy=0;
        for(int j=0;j<n;j++)
        {
            if(a[j].x!=basex && a[j].y!=basey)
                {
                    if(a[j].x>a[j].y)
                        a[j].y=basey;
                    else
                        a[j].x=basex;
                }
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
//                else if(a[j].x!=basex)
//                    a[j].y=basey;
//                else if(a[j].y!=basey)
//                    a[j].x=basex;
                int l=sq_Distance(a[i],a[j]);
                cout << a[i].x << " " << a[i].y << "->" << a[j].x << " " <<a[j].y << " - " << l <<endl;
                if(l>maxy)
                {
                    maxy=l;
                }
            }
        }
        printf("%d\n",maxy);

    }

    return 0;
}





