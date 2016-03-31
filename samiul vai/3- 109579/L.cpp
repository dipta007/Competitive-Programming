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

//#define ull long long

ull Mod; 	 // ja die mod korte hbe

ull BigMod(ull B,ull E)		// B= base & E= expo or power
{
	if(E==0) return 1;
	if(E%2==0)
	{
		ull ret=BigMod(B,E/2);
		return ((ret%Mod)*(ret%Mod))%Mod;
	}
	else return ((B%Mod)*(BigMod(B,E-1)%Mod))%Mod;

}

#define M 1000000
bool marked[M];

bool isPrime(int n) {
  if (n < 2) return 1;
  if (n == 2) return 0;
  if (n % 2 == 0) return 1;
  return marked[n];
}

void sieve(int n) {
  for (ll i = 3; i <= n; i += 2) {
    if (marked[i] == 0) {
      for (ll j = i * i; j <= n; j += i + i) {
        marked[j] = 1;
      }
    }
  }
}

// jodi kono number prime hoi then 0 return korbe
// noito 1 return korbe
// mane
// prime = 0
//composite = 1

int main() {
    //READ("in.txt");
    //WRITE("out.txt");


    ull MAX = 18446744073709551615;
    Mod = MAX;
    set <ull> s;
    ull sq = 65537;
    bool markForPower[70000];
    sieve(sq-1);
    CLR(markForPower);
    for(ll i=2;i<sq;i++)
    {
        //if(markForPower[i]==0)
        for(ll j=i*i;j<=sq;j*=i)
        {
            markForPower[j]=1;
        }
    }
    //debug(sq);
    s.insert(1);
    for(ull i=2;i<sq;i++)
    {
        if(markForPower[i]==0)
        {
            ull k = ceil(64/(log(i)/log(2)));
            //debug(i)
            int in=1;
            ull res=i;
            for(ull j=4;j<k;j++)
            {
                if(isPrime(j)==1)
                {
                    while(in<j)
                    {
                        res*=i;
                        in++;
                    }
                    s.insert(res);
                }
            }
        }
    }
    FOREACH(it,s)
    {
        printf("%llu\n",*it);
    }

    return 0;
}


