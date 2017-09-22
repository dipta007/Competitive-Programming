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


#define MAX 2000004
int arr[MAX];


int tree[MAX*4];

void init(int node,int b,int e)
{
	if(b==e)
	{
		tree[node]=arr[b];
		return;
	}
	int Left= node << 1;
	int Right= (node << 1) +1;
	int mid=(b+e)>>1;
	init(Left,b,mid);
	init(Right,mid+1,e);
	tree[node]=tree[Left]+tree[Right];
}
int query(int node,int b,int e,int i, int j)
{
    //debug(node,b,e,i,j)
//	if (i > e || j < b)	return 0;
	if (b==e) return b;
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;
    //debug(tree[Left],tree[Right])
	int p;
	if(i<=tree[Left])
    {
        p = query(Left,b,mid,i,j);
    }
    else
    {
        i -= tree[Left];
        p = query(Right, mid+1, e, i, i);
    }
	return p;
}
void update(int node,int b,int e,int i,int newvalue)
{
	//if (i > e || i < b)	return;
	if (b ==e) {
		tree[node]=0;
		return;
	}
	int Left=node<<1;
	int Right=(node<<1)+1;
	int mid=(b+e)>>1;

	if(i<=tree[Left])
    {
        update(Left,b,mid,i,newvalue);
    }
    else
    {
        i -= tree[Left];
        update(Right,mid+1, e, i, newvalue);
    }
	tree[node]=tree[Left]+tree[Right];
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("in.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    FOR(i,1,MAX-4)
    {
        arr[i] = (int)(i%2);
    }
    init(1,1,MAX-4);

    int now = 2;
    int cnt=0;
    while(1)
    {
        cnt++;
        int tmp = query(1,1,MAX-4,now,now);
        if(tmp>=1429431) break;
        now++;

        int biog = 0;
        for(int i=tmp; i<=1429431; i+= tmp)
        {
            int up = i - biog;
            update(1,1,MAX-4, up, 0);
            biog++;
        }
    }

    vi lucky;
    for(int i=1;;i++)
    {
        int kk = query(1,1,MAX-4,i,i);
//        debug("l",kk);
        lucky.PB(kk);
        if(kk>=1429431) break;
    }
    FOR(i,0,20)
    {
        debug(lucky[i])
    }
    debug(lucky[lucky.size()-1],lucky.size())

    int t,n;
    getI(t);
    FOR(ci,1,t)
    {
        getI(n);
        printf("Case %d: %d\n",ci, lucky[n-1]);
    }

    return 0;
}



