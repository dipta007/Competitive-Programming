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

int a[1004],mark[1004],n;

int call(int f,int in,int  cnt)
{
    debug(f,in,cnt);
    //-1 0 1
    if(cnt>=n) return 0;
    int s1=INF,s2=INF;
    if(f==0)
    {
        mark[in]=1;
        s1=1+call(1,in,cnt);
        s2=1+call(-1,in,cnt);
    }
    else if(f==-1)
    {
        int last=-1;
        for(int i=in-1,k=0;k<n;k++,i--)
        {
            int pos;
            if(i<0) pos=i+n;
            else pos=i%n;

            if(a[pos]<=cnt && mark[pos]==0)
            {
                mark[pos]=1;
                cnt++;
                last=pos;
            }
        }
        if(last==-1)
            s1=1+call(1,in,cnt);
        else
            s1=1+call(1,last,cnt);

    }
    else
    {
        int last=-1;
        for(int i=in+1,k=0;k<n;k++,i++)
        {
            int pos;
            if(i<0) pos=i+n;
            else pos=i%n;

            if(a[pos]<=cnt && mark[pos]==0)
            {
                mark[pos]=1;
                cnt++;
                last=pos;
            }
        }
        if(last==-1)
            s1=1+call(-1,in,cnt);
        else
            s1=1+call(-1,last,cnt);
    }

    return min(s1,s2);
}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    while(~getI(n))
    {
        vi zero;
        for(int i=0;i<n;i++)
        {
            getI(a[i]);
            if(a[i]==0) zero.PB(i);
        }

        int ans=INF;
        for(int i=0;i<zero.size();i++)
        {
            int mc=call(0,zero[i],1);
            ans=min(ans,mc);
            debug(mc);
        }
        debug(ans);
        continue;
        for(int i=0;i<zero.size();i++)
        {
            int pos=zero[i];
            int cnt=1,mc=0,f=0;
            int mark[n];
            CLR(mark);
            mark[pos]=1;
            while(cnt<n)
            {
                if(f==0)
                {

                }
                int flg=0;
                for(int j=pos;j<n;j++)
                {
                    if(a[j]<=cnt && mark[j]==0)
                    {
                        mark[j]=1;
                        cnt++;
                        pos=j;
                        flg=1;
                    }
                }
                if(flg) mc++;
                flg=0;
                for(int j=pos;j>=0;j--)
                {
                    if(a[j]<=cnt && mark[j]==0)
                    {
                        mark[j]=1;
                        cnt++;
                        pos=j;
                        flg=1;
                    }
                }
                if(flg) mc++;
            }
            debug(mc);
            ans=min(ans,mc);
        }
        debug(ans)



        for(int i=0;i<zero.size();i++)
        {
            int pos=zero[i];
            int cnt=1,mc=1,in=pos,f=0;

            int mark[n];
            CLR(mark);
            while(cnt<n)
            {
                int samne=in+1;
                int pichone=in-1;
                if(in<0) in+=n;
                else in%=n;
                if(samne<0) samne+=n;
                else samne%=n;
                if(pichone<0) pichone+=n;
                else pichone%=n;

                if(f==1)
                {
                    if(a[samne]<=cnt && mark)
                    {
                        cnt++;
                        in=samne;
                    }
                    else
                    {
                        in = pichone;
                        f=-1;
                        cnt++;
                        mc++;
                    }
                }
                else if(f==-1)
                {
                    if(a[in-1]<=cnt)
                    {
                        cnt++;
                        in=pichone;
                    }
                    else
                    {
                        in=samne;
                        f=1;
                        cnt++;
                        mc++;
                    }
                }
                else if(f==0)
                {
                    if(a[samne]<=cnt)
                    {
                        cnt++;
                        in=samne;
                        f=1;
                    }
                    else
                    {
                        in = pichone;
                        f=-1;
                        cnt++;
                    }
                }
            }
            debug("mc",mc);
            ans=min(ans,mc);
        }
        printf("%d\n",ans);
    }

    return 0;
}

