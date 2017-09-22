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


#define mx 300004
int arr[mx];
struct info
{
    vi val,mini;
} tree[mx*4];

int getMin(int node)
{
    int tmp = tree[node].mini.size();
    if(tmp) return tree[node].mini.back();
    return INF;
}

int query(int node,int b,int e,int pos, int res=INF) ///range i theke j
{
    res = min(getMin(node), res);
    if(b>=pos && e<=pos)
    {
        return res;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    if(pos<=mid) return query(Left,b,mid,pos,res);
    else return query(Right,mid+1,e,pos,res);
}

void update(int node,int b,int e,int i,int j, int newVal)
{
    if (i > e || j < b)	return;
    if (b >= i && e <= j)
    {
        tree[node].val.PB(newVal);
        tree[node].mini.PB(min(getMin(node), newVal));
        return;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    update(Left,b,mid,i,j,newVal);
    update(Right,mid+1,e,i,j,newVal);
}

void rollBack(int node,int b,int e,int i,int j)
{
    if (i > e || j < b)	return;
    if (b >= i && e <= j)
    {
        tree[node].val.pop_back();
        tree[node].mini.pop_back();
        return;
    }
    int Left=node<<1;
    int Right=(node<<1)+1;
    int mid=(b+e)>>1;
    rollBack(Left,b,mid,i,j);
    rollBack(Right,mid+1,e,i,j);
}



int main()
{
    READ("invazia.in");
    WRITE("invazia.out");
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    while(cin >> n >> m)
    {
        char ch;
        stack < pii > st;
        FOR(i,1,m)
        {
            cin >> ch;
            switch(ch)
            {
            case 'I':
                int l,r,v;
                cin >> l >> r >> v;
                st.push(pii(l,r));
                update(1,1,n,l,r,v);
                break;
            case 'E':
                l = st.top().ff;
                r = st.top().ss;
                st.pop();
                rollBack(1,1,n,l,r);
                break;
            case 'R':
                int pos;
                cin >> pos;
                int res = query(1,1,n,pos);
                if(res==INF)
                {
                    printf("GUITZZZ!\n");
                }
                else printf("%d\n",res);
                break;
            }
        }
    }

    return 0;
}


