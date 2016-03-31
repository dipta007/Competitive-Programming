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
long long int arr[mx];

//int tree[sizetree];

void init(long long int node,long long int b,long long int e,long long int tree[])
{
	if(b==e)
	{
		tree[node]=arr[b];
		return;
	}
	long long int Left=node*2;
	long long int Right=node*2+1;
	long long int mid=(b+e)/2;
	init(Left,b,mid,tree);
	init(Right,mid+1,e,tree);
	tree[node]=tree[Left]+tree[Right];
}
long long int query(long long int node,long long int b,long long int e,long long int i,long long int j,long long int tree[])
{
	if (i > e || j < b)	return 0; //বাইরে চলে গিয়েছে
	if (b >= i && e <= j) return tree[node]; //রিলেভেন্ট সেগমেন্ট
	long long int Left=node*2;  //আরো ভাঙতে হবে
	long long int Right=node*2+1;
	long long int mid=(b+e)/2;
	long long int p1=query(Left,b,mid,i,j,tree);
	long long int p2=query(Right,mid+1,e,i,j,tree);
	return p1+p2; //বাম এবং ডান পাশের যোগফল
}
//void update(int node,int b,int e,int i,int newvalue)
//{
//	if (i > e || i < b)	return; //বাইরে চলে গিয়েছে
//	if (b >= i && e <= i) { //রিলেভেন্ট সেগমেন্ট
//		tree[node]=newvalue;
//		return;
//	}
//	int Left=node*2;  //আরো ভাঙতে হবে
//	int Right=node*2+1;
//	int mid=(b+e)/2;
//	update(Left,b,mid,i,newvalue);
//	update(Right,mid+1,e,i,newvalue);
//	tree[node]=tree[Left]+tree[Right];
//}
int main()
{
	READ("in.txt");
	long long int n;
	while(~scanf("%I64d",&n))
    {
        CLR(arr);
        for(long long int i=1;i<=n;i++)
        {
            scanf("%I64d",&arr[i]);
        }
        long long int nt[n*3];
        init(1,1,n,nt);
        sort(arr,arr+n+1);
        long long int st[n*3];
        init(1,1,n,st);
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
                cout << "1 ";
                printf("%I64d\n",query(1,1,n,u,v,nt));
            }
            else
            {
                cout << "2 ";
                scanf("%I64d %I64d",&u,&v);
                printf("%I64d\n",query(1,1,n,u,v,st));
            }
        }
    }
	return 0;
}
