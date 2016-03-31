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

int on(int N,int pos)
{
    return N=N | (1<<pos);
}
int off(int N,int pos)
{
    return N=N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

int dp[18][3],n,power;
int pri[18][3];

int call1(int pos,int flg,ll val)
{
    if(pos>=n)
    {
        if(val%power==0) return 1;
        return 0;
    }
    int &ret = dp[pos][flg];
    if(ret!=-1) return ret;

    int s1,s2;
    s1=s2=INF;
    s1=call1(pos+1,1,((val*10)+1)%power);
    if(s1==1)
    {
        pri[pos][flg]=1;
        return ret=1;
    }
    s2=call1(pos+1,2,((val*10)+2)%power);
    if(s2==1)
    {
        pri[pos][flg]=2;
        return ret=2;
    }
    return ret = -1;
}

void print(int pos,int flg,int val)
{
    if(pos>=n)
    {
        return;
    }
    if(pri[pos][flg]==1)
    {
        printf("1");
        print(pos+1,1,((val*10)+1)%power);
    }
    else
    {
        printf("2");
        print(pos+1,2,((val*10)+2)%power);
    }
    return;
}

vector <ll> v;
void call(int pos,ll val)
{
    if(pos>=n)
    {
        v.PB(val);
        return;
    }
    call(pos+1,(val*10)+1);
    call(pos+1,(val*10)+2);
    return;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        int p,q;
        getII(p,q);
        n=p;
        power=1;
        for(int i=1;i<=q;i++)
        {
            power *= 2;
        }
//        SET(dp);
//        int mini=call1(0,0,0);
//        print(0,0,0);
//        cout << endl;
//        debug(mini);

        int flg=0;
        v.clear();
        call(0,0);
        printf("Case %d:",ci);
        for(int i=0;i<v.size();i++)
        {
            if(v[i]%power==0)
            {
                printf(" %lld",v[i]);
                flg=1;
                for(int j=v.size()-1;j>i;j--)
                {
                    if(v[j]%power==0)
                    {
                        printf(" %lld",v[j]);
                        break;
                    }
                }
                break;
            }
        }

        if(flg==0) printf(" impossible");
        puts("");

    }

    return 0;
}


