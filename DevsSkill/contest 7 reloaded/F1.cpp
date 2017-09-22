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
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)         (a|(1<<(k)))
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

#ifdef mamun
     #define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************
int t,n,m;
//ll dp[35][35][(1<<4)+2];
int arr[1005][5];
ll dp[1005][4][1005][(1<<4)+2];
bool mark[1005][4][1005][(1<<4)+2];
ll call(int row,int col,int mask,int lft)
{
    if(row==n)
    {
        if(lft!=0)return -INF;
        return 0;
    }
    ll &ret=dp[row][col][mask][lft];
    bool &vis=mark[row][col][mask][lft];
    if(vis)return ret;
    vis=true;
    if(lft==0)return ret=0;

    ll res=0;
    if(col>=3)
    {
        res=max(res,call(row+1,0,mask,lft));
    }
    else if(col==0||col==1)
    {
        if(bitCheck(mask,col)==0)
        {
            if(row<n-1)res=max(res,call(row,col+1,bitOn(mask,col),lft-1)+arr[row][col]+arr[row+1][col]);
            if(bitCheck(mask,col+1)==0)
            {
                int tmp=mask;
                tmp=bitOff(tmp,col);
                tmp=bitOff(tmp,col+1);
                res=max(res,call(row,col+2,tmp,lft-1)+arr[row][col]+arr[row][col+1]);
            }
        }
        res=max(res,call(row,col+1,bitOff(mask,col),lft));
    }
    else if(bitCheck(mask,col)==0)
    {
        res=max(res,call(row+1,0,bitOff(mask,col),lft));
        if(row<n-1)res=max(res,call(row+1,0,bitOn(mask,col),lft-1)+arr[row][col]+arr[row+1][col]);
    }
    else res=max(res,call(row+1,0,bitOff(mask,col),lft));
//    res=max(res,call(row+1,col+1,mask,lft));
    return ret=res;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    debug(INF)
    getI(t);
    rep(cs,t)
    {
        getII(n,m);
        CLR(arr);
        CLR(mark);

        repI(i,n)
        {
            repI(j,3)getI(arr[i][j]);
        }
        ll ans=call(0,0,0,m);
        printf("%lld\n",ans);
    }




    return 0;
}
