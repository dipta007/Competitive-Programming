#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
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

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

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
int t,n,m;

#define mx 100001
int arr[mx];
struct info
{
    int a[3];
    int prop;
}tree[mx*4];

info call(info a,info b)
{
    info tmp;
    ///merge two info
    FOR(i,0,2)
    {
        tmp.a[i] = a.a[i] + b.a[i];
    }
    tmp.prop = 0;
    return tmp;
}

void init(int node,int b,int e)
{
	if(b==e)
	{
	    FOR(i,0,2) tree[node].a[i] = 0;
	    tree[node].a[0] = 1;
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
	int prop = tree[node].prop % 3;
	tree[Left].prop += tree[node].prop;
	tree[Left].prop %= 3;
	tree[Right].prop += tree[node].prop;
	tree[Right].prop %= 3;
    tree[node].prop=0;
    ///update tree[left].sum
    if(prop == 1)
    {
        int a[3];
        for(int i=1,k=1;k<=3; k++, i=(i+1)%3)
        {
            a[k-1] = tree[Left].a[i];
        }
        FOR(i,0,2)
        {
            tree[Left].a[i] = a[i];
        }
    }
    else if(prop == 2)
    {
        int a[3];
        for(int i=2,k=1;k<=3; k++, i=(i+1)%3)
        {
            a[k-1] = tree[Left].a[i];
        }
        FOR(i,0,2)
        {
            tree[Left].a[i] = a[i];
        }
    }
    ///update tree[right].sum
    if(prop == 1)
    {
        int a[3];
        for(int i=1,k=1;k<=3; k++, i=(i+1)%3)
        {
            a[k-1] = tree[Right].a[i];
        }
        FOR(i,0,2)
        {
            tree[Right].a[i] = a[i];
        }
    }
    else if(prop == 2)
    {
        int a[3];
        for(int i=2,k=1;k<=3; k++, i=(i+1)%3)
        {
            a[k-1] = tree[Right].a[i];
        }
        FOR(i,0,2)
        {
            tree[Right].a[i] = a[i];
        }
    }
}

int query(int node,int b,int e,int i,int j) ///range i theke j
{
	if (i > e || j < b)return 0;
	if(tree[node].prop)propagate(node,b,e);
	if(b>=i && e<=j)
    {
        ///do something
        return tree[node].a[0];
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
    int p1 = query(Left,b,mid,i,j);
    int p2 = query(Right,mid+1,e,i,j);
    return  p1+p2;

}

void update(int node,int b,int e,int i,int j, int newVal=0)
{
	if(tree[node].prop)propagate(node,b,e);
	if (i > e || j < b)	return;
	if (b >= i && e <= j)
    {
        int a[3];
        for(int i=1,k=1;k<=3; k++, i=(i+1)%3)
        {
            a[k-1] = tree[node].a[i];
        }
        FOR(i,0,2)
        {
            tree[node].a[i] = a[i];
        }
        tree[node].prop += 1;
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
//        WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n,q;
        getII(n,q);
        init(1,0,n-1);
        printf("Case %d:\n",ci);
        FOR(i,1,q)
        {
            int t,x,y;
            getIII(t,x,y);
            if(t==0)
            {
                update(1, 0, n-1, x, y);
            }
            else
            {
                printf("%d\n", query(1,0,n-1, x, y));
            }
        }
    }

    return 0;
}



