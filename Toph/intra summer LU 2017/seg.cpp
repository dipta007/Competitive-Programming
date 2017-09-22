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
#define    PB(x)             push_back(x)s
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

#define MAX 100005
int arr[MAX];

struct data
{
    int open, close, ans;
};

data call(data a, data b)
{
    data tmp;
    if(a.ans==-1) return b;
    if(b.ans==-1) return a;
    int kk = min(a.open, b.close);
    tmp.open = a.open + b.open - kk;
    tmp.close = a.close + b.close - kk;
    tmp.ans = a.ans + b.ans + kk;
    return tmp;
}


data tree[MAX*4];

void init(int node,int b,int e)
{
	if(b==e)
	{
	    if(arr[b]==1)
        {
            tree[node].open = 1;
            tree[node].close = 0;
            tree[node].ans = 0;
        }
        else
        {
            tree[node].open = 0;
            tree[node].close = 1;
            tree[node].ans = 0;
        }
		return;
	}
	int Left= node << 1;
	int Right= (node << 1) +1;
	int mid=(b+e)>>1;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=call(tree[Left], tree[Right]);
}
data query(int node,int b,int e,int i,int j)
{
	if (i > e || j < b)
    {
        data tmp;
        tmp.ans = -1;
        tmp.open = INF;
        tmp.close = INF;
        return tmp;
    }
	if (b >= i && e <= j) return tree[node];
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	data p1=query(Left,b,mid,i,j);
	data p2=query(Right,mid+1,e,i,j);
	return call(p1,p2);
}
void update(int node,int b,int e,int i)
{
	if (i > e || i < b)	return;
	if (b >= i && e <= i) {
        if(tree[node].open==1)
        {
            tree[node].open = 0;
            tree[node].close = 1;
            tree[node].ans = 0;
        }
        else
        {
            tree[node].open = 1;
            tree[node].close = 0;
            tree[node].ans = 0;
        }
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	update(Left,b,mid,i);
	update(Right,mid+1,e,i);
	tree[node]=call(tree[Left], tree[Right]);
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    string st;
    while(cin >> st)
    {
        int len = st.size();
        FOR(i,1,len)
        {
            if(st[i-1]=='O') arr[i] = 1;
            else arr[i] = 0;
        }
        init(1,1,len);
        int q;
        cin >> q;
        FOR(i,1,q)
        {
            char ch;
            cin >> ch;
            if(ch=='R')
            {
                int x;
                cin >> x;
                update(1,1,len,x);
            }
            else
            {
                int l,r;
                cin >> l >> r;
                printf("%d\n",query(1,1,len,l,r).ans*2);
            }
        }
    }

    return 0;
}



