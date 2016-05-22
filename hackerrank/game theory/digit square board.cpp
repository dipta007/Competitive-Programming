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

int a[34][34];
int prime[10];
int dp[34][34][34][34];
int vis[34][34][34][34];
int cs;

int call(int lr, int lc, int rr, int rc)
{
    //if((rr-lr)*(rc-lc)<=1) return 0;

    int &ret = dp[lr][lc][rr][rc];
    if(vis[lr][lc][rr][rc]==cs) return ret;
    vis[lr][lc][rr][rc]=cs;

    int flg=0;
    FOR(i,lr,rr)
    {
        FOR(j,lc,rc)
        {
            if(prime[a[i][j]]==0)
            {
                flg=1;
                break;
            }
        }
        if(flg) break;
    }
    if(flg==0) return ret=0;

    set <int> gr;
    FOR(i,lr,rr)
    {
        FOR(j,lc,rc)
        {
            //if(flg)
            {
                ///niche horizontally
                if(i!=rr)
                {
                    gr.insert( call(lr,lc,i,rc) );
                    gr.insert( call(i+1,lc,rr,rc) );
                }
                ///upore horizontally
                if(i!=lr)
                {
                    gr.insert( call(lr,lc,i-1,rc) );
                    gr.insert( call(i,lc,rr,rc) );
                }
                ///bame vertically
                if(j!=lc)
                {
                    gr.insert( call(lr,lc,rr,j-1) );
                    gr.insert( call(lr,j,rr,rc) );
                }
                ///dane vertically
                if(j!=rc)
                {
                    gr.insert( call(lr,lc,rr,j) );
                    gr.insert( call(lr,j+1,rr,rc) );
                }
            }
        }
    }

    int cnt = 0;
    while(gr.count(cnt)) cnt++;
    return ret = cnt;
}


int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    CLR(prime);
    prime[2]=1;
    prime[3]=1;
    prime[5]=1;
    prime[7]=1;
    CLR(vis);
    FOR(ci,1,t)
    {
        cs=ci;
        int n;
        getI(n);
        FOR(i,0,n-1)
        {
            FOR(j,0,n-1)
            {
                getI(a[i][j]);
            }
        }
        if(call(0,0,n-1,n-1)) printf("First\n");
        else printf("Second\n");
    }

    return 0;
}



