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

#define mx 100001
int arr[mx];
struct info
{
    ll sum;
    ll prop;
    bool flg;
}tree[mx*4];

info call(info a,info b)
{
    info tmp;
    ///merge two info
    tmp.prop=0;
    tmp.flg=0;
    tmp.sum = (a.sum+b.sum);
    return tmp;
}

void init(int node,int b,int e)
{
	if(b==e)
	{
	    ///do something
	    tree[node].sum=0;
	    tree[node].prop=0;
	    tree[node].flg=0;
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
        tree[node].flg=0;
        return;
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	int prop = tree[node].prop;
	///update propagation
	tree[Left].prop = tree[node].prop;
	tree[Left].flg=1;
	tree[Right].prop = tree[node].prop;
	tree[Right].flg=1;
    tree[node].prop=0;
    tree[node].flg=0;
    ///update tree[left].sum
    tree[Left].sum = (mid-b+1)*prop;
    ///update tree[right]
    tree[Right].sum = (e-mid)*prop;
}

ll query(int node,int b,int e,int i,int j) ///range i theke j
{
	if (i > e || j < b)return 0;
	if(tree[node].flg)propagate(node,b,e);
	if(b>=i && e<=j)
    {
        ///do something
        return tree[node].sum;
    }
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
    ll p1 = query(Left,b,mid,i,j);
    ll p2 = query(Right,mid+1,e,i,j);
    return  p1+p2;

}

int val;
void update(int node,int b,int e,int i,int j)
{
	if(tree[node].flg)propagate(node,b,e);
	if (i > e || j < b)	return;
	if (b >= i && e <= j)
    {
        ///do something
        tree[node].flg=1;
        tree[node].prop=val;
        tree[node].sum = (e-b+1) * val;
		return;
	}
	int Left=node*2;
	int Right=(node*2)+1;
	int mid=(b+e)/2;
	update(Left,b,mid,i,j);
	update(Right,mid+1,e,i,j);
	tree[node]=call(tree[Left],tree[Right]);
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int t;
    getI(t);
    FOR(ci,1,t)
    {
        int n,q;
        getII(n,q);
        init(1,1,n);
        printf("Case %d:\n",ci);
        FOR(i,1,q)
        {
            int t;
            getI(t);
            if(t==1)
            {
                int x,y,v;
                getIII(x,y,v);
                x++,y++;
                val=v;
                update(1,1,n,x,y);
            }
            else
            {
                int x,y;
                getII(x,y);
                x++,y++;
                ll qq = query(1,1,n,x,y);
                ll ww = (y-x+1);
                ll g = gcd(qq,ww);
                while(g!=1)
                {
                    qq/=g;
                    ww/=g;
                    g=gcd(qq,ww);
                }
                if(ww==1) printf("%lld\n",qq);
                else printf("%lld/%lld\n",qq,ww);
            }
        }
    }

    return 0;
}



