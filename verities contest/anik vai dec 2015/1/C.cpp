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

#define    rep(i,n)          for(i=1;i<=n;i++)
#define    repI(i,n)         for(i=0;i<n;i++)
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
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
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

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N=N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}


//ll call(int pos,int pal,int isSmall,int isStartPoint)
//{
//    debug("*",pos,len)
//    if(pos>=len || pal<=0)
//    {
//        return 1;
//    }
//
//    ll &ret = dp[pos][pal][isSmall][isStartPoint];
//    if(ret!=-1) return ret;
//
//    int mx;
//    if(isSmall) mx=9;
//    else mx=inp[pos];
//    ll cnt=0;
//    if(isStartPoint)
//    {
//        for(int i=1;i<=mx;i++)
//        {
//            int var = len-pos;
//            var = ceil((double)var/2.0);
//            var--;
//            cnt += call(pos+1,var,i<inp[pos],0);
//        }
//        cnt += call(pos+1,pal,1,1);
//    }
//    else
//    {
//        for(int i=0;i<=mx;i++)
//        {
//            cnt += call(pos+1,pal-1,isSmall || (i<inp[pos]),isStartPoint);
//        }
//    }
//    debug(pos,cnt,"*");
//    return ret = cnt;
//}

int len;
vi inp;
ll dp[20][20][2][2][2];

ll call(int low,int high,int isSmall,int isStartingPoint,int chotoDhorsi)
{

    if(low>high)
    {
        if(chotoDhorsi==1 && isSmall==0) return 0;
        return 1;
    }

    ll &ret = dp[low][high][isSmall][isStartingPoint][chotoDhorsi];
    //if(ret!=-1) return ret;

    int mx;
    if(isSmall) mx=9;
    else mx=inp[low];

    ll cnt=0;
    if(isStartingPoint)
    {
        for(int i=1;i<=mx;i++)
        {
//            if(isSmall || i<inp[low])
//            {
//                cnt += call(low+1,high-1,isSmall || (i<inp[low]),0,chotoDhorsi);
//            }
//            else
            if(i<=inp[high])
            {
                cnt += call(low+1,high-1,isSmall || (i<inp[low]),0,chotoDhorsi);
            }
            else
            {
                cnt += call(low+1,high-1,isSmall || (i<inp[low]),0,1);
            }

        }
        cnt += call(low+1,high,1,1,0);
    }
    else
    {
        for(int i=0;i<=mx;i++)
        {
//            if(isSmall || i<inp[low])
//            {
//                cnt += call(low+1,high-1,isSmall || (i<inp[low]),0,chotoDhorsi);
//            }
//            else
            if(i<=inp[high])
            {
                cnt += call(low+1,high-1,isSmall || (i<inp[low]),0,chotoDhorsi);
            }
            else
            {
                cnt += call(low+1,high-1,isSmall || (i<inp[low]),0,1);
            }
            //cnt += call(low+1,high-1,isSmall || (i<inp[low]),isStartingPoint);
        }
    }
    //debug(low,high,cnt);

    return ret = cnt;
}

ll cal(ll x)
{
    inp.clear();
    while(x)
    {
        inp.PB(x%10);
        x /= 10;
    }
    reverse(ALL(inp));
    len=inp.size();

    SET(dp);
    ll res = call(0,len-1,0,1,0);
    debug(res);
    return res;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        ll a,b;
        getLL(a,b);
        if(a>b) swap(a,b);
        debug(a,b,"a b")
        int flg=0;
        if(a==0)
        {
            a++;
            flg=1;
        }
        ll res=cal(b)-cal(a-1);
        if(flg) res++;
        printf("Case %d: %lld\n",ci,res);
    }

    return 0;
}

