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

#define mx 100004
struct info
{
    int sum;
    int prop;
}tree[2][mx*4];
int mod = 1e9+7;

info call(info a,info b)
{
    info tmp;
    tmp.sum = a.sum + b.sum;
    tmp.sum %= mod;
    tmp.prop = 0;
    ///merge two info
    return tmp;
}

int in;

void init(int node,int b,int e)
{
	if(b==e)
	{
//	    debug(in,b)
	    tree[1][node].sum = 1;
	    tree[0][node].sum = 0;
	    tree[1][node].prop = 0;
	    tree[0][node].prop = 0;
	    ///do something
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[0][node]=call(tree[0][Left],tree[0][Right]);
	tree[1][node]=call(tree[1][Left],tree[1][Right]);
}

void propagate(int node,int b,int e)
{
    if(b==e)
    {
        tree[in][node].prop=0;
        return;
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	///update propagation
	int prop = tree[in][node].prop;
	tree[in][Left].prop += tree[in][node].prop;
	tree[in][Left].prop %= mod;
	tree[in][Right].prop += tree[in][node].prop;
	tree[in][Right].prop %= mod;
    tree[in][node].prop=0;
    ///update tree[in][left].sum
    tree[in][Left].sum += (prop * (mid-b+1));
    tree[in][Left].sum %= mod;
    ///update tree[in][right].sum
    tree[in][Right].sum += (prop * (e-mid));
    tree[in][Right].sum %= mod;
}

int query(int node,int b,int e,int i,int j) ///range i theke j
{
	if (i > e || j < b)return 0;
	if(tree[in][node].prop)propagate(node,b,e);
	if(b>=i && e<=j)
    {
        ///do something
//        debug(node, in, tree[in][node].sum)
        return tree[in][node].sum%mod;
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
    int p1 = query(Left,b,mid,i,j);
    int p2 = query(Right,mid+1,e,i,j);
    return  (p1+p2)%mod;

}

void update(int node,int b,int e,int i,int j, int newVal)
{
	if(tree[in][node].prop)propagate(node,b,e);
	if (i > e || j < b)	return;
	if (b >= i && e <= j)
    {
        tree[in][node].sum += (e-b+1)*newVal;
        tree[in][node].sum %= mod;
        tree[in][node].prop = newVal;
        ///do something
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	update(Left,b,mid,i,j,newVal);
	update(Right,mid+1,e,i,j,newVal);
	tree[in][node]=call(tree[in][Left],tree[in][Right]);
}



struct data
{
    int l,r,in;
    data(int a, int b, int c)
    {
        l=a, r=b, in=c;
    }
};

bool cmp(const data &a, const data &b)
{
    if(a.r > b.r) return true;
    if(a.r == b.r) return a.l < b.l;
    return false;
}

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
        int n,m;
        getII(n,m);

        vector < data > a,b;
        FOR(i,1,m)
        {
            int x,y,z;
            getIII(x,y,z);
            if(x==1) a.PB(data(y,z,i));
            else b.PB(data(y,z,i));
        }

        sort(ALL(b), cmp);

        /// 0 - > orginal array
        /// 1 - > query array

        int MX = 1e5+1;
        in = 1;
        init(1,1,MX);
//        debug(tree[1][7].sum)
        FOR(i, 0, b.size()-1)
        {
            int kk = query(1,1,MX,b[i].in, b[i].in);
            debug(kk, b[i].l, b[i].r)
//            debug(query(1, 1, MX, 1, 1))
//            debug(query(1, 1, MX, 2, 2))
            update(1, 1, MX, b[i].l, b[i].r, kk);
//            updateRange(1, b[i].l, b[i].r, kk);
        }

        FOR(i,0,(int)a.size()-1)
        {
            in = 1;
            int kk = query(1, 1, MX, a[i].in, a[i].in);
//            int kk = query(1, a[i].in);
            debug(kk, a[i].l, a[i].r)
            in = 0;
            update(1, 1, MX, a[i].l, a[i].r, kk);
//            updateRange(0, a[i].l, a[i].r, kk);
        }

        in = 0;
        FOR(i,1,n)
        {
            if(i!=1) printf(" ");
            printf("%d",query(1,1,MX,i,i));
        }
        printf("\n");
    }

    return 0;
}


