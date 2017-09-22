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

struct quer
{
    int t;
    ll l, r;
    quer(int a, ll b, ll c)
    {
        t = a;
        l = b;
        r = c;
    }
};

vector < quer > vq;
map <ll, int> mp;
map <int, ll> rev;
vector <ll > v;

#define mx 300004
struct info
{
    int sum;
    int prop;
}tree[mx*4];

info call(info a,info b)
{
    info tmp;
    tmp.sum = a.sum + b.sum;
    tmp.prop = 0;
    ///merge two info
    return tmp;
}

void init(int node,int b,int e)
{
	if(b==e)
	{
	    ///do something
	    tree[node].sum = 0;
	    tree[node].prop = 0;
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
	int propa = tree[node].prop;
	if(propa==1)
    {
        tree[Left].prop = 1;
        tree[Right].prop = 1;
    }
    else if(propa==2)
    {
        tree[Left].prop = 2;
        tree[Right].prop = 2;
    }
    else if(propa==3)
    {
        if(tree[Left].prop == 1) tree[Left].prop = 2;
        else if(tree[Left].prop == 2) tree[Left].prop = 1;
        else if(tree[Left].prop == 3) tree[Left].prop = 0;
        else tree[Left].prop = 3;
        if(tree[Right].prop == 1) tree[Right].prop = 2;
        else if(tree[Right].prop == 2) tree[Right].prop = 1;
        else if(tree[Right].prop == 3) tree[Right].prop = 0;
        else tree[Right].prop = 3;
    }
    tree[node].prop=0;
    ///update tree[left].sum
    if(propa==1) tree[Left].sum = mid-b+1;
    else if(propa==2) tree[Left].sum = 0;
    else tree[Left].sum = (mid-b+1) - tree[Left].sum;
    ///update tree[right].sum
    if(propa==1) tree[Right].sum = e-mid;
    else if(propa==2) tree[Right].sum = 0;
    else tree[Right].sum = (e-mid) - tree[Right].sum;

}

ll query(int node,int b,int e) ///range i theke j
{
	if(tree[node].prop)propagate(node,b,e);
	if(b==e)
    {
        debug(b)
        ///do something
        return rev[b];
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	debug(b,mid,e,tree[Left].sum, tree[Right].sum)
	if(tree[Left].sum == (mid-b+1))
    {
        return query(Right, mid+1, e);
    }
    else
    {
        return query(Left,b,mid);
    }
//    int p1 = query(Left,b,mid,i,j);
//    int p2 = query(Right,mid+1,e,i,j);
//    return  p1+p2;

}

void update(int node,int b,int e,int i,int j, int newVal)
{
	if(tree[node].prop)propagate(node,b,e);
	if (i > e || j < b)	return;
	if (b >= i && e <= j)
    {
        if(newVal==1)
        {
            tree[node].prop = 1;
            tree[node].sum = (e-b+1);
        }
        else if(newVal==2)
        {
            tree[node].prop = 2;
            tree[node].sum = 0;
        }
        else
        {
            tree[node].prop = 3;
            tree[node].sum = (e-b+1) - tree[node].sum;
        }
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

    int n;
    while(~getI(n))
    {
        vq.clear();
        mp.clear();
        rev.clear();
        v.clear();
        FOR(i,1,n)
        {
            int t;
            ll x,y;
            getI(t);
            getLL(x,y);
            vq.PB(quer(t,x,y));
            v.PB(x);
            v.PB(y);
            v.PB(y+1);
        }

        sort(ALL(v));
        UNIQUE(v);
        mp[1] = 1;
        rev[1] = 1;
        int in =2;
        FOR(i,0,v.size()-1)
        {
            debug(v[i]);
            if(mp[v[i]]==0)
            {
                mp[v[i]] = in;
                rev[in] = v[i];
                in++;
            }
            if(mp[v[i]]==0)
            {
                mp[v[i]] = in;
                rev[in] = v[i];
                in++;
            }
        }
        FOR(i,0,n-1)
        {
            vq[i].l = mp[vq[i].l];
            vq[i].r = mp[vq[i].r];
        }

        init(1,1,in);

        FOR(i,0,n-1)
        {
            int t = vq[i].t;
            debug(t, vq[i].l, vq[i].r)
            update(1,1,in,vq[i].l, vq[i].r, t);
            printf("%lld\n", query(1,1,in));
        }

    }

    return 0;
}



