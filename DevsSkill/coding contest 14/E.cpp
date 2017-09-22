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
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< ll, ll >
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

const long long mod[2] = {1000000007LL, 2117566807LL};
const long long base[2] = {1572872831LL, 1971536491LL};

#define mx 100004
int arr[mx];


void calcPower()
{
    power[0][0]=1;
    power[1][0]=1;
    for(int i=0;i<1;i++)
    {
        for(int j=1;j<mx;j++)
        {
            power[i][j] = (power[i][j-1] * base[i]) % mod[i];
        }
    }
}

ll bigmod ( ll b, ll p, ll m ) {
    ll res = 1 % m, x = b % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}

pii extendedEuclid(int a, int b)   // returns x, y jekhane, ax + by = gcd(a,b)
{
    if(b == 0)
		return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.ss, d.ff - d.ss * (a / b));
    }
}


ll modularInverse(int a, int n) { 	// returns a er modular Inverse ; n dara mod kore
  pii ret = extendedEuclid(a, n);
  return ((ret.ff % n) + n) % n;
}


struct info
{
	ll prop,sum;
	int ones;
}tree[mx*4]; 			// size = mx*3 o hobe
						//sum ছাড়াও নিচে অতিরিক্ত কত যোগ হচ্ছে সেটা রাখবো prop এ

void init(int node,int b,int e)
{
	if(b==e)
	{
		tree[node].sum=arr[b];
		tree[node].ones = (int)(arr[b]>0);
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node].ones = tree[Left].ones + tree[Right].ones;
	tree[node].sum=tree[Left].sum+tree[Right].sum;
}

ll query(int node,int b,int e,int i,int j,ll carry=0)
{
	if (i > e || j < b)		return 0;

	if(b>=i && e<=j)
    {
        return tree[node].sum+carry*(e-b+1);	//সাম এর সাথে যোগ হবে সেই রেঞ্জের সাথে অতিরিক্ত যত যোগ করতে বলেছে সেটা
    }

	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;

    ll p1 = query(Left, b,mid,  i, j,   carry+tree[node].prop); //প্রপাগেট ভ্যালু বয়ে নিয়ে যাচ্ছে carry ভ্যারিয়েবল
    ll p2 = query(Right, mid+1, e, i, j,carry+tree[node].prop);

    return  p1+p2;

}

void update(int node,int b,int e,int i,int j,ll x)
{
	if (i > e || j < b)	return;
	if (b >= i && e <= j) //নোডের রেঞ্জ আপডেটের রেঞ্জের ভিতরে
	{
	    if(x==0)
        {
            tree[node].sum = 0;
            tree[node].ones = 0;
            tree[node].prop = 0;
        }
        else
        {
            int len = e-b+1;

            tree[node].sum = 0;
            tree[node].ones = len;
            tree[node].prop=1;
        }
		tree[node].sum+=((e-b+1)*x); //নিচে নোড আছে e-b+1 টি, তাই e-b+1 বার x যোগ হবে এই রেঞ্জে
		tree[node].prop+=x;          //নিচের নোডগুলোর সাথে x যোগ হবে
		return;
	}
	int Left=node*2;
	int Right=(node*2)+1;
	int mid=(b+e)/2;
	update(Left,b,mid,i,j,x);
	update(Right,mid+1,e,i,j,x);
	tree[node].sum=tree[Left].sum+tree[Right].sum+(e-b+1)*tree[node].prop;			//উপরে উঠার সময় পথের নোডগুলো আপডেট হবে
																					//বাম আর ডান পাশের সাম ছাড়াও যোগ হবে নিচে অতিরিক্ত যোগ হওয়া মান

}


int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    calcPower();
    FOR(ci,1,t)
    {
        getchar();
        string st;
        getline(cin,st);
        ll c = 1;
        FOR(i,0,len-1)
        {
            int kk = st[i];
            if(k) arr[i] = c;
            else arr[i] = 0;
            c = (c * base[0])%mod[0];
        }

    }

    return 0;
}



