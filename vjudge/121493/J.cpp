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

#ifdef dipta007
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

//#define SIZE 1000005
//int arr[SIZE];

#define M 100000004
bool marked[M];
vector <int> primes;

void sieve(int n)
{
    primes.push_back(2);
    for (int i = 3; i * i <= n; i += 2)
    {
        if (marked[i] == 0)
        {
            for (int j = i * i; j <= n; j += i + i)
            {
                marked[j] = 1;
            }
        }
    }
    for(int i=3; i<=n; i+=2)
    {
        if(marked[i]==0) primes.PB(i);
    }
}


///Returns number of primes between segment [a,b]
//int segmentedSieve ( int a, int b )
//{
//    if ( a == 1 ) a++;
//
//    int sqrtn = sqrt ( b );
//
//    memset ( arr, 0, sizeof arr ); ///Make all index of arr 0.
//
//    for ( int i = 0; i < primes.size() && primes[i] <= sqrtn; i++ )
//    {
//        int p = primes[i];
//        int j = p * p;
//
//        ///If j is smaller than a, then shift it inside of segment [a,b]
//        if ( j < a ) j = ( ( a + p - 1 ) / p ) * p;
//
//        for ( ; j <= b; j += p )
//        {
//            arr[j-a] = 1; ///mark them as not prime
//        }
//    }
//
//    int res = 0;
//    for ( int i = a; i <= b; i++ )
//    {
//        ///If it is not marked, then it is a prime
//        if ( arr[i-a] == 0 ) res++;
//    }
//    return res;
//}

bool check(ll n)
{
    ll nn = sqrt(n);
    if(n==1) return 0;
    if(n==2) return 1;
    if(n%2==0) return 0;
    for(int i=0; i<primes.size() && primes[i]<=nn; i++)
    {
        if(n%primes[i]==0) return 0;
    }
    return 1;
}

int main()
{
#ifdef dipta007
//        READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007

    string st;
    sieve(100000000);
    debug(primes.size())
    while(getline(cin,st))
    {
        ll n;
        stringstream ss1(st);
        ss1 >> n;
        if(check(n)==0)
        {
            printf("no\n");
            continue;
        }
        int flg=1;
        FOR(i,0,(int)st.size()-1)
        {
            if(st[i]=='6') st[i]='9';
            else if(st[i]=='9') st[i]='6';
            else if(st[i]=='3' || st[i]=='4' || st[i]=='7')
            {
                flg=0;
                break;
            }
        }
        if(flg==0)
        {
            printf("no\n");
            continue;
        }
        reverse(ALL(st));
        //debug(st);
        //debug(st);
        stringstream ss(st);
        ss >> n;
        if(check(n)==0)
        {
            printf("no\n");
            continue;
        }
        printf("yes\n");
    }

    return 0;
}


