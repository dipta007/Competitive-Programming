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
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d %d", &a, &b)
#define    getIII(a,b,c)     scanf("%d %d %d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld %lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long


template< class T > inline T _abs(T n) { return ( (n) < 0 ? -(n) : (n) ); }
template< class T > inline T _max(T a, T b) { return ( ! ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _min(T a, T b) { return ( ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _swap(T &a, T &b) { T temp=a;a=b;b=temp;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd( (b), ( (a) % (b) ) ) ; }
template< class T > inline T lcm(T a, T b) { return ( (a) / gcd( (a), (b) ) * (b) ); }



//******************DELETE****************
#define shubhashis
#ifdef shubhashis
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************

#define MAXN 100002
int dp[MAXN][5];
int par[MAXN];
vector<int>edges[MAXN];

int f(int u,int isGuard)
{
	if(edges[u].size()==0)return 0;
	if(dp[u][isGuard]!=-1) return dp[u][isGuard];
	int sum=0;
	for(int i=0;i<(int)edges[u].size();i++)	{
		int v=edges[u][i];
		if(v!=par[u]){
			par[v]=u;
			if(isGuard==0) sum+=f(v,1);
			else sum+=min(f(v,1),f(v,0));
		}
	}
	return dp[u][isGuard]=sum+isGuard;
}

int main()
{
        memset(dp,-1,sizeof(dp));
	int n;
	int chele,mey;
	getII(chele,mey);
	scanf("%d",&n);
	set<int> s;
	for(int i=1;i<=n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		edges[u].push_back(v);
		edges[v].push_back(u);
		s.insert(u);
		s.insert(v);
	}
	int ans=0;
	ans=min(f(0,1),f(0,0));
	debug(ans);
	printf("%d\n",chele+mey-ans);
	return 0;
}
