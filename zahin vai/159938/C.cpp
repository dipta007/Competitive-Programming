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

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef dipta007
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;



#define M 1000000
bool marked[M];
vector <int> primes;

void sieve(int n)
{
    primes.push_back(2);
    for (int i = 3; i * i <= n; i += 2)
    {
        if (marked[i] == 0)
        {
            for (int j = i * i; j <= n; j += i + i)
            {
                marked[j] = 1;
            }
        }
    }
    FOR(i,3,n)
    {
        if(marked[i]==0) primes.PB(i);
        i++;
    }
}


#define mx 100001
int arr[40][mx];
struct info
{
    ll pwr;
    ll prop;
} tree[36][mx*4];

info call(info a,info b)
{
    info tmp;
    tmp.pwr = a.pwr + b.pwr;
    tmp.prop = 0;
    return tmp;
}

void init(int in,int node,int b,int e)
{
    if(b==e)
    {
        tree[in][node].pwr = arr[in][b];
        tree[in][node].prop = 0;
        return;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    init(in,Left,b,mid);
    init(in,Right,mid+1,e);
    tree[in][node]=call(tree[in][Left],tree[in][Right]);
}

void propagate(int in, int node,int b,int e)
{
    if(b==e)
    {
        tree[in][node].prop=0;
        return;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    ///update propagation
    ll prop = tree[in][node].prop;
    tree[in][Left].prop += tree[in][node].prop;
    tree[in][Right].prop += tree[in][node].prop;
    tree[in][node].prop=0;
    ///update tree[in][left].sum
    tree[in][Left].pwr += (mid-b+1)*prop;
    ///update tree[in][right].sum
    tree[in][Right].pwr += (e-mid)*prop;
}

ll query(int in, int node,int b,int e,int i,int j) ///range i theke j
{
    if (i > e || j < b)return 0;
    if(tree[in][node].prop!=0)propagate(in,node,b,e);
    if(b>=i && e<=j)
    {
        return tree[in][node].pwr;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    ll p1 = query(in,Left,b,mid,i,j);
    ll p2 = query(in,Right,mid+1,e,i,j);
    return  p1+p2;
}

void updateMul(int in, int node,int b,int e,int i,int j, ll newVal)
{
    if(tree[in][node].prop!=0)propagate(in,node,b,e);
    if (i > e || j < b)	return;
    if (b >= i && e <= j)
    {
        tree[in][node].pwr += (ll)(e-b+1) * newVal;
        tree[in][node].prop += newVal;
        return;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    updateMul(in,Left,b,mid,i,j,newVal);
    updateMul(in,Right,mid+1,e,i,j,newVal);
    tree[in][node]=call(tree[in][Left],tree[in][Right]);
}
void updateDiv(int in, int node,int b,int e,int i,int j, int newVal)
{
    if(tree[in][node].prop!=0)propagate(in,node,b,e);
    if (i > e || j < b)	return;
    if (b >= i && e <= j)
    {
        tree[in][node].pwr -= (ll)(e-b+1)*newVal;
        tree[in][node].prop -= newVal;
        return;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    updateDiv(in,Left,b,mid,i,j,newVal);
    updateDiv(in,Right,mid+1,e,i,j,newVal);
    tree[in][node]=call(tree[in][Left],tree[in][Right]);
}

ll bigmod ( ll b, ll p, ll m )
{
    ll res = 1 % m, x = b % m;
    while ( p )
    {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}

int main()
{
#ifdef dipta007
    READ("in.txt");
//        WRITE("in.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    sieve(150);
    int n,q;
    int t;
    getI(t);
    FOR(ci,1,t)
    {
        getII(n,q);
        FOR(i,1,n)
        {
            FOR(j,0,(int)primes.size()-1)
            {
                int cnt=0;
                int x = 1;
                while(x%primes[j]==0)
                {
                    x/= primes[j];
                    cnt++;
                }
                arr[j][i] = cnt;
            }
        }
        FOR(i,0,(int)primes.size()-1)
        {
            init(i,1,1,n);
        }

        FOR(i,1,q)
        {
            int tt;
            getI(tt);
            int l,r,x;
            getIII(l,r,x);
            if(tt==0)
            {
                if(l<=r)
                {
                    ll res = 1;
                    FOR(i,0,(int)primes.size()-1)
                    {
                        ll bb = primes[i];
                        ll ee = query(i, 1, 1, n, l, r);
                        //debug(bb,ee)
                        res = (res * bigmod(bb, ee, x)) % x;
                    }
                    printf("%lld\n",res);
                }
                else
                {
                    ll res = 1;
                    FOR(i,0,(int)primes.size()-1)
                    {
                        ll bb = primes[i];
                        ll ee = query(i, 1, 1, n, l, n) + query(i,1,1,n,1,r);
                        //debug(bb,ee)
                        res = (res * bigmod(bb, ee, x)) % x;
                    }
                    printf("%lld\n",res);
                }
            }
            else if(tt==1)
            {
                FOR(i,0,(int)primes.size()-1)
                {
                    int cnt = 0;
                    while(x%primes[i]==0)
                    {
                        x/=primes[i];
                        cnt++;
                    }
                    if(l<=r && cnt>0) updateMul(i, 1, 1, n, l, r, cnt);
                    else if(cnt>0)
                    {
                        updateMul(i,1,1,n,l,n,cnt);
                        updateMul(i,1,1,n,1,r,cnt);
                    }
                }
            }
            else
            {
                FOR(i,0,(int)primes.size()-1)
                {
                    int cnt = 0;
                    while(x%primes[i]==0)
                    {
                        x/=primes[i];
                        cnt++;
                    }
                    if(l<=r && cnt>0) updateDiv(i, 1, 1, n, l, r, cnt);
                    else if(cnt>0)
                    {
                        updateDiv(i,1,1,n,1,r,cnt);
                        updateDiv(i,1,1,n,l,n,cnt);
                    }
                }
            }
        }
    }


    return 0;
}



