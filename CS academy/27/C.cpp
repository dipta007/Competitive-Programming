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
struct info
{
    int mark[11];
    int tot;
    int prop;
}tree[mx*4];

info call(info a,info b)
{
    info tmp;
    CLR(tmp.mark);
//    FOR(i,1,10)
//    {
//        tmp.mark[i] += a.mark[i];
//    }
//    FOR(i,1,10)
//    {
//        tmp.mark[i] += b.mark[i];
//    }
    tmp.tot = a.tot + b.tot;
    tmp.prop=0;
    return tmp;
}

void init(int node,int b,int e)
{
	if(b==e)
	{
	    CLR(tree[node].mark);
	    tree[node].tot = 0;
	    tree[node].prop=0;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=call(tree[Left],tree[Right]);
}

void propagate(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].prop=0;
        return;
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	///update propagation
	int prop = tree[node].prop;
	tree[Left].prop += tree[node].prop;
	tree[Right].prop += tree[node].prop;
    tree[node].prop=0;
    ///update tree[left].sum
    FOR(i,1,10)
    {
        tree[Left].mark[i] = max(tree[Left].mark[i], tree[node].mark[i]);
    }
    tree[Left].tot+=prop;
    ///update tree[right].sum
    FOR(i,1,10)
    {
        tree[Right].mark[i] = max(tree[Right].mark[i], tree[node].mark[i]);
    }
    tree[Right].tot+=prop;
}

int query(int node,int b,int e,int i,int j, int row) ///range i theke j
{
	if (i > e || j < b)return 0;
	if(tree[node].prop)propagate(node,b,e);
	if(b>=i && e<=j)
    {
        ///do something
        int res = 0;
        FOR(ik,1,10)
        {
            debug(i,ik,tree[node].mark[ik],tree[node].tot)
            if(tree[node].mark[ik]>0)
            {
                res++;
            }
        }
        if(tree[node].tot<row) res++;
        return res;
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
    int p1 = query(Left,b,mid,i,j,row);
    int p2 = query(Right,mid+1,e,i,j,row);
    return  p1+p2;

}

void update(int node,int b,int e,int i,int j, int newVal)
{
	if(tree[node].prop)propagate(node,b,e);
	if (i > e || j < b)	return;
	if (b >= i && e <= j)
    {
        tree[node].mark[newVal]=1;
        tree[node].tot++;
        tree[node].prop++;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	update(Left,b,mid,i,j,newVal);
	update(Right,mid+1,e,i,j,newVal);
	tree[node]=call(tree[Left],tree[Right]);
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m;
    while(~getII(n,m))
    {
        init(1,1,m);
        FOR(i,1,n)
        {
            int l,r,k;
            getIII(l,r,k);
            update(1,1,m,l,r,k);
        }
        int maxy = 0;
        FOR(i,1,m)
        {
            int res = query(1,1,m,i,i,n);
            debug(res);
            maxy = max(maxy, res);
        }
        printf("%d\n",maxy);
    }

    return 0;
}


