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


#define mx 100001
int arr[mx];
struct info
{
    ll prefix,prefixSz;
    ll suffix,suffixSz;
    ll total,totalSz;
    ll maxy,maxySz;
}tree[mx*4];

info call(info a,info b)
{
    info tmp;
    tmp.prefix = a.prefix;
    tmp.prefixSz = a.prefixSz;

    if((a.total+b.prefix > tmp.prefix) || (a.total+b.prefix==tmp.prefix && a.totalSz+b.prefixSz > tmp.prefixSz))
    {
        tmp.prefix = a.total + b.prefix;
        tmp.prefixSz = a.totalSz + b.prefixSz;
    }

    tmp.suffix = b.suffix;
    tmp.suffixSz = b.suffixSz;

    if((b.total+a.suffix > tmp.suffix) || (b.total+a.suffix==tmp.suffix && b.totalSz+a.suffixSz>tmp.suffixSz))
    {
        tmp.suffix = b.total + a.suffix;
        tmp.suffixSz = b.totalSz + a.suffixSz;
    }

    tmp.total = a.total + b.total;
    tmp.totalSz = a.totalSz + b.totalSz;

    tmp.maxy = a.maxy;
    tmp.maxySz = a.maxySz;
    if((b.maxy>tmp.maxy) || (b.maxy==tmp.maxy && b.maxySz > tmp.maxySz))
    {
        tmp.maxy = b.maxy;
        tmp.maxySz = b.maxySz;
    }
    if((a.suffix+b.prefix > tmp.maxy) || (a.suffix+b.prefix==tmp.maxy && a.suffixSz+b.prefixSz > tmp.maxySz))
    {
        tmp.maxy = a.suffix + b.prefix;
        tmp.maxySz = a.suffixSz + b.prefixSz;
    }
    if((a.total+b.prefix > tmp.maxy) || (a.total+b.prefix==tmp.maxy && a.totalSz+b.prefixSz>tmp.maxySz))
    {
        tmp.maxy = a.total + b.prefix;
        tmp.maxy = a.totalSz + b.prefixSz;
    }
    if((a.suffix+b.total>tmp.maxy) || (a.suffix+b.total==tmp.maxy && a.suffixSz+b.totalSz>tmp.maxySz))
    {
        tmp.maxy = a.suffix + b.total;
        tmp.maxySz = a.suffixSz + b.totalSz;
    }

    return tmp;
}

void init(int node,int b,int e)
{
	if(b==e)
	{
	    tree[node].prefix = arr[b];
	    tree[node].prefixSz = 1;
	    tree[node].suffix = arr[b];
	    tree[node].suffixSz = 1;
	    tree[node].total = arr[b];
	    tree[node].totalSz = 1;
	    tree[node].maxy = arr[b];
	    tree[node].maxySz = 1;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=call(tree[Left],tree[Right]);
}

info query(int node,int b,int e,int i,int j) ///range i theke j
{
	if (i > e || j < b)
    {
        info tmp;
        tmp.prefix = -1000000004;
        tmp.prefixSz = 0;
        tmp.suffix = -1000000004;
        tmp.suffixSz = 0;
        tmp.total = -1000000004;
        tmp.totalSz = 0;
        tmp.maxy = -1000000004;
        tmp.maxySz = 0;
        return tmp;
    }
	if(b>=i && e<=j)
    {
        ///do something
        return tree[node];
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
    info p1 = query(Left,b,mid,i,j);
    info p2 = query(Right,mid+1,e,i,j);
    return  call(p1,p2);
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,q;
    while(~getI(n))
    {
        FOR(i,1,n)
        {
            getI(arr[i]);
        }
        init(1,1,n);
        getI(q);
        FOR(i,1,q)
        {
            int l,r;
            getII(l,r);
            info res = query(1,1,n,l,r);
            printf("%lld %lld\n",res.maxy, res.maxySz);
        }
    }

    return 0;
}


