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

template< class T > inline T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > inline T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > inline T _min(T a, T b) { return (a < b ? a : b); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template< class T > inline T lcm(T a, T b) { return (a / gcd(a, b) * b); }

struct point
{
    ll x,y;
};

const ll INF = 9223372036854775807;

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        point org,a1,a2,a3,a4;
        scanf("%lld %lld %lld %lld %lld %lld",&org.x,&org.y,&a1.x,&a1.y,&a3.x,&a3.y);
        a2.x=a3.x;
        a2.y=a1.y;
        a4.x=a1.x;
        a4.y=a3.y;
        ll a,b,c;
        ll d1,d2,d3,d4;

        a=0;
        b=(a1.x-a2.x);
        c=b*a1.y;
        if(!a && !b) d1=INF;
        else d1=(labs(b*org.y+c))/(sqrt(a*a+b*b));

        a=0;
        b=a3.x-a4.x;
        c=b*a3.y;
        if(!a && !b) d3=INF;
        else d3=(labs(b*org.y+c))/(sqrt(a*a+b*b));

        a=a1.y-a4.y;
        b=0;
        c=a*a1.x;
        if(!a && !b) d4=INF;
        else d4=(labs(a*org.x+c))/(sqrt(a*a+b*b));

        a=a2.y-a3.y;
        b=0;
        c=a*a2.x;
        if(!a && !b) d2=INF;
        else d2=(labs(a*org.x+c))/(sqrt(a*a+b*b));
        //cout << d1 <<" "<<d2<<" "<<d3<<" "<<d4<<endl;
        ll mini=_min(d1,_min(d2,_min(d3,d4)));
        printf("%lld\n",mini);
    }

    return 0;
}

