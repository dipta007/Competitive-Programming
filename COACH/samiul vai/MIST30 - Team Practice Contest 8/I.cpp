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
const int INF = 90000;
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

map <string,int> vis;
vii adj;

bool check(string st)
{
    FOR(i,0,6)
    {
        if(st[i]=='A')
        {
            for(int j=i,k=0;k<6;k++,j++)
            {
                j%=6;
                if(st[j]!='A'+k)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int call(int in, string st, int par)
{
    if(check(st)) return 0;
    //if(mp.find(st)!=mp.end()) return mp[st];
    vis[st]=1;
    //debug(in)
    int res = INF;
    string tmp = st;
    FOR(i,0,(int)adj[in].size()-1)
    {
        int v = adj[in][i];
        if(v==par) continue;
//        debug(in,i);
        swap(st[in],st[v]);
        if(vis.find(st)==vis.end())
        {
            res = min(res, 1+call(v, st, in));
            debug(i,in,v,st,res);
        }
        swap(st[in],st[v]);
    }
    debug(st)
    return res;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);

    adj.assign(10,vi());
    adj[0].PB(1);
    adj[0].PB(5);
    adj[1].PB(0);
    adj[1].PB(2);
    adj[1].PB(6);
    adj[2].PB(1);
    adj[2].PB(3);
    adj[3].PB(2);
    adj[3].PB(4);
    adj[4].PB(3);
    adj[4].PB(5);
    adj[4].PB(6);
    adj[5].PB(4);
    adj[5].PB(0);
    adj[6].PB(1);
    adj[6].PB(4);

    FOR(ci,1,t)
    {
        int n;
        string st;
        cin >> n >> st;
        st += "*";
        vis.clear();
        int kk = call(6, st, -1);
        printf("%d %d\n",n,kk);
    }

    return 0;
}



