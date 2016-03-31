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


int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    ll n,m;
    while(~scanf("%I64d %I64d",&n,&m))
    {
        if(m==1)
        {
            ll k;
            if(n%2==0) { k =n/2;k=k*(n-1);}
            else {k=(n-1)/2;k=k*n;}
            printf("%I64d %I64d\n",k,k);
        }
        else
        {
            ll l = n-(m-1);
            ll maxy;
            if(l%2==0) { maxy=l/2;maxy=maxy*(l-1);}
            else { maxy = (l-1)/2;maxy=maxy*l;}

            ll p=n/m;
            ll mini;
            if(n%m==0)
            {
                ll u;
                if(p%2==0) {u=p/2;u=(p-1)*u;}
                else {u=(p-1)/2;u=u*p;}
                mini=u*m;
            }
            else
            {
                p++;
                ll u = n%m;
                ll g;
                if(p%2==0) {g=p/2;g=g*(p-1);}
                else {g=(p-1)/2;g=g*p;}

                ll sum=g*u;
                //debug(u);
//                cout <<sum<<endl;
//                cout << n/p <<endl;
                m=m-u;
                p--;
                //debug(p);
                if(p%2==0) {g=p/2;g=g*(p-1);}
                else {g=(p-1)/2;g=g*p;}
//                cout <<n <<endl;
                //u=u/2;
                mini=sum+(g*m);
            }
            printf("%I64d %I64d\n",mini,maxy);
        }
    }

    return 0;
}


