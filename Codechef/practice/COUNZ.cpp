//#include <algorithm>
//#include <bitset>
//#include <cassert>
//#include <cctype>
//#include <climits>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <fstream>
//#include <iostream>
//#include <iomanip>
//#include <iterator>
//#include <list>
//#include <map>
//#include <numeric>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <string>
//#include <utility>
//#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getF(n)           scanf("%lf",&n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    ranL(a, b)         ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define    ranI(a, b)         ((((ll)rand() * rand()) % ((b) - (a) + 1)) + (a))
#define    ranF(a, b)         (((double)rand()/RAND_MAX)*((b) - (a)) + (a))
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    ff 	              first
#define    ss 	              second
#define    sf                 scanf
#define    pf                 printf
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector < int >     vi;
typedef    vector < vi >      vii;
typedef    pair < int, int>   pii;
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
#else
    #define debug(args...)  /// Just strip off all debug tokens
    #define trace(...) ///yeeeee
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const double PI = 2.0 * acos(0.0);

ll MIN() { return INF; }
template <typename T, typename... Args >
inline T MIN(T a, Args... args) { return min(a, (T)MIN(args...)); }

ll MAX() { return -INF; }
template <typename T, typename... Args >
inline T MAX(T a, Args... args) { return max(a, (T)MAX(args...)); }

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************


int twoA[1000004];
int fiveA[1000004];
void pre()
{
    twoA[0] = 0;
    fiveA[0] = 0;
    FOR(i,1,1000000)
    {
        int c2 = 0, c5 = 0;
        int x = i;
        while(x%2 == 0) c2++, x/=2;
        while(x%5 == 0) c5++, x/=5;

        twoA[i] = c2;
        fiveA[i] = c5;
    }
}

#define mx 100004
int arr[mx];
struct info
{
    int two, five, zero;
    int prop;
}tree[mx*4];

info call(info &a,info &b)
{
    info tmp;
    tmp.two = a.two + b.two;
    tmp.five = a.five + b.five;
    tmp.zero = a.zero + b.zero;
    tmp.prop = -1;
    return tmp;
}
void init(int node,int b,int e)
{
	if(b==e)
	{
	    tree[node].two = twoA[arr[b]];
	    tree[node].five = fiveA[arr[b]];
	    tree[node].zero = (arr[b] == 0);
	    tree[node].prop = -1;
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
        tree[node].prop=-1;
        return;
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	///update propagation
	tree[Left].prop = tree[node].prop;
	tree[Right].prop = tree[node].prop;
    tree[node].prop=-1;
    ///update tree[left].sum
    tree[Left].two = twoA[tree[Left].prop] * (mid-b+1);
    tree[Left].five = fiveA[tree[Left].prop] * (mid-b+1);
    tree[Left].zero = (tree[Left].prop == 0);
    ///update tree[right].sum
    tree[Right].two = twoA[tree[Right].prop] * (e-mid);
    tree[Right].five = fiveA[tree[Right].prop] * (e-mid);
    tree[Right].zero = (tree[Right].prop == 0);
}
info query(int node,int b,int e,int i,int j) ///range i theke j
{
	if (i > e || j < b)
    {
        info tmp;
        tmp.five = tmp.two = tmp.zero = 0;
        return tmp;
    }
	if(tree[node].prop != -1)propagate(node,b,e);
	if(b>=i && e<=j)
    {
        return tree[node];
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
    info p1 = query(Left,b,mid,i,j);
    info p2 = query(Right,mid+1,e,i,j);
    return call(p1, p2);
}
void update(int node,int b,int e,int i,int j, int newVal)
{
	if(tree[node].prop != -1)propagate(node,b,e);
	if (i > e || j < b)	return;
	if (b >= i && e <= j)
    {
        int len = (e-b+1);
        tree[node].two = twoA[newVal] * len;
        tree[node].five = fiveA[newVal] * len;
        tree[node].prop = newVal;
        tree[node].zero = (newVal == 0);
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
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    pre();
    int n;
    while(cin >> n)
    {
        FOR(i,1,n) cin >> arr[i];

        init(1,1,n);

        int q;
        cin >> q;
        FOR(i,1,q)
        {
            int tt;
            cin >> tt;
            if(tt == 1)
            {
                int l, r;
                cin >> l >> r;
                info res = query(1, 1, n, l, r);
                int ans = min(res.two, res.five);
                if(res.zero > 0) ans = 1;
                cout << ans << endl;
            }
            else
            {
                int l, r, v;
                cin >> l >> r >> v;
                update(1, 1, n, l, r, v);
            }
        }
    }

    return 0;
}


