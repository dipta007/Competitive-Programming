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

#define MAX 100004
//int arr[MAX];
char st[100004];


pii tree[MAX*4];

pii jog(pii a, pii b)
{
    pii tmp;
    tmp.ff = a.ff + b.ff;
    tmp.ss = a.ss + b.ss;
    return tmp;
}


void init(int node,int b,int e)
{
	if(b==e)
	{
		tree[node].ff=(st[b]=='(');
		tree[node].ss=(st[b]==')');
		return;
	}
	int Left= node << 1;
	int Right= (node << 1) +1;
	int mid=(b+e)>>1;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=jog(tree[Left],tree[Right]);
}

pii query(int node,int b,int e,int i,int j)
{
	if (i > e || j < b)	return MP(0,0);
	if (b >= i && e <= j) return tree[node];
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	pii p1=query(Left,b,mid,i,j);
	pii p2=query(Right,mid+1,e,i,j);
	return jog(p1,p2);
}
void update(int node,int b,int e,int i,int newvalue=0)
{
	if (i > e || i < b)	return;
	if (b >= i && e <= i) {
        int tmp = tree[node].ff;
		tree[node].ff = tree[node].ss;
		tree[node].ss = tmp;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
	update(Left,b,mid,i,newvalue);
	update(Right,mid+1,e,i,newvalue);
	tree[node]=jog(tree[Left],tree[Right]);
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
        getchar();
        scanf("%s",st);
        int len = strlen(st)-1;
        init(1,0,len);
        int q;
        getI(q);
        printf("Case %d:\n",ci);
        FOR(i,1,q)
        {
            int tt;
            getI(tt);
            if(tt==1)
            {
                int x,y;
                getII(x,y);
                pii p = query(1,0,len, x-1, y-1);
//                debug(p.ff, p.ss)
                if(p.ff == p.ss) printf("YES\n");
                else printf("NO\n");
            }
            else
            {
                int x;
                getI(x);
                update(1,0,len,x-1,x-1);
            }
        }
    }


    return 0;
}



