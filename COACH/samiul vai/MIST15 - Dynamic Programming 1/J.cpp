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
#define    bitCheck(N,in)    ((bool)(a&(1<<(k))))
#define    bitOff(N,in)      (a&(~(1<<(k))))
#define    bitOn(N,in)       (a|(1<<(k)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
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
#endif ///dipta007

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

int r,c,k;

vector <pii> vp;
int mark[54][54];
int dp[54][54][54][204];

int call(int in,int rr,int cc, int cnt)
{
//    cout << in <<endl;
//    debug(rr,cc,r,c)
    if(in>=k) return 1;
    if(cnt>200) return 0;

    if(rr<0 || rr>=r || cc<0 || cc>=c)
    {
//        debug(in)
        int res = call(in+1,vp[in+1].ff+1,vp[in+1].ss,1);
        if(res) return 1;
        res = call(in+1,vp[in+1].ff-1,vp[in+1].ss,1);
        if(res) return 1;
        res = call(in+1,vp[in+1].ff,vp[in+1].ss+1,1);
        if(res) return 1;
        res = call(in+1,vp[in+1].ff,vp[in+1].ss-1,1);
        if(res) return 1;
//        debug(in,res);
        return res;
    }

    int &ret = dp[in][rr][cc][cnt];
    if(ret!=-1) return ret;

    if(mark[rr][cc]==2) return 0;
    if(mark[rr][cc]==1) return 0;
//    if(mark[rr][cc] && !(rr==vp[in].ff && cc==vp[in].ss)) return ret=0;

    if(mark[rr][cc]!=2) mark[rr][cc]=1;

    ret=0;
    int o1 = call(in,rr+1,cc,cnt+1);
    if(o1) return ret=1;
    int o2 = call(in,rr-1,cc,cnt+1);
    if(o2) return ret=1;
    int o3 = call(in,rr,cc+1,cnt+1);
    if(o3) return ret=1;
    int o4 = call(in,rr,cc-1,cnt+1);
    if(o4) return ret=1;

    if(mark[rr][cc]!=2) mark[rr][cc]=0;

    return ret=0;
}



int main() {
    #ifdef dipta007
        READ("in.txt");
        WRITE("out.txt");
    #endif /// dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        CLR(mark);
        SET(dp);
        vp.clear();
        getIII(r,c,k);
//        if(ci==31) debug(r,c,k);
        int f=1;
        FOR(i,1,k)
        {
            pii p;
            getII(p.ff,p.ss);
            p.ff--;
            p.ss--;
//            if(ci==31) debug(p.ff,p.ss);
            vp.PB(p);
            if(mark[p.ff][p.ss]) f=0;
            mark[p.ff][p.ss]=2;
        }
//        debug("*")
//        if(ci!=31) continue;
        if(!f)
        {
            printf("not possible\n");
            continue;
        }
        vp.PB(pii(r+1,c+1));
        f=0;
        int res = call(0,vp[0].ff+1,vp[0].ss,1);
        if(res) f=1;
        if(!f) res = call(0,vp[0].ff-1,vp[0].ss,1);
        if(res) f=1;
        if(!f) res = call(0,vp[0].ff,vp[0].ss+1,1);
        if(res) f=1;
        if(!f) res = call(0,vp[0].ff,vp[0].ss-1,1);
        if(res) f=1;

        if(f) printf("possible\n");
        else printf("not possible\n");
    }

    return 0;
}
