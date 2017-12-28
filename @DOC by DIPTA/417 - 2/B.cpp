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
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
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

#define dipta00
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

int lgt[18];
int a[18][116];
int dp[16][2][1640];
int n,m;

int call(int in, int strt, int tot)
{
	if(in<0) return 0;
	
	int &ret = dp[in][strt][tot];
	if(ret!=-1) return ret;
	
	if(strt==0)
	{
		debug(in, lgt[in])
		int cnt = 0;
		int cntLgt = lgt[in];
		for(;cntLgt>0 && strt<m+2; strt++, cnt++ )
		{
			if(a[in][strt]==1)
			{
				cntLgt--;
			}
			if(cntLgt==0) break;
		}
		if(tot - lgt[in]==0) return cnt;
		int res = cnt + strt + 1 +call(in-1, 0, tot-lgt[in]);
		res = min(res , cnt + (m+2-strt-1) + 1 + call(in-1, 1, tot-lgt[in]));
		
		return ret = res;
	}
	else
	{
		strt = m+2-1;
		int cnt = 0;
		int cntLgt = lgt[in];
		for(;cntLgt>0 && strt>=0; strt--, cnt++ )
		{
			if(a[in][strt]==1)
			{
				cntLgt--;
			}
			if(cntLgt==0) break;
		}
		if(tot - lgt[in]==0) return cnt;
		int res = cnt + strt + 1 + call(in-1, 0, tot-lgt[in]);
		res = min(res , cnt + (m+2-strt-1) + 1 + call(in-1, 1, tot-lgt[in]));
		
		return ret = res;
	}
}

int main() {
#ifdef dipta007
	READ("in.txt");
//        WRITE("in.txt");
#endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);
	
	while(cin >> n >> m)
	{
		CLR(lgt);
		int tot = 0;
		FOR(i,0,n-1)
		{
			string st;
			cin >> st;
			FOR(j,0,m+2-1)
			{
				if(st[j]=='1')
				{
					lgt[i]++;
					a[i][j]=1;
					tot++;
				}
			}
		}
		
		SET(dp);
		printf("%d\n",call(n-1,0, tot));
		
		continue;
		int in = 0;
		int res = 0;
		ROF(i,n-1,0)
		{
			if(in==0)
			{
				for(;lgt[i]>0 && in<m; in++, res++ )
				{
					if(a[i][in]==1)
					{
						lgt[i]--;
					}
				}
				
				int kk = min(in, m-in-1);
			}
		}
	}
	
	
	return 0;
}


