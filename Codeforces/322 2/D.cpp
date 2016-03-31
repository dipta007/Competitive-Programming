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
#define    getL(a)           scanf("%I64d",&a)
#define    getLL(a,b)        scanf("%I64d%I64d",&a,&b)
#define    getLLL(a,b,c)     scanf("%I64d%I64d%I64d",&a,&b,&c)
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


template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

//******************DELETE****************
#define shubhashis
#ifdef shubhashis
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

/// ********* debug template bt Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}


#define deb(x) cerr << #x << " = " << x << endl;
//******************DELETE****************

struct point
{
    int x,y;
};

bool check(point a,point b,point c)
{
    int l,w;
    //1
    if(a.x==b.x && b.x==c.x)
    {
        l=a.x;
        w=a.y+b.y+c.y;
        if(l==w)
        {
            printf("%d\n",l);
            int col=l;
            int row=w;
            for(int i=0;i<a.y;i++)
            {
                for(int j=0;j<a.x;j++)
                {
                    printf("A");
                }
                printf("\n");
            }
            for(int i=0;i<b.y;i++)
            {
                for(int j=0;j<b.x;j++)
                {
                    printf("B");
                }
                printf("\n");
            }
            for(int i=0;i<c.y;i++)
            {
                for(int j=0;j<c.x;j++)
                {
                    printf("C");
                }
                printf("\n");
            }

            return 1;
        }
    }

    //2
    if(a.y==b.y && b.y==c.y)
    {
        l=a.x+b.x+c.x;
        w=a.y;
        if(l==w)
        {
            printf("%d\n",l);
            int col=l;
            int row=w;
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    if(j<a.x) printf("A");
                    else if(j<a.x+b.x) printf("B");
                    else printf("C");
                }
                printf("\n");
            }

            return 1;
        }
    }

    //3
    if(a.x+b.x==c.x && a.y==b.y)
    {
        l=c.x;
        w=a.y+c.y;
        if(l==w)
        {
            printf("%d\n",l);
            int col=l;
            int row=w-c.y;
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    if(j<a.x) printf("A");
                    else if(j<a.x+b.x) printf("B");
                }
                printf("\n");
            }
            for(int i=0;i<c.y;i++)
            {
                for(int j=0;j<c.x;j++)
                {
                    printf("C");
                }
                printf("\n");
            }

            return 1;
        }
    }

    //4
    if(a.x+c.x==b.x && a.y==c.y)
    {
        l=b.x;
        w=a.y+b.y;
        if(l==w)
        {
            printf("%d\n",l);
            int col=l;
            int row=w-b.y;
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    if(j<a.x) printf("A");
                    else if(j<a.x+c.x) printf("C");
                }
                printf("\n");
            }
            for(int i=0;i<b.y;i++)
            {
                for(int j=0;j<b.x;j++)
                {
                    printf("B");
                }
                printf("\n");
            }


            return 1;
        }
    }

    //5
    if(b.x+c.x==a.x && b.y==c.y)
    {
        l=a.x;
        w=b.y+a.y;
        if(l==w)
        {
            printf("%d\n",l);
            int col=l;
            int row=w-a.y;
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    if(j<b.x) printf("B");
                    else if(j<b.x+c.x) printf("C");
                }
                printf("\n");
            }
            for(int i=0;i<a.y;i++)
            {
                for(int j=0;j<a.x;j++)
                {
                    printf("A");
                }
                printf("\n");
            }


            return 1;
        }
    }

    //6
    if(a.x==b.x && a.y+b.y==c.y)
    {
        l=a.x+c.x;
        w=c.y;
        if(l==w)
        {
            printf("%d\n",l);
            int col=l;
            int row=w;
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    if(j<c.x) printf("C");
                    else
                    {
                        if(i<a.y) printf("A");
                        else printf("B");
                    }
                }
                printf("\n");
            }

            return 1;
        }
    }


    //7
    if(a.x==c.x && a.y+c.y==b.y)
    {
        l=a.x+b.x;
        w=b.y;
        if(l==w)
        {
            printf("%d\n",l);

            int col=l;
            int row=w;
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    if(j<b.x) printf("B");
                    else
                    {
                        if(i<a.y) printf("A");
                        else printf("C");
                    }
                }
                printf("\n");
            }
            return 1;
        }
    }

    //8
    if(b.x==c.x && b.y+c.y==a.y)
    {
        l=a.x+b.x;
        w=a.y;
        if(l==w)
        {
            printf("%d\n",l);

            int col=l;
            int row=w;
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    if(j<a.x) printf("A");
                    else
                    {
                        if(i<b.y) printf("B");
                        else printf("C");
                    }
                }
                printf("\n");
            }

            return 1;
        }
    }
    return 0;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    point a[2],b[2],c[2];
    while(~getII(a[0].x,a[0].y))
    {
        a[1].x=a[0].y;
        a[1].y=a[0].x;
        getII(b[0].x,b[0].y);
        b[1].x=b[0].y;
        b[1].y=b[0].x;
        getII(c[0].x,c[0].y);
        c[1].x=c[0].y;
        c[1].y=c[0].x;

        int flg=1;
        for(int i=0;i<2 && flg;i++)
        {
            for(int j=0;j<2 && flg;j++)
            {
                for(int k=0;k<2 && flg;k++)
                {
                    if(check(a[i],b[j],c[k]))
                    {
                        flg=0;
                        break;
                    }
                }
            }
        }
        if(flg) printf("-1");
    }


    return 0;
}

