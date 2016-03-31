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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    rep(i,n)          for(i=1;i<=n;i++)
#define    repI(i,n)         for(i=0;i<n;i++)
#define    F(i,L,R)	         for (int i = L; i < R; i++)
#define    FF(i,L,R) 	     for (int i = L; i <= R; i++)
#define    FR(i,L,R) 	     for (int i = L; i > R; i--)
#define    FRF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double


template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

//******************DELETE****************
#define shubhashis
#ifdef shubhashis
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

/// ********* debug template bt Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;
//******************DELETE****************

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N=N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

struct edge
{
	int u,v,w,in;
	bool operator < ( const edge& p ) const
	{
		return w < p.w;
	}
};

const int MAXN = 200004;
int pr[MAXN];
vector<edge>e,realE;
ll res[200004];
vector < vector <pii > > AdjList;
vector <int> visited;

int find(int r)
{
   return (pr[r]==r) ? r:  find(pr[r]);
}

ll mst(int n,int count,ll s,int f)
{
	sort(e.begin(),e.end());

	for(int i=0;i<(int)e.size();i++)
	{
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(u!=v)
		{
		    if(f==1) res[e[i].in]=-2;
			pr[u]=v;
			AdjList[e[i].u].PB(pii(e[i].v,e[i].w));
			AdjList[e[i].v].PB(pii(e[i].u,e[i].w));
			count++;
			s+=e[i].w;
			if(count==n-1) break;
		}
	}
	return s;
}

int maxy;
int dfs(int u,int src)
{
    if(u==src) return 1;
    visited[u]=1;
    int k=0;
    for(int i=0;i<AdjList[u].size();i++)
    {
        pii v=AdjList[u][i];
        if(visited[v.ff]==0)
        {
            k=dfs(v.ff,src);
            if(k)
            {
                maxy=max(v.ss,maxy);
                break;
            }
        }
    }
    return k;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n,m;
    while(~getII(n,m))
    {
        e.clear();
        realE.clear();
        SET(res);
        AdjList.assign(n+4,vector<pii>());
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            getIII(u,v,w);
            edge get;
            get.u=u; get.v=v; get.w=w; get.in=i;
            e.push_back(get);
            realE.PB(get);
        }
        for(int i=1;i<=n;i++)pr[i]=i;
        ll k=mst(n,0,0,1);

        for(int i=0;i<m;i++)
        {
            if(res[i]==-2)
            {
                res[i]=k;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(res[i]!=-1) ;
            else
            {
                int u=realE[i].u;
                int v=realE[i].v;
                pr[u]=v;
//                AdjList[u].PB(v);
//                AdjList[v].PB(u);
                maxy=-1;
                visited.assign(n+4,0);
                int l=dfs(u,v);
                //debug(i,l,maxy);
                res[i]=k-maxy+realE[i].w;
            }
            //debug(i,res[i]);
        }
        for(int i=0;i<m;i++) printf("%lld\n",res[i]);
    }

    return 0;
}


