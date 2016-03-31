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

#define    READ(f)           freopen(f, "r", stdin)
#define    WRITE(f)          freopen(f, "w", stdout)

#define    MP(x, y)          make_pair(x, y)
#define    SZ(c)             (int)c.size()
#define    PB(x)             push_back(x)

#define    F(i,L,R)          for (int i = L; i < R; i++)
#define    FF(i,L,R)         for (int i = L; i <= R; i++)
#define    FR(i,L,R)         for (int i = L; i > R; i--)
#define    FRF(i,L,R)        for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p)            p.begin(),p.end()
#define    ALLR(p)           p.rbegin(),p.rend()

#define    SET(p)            memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a)           scanf("%d", &a)
#define    getII(a,b)        scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%I64d",&a)
#define    getLL(a,b)        scanf("%I64d%I64d",&a,&b)
#define    getLLL(a,b,c)     scanf("%I64d%I64d%I64d",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getL(n)           scanf("%I64d",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi    vector < int >
#define    vii   vector < vector < int > >
#define    pii   pair< int, int >
#define    psi   pair< string, int >
#define    ff    first
#define    ss    second
#define    ll    long long
#define    ull   unsigned long long
#define    ui    unsigned int
#define    us    unsigned short
#define    ld    long double


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
//******************DELETE****************


int darr[]={
1,
10,
11,
100,
101,
110,
111,
1000,
1001,
1010,
1011,
1100,
1101,
1110,
1111,
10000,
10001,
10010,
10011,
10100,
10101,
10110,
10111,
11000,
11001,
11010,
11011,
11100,
11101,
11110,
11111,
100000,
100001,
100010,
100011,
100100,
100101,
100110,
100111,
101000,
101001,
101010,
101011,
101100,
101101,
101110,
101111,
110000,
110001,
110010,
110011,
110100,
110101,
110110,
110111,
111000,
111001,
111010,
111011,
111100,
111101,
111110,
111111,
1000000
};

//0-63

int dp[1000004];
int print[1000004];

int call(int n)
{
    if(n<=0) return 0;
    if(dp[n]!=-1) return dp[n];

    int ans=INF;
    int ret=0;
    for(int i=62;i>=0;i--)
    {
        if(n-darr[i]>=0)
        {
            //debug(i,darr[i]);
            ret=1+call(n-darr[i]);
            if(ans>=ret)
            {
                print[n]=darr[i];
                ans=ret;
            }
        }
    }
    return dp[n]=ans;
}

vi v;
void printALL(int n)
{
    if(n<=0) return;

    v.PB(print[n]);
    //debug(n,print[n]);
    printALL(n-print[n]);
    return;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n;
    while(~getI(n))
    {
        SET(dp);
        printf("%d\n",call(n));
        v.clear();
//        debug(print[n]);
//        debug(print[n-1]);
        printALL(n);
        //debug("sz",v.size());
        for(int i=0;i<v.size();i++)
        {
            if(i) printf(" ");
            printf("%d",v[i]);
        }
        printf("\n");
    }

    return 0;
}

