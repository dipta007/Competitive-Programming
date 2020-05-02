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

#define NODE 100

vector < vi > adj;

int vis[NODE], Left[NODE], Right[NODE];

bool tryK ( int s ) {
    if ( vis[s] == 1 ) return false;
    vis[s] = 1;

    for ( int i = 0; i < adj[s].size(); i++ ) {
        int t = adj[s][i];

        if ( Right[t] == -1 || tryK(Right[t]) ) {
            Left[s] = t;
            Right[t] = s;
            return true;
        }
    }

    return false;
}

int kuhn ( int n ) {
    int res = 0;
    memset(Left,-1,sizeof Left);
    memset(Right,-1,sizeof Right);
    for ( int i = 1; i <= n; i++ ) {
        memset(vis,0,sizeof vis);
        if ( tryK ( i ) ) {
            res++;
        }
    }

    return res;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
        //WRITE("in.txt");
    #endif // dipta007

    int t;
    map <string, int> mp;
    mp["XXL"]=0;
    mp["XL"]=1;
    mp["L"]=2;
    mp["M"]=3;
    mp["S"]=4;
    mp["XS"]=5;
    getI(t);
    FOR(ci,1,t)
    {
        vi v[6];
        int n,m;
        getII(n,m);
        int in=0;
        FOR(i,0,5)
        {
            FOR(j,0,n/6-1)
            {
                v[i].PB(in++);
            }
        }
        debug(in)
        adj.assign(m+4, vi());
        FOR(i,1,m)
        {
            string a,b;
            cin >> a >> b;
            //debug(a,b)
            debug(v[mp[a]].size(), v[mp[b]].size())
            FOR(j,0,(int)v[mp[a]].size()-1)
            {
                adj[i].PB(32+v[mp[a]][j]);
            }
            FOR(j,0,(int)v[mp[b]].size()-1)
            {
                adj[i].PB(32+v[mp[b]][j]);
            }
        }
        int res = kuhn(m);
        if(res==m) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}



