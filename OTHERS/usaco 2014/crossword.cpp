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
    bool operator < (const point &b) const
    {
        if(x<b.x) return true;
        else if(x==b.x) return y<b.y;
        return false;
    }
};

bool cmp(const point &a,const point &b)
{
    if(a.x<b.x) return true;
    else if(a.x==b.x) return a.y<b.y;
    return false;
}

int main() {
    READ("crosswords.in");
    WRITE("crosswords.out");

    int n,m;
    while(~getII(n,m))
    {
        int a[n+2][m+2];
        for(int i=0;i<n+2;i++)
        {
            for(int j=0;j<m+2;j++)
            {
                a[i][j]=1;
            }
        }
        getchar();
        char st[56];
        for(int i=1;i<=n;i++)
        {
            gets(st);
            int len=strlen(st);
            for(int j=0;j<len;j++)
            {
                if(st[j]=='.') a[i][j+1]=0;
                else a[i][j+1]=1;
            }
        }
//        for(int i=0;i<n+2;i++)
//        {
//            for(int j=0;j<m+2;j++)
//            {
//                cout << a[i][j] ;
//            }
//            cout << endl;
//        }
        set <point> s;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int flg=0;
                if(a[i-1][j]==1 && a[i][j]==0 && a[i+1][j]==0 && a[i+2][j]==0)
                {
//                    debugI();
                    point d;
                    d.x=i;d.y=j;
                    s.insert(d);
                }
                else if(a[i][j-1]==1 && a[i][j]==0 && a[i][j+1]==0 && a[i][j+2]==0)
                {
//                    debugII();
                    point d;
                    d.x=i;d.y=j;
                    s.insert(d);
                }
            }
        }
        printf("%d\n",s.size());
        FOREACH(i,s)
        {
            point d=*i;
            printf("%d %d\n",d.x,d.y);
        }
    }

    return 0;
}
