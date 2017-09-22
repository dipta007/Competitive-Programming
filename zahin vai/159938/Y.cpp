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

#define mx 500004
int arr[mx];
struct info
{
    int maxy,lft,rgt;
}tree[mx*4];

info call(info a,info b)
{
    info tmp;
    if(a.maxy > b.maxy) return a;
    else if(b.maxy > a.maxy)return b;
    else
    {
        tmp.maxy = a.maxy;
        tmp.lft = a.lft;
        tmp.rgt = b.rgt;
        return tmp;
    }
}

void init(int node,int b,int e)
{
	if(b==e)
	{
	    tree[node].maxy = arr[b];
	    tree[node].lft = b;
	    tree[node].rgt = b;
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
        tmp.maxy = -1e9-2;
        tmp.lft = 0;
        tmp.rgt = -1;
        return tmp;
    }
	if(b>=i && e<=j)
    {
        return tree[node];
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
    info p1 = query(Left,b,mid,i,j);
    info p2 = query(Right,mid+1,e,i,j);
    return call(p1,p2);
}
//info queryLeft(int node,int b,int e,int i,int j) ///range i theke j
//{
//	if (i > e || j < b)
//    {
//        info tmp;
//        tmp.maxy = 0;
//        tmp.in = -1;
//        return tmp;
//    }
//	if(b>=i && e<=j)
//    {
//        return tree[node];
//    }
//	int Left=node<<1;
//	int Right=(node<<1)+1;
//	int mid=(b+e)>>1;
//    info p1 = queryLeft(Left,b,mid,i,j);
//    info p2 = queryLeft(Right,mid+1,e,i,j);
//    if(p1.maxy >= p2.maxy ) return p1;
//    else return p2;
//}
//info queryRight(int node,int b,int e,int i,int j) ///range i theke j
//{
//	if (i > e || j < b)
//    {
//        info tmp;
//        tmp.maxy = 0;
//        tmp.in = -1;
//        return tmp;
//    }
//	if(b>=i && e<=j)
//    {
//        return tree[node];
//    }
//	int Left=node<<1;
//	int Right=(node<<1)+1;
//	int mid=(b+e)>>1;
//    info p1 = queryRight(Left,b,mid,i,j);
//    info p2 = queryRight(Right,mid+1,e,i,j);
//    if(p1.maxy > p2.maxy ) return p1;
//    else return p2;
//}


int len = 0;
int call(int l, int r,int n)
{
    if(l>=r) return 0;
    if(r-l+1<=len) return 0;
    info tmp = query(1,1,n,l,r);
    debug(l,r,tmp.maxy, tmp.lft, tmp.rgt)

    {
        len = max(len, tmp.rgt - tmp.lft);
        len = max(len, call(l,tmp.lft-1,n));
        len = max(len, call(tmp.rgt+1, r,n));
    }
    return len;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,q;
    while(~getII(n,q))
    {
        FOR(i,1,n)
        {
            getI(arr[i]);
        }
        init(1,1,n);
        debug("*")
        FOR(i,1,q)
        {
            int l,r;
            getII(l,r);
            len = 0;
            printf("%d\n",call(l,r,n));
        }
    }

    return 0;
}



