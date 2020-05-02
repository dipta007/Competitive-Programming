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
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
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
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
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
#define MAXN 25
#define INF 0x3f3f3f3f
using namespace std;
int a[MAXN][MAXN];
int free_rec[MAXN];
int x[MAXN];
int equ, var;
void init_a()
{
    equ = var = 20;
    memset(a, 0, sizeof(a));
    for(int i = 1; i < 20; i++)
    {
        scanf("%d", &a[i][var]), a[i][var] ^= 0;
        a[i][i] = 1;
        a[i][i-1] = 1;
        if(i < 19)
            a[i][i+1] = 1;
    }
}
int Gauss()
{
    int max_r, k;
    int col = 0;
    int num = 0;
    for(k = 0; k < equ && col < var; k++, col++)
    {
        max_r = k;
        for(int i = k+1; i < equ; i++)
            if(a[i][col] > a[max_r][i])
                max_r = i;
        if(max_r != k)
            for(int i = col; i < var+1; i++)
                swap(a[k][i], a[max_r][i]);
        if(a[k][col] == 0)
        {
            k--;
            free_rec[num++] = col;
            continue;
        }
        for(int i = k+1; i < equ; i++)
            if(a[i][col] != 0)
                for(int j = col; j < var+1; j++)
                    a[i][j] ^= a[k][j];
    }
    for(int i = k+1; i < equ; i++)
        if(a[i][col] != 0)
            return -1;
    if(var > k)
        return var - k;
    return 0;
}
void solve(int S)
{
    int state = (1<<S);
    int ans = INF;
    for(int i = 0; i < state; i++)
    {
        int cnt = 0;
        for(int j = 0; j < S; j++)
        {
            if((1<<j) & i)
            {
                cnt++;
                x[free_rec[j]] = 1;
            }
            else
                x[free_rec[j]] = 0;
        }
        for(int j = var-S-1; j >= 0; j--)
        {
            int temp = a[j][var];
            for(int l = j+1; l < var; l++)
                if(a[j][l])
                    temp ^= x[l];
            x[j] = temp;
            cnt += x[j] ? 1 : 0;
        }
        ans = min(ans, cnt);
    }
    printf("%d\n", ans);
}
int main()
{
    READ("inD.txt");
    WRITE("outD.txt");
    while(scanf("%d", &a[0][20]) != EOF)
    {
        a[0][0] = 1, a[0][1] = 1, a[0][20] ^= 0;
        init_a();
        solve(Gauss());
    }
    return 0;
}


