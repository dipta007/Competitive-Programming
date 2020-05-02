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
    ll sum;
    ll maxy;
    int in;
}tree[mx*4];

info call(info a,info b)
{
    info tmp;
    tmp.sum = a.sum + b.sum;
    if(a.maxy > b.maxy)
    {
        tmp.maxy = a.maxy;
        tmp.in = a.in;
    }
    else
    {
        tmp.maxy = b.maxy;
        tmp.in = b.in;
    }
    ///merge two info
    return tmp;
}

void init(int node,int b,int e)
{
	if(b==e)
	{
	    tree[node].sum = arr[b];
	    tree[node].maxy = arr[b];
	    tree[node].in = b;
	    ///do something
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=call(tree[Left],tree[Right]);
}

ll query(int node,int b,int e,int i,int j) ///range i theke j
{
	if (i > e || j < b)return 0;
	if(b>=i && e<=j)
    {
        ///do something
        return tree[node].sum;
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
    ll p1 = query(Left,b,mid,i,j);
    ll p2 = query(Right,mid+1,e,i,j);
    return  p1+p2;

}
info queryMax(int node,int b,int e,int i,int j) ///range i theke j
{
	if (i > e || j < b)
    {
        info tmp;
        tmp.maxy = -1;
        return tmp;
    }
	if(b>=i && e<=j)
    {
        ///do something
        return tree[node] ;
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
    info p1 = queryMax(Left,b,mid,i,j);
    info p2 = queryMax(Right,mid+1,e,i,j);
    return  (p1.maxy > p2.maxy ? p1 : p2);

}

void updateSet(int node,int b,int e,int i,int newVal)
{
	if (i > e || i < b)	return;
	if (b >= i && e <= i)
    {
        tree[node].sum = newVal;
        tree[node].maxy = newVal;
        tree[node].in = b;
        ///do something
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	updateSet(Left,b,mid,i,newVal);
	updateSet(Right,mid+1,e,i,newVal);
	tree[node]=call(tree[Left],tree[Right]);
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

        FOR(i,1,q)
        {
            int tt;
            getI(tt);
            if(tt==1)
            {
                int l,r;
                getII(l,r);
                printf("%lld\n",query(1,1,n,l,r));
            }
            else if(tt==2)
            {
                int l,r,x;
                getIII(l,r,x);
                info in = queryMax(1,1,n,l,r);
                while(in.maxy >= x)
                {
                    //debug(in.maxy)
                    updateSet(1,1,n,in.in,in.maxy%x);
                    in = queryMax(1,1,n,l,r);
                    //getchar();
                }
            }
            else
            {
                int k,x;
                getII(k,x);
                updateSet(1,1,n,k,x);
            }
        }
    }

    return 0;
}



