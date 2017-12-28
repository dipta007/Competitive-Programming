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
#define    UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
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

#define MAX 1000004
int arr[MAX];


vi tree[MAX*4];

vi call(vi &a, vi &b)
{
//    vi tmp;
//    if(b[0] <= a.back())
//    {
        vi tmp = a;
        FOR(i,0,(int)b.size()-1)
        {
            if(b[i] > tmp.back())
            {
                tmp.PB(b[i]);
            }
        }
        return tmp;
//    }
//    else
//    {
//        vi tmp(a.size()+b.size());
////        tmp.resize(a.size()+b.size());
//        merge(ALL(a), ALL(b), tmp.begin());
//        return tmp;
//    }
}

void init(int node,int b,int e)
{
	if(b==e)
	{
		tree[node].PB( arr[b] );
		return;
	}
	int Left= node << 1;
	int Right= (node << 1) +1;
	int mid=(b+e)>>1;
	init(Left,b,mid);
	init(Right,mid+1,e);

//	if(tree[Left].back() >= tree[Right][0])
//    {
//        tree[node] = tree[Left];
//    }
//    else
//    {
//        merge(ALL(tree[Left]), ALL(tree[Right]), back_inserter(tree[node]));
//    }

//	debug(node, b, e)
//    merge(ALL(tree[Left]), ALL(tree[Right]), back_inserter(tree[node]));
	tree[node]= call(tree[Left], tree[Right]);
}

pii add(pii &a, pii &b)
{
    pii tmp;
    tmp.ff = a.ff + b.ff;
    tmp.ss = max(a.ss, b.ss);
    return tmp;
}

int query(int node,int b,int e,int i, int j,  int &l, int &r)
{
//    debug(node, b, e, l, r)
	if (i > e || j < b)	return 0;//pii(0,l-1);
	if (b >= i && e <= j)
    {
        debug(node, b, e, l, r, tree[node].size())
        FOR(i,0,(int)tree[node].size()-1)
        {
            debug(tree[node][i])
        }
        debug(l,r)
        auto low = lower_bound(ALL(tree[node]), l) - tree[node].begin();
        auto high = lower_bound(ALL(tree[node]), r) - tree[node].begin();
        if(high >= tree[node].size()) high--;
//        if(tree[node][high]!=r) high++;
//        debug("*")
//        debug(l,r, low, high)
        if(low >= tree[node].size()) return 0;
        if(high < low)
        {
//            l = l-1;
            return 0;//pii(0, l-1);
        }

        l = tree[node][high]+1;
        return (high-low+1);//MP(high - low + 1, tree[node][high]);
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	int p1=query(Left,b,mid,i,j, l, r);
	int p2=query(Right,mid+1,e,i,j, l, r);
	return p1+p2;
}
void update(int node,int b,int e,int i,int newvalue)
{
	if (i > e || i < b)	return;
	if (b >= i && e <= i) {
		tree[node][0] += newvalue;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	if(i <= mid) update(Left,b,mid,i,newvalue);
	else update(Right,mid+1,e,i,newvalue);
	tree[node]=call(tree[Left], tree[Right]);
//    merge(ALL(tree[Left]), ALL(tree[Right]), back_inserter(tree[node]));
}


int main() {
    #ifdef dipta007
        READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        int n,q;
        cin >> n >> q;
        FOR(i,1,n)
        {
            cin >> arr[i];
        }

        init(1,1,n);

        FOR(i,1,q)
        {
            char ch;
            cin >> ch;
            if(ch == '?')
            {
                int x,l,r;
                cin >> x >> l >> r;

                int res = query(1,1,n, x, n, l, r);
                printf("%d\n",res);
            }
            else
            {
                int x,y;
                cin >> x >> y;
                update(1,1,n,x,y);
            }
        }
    }

    return 0;
}

//1
//6 4
//3 7 2 2 8 7
//? 4 3 9
//? 3 1 7
//+ 6 2
//? 4 3 9

