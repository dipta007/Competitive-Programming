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

struct point
{
    int x,y;
};


int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int x,y;
    while(~getII(x,y))
    {
        point a[8];
        a[0].x=x;
        a[0].y=y;
        for(int i=1;i<8;i++)
        {
            getII(a[i].x,a[i].y);
        }
        vector <int> vx,vy;
        vector <pii>vp;
        for(int i=0;i<8;i++)
        {
            int x=a[i].x;
            int y=a[i].y;
            vp.PB(MP(x,y));
            if(find(ALL(vx),x)==vx.end()) vx.PB(x);
            if(find(ALL(vy),y)==vy.end()) vy.PB(y);
        }
//        for(int i=0;i<8;i++)
//        {
//            cout << vp[i].ff << " " << vp[i].ss <<endl;
//        }
        if(vx.size()<3 || vy.size()<3)
        {
            printf("ugly\n");
            continue;
        }
        sort(ALL(vx));
        sort(ALL(vy));
        int flg=1;
        for(int i=0;i<3 && flg==1;i++)
        {
            for(int j=0;j<3 && flg==1;j++)
            {
                if(i==1 && j==1) continue;
                pii p=MP(vx[i],vy[j]);
                if(find(ALL(vp),p)==vp.end())
                {
                    flg=0;
                }
            }
        }
        if(flg==1) printf("respectable\n");
        else printf("ugly\n");
//        if(vx.size()==)
    }

    return 0;
}

