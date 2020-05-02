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

#ifdef dipta07
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

vi v;
map < int, pii > child;
bool vis[500004];
vii adj;
int par[500004];

void dfs(int u)
{
    vis[u]=1;
    int start = v.size();
    FOR(i,0,(int)adj[u].size()-1)
    {
        int v = adj[u][i];
        if(vis[v]==0)
        {
            par[v]=u;
            dfs(v);
        }
    }
    int endd = v.size();
    v.PB(u);
    child[u] = pii(start, endd);
}

#define mx 500004
struct info
{
    ll sum;
    int prop;
}tree[mx*4];

info call(info a,info b)
{
    info tmp;
    tmp.sum = a.sum + b.sum;
    tmp.prop = 0;
    return tmp;
}

void init(int node,int b,int e)
{
	if(b==e)
	{
	    tree[node].sum=500004;
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
	tree[Left].prop = tree[node].prop;
	tree[Right].prop = tree[node].prop;
    tree[node].prop=0;
    ///update tree[left].sum
    tree[Left].sum = 0;
    ///update tree[right].sum
    tree[Right].sum = 0;
}

ll query(int node,int b,int e,int i,int j) ///range i theke j
{
	if (i > e || j < b)return 0;
	if(tree[node].prop)propagate(node,b,e);
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

void updateFill(int node,int b,int e,int i,int j)
{
	if(tree[node].prop)propagate(node,b,e);
	if (i > e || j < b)	return;
	if (b >= i && e <= j)
    {
        tree[node].sum = 0;
        tree[node].prop = 1;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	updateFill(Left,b,mid,i,j);
	updateFill(Right,mid+1,e,i,j);
	tree[node]=call(tree[Left],tree[Right]);
}

void updateEmpty(int node,int b,int e,int i)
{
	if(tree[node].prop)propagate(node,b,e);
	if (i > e || i < b)	return;
	if (b >= i && e <= i)
    {
        tree[node].sum = 1;
        tree[node].prop = 0;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	updateEmpty(Left,b,mid,i);
	updateEmpty(Right,mid+1,e,i);
	tree[node]=call(tree[Left],tree[Right]);
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(~getI(n))
    {
        adj.assign(n+4, vi());
        FOR(i,1,n-1)
        {
            int x,y;
            getII(x,y);
            adj[x].PB(y);
            adj[y].PB(x);
        }
        child.clear();
        v.clear();
        CLR(vis);
        par[1]=1;
        dfs(1);

//        FOR(i,1,n)
//        {
//            debug(i,par[i])
//        }


        int q;
        getI(q);
        init(1,0,n-1);
        FOR(i,1,q)
        {
            int tt,v;
            getII(tt,v);
            if(tt==1)
            {
                int l = child[v].ff;
                int r = child[v].ss;
                ll res = query(1,0,n-1,l,r);
                debug(l,r,res)
                if(res>0 && res<=r-l+1)
                {
                    int pos = child[par[v]].ss;
                    updateEmpty(1,0,n-1,pos);
                }
                updateFill(1,0,n-1,l,r);
            }
            else if(tt==2)
            {
                int pos = child[v].ss;
                updateEmpty(1,0,n-1,pos);
            }
            else
            {
                int l = child[v].ff;
                int r = child[v].ss;
                ll res = query(1,0,n-1,l,r);
                debug(l,r,res)
                if(res>0) printf("0\n");
                else printf("1\n");
            }
        }
    }

    return 0;
}
////10
////1 2
////2 3
////2 4
////1 5
////4 6
////3 7
////6 8
////6 9
////2 10
////10
////3 8
////3 6
////3 4
////1 2
////1 5
////3 10
////3 3
//2 8
//2 4
//3 9
//

//5
//1 2
//1 3
//1 4
//1 5
//16
//1 1
//2 2
//1 2
//3 1
//3 2
//3 3
//3 4
//3 5
//2 2
//1 1
//2 4
//3 1
//3 2
//3 3
//3 4
//3 5

