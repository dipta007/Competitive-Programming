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
const int INF = 999999;
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
#define    bitFlip(N,in)       (N^(1<<(in)))
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
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

int dp[6][6][(1<<4)+4][(1<<4)+4][(1<<4)+4];
int arr[10];

int call(int r, int c, int m0, int m1, int m2)
{
    if(r>=4)
    {
        debug(m0,bitCount(m0))
        if(bitCount(m0)!=4) return INF;
        return 0;
    }
    if(c>=4)
    {
        /// porer row te jabo
        if(r!=0)
        {
//            debug(r,bitCount(m0))
            if(bitCount(m0)!=4) return INF;
        }
        return call(r+1, 0, m1, m2, arr[r+2]);
    }

    int &ret = dp[r][c][m0][m1][m2];
    if(ret!=-1) return ret;

    int tmp0 = m0;
    int tmp1 = m1;
    int tmp2 = m2;
    int res = INF;

    res = min(res, call(r,c+1, m0, m1, m2));
    if(c==0)
    {
        tmp0 = bitFlip(tmp0, 0);
        tmp1 = bitFlip(tmp1, 0);
        tmp1 = bitFlip(tmp1, 1);
        tmp2 = bitFlip(tmp2, 0);
        res = min(res, 1 + call(r, c+1, tmp0, tmp1, tmp2));
    }
    else if(c==3)
    {
        tmp0 = bitFlip(tmp0, 3);
        tmp1 = bitFlip(tmp1, 3);
        tmp1 = bitFlip(tmp1, 2);
        tmp2 = bitFlip(tmp2, 3);
        res = min(res, 1 + call(r, c+1, tmp0, tmp1, tmp2));
    }
    else
    {
        tmp0 = bitFlip(tmp0, c);
        tmp1 = bitFlip(tmp1, c);
        tmp1 = bitFlip(tmp1, c-1);
        tmp1 = bitFlip(tmp1, c+1);
        tmp2 = bitFlip(tmp2, c);
        res = min(res, 1 + call(r, c+1, tmp0, tmp1, tmp2));
    }
    //debug(r,c,res)

    return ret =res;
}
int call1(int r, int c, int m0, int m1, int m2)
{
    if(r>=4)
    {
        if(bitCount(m0)!=0) return INF;
        return 0;
    }
    if(c>=4)
    {
        /// porer row te jabo
        if(r!=0)
        {
            if(bitCount(m0)!=0) return INF;
        }
        return call1(r+1, 0, m1, m2, arr[r+2]);
    }

    int &ret = dp[r][c][m0][m1][m2];
    if(ret!=-1) return ret;

    int tmp0 = m0;
    int tmp1 = m1;
    int tmp2 = m2;
    int res = INF;

    res = min(res, call1(r,c+1, m0, m1, m2));
    if(c==0)
    {
        tmp0 = bitFlip(tmp0, 0);
        tmp1 = bitFlip(tmp1, 0);
        tmp1 = bitFlip(tmp1, 1);
        tmp2 = bitFlip(tmp2, 0);
        res = min(res, 1 + call1(r, c+1, tmp0, tmp1, tmp2));
    }
    else if(c==3)
    {
        tmp0 = bitFlip(tmp0, 3);
        tmp1 = bitFlip(tmp1, 3);
        tmp1 = bitFlip(tmp1, 2);
        tmp2 = bitFlip(tmp2, 3);
        res = min(res, 1 + call1(r, c+1, tmp0, tmp1, tmp2));
    }
    else
    {
        tmp0 = bitFlip(tmp0, c);
        tmp1 = bitFlip(tmp1, c);
        tmp1 = bitFlip(tmp1, c-1);
        tmp1 = bitFlip(tmp1, c+1);
        tmp2 = bitFlip(tmp2, c);
        res = min(res, 1 + call1(r, c+1, tmp0, tmp1, tmp2));
    }

    return ret =res;
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    string st;
    while(cin >> st)
    {
        CLR(arr);
        int tmp = 0;
        FOR(i,0,3)
        {
            if(st[i]=='b') tmp = bitOn(tmp, i);
        }
        arr[0] = tmp;
        FOR(i,1,3)
        {
            cin >> st;
            tmp = 0;
            FOR(j,0,3)
            {
                if(st[j]=='b') tmp = bitOn(tmp, j);
            }
            arr[i]=tmp;
            debug(arr[i])
        }
        SET(dp);
        int ans = call(0,0, 0, arr[0], arr[1]);
        debug(ans)
        SET(dp);
        ans = min(ans, call1(0,0, 0, arr[0], arr[1]));
        if(ans>=INF) printf("Impossible\n");
        else printf("%d\n",ans);
    }

    return 0;
}

//wwww
//wwww
//wwbw
//wwww



