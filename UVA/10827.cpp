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



int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        int n;
        getI(n);
        int a[2*n][2*n],maxRec=-INF;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                getI(a[i][j]);
                maxRec=max(maxRec,a[i][j]);
            }
        }
        for(int i=n;i<2*n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=a[i-n][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=n;j<2*n;j++)
            {
                a[i][j]=a[i][j-n];
            }
        }
        for(int i=n;i<2*n;i++)
        {
            for(int j=n;j<2*n;j++)
            {
                a[i][j]=a[i-n][j-n];
            }
        }


        if(maxRec<0)
        {
            printf("%d\n",maxRec);
            continue;
        }
        int kad[n];

        for(int l=0;l<n;l++)
        {
            CLR(kad);
            for(int r=l;r<l+n;r++)
            {
                int right=r;

                for(int i=0;i<n;i++)
                {
                    kad[i] += a[i][right];
//                    if(l==n-1 && right==5) debug(kad[i])
                }

                int left=0,maxy,curr;
                for(int i=0;i<n;i++)
                {
                    maxy=0;
                    curr=0;
                    for(int k=i;k<i+n;k++)
                    {
                        int down=k%n;
                        if(curr<0)
                        {
                            curr=kad[down];
                            left=down;
                        }
                        else
                        {
                            curr += kad[down];
                        }
//                        if(l==n-1 && right==5 && i==2) deb(curr);
                        maxy=max(maxy,curr);
//                        if(l==n-1 && right==5 && i==2)deb(maxy)
                    }

                    maxRec=max(maxRec,maxy);
//                    if(l==n-1 && right==5 && i==2)deb(maxy)
                }
//                if(l==n-1 && right==5)deb(maxy)
//                if(l==n-1 && right==5)deb(maxRec)
//                for(int i=1;i<left+n;i++)
//                {
//                    int down=i%n;
//                    if(curr<0)
//                    {
//                        curr=kad[down];
//                        left=down;
//                    }
//                    else
//                    {
//                        curr += kad[down];
//                    }
//
//                    maxy=max(maxy,curr);
//                }
//                if(l==n-1 && right==5)
//                debug(maxRec,maxy);

            }
        }
        printf("%d\n",maxRec);
    }

    return 0;
}

