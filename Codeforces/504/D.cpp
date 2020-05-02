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

//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#define    SETI(ar)           memset(ar,126,sizeof ar)


#define printbits(x, n) cout << #x << " = " << x << " = " << bitset<n>(x) << endl /// Least significant n bits of x, n must be constant
#define tobinary(x) string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(min(63, __builtin_clzll(x)), 64)
#define lastbits(x, n) cout << string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(64 - n, 64) << endl
#define firstbits(x, n) cout << string(bitset<64>(x).to_string<char, string::traits_type, string::allocator_type>()).substr(min(63, __builtin_clzll(x)), 64).substr(0, n) << endl;

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

#define mx 200004
int arr[mx];
struct info
{
    int sum;
    int prop;
}tree[mx*4];

info call(info a,info b)
{
    info tmp;
    tmp.sum = min(a.sum, b.sum);
    tmp.prop = 0;
    return tmp;
}
void init(int node,int b,int e)
{
	if(b==e)
	{
	    tree[node].sum = arr[b];
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
	int prop = tree[node].prop;
	tree[Left].prop = tree[node].prop;
	tree[Right].prop = tree[node].prop;
    tree[node].prop=0;
    ///update tree[left].sum
    tree[Left].sum = prop;
    ///update tree[right].sum
    tree[Right].sum = prop;
}
int query(int node,int b,int e,int i,int j) ///range i theke j
{
	if (i > e || j < b)return INF;
	if(tree[node].prop) propagate(node,b,e);
	if(b>=i && e<=j)
    {
        return tree[node].sum;
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
    int p1 = query(Left,b,mid,i,j);
    int p2 = query(Right,mid+1,e,i,j);
    return  min(p1, p2);
}
void update(int node,int b,int e,int i,int j, int newVal)
{
	if(tree[node].prop)propagate(node,b,e);
	if (i > e || j < b)	return;
	if (b >= i && e <= j)
    {
        tree[node].prop = newVal;
        tree[node].sum = newVal;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	update(Left,b,mid,i,j,newVal);
	update(Right,mid+1,e,i,j,newVal);
	tree[node]=call(tree[Left],tree[Right]);
}

const int SZ = 2e5 + 4;
int MN[SZ];
int MX[SZ];
int res[SZ];

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, q;
    while(cin >> n >> q)
    {
        FOR(i,0,n-1) cin >> arr[i];
        FOR(i,0,n-1) if(arr[i] == 0) arr[i] = INF;

        FOR(i,0,n-1) res[i] = arr[i];

        init(1, 0, n-1);

        set <int > s;
        SET(MN);
        FOR(i,0,n-1)
        {
            if(arr[i] != INF)
            {
                s.insert(arr[i]);

                if(MN[ arr[i] ] == -1)
                    MN[ arr[i] ] = i;
                MX[arr[i]] = i;
            }
        }
//        trace("SD");

        int flg = 1;
        for(auto v: s) {
            int mn = query(1, 0, n-1, MN[v], MX[v]);
            if(mn < v)
            {
                flg = 0;
                break;
            }
        }



        if(!flg) cout << "NO" << endl;
        else
        {
            for(auto v: s) {
                update(1, 0, n-1, MN[v], MX[v], v);
            }
            int mxFlg = 0;
            int zero = -1;
            FOR(i, 0, n-1) {

                if(res[i] == INF)
                {
                    zero = i;
                    res[i] = query(1, 0, n-1, i, i);
                }
                if(res[i] == q) mxFlg = 1;
            }

            FOR(i,0,n-1)
            {
                if(res[i] == INF)
                {
                    if(mxFlg) res[i] = 1;
                    else res[i] = q, mxFlg = 1;
                }
            }

            if(!mxFlg)
            {
                if(zero == -1) cout << "NO" << endl;
                else
                {
                    mxFlg = 1;
                    res[zero] = q;
                }
            }

            if(mxFlg)
            {
                cout << "YES" << endl;
                FOR(i,0,n-1)
                {
                    if(i) cout << " ";
                    cout << res[i];
                }
                cout << endl;
            }

        }
//        FOR(i,0,n-1)
//        {
//            if(res[i] == INF)
//            {
//                if(i-1 > 0 && res[i-1] != INF) res[i] = res[i-1];
//                else if(i+1 < n && res[i+1] != INF) res[i] = res[i+1];
//            }
//        }
    }

    return 0;
}


