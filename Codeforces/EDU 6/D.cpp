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
const long long INF = 9223372036854775800;
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

int bitOn(int N,int pos)
{
    return N=N | (1<<pos);
}
int bitOff(int N,int pos)
{
    return N=N & ~(1<<pos);
}
bool bitCheck(int N,int pos)
{
    return (bool)(N & (1<<pos));
}


int n,m,a[2004],b[2004];
ll sum1,sum2;
vector <pii> res;
ll dp[2004][2004][3];
int pri[2004][2004][3];


void SETDP()
{
    for(int i=0;i<2001;i++)
    {
        for(int j=0;j<2001;j++)
        {
            for(int k=0;k<3;k++)
            {
                dp[i][j][k]=-1;
            }
        }
    }
}

ll call(int ina,int inb,int swp)
{
    //debug(sum1,sum2)
    if(swp>=2 || ina>=n || inb>=m)
    {
        return labs(sum1-sum2);
    }
    ll s1,s2,s3;
    s1=s2=s3=INF;

    ll &ret = dp[ina][inb][swp];
    if(ret!=-1) return ret;


    if(ina<n)
    {
        s1=call(ina+1,inb,swp);
    }
    if(inb<m)
    {
        s2=call(ina,inb+1,swp);
    }
    if(swp<2 && ina<n && inb<m)
    {
        ll aa=(ll)a[ina];
        ll bb=(ll)b[inb];

        sum1=sum1-aa+bb;
        sum2=sum2+aa-bb;

        s3=call(ina+1,inb+1,swp+1);

        sum1=sum1+aa-bb;
        sum2=sum2-aa+bb;
    }

    if(s1<=s2 && s1<=s3)
    {
        pri[ina][inb][swp]=1;
        return ret=s1;
    }
    else if(s2<=s1 && s2<=s3)
    {
        pri[ina][inb][swp]=2;
        return ret=s2;
    }
    else
    {
        pri[ina][inb][swp]=3;
        return ret=s3;
    }
}

void print(int ina,int inb,int swp)
{
    if(swp>=2 || ina>=n || inb>=m)
    {
        return;
    }

    int ekhn = pri[ina][inb][swp];
    if(ekhn==1)
    {
        print(ina+1,inb,swp);
    }
    else if(ekhn==2)
    {
        print(ina,inb+1,swp);
    }
    else
    {
        print(ina+1,inb+1,swp+1);
        res.PB(pii(ina+1,inb+1));
    }
    return;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    while(~getI(n))
    {
        res.clear();
        sum1=sum2=0;
        for(int i=0;i<n;i++)
        {
            getI(a[i]);
            sum1+= (ll) a[i];
        }
        getI(m);
        for(int i=0;i<m;i++)
        {
            getI(b[i]);
            sum2+= (ll)b[i];
        }
//        debug(sum1,sum2)
        SETDP();
        printf("%I64d\n",call(0,0,0));
        print(0,0,0);
        printf("%d\n",res.size());
        for(int i=0;i<res.size();i++)
        {
            printf("%d %d\n",res[i].ff,res[i].ss);
        }
    }

    return 0;
}


