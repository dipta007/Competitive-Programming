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

struct data {
    int x, y1, y2, id, tt;
    data() {}
    data(int _x,int _y1,int _y2,int _id,int _tt)
    {
        x = _x;
        y1 = _y1;
        y2 = _y2;
        id = _id;
        tt = _tt;
    }
};

bool cmp(const data &a, const data &b)
{
    if(a.x != b.x) return a.x < b.x;
    if(a.x == b.x) {
        return a.tt < b.tt;
    }
}

vector <data> vpp;
vector <int> v;

#define MAX 300000+4
int arr[MAX];

int tree[MAX*4];

int query(int node,int b,int e,int i,int j)
{
	if (i > e || j < b)	return 0;
	if (b >= i && e <= j) return tree[node];
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	int p1=query(Left,b,mid,i,j);
	int p2=query(Right,mid+1,e,i,j);
	return p1+p2;
}
void update(int node,int b,int e,int i,int newvalue)
{
	if (i > e || i < b)	return;
	if (b >= i && e <= i) {
		tree[node] += newvalue;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	update(Left,b,mid,i,newvalue);
	update(Right,mid+1,e,i,newvalue);
	tree[node]=tree[Left]+tree[Right];
}

int res[MAX];

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n, m;
        getII(n,m);

        vpp.clear();
        v.clear();

        FOR(i,1,n)
        {
            int u, vv;
            getII(u, vv);
            vpp.push_back(data(u, vv, vv, -1, 2));
            v.push_back(vv);
        }

        FOR(i,1,m)
        {
            int a, b, c, d;
            getII(a,b);
            getII(c,d);
            vpp.push_back(data(a, b, d, i, 1));
            vpp.push_back(data(c, b, d, i, 3));
            v.PB(b);
            v.PB(d);
        }

        sort(ALL(v));
        UNIQUE(v);

        sort(ALL(vpp), cmp);

        CLR(tree);
        int tot = (int)v.size() + 10;

        CLR(res);
        FOR(i,0,(int)vpp.size()-1)
        {
            data d = vpp[i];
//            trace(d.x, d.y1, d.y2, d.id, d.tt);
            int p1 = lower_bound(ALL(v), d.y1) - v.begin();
            int p2 = lower_bound(ALL(v), d.y2) - v.begin();
            if(d.tt == 2)
            {
                update(1, 0, tot, p1, 1);
            }
            else if(d.tt == 1)
            {
                res[d.id] += -query(1, 0, tot, p1, p2);
//                trace(d.id, res[d.id]);
            }
            else
            {
                res[d.id] += query(1, 0, tot, p1, p2);
//                trace(d.id, res[d.id]);
            }
        }

        pf("Case %d:\n", ci);
        FOR(i,1,m)
        {
            pf("%d\n", res[i]);
        }
    }

    return 0;
}


