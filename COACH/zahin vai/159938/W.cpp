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


#define MAX 300004
int arr[MAX];

struct info
{
    int val,cnt;
};

info tree[MAX*4];

vii colFreq;

int occ(int x,int l,int r)
{
    int up = upper_bound(ALL(colFreq[x]), r) - colFreq[x].begin();
    int low = lower_bound(ALL(colFreq[x]), l) - colFreq[x].begin();
//    if(binary_search(ALL(colFreq[x]), l)==false) low++;
//    else up++;
    return up-low;
}

info call(info a, info b, int l , int r)
{
    info tmp;
    tmp.val = 0;
    tmp.cnt = -1;
    if(occ(a.val, l, r) > (r-l+1)/2)
    {
        tmp.val = a.val;
        tmp.cnt = 1;
    }
    if(occ(b.val, l, r) > (r-l+1)/2)
    {
        tmp.val = b.val;
        tmp.cnt = 1;
    }
    debug(l,r,tmp.val,a.val,occ(a.val, l, r),b.val,occ(b.val, l, r))
    return tmp;
}

void init(int node,int b,int e)
{
	if(b==e)
	{
		tree[node].val = arr[b];
		tree[node].cnt = 1;
		return;
	}
	int Left= node << 1;
	int Right= (node << 1) +1;
	int mid=(b+e)>>1;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=call(tree[Left],tree[Right],b,e);
}
info query(int node,int b,int e,int i,int j)
{
	if (i > e || j < b)
    {
        info tmp;
        tmp.cnt=0,tmp.val=0;
        return tmp;
    }
	if (b >= i && e <= j) return tree[node];
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	info p1=query(Left,b,mid,i,j);
	info p2=query(Right,mid+1,e,i,j);
	return call(p1,p2,i,j);
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,c;
    while(~getII(n,c))
    {
        colFreq.assign(c+4, vi());

        FOR(i,0,n-1)
        {
            int x;
            getI(x);
            colFreq[x].PB(i);
            arr[i] = x;
        }
        init(1,0,n-1);
        int q;
        getI(q);
        FOR(i,1,q)
        {
            int l,r;
            getII(l,r);
            l--,r--;
            info res = query(1,0,n-1,l,r);
            if(res.cnt==-1) printf("no\n");
            else printf("yes %d\n",res.val);
        }
    }


    return 0;
}

/// http://codeforces.com/blog/entry/49724

