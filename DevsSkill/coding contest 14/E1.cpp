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
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< ll, ll >
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

const long long mod[2] = {1000000007LL, 2117566807LL};
const long long base[3] = {1572872831LL, 1971536491LL};

#define mx 100004
ll arr[mx];
ll power[mx];
ll oneArr[mx];

void calcPower()
{
    power[0]=1;
    FOR(i,1,mx-1)
    {
        power[i] = (power[i-1] * base[0]) % mod[0];
    }
    oneArr[0]=0;
    FOR(i,1,mx-1)
    {
        oneArr[i] = ((oneArr[i-1] * base[0]) + 1) %mod[0];
    }
}

pii extendedEuclid(int a, int b)   // returns x, y jekhane, ax + by = gcd(a,b)
{
    if(b == 0)
        return pii(1, 0);
    else
    {
        pii d = extendedEuclid(b, a % b);
        return pii(d.ss, d.ff - d.ss * (a / b));
    }
}


ll modularInverse(int a, int n)   	// returns a er modular Inverse ; n dara mod kore
{
    pii ret = extendedEuclid(a, n);
    return ((ret.ff % n) + n) % n;
}


struct info
{
    ll sum;
    int ones;
    ll prop;
} tree[mx*4];

info call(info a,info b)
{
    info tmp;
    tmp.ones = a.ones + b.ones;
    tmp.sum = a.sum + b.sum;
    return tmp;
}

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum = arr[b];
        tree[node].ones = (int)(arr[b]>0);
        tree[node].prop = 0;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=call(tree[Left],tree[Right]);
    tree[node].prop = tree[Left].prop + tree[Right].prop;
}
void propagate(int node,int b,int e, int x)
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
    ll tmp = tree[Left].prop;
    tree[Left].prop=tree[node].prop;
    tree[Right].prop=tree[node].prop;
    tree[node].prop=0;
    ///update tree[left]
    if(x==1)
    {
        int len = mid-b+1;
        ll koto = power[b-1];
        ll now= 0;
        now = oneArr[len];
        ll hbe = (now * koto) %mod[0];
        ll ase = tree[Left].sum;
        tree[Left].sum = hbe;
        tree[Left].ones = len;
        tree[Left].prop = 1;
        ///update tree[right]
        len = e - mid -1 + 1;
        koto = power[mid];
        now = oneArr[len];
        hbe = (now * koto) %mod[0];
        ase = tree[Right].sum;
        tree[Right].sum = hbe;
        tree[Right].ones = len;
        tree[Right].prop = 1;
    }
    else
    {
        tree[Left].sum = 0;
        tree[Left].ones = 0;
        tree[Right].sum = 0;
        tree[Right].ones = 0;
    }
}


ll query(int node,int b,int e,int i,int j)
{
    if (i > e || j < b)return 0;
    if(tree[node].prop!=0)propagate(node,b,e, tree[node].prop);
    if(b>=i && e<=j)
    {
        ll koto = tree[node].sum;
        debug(b,e, i,j,koto)
        return koto;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    ll p1 = query(Left,b,mid,i,j);
    ll p2 = query(Right,mid+1,e,i,j);
    return  (p1+p2)%mod[0];
}

ll query1(int node,int b,int e,int i,int j)
{
    if (i > e || j < b)return 0;
    if(tree[node].prop!=0)propagate(node,b,e, tree[node].prop);
    if(b>=i && e<=j)
    {
        ll koto = tree[node].ones;
        return koto;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    ll p1 = query(Left,b,mid,i,j);
    ll p2 = query(Right,mid+1,e,i,j);
    return  (p1+p2);
}

void update(int node,int b,int e,int i,int j, int x)
{
    if(tree[node].prop!=0)propagate(node,b,e, tree[node].prop);
    if (i > e || j < b)	return;
    if (b >= i && e <= j)
    {
        if(x==0)
        {
            ll tmp = tree[node].sum;
            tree[node].sum = 0;
            tree[node].ones = 0;
            tree[node].prop = 2;
        }
        else
        {
            int len = e-b+1;
            ll koto = power[b-1];

            ll now = oneArr[len];
            ll hbe = (koto * now) %mod[0];
            ll ase = tree[node].sum;

            debug(b,e,i,j,koto, now)
            tree[node].sum = hbe;
            tree[node].ones = len;
            tree[node].prop=1;
        }
        return;
    }
    int Left=node*2;
    int Right=(node*2)+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,j,x);
    update(Right,mid+1,e,i,j,x);
    tree[node]=call(tree[Left],tree[Right]);
    tree[node].prop = 0;
}

void update1(int node,int b,int e,int i,int j)
{
    if(tree[node].prop!=0)propagate(node,b,e, tree[node].prop);
    if (i > e || j < b)	return;
    if (b >= i && e <= j)
    {
        if(tree[node].ones>0)
        {
            tree[node].sum = 0;
            tree[node].ones = 0;
            tree[node].prop = 0;
        }
        else
        {
            tree[node].sum = power[b-1];
            debug(power[b-1])
            tree[node].ones = 1;
            tree[node].prop = 0;
        }
        return;
    }
    int Left=node*2;
    int Right=(node*2)+1;
    int mid=(b+e)/2;
    update1(Left,b,mid,i,j);
    update1(Right,mid+1,e,i,j);
    tree[node]=call(tree[Left],tree[Right]);
    tree[node].prop = 0;
}

int main()
{
#ifdef dipta007
    //READ("in.txt");
    //WRITE("out.txt");
#endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    string player[] = {"Alice", "Bob"};
    calcPower();
    FOR(ci,1,t)
    {
        getchar();
        string st;
        getline(cin,st);
        int len = st.size();
        ll c = 1;
        int pos = 0;
        arr[0]=0;
        FOR(i,0,len-1)
        {
            int kk = st[i]-'0';
            if(kk) arr[i+1] = power[i];
            else arr[i+1] = 0;
        }
        init(1,1,len);
//        debug("1pos", arr[1], tree[16].sum)
//        debug(query(1,1,len, 1,1))
        int q;
        getI(q);
        FOR(i,1,q)
        {
            debug("main ", tree[1].prop)
            int t;
            getI(t);
            if(t==1)
            {
                int x,y,z;
                getIII(x,y,z);
                update(1,1,len, x, y, z);
            }
            else if(t==2)
            {
                int x;
                getI(x);
                update1(1,1,len, x, x);
            }
            else if(t==3)
            {
                int x;
                getI(x);
                ll val = query1(1, 1, len, x, x);
                //debug(val, base[0])
                if(val>0) printf("%s 1\n",player[pos].c_str());
                else printf("%s 0\n",player[pos].c_str());
            }
            else
            {
                int x,y,z;
                getIII(x,y,z);
                if(x+z-1>len || y+z-1>len)
                {
                    printf("%s loses\n",player[pos].c_str());
                    pos = (pos + 1) % 2;
                    continue;
                }
                ll bam = query(1,1,len,x,x+z-1);
                ll dan = query(1,1,len,y,y+z-1);
                debug(bam, dan)
                ll vag = power[x-1];
                vag = modularInverse(vag, mod[0]);
                bam = (bam * vag)%mod[0];

                vag = power[y-1];
                vag = modularInverse(vag, mod[0]);
                dan = (dan * vag) % mod[0];

                debug(bam, dan)
                if(bam==dan) printf("%s wins\n",player[pos].c_str());
                else printf("%s loses\n",player[pos].c_str());
            }
            pos = (pos + 1) % 2;
        }
    }

    return 0;
}




