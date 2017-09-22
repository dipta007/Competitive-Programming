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

#ifdef mamun
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
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
///****************** template ends here ****************
int t,n,m;
#define mod 1000000007
vector<int>pls,mns,zero;
ll modulusu(ll num)
{
    if(num<0)num+=mod;
    return num%mod;
}

vector < pair<ll,int> > vp;

ll findminimum()
{
    sort(ALL(vp));
    FOR(i,0,m-1)
    {
        res =
    }
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
//        READ("in.txt");
//        WRITE("out.txt");
#endif // mamun
    getI(t);
    rep(cs,t)
    {
        getII(n,m);
        int x;
        pls.clear();
        mns.clear();
        zero.clear();
        vp.clear();
        rep(i,n)
        {
            getI(x);
            if(x<=0) vp.PB( MP(labs(x), minuss));
            else vp.PB( MP(x, pluss));
            if(x>0)pls.push_back(x);
            else if(x<0)mns.push_back(x);
            else zero.push_back(x);
        }
        sort(ALL(pls));
        reverse(ALL(pls));
        sort(ALL(mns));
//        reverse(ALL(mns));
        if(pls.size()==0 && zero.size()>0 && m%2==1)puts("0");
        else if( pls.size()+mns.size()<m && zero.size())puts("0");
        else
        {
            ll ans=1;
            int lft=m;
            int frst=0,scnd=0;
            if(frst<pls.size() && m%2==1)
            {
                ans=modulusu(ans*pls[frst++]);
                lft--;
            }
            while(lft)
            {
                if(frst>=pls.size())
                {
                    while(lft>1)
                    {
                        ans=modulusu(ans*mns[scnd++]);
                        ans=modulusu(ans*mns[scnd++]);
                        lft-=2;
                    }
                    if(lft&&zero.size())ans=0;
                    else if(lft)
                    {
                        ans = findminimum();

                    }
                }
                else if(scnd>=mns.size())
                {
                    lft--;
                    ans=modulusu(ans*pls[frst++]);
                }
                else
                {
                    if(lft>=2&&frst<=pls.size()-2&&scnd<=mns.size()-2)
                    {
                        if(modulusu(ans*pls[frst]*pls[frst+1])>modulusu(ans*mns[scnd]*mns[scnd+1]))
                        {
                            lft-=2;
//                            frst++;
                            ans=(ans*pls[frst]*pls[frst+1]);
                            frst+=2;
                        }
                        else
                        {
                            lft-=2;
                            ans=modulusu(ans*mns[scnd]*mns[scnd+1]);
                            scnd+=2;
                        }

                    }
                    else if(lft>=2&&scnd<=mns.size()-2)
                    {
                        if(modulusu(ans*pls[frst])>modulusu(ans*mns[scnd]*mns[scnd+1]))
                        {
                            lft--;
//                            frst++;
                            ans=(ans*pls[frst++]);
                        }
                        else
                        {
                            lft-=2;
                            ans=modulusu(ans*mns[scnd]*mns[scnd+1]);
                            scnd+=2;
                        }
                    }
                    else
                    {
                        ans=modulusu(ans*pls[frst++]);
                        lft--;
                    }
                }
//                debug(ans,lft)
            }
            printf("%lld\n",ans);
        }
    }


    return 0;
}
