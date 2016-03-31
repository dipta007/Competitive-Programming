#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
#include <ctime>
using namespace std;

#define rep(i,n) for(int i = 1 ; i<=(n) ; i++)
#define repI(i,n) for(int i = 0 ; i<(n) ; i++)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define mem(p,v) memset(p, v, sizeof(p))
#define SET(p) 	  memset(p, -1, sizeof(p))
#define CLR(p)    memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(p)  p.begin(),p.end()
#define ALLR(p) p.rbegin(),p.rend()
#define pb(x) push_back(x)
#define chk(a,k) ((bool)(a&(1<<(k))))
#define off(a,k) (a&(~(1<<(k))))
#define on(a,k) (a|(1<<(k)))

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);
#define iseq(a,b) (fabs(a-b)<EPS)
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
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}

//******************DELETE****************
#define mamun
#ifdef mamun
#define debug(args...) {cerr<<"* ";dbg,args; cerr<<endl;}
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
//******************DELETE****************
int t,n,m;
ull dp[1005][1005];
bool vis[1005][1005];
//map<string,int> mp;
//map<string,pii> st;
string NumberToString ( ull Number )
{
    stringstream ss;
    ss << Number;
    return ss.str();
}
//vector<int>
vector<pii>res[11];
int cnt;
string in[10];
ull call(int posx,int posy)
{
    if(posx>1000||posy>1000)return 0;
    if(posx==1000&&posy==1000)return 1;
    ull &ret=dp[posx][posy];
    if(vis[posx][posy])return ret;
    vis[posx][posy]=1;
    ll ans=0;
    ans+=call(posx+1,posy);
    ans+=call(posx,posy+1);
    string s=NumberToString(ans);
    rep(i,t)
    {
        if(s==in[i])
        {
            res[i].push_back(make_pair(1000-posx+1,1000-posy+1));
        }
    }
//    if(!mp[s])mp[s]=cnt++;
//    mp[s]=make_pair(1000-posx,1000-posy);
    return ret=ans;
}

int main()
{
    ///check for 0 and negative if limit is not specified

    //READ("in.txt");
    //WRITE("out.txt");
    cnt=0;
    CLR(vis);
    CLR(dp);
    getI(t);
    rep(cs,t)
    {
//        res.clear();
        cin>>in[cs];
//        CLR(vis);


    }
    ull tmp=call(0,0);
    rep(i,t)
    {
        int sz=res[i].size();
        if(sz==0)puts("The Grid is Too Big!");
        else
        {
            printf("%d\n",sz);
//            debug(res[i])

            repI(j,sz)printf("%d %d\n",res[i][j].ff,res[i][j].ss);
//            repI(j,sz)debug(res[i].ff);
        }
    }


    return 0;
}





