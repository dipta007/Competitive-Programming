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
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< ll, ll >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef dipta00
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

#define pdi pair <double,int>


int t,n,m;
#define mx 205
pii posi[mx];
int strt[mx],fin[mx];
int linenum[mx];
pdi dp[205];
int vis[205];
double needtime(pii a,pii b,double speed)
{
    ll sqDist = (a.ff-b.ff)*(a.ff-b.ff) + (a.ss-b.ss)*(a.ss-b.ss);
    double dist =  sqrt((double) sqDist);
    //debug(b.ff,b.ss,sqDist,dist)
    double res = (dist)/(speed);
    return res;

}

pdi addDem(pdi a, double x)
{
    pdi d = a;
    d.ff += x;
    return d;
}

pdi minDem(pdi a, pdi b)
{
    if(b.ss==0)
    {
        return a;
    }
    pdi d;
    d.ff = min(a.ff, b.ff);
    d.ss = 1;
    return d;
}


int cur,line;
pdi call(int pos)
{
    if(pos==2)return MP(0.0, 1);

    pdi &ret=dp[pos];
    int &mark=vis[pos];
    if(mark==1)return ret;
    mark=1;
    ret.ff=INF;
    ret.ss=0;
    /// sb gulai paye hete jabo

    rep(i,cur)
    {
        //debug(i,posi[i].ff, posi[i].ss)
        debug(posi[pos].ff, posi[pos].ss, needtime(posi[pos],posi[i],166.666))
        ret=minDem(ret, addDem(call(i), needtime(posi[pos],posi[i],166.666)));
    }
    /// same line er gulai sub die jabo
    //if(pos<=2)return ret;
    int num=linenum[pos];
    for(int i=strt[num];i<=fin[num];i++)
    {
        ret=minDem(ret,addDem(call(i),needtime(posi[pos],posi[i],166.666*4)));
    }
    return ret;
}

int main() {
    ///check for 0 or -1 if input not specified
    #ifdef dipta007
        READ("in.txt");
//        WRITE("out.txt");
    #endif // mamun
//    ios_base::sync_with_stdio(0);cin.tie(0);
    cur=1;
    rep(i,2){
        getLL(posi[i].ff,posi[i].ss);
        //debug(i,posi[i].ff, posi[i].ss)
    }
    cur=3;
    linenum[1] =1;
    linenum[2]=2;
    strt[1]=strt[2]=0;
    fin[1]=fin[2]=-1;

    line=3;
    strt[line]=cur;
    while(~getLL(posi[cur].ff,posi[cur].ss))
    {
        linenum[cur]=line;
        if(posi[cur].ss==-1)
        {
            fin[line]=cur-1;
            strt[++line]=cur;
//            debug(cur)
        }
        else cur++;
    }
    line--;
    cur--;
//    rep(i,line)debug(strt[i],fin[i])
//    debug(line,cur)
//    rep(i,cur)debug(linenum[i])
//    SET(dp);
//    ll ans=call(1);
//    printf("%lld\n",ans);
    CLR(vis);
    pdi res = call(1);
//    debug(res.ss)
    printf("%lld\n",(ll)round(res.ff));
    //debug(call(1));
    return 0;
}


