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

#define dipta007
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

ll cal[200][100004];
int arr[100004];

void preCalculate(int n)
{
	int a[n];
	FOR(i,0,n-1) a[i] = arr[i];
	CLR(cal);
	
	FOR(i,0,(int)primes.size()-1)
	{
		for(int j=0; j<n; j++)
		{
			ll cnt = 0;
			while(a[j]%primes[i] == 0)
			{
				a[j] /= primes[i];
				cnt++;
			}
			cal[i][j] += cnt;
		}
	}
	
	FOR(i,1,n-1)
	{
		cal[0][i] += cal[0][i-1];
	}
	FOR(i,1,(int)primes.size()-1)
	{
		cal[i][0] += cal[i-1][0];
	}
	FOR(i,1,(int)primes.size()-1)
	{
		FOR(j,1,n-1)
		{
			cal[i][j] += cal[i][j-1] + cal[i-1][j] - cal[i-1][j-1];
		}
	}
}

#define SQRSIZE  400

//int block[SQRSIZE][1000004];          // decomposed array
vi block[SQRSIZE];
int blk_sz;                      // block size

int bin_srcR(int val,int in)
{
	int low = 0, high = block[in].size()-1;
	int res = -1;
	while(low <= high)
	{
		int mid = (low + high)/2;
		if(block[in][mid]<=val)
		{
			low = mid + 1;
			res = mid;
		}
		else high = mid - 1;
	}
	return res;
}
int bin_srcL(int val, int in)
{
	int low = 0, high = block[in].size()-1;
	int res = 0;
	while(low <= high)
	{
		int mid = (low + high)/2;
		if(block[in][mid]<val)
		{
			low = mid + 1;
		}
		else
		{
			res = mid;
			high = mid - 1;
		}
	}
	return res;
}

int bin_srcR(int val)
{
	int low = 0, high = primes.size()-1;
	int res = -1;
	while(low <= high)
	{
		int mid = (low + high)/2;
		if(primes[mid]<=val)
		{
			low = mid + 1;
			res = mid;
		}
		else high = mid - 1;
	}
	return res;
}
int bin_srcL(int val)
{
	int low = 0, high = primes.size()-1;
	int res = -1;
	while(low <= high)
	{
		int mid = (low + high)/2;
		if(primes[mid]<val)
		{
			low = mid + 1;
		}
		else
		{
			res = mid;
			high = mid - 1;
		}
	}
	return res;
}

// Time Complexity : O(sqrt(n))
ll query(int l, int r, int x, int y)
{
	ll sum = 0;
	while (l<r and l%blk_sz!=0 and l!=0)
	{
		// traversing first block in range
		if(arr[l]>=x && arr[r]<=y && marked[arr[l]]==0)
		{
			sum ++;
		}
		l++;
	}
	while (l+blk_sz <= r)
	{
		// traversing completely overlapped blocks in range
		int pos1 = bin_srcL(x,l/blk_sz);
		int pos2 = bin_srcR(y,l/blk_sz);
		sum += (pos2- pos1 + 1);
		
		debug("bs", pos1,pos2,sum)
		
//		sum += (block[l/blk_sz][y] - block[l/blk_sz][x-1]);
		l += blk_sz;
	}
	while (l<=r)
	{
		// traversing last block in range
		if(arr[l]>=x && arr[r]<=y && marked[arr[l]]==0)
		{
			sum ++;
		}
		l++;
	}
	return sum;
}

// Fills values in input[]
void preprocess(int n)
{
	// initiating block pointer
	int blk_idx = -1;
	
	// calculating size of block
	blk_sz = sqrt(n);
	
	// building the decomposed array
	for (int i=0; i<n; i++)
	{
		if (i%blk_sz == 0)
		{
			// entering next block
			// incementing block pointer
			blk_idx++;
//			CLR(block[blk_idx]);
			block[blk_idx].clear();
		}
		if(arr[i]>primes.back() && marked[arr[i]]==0)
		{
//			block[blk_idx][arr[i]] += 1;
			block[blk_idx].PB(arr[i]);
		}
	}
//	FOR(i,0,blk_idx)
//	{
//		FOR(j,1,1000000)
//		{
//			block[i][j] += block[i][j-1];
//		}
//	}
	
	FOR(i,0,blk_idx)
	{
		sort(ALL(block[i]));
	}
}



ll queryFinal(int l, int r, int x, int y)
{
	if(x>primes.back())
	{
		return query(l,r,x,y);
	}
	else
	{
		int yy = min(primes.back(), y);
		debug(x,y)
		x = bin_srcL(x);
		yy = bin_srcR(yy);
		debug("now",x,yy)
		
		ll sum = 0;
		if(x<=yy && l==0 && x==0)
		{
			sum += cal[yy][r];
		}
		else if(x<=yy && l==0)
		{
			sum += cal[yy][r] - cal[x-1][r];
		}
		else if(x<=yy && x==0)
		{
			sum += cal[yy][r] - cal[yy][l-1];
		}
		else if(x<=yy)
		{
			sum += cal[yy][r] - cal[x][l - 1] - cal[x - 1][l] + cal[x - 1][l - 1];
		}
		if(yy!=-1 && primes[yy]+1 <= y)
		{
			sum += query(l, r, primes[yy]+1, y);
		}
		debug(sum)
		return sum;
	}
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
		preCalculate(n);
		
		preprocess(n);
		int q;
		getI(q);
		FOR(i,1,q)
		{
			int l,r, x,y;
			getII(l,r);
			getII(x,y);
			l--,r--;
			printf("%lld\n", queryFinal(l,r,x,y));
		}
	}
	
	return 0;
}
