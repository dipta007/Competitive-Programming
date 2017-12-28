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

#define M 1000002
bool marked[M];
vector <int> primes;

void sieve(int n) {
	primes.push_back(2);
	for (int i = 3; i * i <= n; i += 2) {
		if (marked[i] == 0) {
			primes.PB(i);
			for (int j = i * i; j <= n; j += i + i) {
				marked[j] = 1;
			}
		}
	}
}

#define MAX 100005
int arr[MAX];


vi tree[MAX*4];

void init(int node,int b,int e)
{
	tree[node].clear();
	debug(node, b, e)
	if(b==e)
	{
		int nn = arr[b];
		int sqn = sqrt(nn);
		for(int i=0 ; i < primes.size() && primes[i] <= sqn; i++)
		{
			if( nn % primes[i] == 0 )
			{
				while( nn % primes[i] == 0 )
				{
					tree[node].push_back(primes[i]);
					nn /= primes[i];
				}
				sqn = sqrt(nn);
			}
		}
		debug("nn", nn)
		if(nn!=1) tree[node].push_back(nn);
		return;
	}
	int Left= node << 1;
	int Right= (node << 1) +1;
	int mid=(b+e)>>1;
	init(Left,b,mid);
	init(Right,mid+1,e);
	debug(node,b,e)
	int sz = (int)tree[Left].size() + (int)tree[Right].size();
	tree[node].resize(sz);
	merge(ALL(tree[Left]), ALL(tree[Right]), tree[node].begin());
	return;
}
int query(int node,int b,int e,int i,int j, int x, int y)
{
	if (i > e || j < b)	return 0;
	if (b >= i && e <= j)
	{
		int lft = lower_bound(ALL(tree[node]), x) - tree[node].begin();
		int rgt = upper_bound(ALL(tree[node]), y) - tree[node].begin();
		rgt --;
		debug(tree[node].size());
		return rgt - lft + 1;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	int p1=query(Left,b,mid,i,j, x, y);
	int p2=query(Right,mid+1,e,i,j, x, y);
	return p1+p2;
}


int main() {
#ifdef dipta007
	//READ("in.txt");
//        WRITE("in.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);
	
	sieve(1000000);
//	debug(primes.back())
//	debug(primes.size())
	int n;
	while(~getI(n))
	{
		FOR(i,0,n-1)
		{
			getI(arr[i]);
		}
		init(1,0,n-1);
		debug("*")
		int q;
		getI(q);
		FOR(i,1,q)
		{
			int l,r, x,y;
			getII(l,r);
			getII(x,y);
			l--,r--;
			
			printf("%d\n",query(1,0,n-1, l, r, x, y));
		}
	}
	
	return 0;
}


