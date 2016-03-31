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


template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

//******************DELETE****************
#define shubhashis
#ifdef shubhashis
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

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

#define M 1000004
bool marked[M];
vector <int> primes;

void sieve(int n)
{
    primes.push_back(2);
    int sqrtn = sqrt(n);
    for (int i = 3; i  <= sqrtn; i += 2)
    {
        if (marked[i] == 0)
        {
            primes.push_back(i);
            for (int j = i * i; j <= sqrtn; j += i + i)
            {
                marked[j] = 1;
            }
        }
    }
}

// prime number sob serially "primes" vector e save hobe
// like primes[0]=2,primes[1]=3 and so on

vector<int>factors,power;
map <int,int> mp;
void factorize( int n )
{
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < primes.size() && primes[i] <= sqrtn; i++ )
    {
        if ( n % primes[i] == 0 )
        {
            int cnt=0;
            while ( n % primes[i] == 0 )
            {
                n /= primes[i];
                cnt++;
            }
            mp[primes[i]] += cnt;
//            power.push_back(cnt);
//            factors.push_back(primes[i]);
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 )
    {
        mp[n]++;
//        power.push_back(1);
//        factors.push_back(n);
    }
}




int main()
{
//    READ("in.txt");
    //WRITE("out.txt");

    int n,d;
    sieve(2147483647);
    while(~getII(n,d))
    {
        if(n==0 && d==0) break;

        if((n==0 || n==1))
        {
            if(d==1) printf("1\n");
            else printf("0\n");
            continue;
        }
        if(d<0)
        {
            printf("0\n");
            continue;
        }
        mp.clear();
        for(int i=1;i<=n;i++)
        {
            factorize(i);
        }
        ll res=1;
        FOREACH(i,mp)
        {
            //debug(i->ff,i->ss)
            int p=i->first;
            while(d%p==0)
            {
                if(i->ss==0) res=0;
                d/=p;
                i->ss--;
            }
            //debug(i->ss+1)
            res *= (i->ss+1);
        }
        if(d!=1) res=0;
        printf("%lld\n",res);
//
//        ll res=1;
//        fore
//
//        int loop = 1,res=0;
//        for(int i=d; loop || res<=250; i+=d)
//        {
//            //debug(i)
//            factors.clear();
//            power.clear();
//            factorize(i);
//
//
//            int flg=1;
//            for(int j=0; j<factors.size(); j++)
//            {
//                int cnt=0;
//                int x=n;
//                while(x)
//                {
//                    cnt += x/factors[j];
//                    x /= factors[j];
//                }
//                //debug(factors[j],power[j],cnt,i)
//                if(cnt< power[j])
//                {
//                    flg=0;
//                    break;
//                }
//            }
//            if(flg==0) loop=1;
//            else res++;
//        }
    }

    return 0;
}


