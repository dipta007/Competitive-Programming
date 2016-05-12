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
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

string a,b,ra,rb;
int len;

int call(int in)
{
    if(in>=len)
    {
        stringstream ss(a);
        ll x,y;
        ss >> x;
        stringstream ss1(b);
        ss1 >> y;
        return labs(x-y);
    }
    int res = INF;

    if(a[in]=='?')
    {
        FOR(i,0,9)
        {
            a[in]=i+'0';
            if(b[in]=='?')
            {
                FOR(j,0,9)
                {
                    b[in]=j+'0';
                    int k = call(in+1);
                    if(k<res)
                    {
                        res=k;
                        ra[in]=i+'0';
                        rb[in]=j+'0';
                    }
                    b[in]='?';
                }
            }
            a[in]='?';
        }
    }
    else if(b[in]=='?')
    {
        FOR(i,0,9)
        {
            b[in]=i+'0';
            int k = call(in);
            if(k<res)
            {
                res=k;
                rb[in]=i+'0';
            }
            b[in]='?';
        }
    }
    else
//    if(a[in]!='?' && b[in]!='?')
    {
        int k = call(in+1);
        if(k<res) res=k;
    }

    return res;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        //string a,b;
        cin >> a >> b;
        int len = a.size()-1;
        int f=0;
        FOR(i,0,len)
        {
//            if(f==-1)
//            {
//
//            }
            if(f==0)
            {
                if(a[i]=='?' && b[i]=='?')
                {
                    a[i]='0';
                    b[i]='0';
                }
                else if(a[i]=='?')
                {
                    FOR(j,i+1,len)
                    {
                        if(a[j]=='?' || b[j]=='?') continue;
                        if(a[j]<b[j])
                        {
                            a[i]=b[i]+1
                        }
                    }
                    a[i]=b[i];
                }
                else if(b[i]=='?')
                {
                    b[i]=a[i];
                }
//                else
                {
                    if(a[i]<b[i])
                    {
                        f=1;
                    }
                    else if(a[i]==b[i])
                    {
                        f=0;
                    }
                    else
                    {
                        f=2;
                    }
                }
            }
            if(f==1) ///a=9,b=0;
            {
                if(a[i]=='?' && b[i]=='?')
                {
                    a[i]='9';
                    b[i]='0';
                }
                else if(a[i]=='?')
                {
                    a[i]='9';
                }
                else if(b[i]=='?')
                {
                    b[i]='0';
                }
            }
            else if(f==2) ///a=0,b=9
            {
                if(a[i]=='?' && b[i]=='?')
                {
                    a[i]='0';
                    b[i]='9';
                }
                else if(a[i]=='?')
                {
                    a[i]='0';
                }
                else if(b[i]=='?')
                {
                    b[i]='9';
                }
            }
        }
        printf("Case #%d: %s %s\n",ci,a.c_str(),b.c_str());
    }

    return 0;
}




