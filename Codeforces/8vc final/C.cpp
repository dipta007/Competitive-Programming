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

ll bitOn(ll N,int pos)
{
    return N=(ll)N | (1<<pos);
}
ll bitOff(ll N,int pos)
{
    return N=(ll)N & ~(1<<pos);
}
bool bitCheck(ll N,int pos)
{
    return (bool)(N & (1<<pos));
}

int n,t;
ll s,x;
ll dp[70][4][70][70];

//ll call(int pos,int type,int z1,int z2,ll m1,ll m2)
//{
//    if(t==0) cout << m2 << endl;
//    if(pos>=n)
//    {
//        t++;
//        if(t<=1) debug(m1,m2);
////        cout << m1 << " "<<m2 <<endl;
//        if(m1+m2==s && m1>0 && m2>0)
//        {
//            return 1;
//        }
//        return 0;
//    }
//    ll &ret = dp[pos][z1][z2];
////    if(ret!=-1) return ret;
//    ll res =0;
//    if(bitCheck(x,pos)==0)
//    {
//        res += call(pos+1,1,z1+1,z2+1,bitOff(m1,pos),bitOff(m2,pos));
//        res += call(pos+1,2,z1,z2,bitOn(m1,pos),bitOn(m2,pos));
//    }
//    else
//    {
//        res += call(pos+1,1,z1+1,z2,bitOff(m1,pos),bitOn(m2,pos));
//        res += call(pos+1,2,z1,z2+1,bitOn(m1,pos),bitOff(m2,pos));
//    }
//    return ret=res;
//}

ll binToLL(string st)
{
    ll res=0;
    ll c=1;
    for(int i=st.size()-1;i>=0;i--)
    {
        if(st[i]=='1') res += c;
        c*=2;
    }
    return res;
}

ll call1(int pos,int type,int z1,int z2,string m1,string m2)
{
//    if(t==0) cout << m2 << endl;
    if(pos>=n)
    {
        ll mm1,mm2;
        mm1=binToLL(m1);
        mm2=binToLL(m2);
//        cout << m1 << " " << mm1 << " "<<m2 << " " << mm2 <<endl;
//        debug(mm1,mm2);
        if(mm1+mm2==s && mm1>0 && mm2>0)
        {
            return 1;
        }
        return 0;
    }
    ll &ret = dp[pos][type][z1][z2];
    if(ret!=-1) return ret;
    ll res =0;
    if(bitCheck(x,pos)==0)
    {
        res += call1(pos+1,1,z1+1,z2+1,'0'+m1,'0'+m2);
        res += call1(pos+1,2,z1,z2,'1'+m1,'1'+m2);
    }
    else
    {
        res += call1(pos+1,1,z1+1,z2,'0'+m1,'1'+m2);
        res += call1(pos+1,2,z1,z2+1,'1'+m1,'0'+m2);
    }
    return ret=res;
}

int main() {
    READ("in.txt");
//    WRITE("out.txt");

//    ll s,x;
    while(cin>>s>>x)
    {
        t=0;
        SET(dp);
        n=0;
        ll ss=s;
        while(ss)
        {
            ss /= 2;
            n++;
        }
        debug(999999999999^1);
        debug(n)
        ll z=0;
        printf("%I64d\n",call1(0,0,0,0,"",""));
//        debug(call(0,0,0,0));
    }

    return 0;
}


