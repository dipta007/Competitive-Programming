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
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#define dipta00
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
///****************** template ends here ****************

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out


const int MAX_N = 2e6+4;
string text;
int N, m, SA [MAX_N], LCP [MAX_N];
int x [MAX_N], y [MAX_N], w [MAX_N], c [MAX_N];

inline bool cmp (const int a, const int b, const int l)
{
    return (y [a] == y [b] && y [a + l] == y [b + l]);
}

void Sort ()
{
    for (int i = 0; i < m; ++i)
        w [i] = 0;
    for (int i = 0; i < N; ++i)
        ++w [x [y [i]]];
    for (int i = 0; i < m - 1; ++i)
        w [i + 1] += w [i];
    for (int i = N - 1; i >= 0; --i)
        SA [--w [x [y [i]]]] = y [i];
}

void DA ()
{
    ++N;
    for (int i = 0; i < N; ++i)
        x [i] = text [i], y[i] = i;
    Sort ();
    for (int i, j = 1, p = 1; p < N; j <<= 1, m = p)
    {
        for (p = 0, i = N - j; i < N; i++)
            y [p++] = i;
        for (int k = 0; k < N; ++k)
            if (SA [k] >= j)
                y [p++] = SA [k] - j;
        Sort ();
        for (swap (x, y), p = 1, x [SA [0]] = 0, i = 1; i < N; ++i)
            x [SA [i]] = cmp (SA [i - 1], SA [i], j) ? p - 1 : p++;
    }
    for (int i = 1; i < N; ++i)
        SA [i - 1] = SA [i];
    --N;
}

void kasaiLCP ()
{
    int i,j,k;
    for(i=0; i<N; i++) c [ SA[i] ] = i;

    k = 0;
    for (i = 0; i < N; i++) {
        if (c[i] == (N - 1)) k = 0;
        else {
            j = SA[c[i] + 1];
            while ( ((i + k) < N) && ((j + k) < N) &&
                    (text[i + k] == text[j + k]) )
                k++;
        }
        LCP[c[i]] = k;

        if(k > 0) k--;
    }
}

void suffixArray ()
{
    m = 256;
    N = text.size();
    DA ();
    kasaiLCP ();
}

const int MAX = 2e6+4;
vector < string > vs;
int mark[MAX];
int inv[MAX];

struct data
{
    int val;
    bool zero;
};

data tree[MAX*4];

void merge(int a, int b, int c)
{
    tree[a].val = tree[b].val + tree[c].val;
    tree[a].zero = tree[b].zero || tree[c].zero;
}

void init(int node,int b,int e)
{
	if(b==e)
	{
	    /// text e kon pos e ase
	    int kk = mark[b];

	    if(kk == -1)
        {
            tree[node].val = 0;
            tree[node].zero = 1;
            return;
        }

	    /// oi pos er suffix array te kon pos
	    kk = inv[kk];
		tree[node].val = LCP[kk];
		tree[node].zero = (LCP[kk] == 0);
		return;
	}
	int Left= node << 1;
	int Right= (node << 1) +1;
	int mid=(b+e)>>1;
	init(Left,b,mid);
	init(Right,mid+1,e);
	merge(node, Left, Right);
}
int query(int node,int b,int e,int i,int j)
{
	if (i > e || j < b)	return 0;
	if (b >= i && e <= j) return tree[node].val;
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	int p1=query(Left,b,mid,i,j);
	int p2=query(Right,mid+1,e,i,j);
	return p1+p2;
}
int queryLeft(int node,int b,int e,int i,int j)
{
	if (i > e || j < b)	return -1;
	if(tree[node].zero == 0) return -1;
	if (b==e) return b;
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;

	int rr = queryLeft(Right,mid+1,e,i,j);
	if(rr != -1) return rr;

	int lf = queryLeft(Left,b,mid,i,j);
    return lf;
}
int queryRight(int node,int b,int e,int i,int j)
{
	if (i > e || j < b)	return -1;
	if(tree[node].zero == 0) return -1;
	if (b==e) return b;
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;

	int lf = queryRight(Left,b,mid,i,j);
	if(lf != -1) return lf;

	int rr = queryRight(Right,mid+1,e,i,j);
    return rr;
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
        vs.clear();
        FOR(i,1,n)
        {
            string st;
            cin >> st;
            vs.PB(st);
        }

        sort(ALLR(vs));

        text = "";
        int sen = 0;
        mark[0] = -1;
        mark[n+1] = -1;
        FOR(i,0,n-1)
        {
            mark[i+1] = text.size();
            text += vs[i];
            text += (char)(sen + '0');
            sen ++;
            sen %= 10;
        }

        suffixArray();

        int len = text.size();
        FOR(i,0,len-1)
        {
            inv[ SA[i] ] = i;
        }

        init(1,0,n+1);

        FOR(i,1,n)
        {
//            int posInString = mark[i];
//            int kk = inv[posInString];
            int kk = i;
            int l = queryLeft(1, 0, n+1, 0, kk-1);
            int r = queryRight(1, 0, n+1, kk+1, n+1);
            debug(l, r, vs[i-1], query(1, 0, n+1, i, r))
        }
    }

    return 0;
}

