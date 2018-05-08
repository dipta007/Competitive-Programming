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

#define MAXN 300004
#define SQRSIZE  600

struct info
{
    vector <pii> v;
};

int arr[MAXN];               // original array
info block[SQRSIZE];          // decomposed array
int blk_sz;                      // block size

// Time Complexity : O(1)
void update(int valIdx, int x)
{
    int blockNumber = valIdx / blk_sz;
    int idx = -1;
    arr[valIdx] = x;
    FOR(i,0,(int)block[blockNumber].v.size()-1)
    {
        if(block[blockNumber].v[i].ss==valIdx)
        {
            idx = i;
            break;
        }
    }
    block[blockNumber].v[idx].ff = x;
    FOR(i,idx,block[blockNumber].v.size()-2)
    {
        if(block[blockNumber].v[i].ff > block[blockNumber].v[i+1].ff)
        {
            swap(block[blockNumber].v[i], block[blockNumber].v[i+1]);
        }
    }
    ROF(i,idx,1)
    {
        if(block[blockNumber].v[i].ff < block[blockNumber].v[i-1].ff)
        {
            swap(block[blockNumber].v[i], block[blockNumber].v[i-1]);
        }
    }
}

int lower_bound(int blkNo, int val)
{
    int low = 0;
    int high = block[blkNo].v.size()-1;
    int res = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(block[blkNo].v[mid].ff<val)
        {
            res = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    return res+1;
}

// Time Complexity : O(sqrt(n))
int query(int l, int r, int val)
{
    int res = 0;
    while (l<r && l%blk_sz!=0 && l!=0)
    {
        debug("**")
        /// traversing first block in range
        if(arr[l]<val) res++;
        l++;
    }
    while (l+blk_sz <= r)
    {
        // traversing completely overlapped blocks in range
            debug("*")
        int up = lower_bound(l/blk_sz, val);
        res += up;
        l += blk_sz;
    }
    while (l<=r)
    {
        debug("***")
        // traversing last block in range
        if(arr[l]<val) res++;
        l++;
    }
    return res;
}

// Fills values in input[]
void preprocess(int n)
{
    // initiating block pointer
    int blk_idx = -1;

    // calculating size of block
    blk_sz = sqrt(n);

    // building the decomposed array
    for (int i=0; i<n; i++)
    {
        if (i%blk_sz == 0)
        {
            // entering next block
            // incementing block pointer
            blk_idx++;
        }
        block[blk_idx].v.PB(pii(arr[i],i));
    }
    FOR(i,0,blk_idx)
    {
        sort(ALL(block[i].v));
    }
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,m,u;
    while(~getIII(n,m,u))
    {
        FOR(i,0,n-1)
        {
            getI(arr[i]);
        }
        preprocess(n);
        FOR(i,1,m)
        {
            int l,r,v,p;
            getII(l,r);
            l--,r--;
            getII(v,p);
            p--;
            int k = query(l,r,v);
            debug("*")
            update(p, (ll)u*k/(r-l+1));
        }
        FOR(i,0,n-1)
        {
            printf("%d\n",arr[i]);
        }
    }

    return 0;
}



