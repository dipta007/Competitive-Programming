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
#define    pii 	 pair< ll, ll >
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

int base(int x)
{
    if(x==0) return 1;
    int cnt = 0;
    while(x)
    {
        x/=7;
        cnt++;
    }
    return cnt;
}

int h,m,hh,mm,hm;
int arr[10];

bool check(string st)
{
    pii p;
    p.ff = p.ss = 0;
    ll c=1;
    ROF(i,hh-1,0)
    {
        ll k = st[i]-'0';
        p.ff += (k*c);
        c *= 7;
    }
    c = 1;
    ROF(i,hh+mm-1,hh)
    {
        ll k = st[i]-'0';
        p.ss += (k*c);
        c *= 7;
    }
    if(p.ff>=h || p.ss >= m) return 0;
    return 1;
}

ll call(int in, string st)
{
    if(in>=hh+mm)
    {
        //if(check(st)) debug(in,st, check(st))
        if(check(st)) return 1;
        return 0;
    }
    ll res = 0;
    if(in<hh)
    {
        FOR(i,0,6)
        {
            if(arr[i]==0)
            {
                arr[i]=1;
                res += call(in+1, st + (char)(i+'0'));
                arr[i]=0;
            }
        }
    }
    else
    {
        FOR(i,0,6)
        {
            if(arr[i]==0)
            {
                arr[i]=1;
                res += call(in+1, st + (char)(i+'0'));
                arr[i]=0;
            }
        }
    }
    return res;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    while(~getII(h,m))
    {
        hh = base(h-1);
        mm = base(m-1);
//        if(hh==0 && mm==0)
//        {
//            printf("0\n");
//            continue;
//        }
        //debug(hh,mm)
        CLR(arr);
        printf("%I64d\n",call(0,""));
    }

    return 0;
}



