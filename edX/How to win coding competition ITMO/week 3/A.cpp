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
#define    iseq(a,b)          (fabs(a-b)<EPS)
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

#define LL long long
LL a[100004];
LL ans=0;
void Merge(LL left_begin,LL left_end,LL right_begin,LL right_end)
{
    LL pos=0,pp=left_begin;
    LL temp[right_end-left_begin+3];
    while(left_begin<=left_end&&right_begin<=right_end)
    {
        if(a[left_begin]<=a[right_begin])
            temp[pos++]=a[left_begin++];
        else
        {
            ans=ans+(left_end-left_begin+1);
            temp[pos++]=a[right_begin++];
        }
    }
    while(left_begin<=left_end) temp[pos++]=a[left_begin++];
    while(right_begin<=right_end) temp[pos++]=a[right_begin++];
    for(LL i=0;i<pos;i++)
        a[pp+i]=temp[i];
    return;
}

void MergeSort(LL left,LL right)
{
    LL mid=(left+right)>>1;
    if(left<right)
    {
        MergeSort(left,mid);
        MergeSort(mid+1,right);
//        printf("%lld %lld %lld %lld\n",left+1,mid+1,a[left],a[mid]);
//        printf("%lld %lld %lld %lld\n",mid+2,right+1,a[mid+1],a[right]);
        Merge(left,mid,mid+1,right);
//        debug(left,right)
    }
    printf("%lld %lld %lld %lld\n",left+1, right+1, a[left], a[right]);
}

void mergesort(ll arr[], ll w[], ll s, ll t)
{
    debug(s,t)
    if(s+1==t) return;
    ll m = (s+t)/2;
    mergesort(arr,w,s,m);
    mergesort(arr,w,m,t);
    ll i = s, j = m, k =s;
    while(i<m || j<t)
    {
        debug(i,j,m,t)
        if(j==t || (i<m && arr[i]<=arr[j]))
        {
            w[t] = arr[i];i++;t++;
        }
        else
        {
            w[t]=arr[j];j++;t++;
        }
    }
    FOR(i,s,t)
    {
        arr[i]=w[i];
    }

    printf("%lld %lld %lld %lld\n",s+1,t+1,arr[s],arr[t]);
}

int main() {
//    #ifdef dipta007
        READ("sort.in");
        WRITE("sort.out");
////    #endif // dipta007

    int n;
    while(~getI(n))
    {
        FOR(i,0,n-1)
        {
            getL(a[i]);
        }
        MergeSort(0,n-1);
        FOR(i,0,n-1)
        {
            if(i!=0) printf(" ");
            printf("%d",a[i]);
        }
        puts("");
    }

    return 0;
}




