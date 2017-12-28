
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
#define    getII(a,b) 	     scanf("%d %d", &a, &b)
#define    getIII(a,b,c)     scanf("%d %d %d", &a, &b, &c)
#define    getL(a)           scanf("%I64d",&a)
#define    getLL(a,b)        scanf("%I64d %I64d",&a,&b)
#define    getLLL(a,b,c)     scanf("%I64d %I64d %I64d",&a,&b,&c)
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


template< class T > inline T _abs(T n) { return ( (n) < 0 ? -(n) : (n) ); }
template< class T > inline T _max(T a, T b) { return ( ! ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _min(T a, T b) { return ( ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _swap(T &a, T &b) { T temp=a;a=b;b=temp;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd( (b), ( (a) % (b) ) ) ; }
template< class T > inline T lcm(T a, T b) { return ( (a) / gcd( (a), (b) ) * (b) ); }


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
    double suru,sesh;
};

bool cmp(const data &a, const data &b)
{
    if(a.suru+EPS<b.suru) return true;
    if(fabs(a.suru-b.suru)<=EPS)
    {
        if(a.sesh+EPS<b.sesh) return true;
    }
    return false;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int l,w;
    double cut;
    while(getII(l,w))
    {
        getF(cut);
        if(l==0 && w==0 && fabs(cut-0.0)<=EPS) break;
        cut=cut/2.0;
        double len[l];
        data cutL[l];
        for(int i=0;i<l;i++)
        {
            getF(len[i]);
            cutL[i].suru=len[i]-cut;
            if(cutL[i].suru+EPS<0.0) cutL[i].suru=0.0;
            cutL[i].sesh=len[i]+cut;
            if(cutL[i].sesh>75.0+EPS) cutL[i].sesh=75.0;
        }
        double wid[w];
        data cutW[w];
        for(int i=0;i<w;i++)
        {
            getF(wid[i]);
            cutW[i].suru=wid[i]-cut;
            if(cutW[i].suru+EPS<0.0) cutW[i].suru=0.0;
            cutW[i].sesh=wid[i]+cut;
            if(cutW[i].sesh>100.0+EPS) cutW[i].sesh=100.0;
        }
        sort(cutL,cutL+l,cmp);
        int flg=1;
        if(cutL[0].suru>0.0+EPS) flg=0;
        for(int i=1;i<l && flg;i++)
        {
//            debug(cutL[i-1].suru,cutL[i-1].sesh)
//            debug(cutL[i].suru,cutL[i].sesh)
            if(cutL[i].suru+EPS<cutL[i-1].sesh || fabs(cutL[i].suru-cutL[i-1].sesh)<=EPS)
                ;
            else flg=0;
        }
        if(cutL[l-1].sesh+EPS<75.0) flg=0;

        sort(cutW,cutW+w,cmp);
        if(cutW[0].suru>0.0+EPS) flg=0;
        for(int i=1;i<w && flg;i++)
        {
            if(cutW[i].suru+EPS<cutW[i-1].sesh || fabs(cutW[i].suru-cutW[i-1].sesh)<=EPS)
                ;
            else flg=0;
        }
        if(cutW[w-1].sesh+EPS<100.0) flg=0;
        if(flg) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
