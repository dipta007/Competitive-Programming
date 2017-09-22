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

const int MAXN = (int)3e5 + 1;
const int MAXV = (int)1e9;

struct wavelet_tree
{
	int lo, hi;
	wavelet_tree *l, *r;
	int *b, psz;

	wavelet_tree() { lo = 1; hi = 0; psz = 0; l = NULL; r = NULL; }

	void init(int *from, int *to, int x, int y)
	{
		lo = x, hi = y;
		if(lo == hi || from >= to) return;
		int mid = (lo + hi) >> 1; auto f = [mid](int x) { return x <= mid; };
		b = (int*)malloc((to - from + 2) * sizeof(int)); psz = 0; b[psz++] = 0;
		for(auto it = from; it != to; it++)	b[psz] = (b[psz - 1] + f(*it)), psz++;
		auto pivot = stable_partition(from, to, f);
		l = new wavelet_tree();
		l->init(from, pivot, lo, mid);
		r = new wavelet_tree();
		r->init(pivot, to, mid+1, hi);
	}

	int kth(int l, int r, int k)
	{
		if(l > r) return 0;
		if(lo == hi) return lo;
		int inLeft = b[r] - b[l - 1], lb = b[l - 1], rb = b[r];
		if(k <= inLeft) return this->l->kth(lb + 1, rb, k);
		return this->r->kth(l - lb, r - rb, k - inLeft);
	}

	int LTE(int l, int r, int k)
	{
		if(l > r || k < lo) return 0;
		if(hi <= k) return r - l + 1;
		int lb = b[l - 1], rb = b[r];
		return this->l->LTE(lb + 1, rb, k) + this->r->LTE(l - lb, r - rb, k);
	}

	int count(int l, int r, int k)
	{
		if(l > r || k < lo || k > hi) return 0;
		if(lo == hi) return r - l + 1;
		int lb = b[l - 1], rb = b[r];
		int mid = (lo + hi) >> 1;
		if(k <= mid) return this->l->count(lb + 1, rb, k);
		return this->r->count(l - lb, r - rb, k);
	}

	~wavelet_tree()
	{
		delete l;
		delete r;
	}
};

int n;
int a[MAXN];

wavelet_tree wt;


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        getI(n);
        FOR(i,1,n)
        {
            getI(a[i]);
        }
        wt.init(a,a+n, 1, MAXV);
        int m;
        getI(m);
        FOR(i,1,m)
        {
            int l,r,k;
            getIII(l,r,k);
            int xx = wt.LTE(l,r,k);
            debug(xx);
        }
    }

    return 0;
}



