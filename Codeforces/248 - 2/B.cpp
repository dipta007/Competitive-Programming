#include <algorithm>
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
#define    SZ(c) 	         (int)c.size()
#define    PB(x)             push_back(x)

#define    F(i,L,R)	         for (int i = L; i < R; i++)
#define    FF(i,L,R) 	     for (int i = L; i <= R; i++)
#define    FR(i,L,R) 	     for (int i = L; i > R; i--)
#define    FRF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()

#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    CPY(d, s)         memcpy(d, s, sizeof(s))

#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)

#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    psi 	 pair< string, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long
#define    ui    unsigned int
#define    us 	 unsigned short
#define    ld 	 long double

#define    debug(a)     { cout << a <<endl; }
#define    debugI()     { cout << "*" <<endl; }
#define    debugII()    { cout << "**" <<endl; }
#define    debugIII()   { cout << "***" <<endl; }

template< class T > inline T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > inline T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > inline T _min(T a, T b) { return (a < b ? a : b); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template< class T > inline T lcm(T a, T b) { return (a / gcd(a, b) * b); }
const int MaxMatrixSize=40;
template< class T > inline void showMatrix(int n,T A[][MaxMatrixSize])
  {for (int i=0;i<n;i++){for (int j=0;j<n;j++)cout<<A[i][j]<<" ";cout<<endl;}}


// jodi proti ber 1 ta value update korte hoi dn eita use kora better

#define mx 100001
long long int arr[mx],arre[mx],nt[mx*4],st[mx*4];

//int tree[sizetree];

void init(long long int node,long long int b,long long int e)
{
	if(b==e)
	{
		nt[node]=arr[b];
		return;
	}
	long long int Left=node*2;
	long long int Right=node*2+1;
	long long int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	nt[node]=nt[Left]+nt[Right];
}
long long int query(long long int node,long long int b,long long int e,long long int i,long long int j)
{
	if (i > e || j < b)	return 0; //বাইরে চলে গিয়েছে
	if (b >= i && e <= j) return nt[node]; //রিলেভেন্ট সেগমেন্ট
	long long int Left=node*2;  //আরো ভাঙতে হবে
	long long int Right=node*2+1;
	long long int mid=(b+e)/2;
	long long int p1=query(Left,b,mid,i,j);
	long long int p2=query(Right,mid+1,e,i,j);
	return p1+p2; //বাম এবং ডান পাশের যোগফল
}

void sinit(long long int node,long long int b,long long int e)
{
	if(b==e)
	{
		st[node]=arre[b];
		return;
	}
	long long int Left=node*2;
	long long int Right=node*2+1;
	long long int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	st[node]=st[Left]+st[Right];
}
long long int squery(long long int node,long long int b,long long int e,long long int i,long long int j)
{
	if (i > e || j < b)	return 0; //বাইরে চলে গিয়েছে
	if (b >= i && e <= j) return st[node]; //রিলেভেন্ট সেগমেন্ট
	long long int Left=node*2;  //আরো ভাঙতে হবে
	long long int Right=node*2+1;
	long long int mid=(b+e)/2;
	long long int p1=query(Left,b,mid,i,j);
	long long int p2=query(Right,mid+1,e,i,j);
	return p1+p2; //বাম এবং ডান পাশের যোগফল
}

int main()
{
	//READ("in.txt");
	long long int n;
	while(~scanf("%I64d",&n))
    {
        CLR(arr);
        CLR(st);
        CLR(nt);
        for(long long int i=1;i<=n;i++)
        {
            scanf("%I64d",&arr[i]);
            arre[i]=arr[i];
        }

        init(1,1,n);
        sort(arre,arre+n+1);
        sinit(1,1,n);
        long long int qu;
        scanf("%I64d",&qu);
        for(long long int j=1;j<=qu;j++)
        {
            long long int k;
            scanf("%I64d",&k);
            long long int u,v;
            if(k==1)
            {
                scanf("%I64d %I64d",&u,&v);
                printf("%I64d\n",query(1,1,n,u,v));
            }
            else
            {
                scanf("%I64d %I64d",&u,&v);
                printf("%I64d\n",squery(1,1,n,u,v));
            }
        }
    }
	return 0;
}
