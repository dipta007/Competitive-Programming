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
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
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
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)        (a|(1<<(k)))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    iseq(a,b)         (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef mamun
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///****************** template ends here ****************
int t,n,m;

#define root 0
#define mx 30005
#define LN 14

vector <int> adj[mx],costs;
int parent[mx],sparse[mx][22],depth[mx];
int baseArray[mx], ptr;
int chainNo, chainInd[mx], chainHead[mx], posInBase[mx];
int  subsize[mx];

///dfs is used to set parent,depth,subtree size
void dfs(int from,int u,int dep=0)
{
    depth[u]=dep;
    parent[u]=from;
    subsize[u]=1;
    repI(i,adj[u].size())
    {
        int v=adj[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
        subsize[u]+=subsize[v];
    }
}
///LCA
void lca_init(int N)
{
    SET(sparse);
    for (int i = 0; i < N; i++)sparse[i][0] = parent[i];
    for (int j = 1; (1 << j) < N; j++)
        for (int i = 0; i < N; i++)
            if (sparse[i][j - 1] != -1)
            {
                int tmp=sparse[i][j - 1];
                sparse[i][j] = sparse[tmp][j - 1];
            }
}
int lca_query(int p, int q)
{
    int tmp, log, i;
    if (depth[p] < depth[q])swap(p,q);

    log=1;
    while(1)
    {
        int next=log+1;
        if((1<<next)>depth[p])break;
        log++;
    }
    for (i = log; i >= 0; i--)
        if (depth[p] - (1 << i) >= depth[q])
            p = sparse[p][i];

    if (p == q)return p;

    for (i = log; i >= 0; i--)
        if (sparse[p][i] != -1 && sparse[p][i] != sparse[q][i])
            p = sparse[p][i], q = sparse[q][i];

    return parent[p];
}


/*
 * Actual HL-Decomposition part
 * Initially all entries of chainHead[] are set to -1.
 * So when ever a new chain is started, chain head is correctly assigned.
 * As we add a new node to chain, we will note its position in the baseArray.
 * In the first for loop we find the child node which has maximum sub-tree size.
 * The following if condition is failed for leaf nodes.
 * When the if condition passes, we expand the chain to special child.
 * In the second for loop we recursively call the function on all normal nodes.
 * chainNo++ ensures that we are creating a new chain for each normal child.
 */
void HLD(int curNode, int cost, int from)
{
    if(chainHead[chainNo] == -1)
    {
        chainHead[chainNo] = curNode; /// Assign chain head
    }
    chainInd[curNode] = chainNo;
    posInBase[curNode] = ptr; /// Position of this node in baseArray which we will use in Segtree
    baseArray[ptr++] = cost;

    int sc = -1, ncost; ///sc = subchild
    /// Loop to find special child
    repI(i,adj[curNode].size())
    {
        int v=adj[curNode][i];
        if(v==from)continue;
        if(sc==-1||subsize[sc]<subsize[v])
        {
            sc=v;
            ncost=costs[v];
        }
    }
    if(sc != -1)
    {
        /// Expand the chain
        HLD(sc, ncost, curNode);
    }
    repI(i,adj[curNode].size())
    {
        int v=adj[curNode][i];
        if(v==from||v==sc)continue;
        /// New chains at each normal node
        chainNo++;
        HLD(v, costs[v], curNode);
    }
}

///segment tree
int tree[mx*3];

void init(int node,int b,int e)
{
	if(b==e)
	{
		tree[node]=baseArray[b];
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=tree[Left]+tree[Right];
}
int query(int node,int b,int e,int i,int j)
{
	if (i > e || j < b)	return 0;
	if (b >= i && e <= j) return tree[node];
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	int p1=query(Left,b,mid,i,j);
	int p2=query(Right,mid+1,e,i,j);
	return p1+p2;
}
void update(int node,int b,int e,int i,int newvalue)
{
	if (i > e || i < b)	return;
	if (b >= i && e <= i) {
		tree[node]=newvalue;
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	update(Left,b,mid,i,newvalue);
	update(Right,mid+1,e,i,newvalue);
	tree[node]=tree[Left]+tree[Right];
}


/*
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 */
int query_up(int u, int v)
{
    if(u == v) return query(1,0,ptr-1,posInBase[u],posInBase[v]); /// Trivial
    int uchain, vchain = chainInd[v], ans = 0;
    /// uchain and vchain are chain numbers of u and v
    while(1)
    {
        uchain = chainInd[u];
        if(uchain == vchain)
        {
            /// Both u and v are in the same chain, so we need to query from u to v
            /// We break because we came from u up till v, we are done
            ans+=query(1, 0, ptr-1, posInBase[v], posInBase[u]);
            break;
        }
        int uchainhed = chainHead[uchain]; /// move u to u's chainHead
        /// Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
        /// start till head. We then update the answer
        ans+=query(1, 0, ptr-1, posInBase[uchainhed], posInBase[u]);
        u = parent[uchainhed]; ///Then move to its parent, that means we changed chains
    }
    return ans;
}
void query(int u, int v)
{
     ///We have a query from u to v, we break it into two queries
     /// u to LCA(u,v) and LCA(u,v) to v
    int lca = lca_query(u, v);
    int ans1 = query_up(u, lca); /// One part of path
    int ans2 = query_up(v, lca); /// another part of path
    int ans3 = query(1,0,ptr-1,posInBase[lca],posInBase[lca]);
//    debug(ans1,ans2,ans3)
//    debug(lca,posInBase[u],posInBase[v],posInBase[lca])
    printf("%d\n", ans1+ans2-ans3);
}

///find pos in segtree and update
void change(int u, int val)
{
    int indx = posInBase[u];
    update(1,0,ptr-1,indx,val);
}

void clear(int n)
{
    ptr = 0;
    chainNo = 0;
    costs.clear();
    repI(i,n+1)adj[i].clear();
    SET(chainHead);

}

int main()
{
    getI(t);
    rep(cs,t)
    {
        getI(n);
        /// Cleaning step, new test case
        clear(n);

        repI(i,n)
        {
            int c;
            getI(c);
            costs.PB(c);
        }
        rep(i,n-1)
        {
            int u, v;
            getII(u,v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(-1,root); /// We set up subsize, depth and parent for each node
        HLD(root, costs[root], -1); /// We decomposed the tree and created baseArray
        init(1,0,ptr-1); /// We use baseArray and construct the needed segment tree
        lca_init(n);

        printf("Case %d:\n",cs);
        int q;
        getI(q);
        rep(i,q)
        {
            int type,u,v;
            getIII(type,u,v);
            if(type)change(u,v);
            else query(u,v);
        }

    }
}
