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

struct data
{
    int val,last;
};

bool cmp(const data &a,const data &b)
{
    if(a.last>b.last) return true;
    else if(a.last==b.last)
    {
        return a.val<b.val;
    }
    return false;
}

int value(int v)
{
    int k=floor((double)v/10.0);
    return k;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");


    int n,k;
    while(~getII(n,k))
    {
        data a[n];
        for(int i=0;i<n;i++)
        {
            getI(a[i].val);
            int k=a[i].val%10;
            //if(k==0) k+=10;
            a[i].last=k;
        }
        sort(a,a+n,cmp);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int l = a[i].val%10;
            l=min(10-l,100-a[i].val);
            if(l>k)
            {
                cnt+= value(a[i].val);
                a[i].last=a[i].val%10;
            }
            else
            {
                a[i].val += l;
                k -= l;
                cnt += value(a[i].val);
                a[i].last=0;
            }
        }
        if(k>=10)
        {
            sort(a,a+n,cmp);
            for(int i=n-1;i>=0 && k>0;i--)
            {
                //int l=a[i].val%10;
                int l=min(k,100-a[i].val);
                cnt+= value(l+a[i].val%10);
                k-=l;
            }
        }
        //debug(k);
//        int cnt=0;
//        int mc=0;
//        while(k>0)
//        {
//            sort(a,a+n,cmp);
//            //debug("a",a[0].last,a[0].val);
//            if(a[0].last==-1) break;
//            int l;
//            if(a[0].last==0)
//            {
//                l=min(k,100-a[0].val);
//            }
//            else
//                l=min(10-a[0].last,100-a[0].val);
//
//            if(l>k)
//            {
//                a[0].last = -1;
//                cnt += value(a[0].val);
//                //debug(cnt,a[0].val)
//                a[0].val=a[0].val%10;
//                mc++;
//                //a[0].val += k;
//                //k=0;
//            }
//            else
//            {
//                k -= l;
//                a[0].val += l;
//                a[0].last = 0;
//                if(a[0].val==100) a[0].last=-1;
//                cnt += value(a[0].val);
//                a[0].val=0;
//            }
//
//            if(mc>n) break;
//            //debug(a[0].val,value(a[0].val))
//        }
        printf("%d\n",cnt);

    }

    return 0;
}

