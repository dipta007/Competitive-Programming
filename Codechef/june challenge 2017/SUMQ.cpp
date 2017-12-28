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

ll mod = 1e9+7;
ll aa[100004];
ll cc[100004];


int main() {
#ifdef dipta007
	//READ("in.txt");
//        WRITE("in.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);
	
	int t;
	getI(t);
	FOR(ci,1,t)
	{
		int p,q,r;
		getIII(p,q,r);
		vector < ll >  a, b, c;
		FOR(i,1,p)
		{
			ll x;
			getL(x);
			a.PB(x);
		}
		FOR(i,1,q)
		{
			ll x;
			getL(x);
			b.PB(x);
		}
		FOR(i,1,r)
		{
			ll x;
			getL(x);
			c.PB(x);
		}
		
		sort(ALL(a));
		sort(ALL(b));
		sort(ALL(c));
		
		aa[0] = a[0];
		aa[0] %= mod;
		FOR(i,1,p-1)
		{
			aa[i] = a[i];
			aa[i] += aa[i-1];
			aa[i] %= mod;
		}
		
		cc[0] = c[0];
		cc[0] %= mod;
		FOR(i,1,r-1)
		{
			cc[i] = c[i];
			cc[i] += cc[i-1];
			cc[i] %= mod;
		}
		
		ll res = 0;
		FOR(i,0,q-1)
		{
			ll kk = b[i];
			
			int pos = upper_bound(ALL(a), kk) - a.begin();
			pos--;
			
			int ase = pos + 1;
			debug(ase);
			ll now1 = 0;
			
			now1 += (ase * kk)%mod;
			now1 %= mod;
			
			now1 += aa[pos];
			now1 %= mod;
			
			pos = upper_bound(ALL(c), kk) - c.begin();
			pos--;
			debug(pos)
			
			ase = pos + 1;
			ll now2 = 0;
			
			now2 += (ase * kk)%mod;
			now2 %= mod;
			
			now2 += cc[pos];
			now2 %= mod;
			
			debug(now1, now2)
			res += (now1 * now2)%mod;
			res%=mod;
		}
		printf("%lld\n",res);
	}
	
	return 0;
}


