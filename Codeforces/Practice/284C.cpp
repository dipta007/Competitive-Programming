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
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    ff 	              first
#define    ss 	              second
#define    sf                 scanf
#define    pf                 printf
typedef    vector < int >     vi;
typedef    vector < vi >      vii;
typedef    pair < int, int>   pii;
typedef    long long          ll;
typedef    unsigned long long ull;
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

#ifdef dipta00
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

#define mx 200004
struct info
{
    ll sum;
    ll prop;
}tree[mx*4];

info call(info &a,info &b)
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
    trace("prr", node, b, e, tree[node].prop);
    if(b==e)
    {
        tree[node].prop=0;
        return;
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	///update propagation
	tree[Left].prop += tree[node].prop;
	tree[Right].prop += tree[node].prop;
    ///update tree[left].sum
    tree[Left].sum += (ll)(mid-b+1) * tree[node].prop;
    ///update tree[right].sum
    tree[Right].sum += (ll)(e-mid) * tree[node].prop;
    tree[node].prop=0;
}
void update(int node,int b,int e,int i,int j, ll newVal)
{
	if(tree[node].prop)propagate(node,b,e);
	if (i > e || j < b)	return;
	if (b >= i && e <= j)
    {
        tree[node].sum += (ll)(e-b+1) * newVal;
        tree[node].prop += newVal;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	update(Left,b,mid,i,j,newVal);
	update(Right,mid+1,e,i,j,newVal);
	tree[node]=call(tree[Left],tree[Right]);
}
void update1(int node,int b,int e,int i, ll newVal)
{
	if(tree[node].prop)propagate(node,b,e);
	if (i > e || i < b)	return;
	if (b >= i && e <= i)
    {
        tree[node].sum = newVal;
        tree[node].prop = 0;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	update1(Left,b,mid,i,newVal);
	update1(Right,mid+1,e,i,newVal);
	tree[node]=call(tree[Left],tree[Right]);
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(cin >> n)
    {
        int tot = 200000;
        init(1, 0, tot);
        int nn = 1;
        FOR(i,1,n)
        {
            int tt;
            cin >> tt;
            if(tt == 1)
            {
                int a,x;
                cin >> a >> x;
                update(1, 0, tot, 0, a-1, x);
            }
            else if(tt == 2)
            {
                int kk;
                cin >> kk;
                update1(1,0,tot,nn, kk);
                nn++;
            }
            else if(nn >= 2)
            {
                nn--;
                update1(1,0,tot, nn, 0);
            }

            ll now = tree[1].sum;
            double res = (double)now / nn;
            res += EPS;
            trace(now, nn, res);
//            trace(query(1,0,tot,0,0));
//            trace(tree[131072].sum, tree[131072].prop);
//            trace(query(1,0,tot,1,1));
//            trace(query(1,0,tot,2,2));
//            trace(query(1,0,tot,0,2));
            cout << setprecision(12) << fixed;
            cout << res << endl;
        }
    }

    return 0;
}



