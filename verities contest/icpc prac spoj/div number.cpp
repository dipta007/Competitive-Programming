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
#define    getC(n)           scanf("%c",&n)
#define    getL(n)           scanf("%lld",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)

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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }



// jodi proti ber 1 ta value update korte hoi dn eita use kora better

#define mx 100001
int arr[mx];

struct data
{
    int val;
    int a[1001];
    void wer()
    {
        CLR(a);
    }
};

data tree[mx*3+4];

void init(int node,int b,int e)
{
	if(b==e)
	{
	    for(int i=1;i<=1000;i++)
        {
            if(arr[b]%i==0)
            {
                tree[node].a[i]=arr[b];
            }
        }
//		tree[node]=arr[b];
		return;
	}
	int Left=node*2;
	int Right=node*2+1;
	int mid=(b+e)/2;
	init(Left,b,mid);
	init(Right,mid+1,e);
	for(int i=1;i<=1000;i++)
    {
        tree[node].a[i]=tree[Left].a[i]+tree[Right].a[i];
    }
//	tree[node]=tree[Left]+tree[Right];
}
int query(int node,int b,int e,int i,int j,int x)
{
	if (i > e || j < b)	return 0; //বাইরে চলে গিয়েছে
	if (b >= i && e <= j) return tree[node].a[x]; //রিলেভেন্ট সেগমেন্ট
	int Left=node*2;  //আরো ভাঙতে হবে
	int Right=node*2+1;
	int mid=(b+e)/2;
	int p1=query(Left,b,mid,i,j,x);
	int p2=query(Right,mid+1,e,i,j,x);
	return p1+p2; //বাম এবং ডান পাশের যোগফল
}



int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        printf("Case #%d\n",ci);

        int n,m;
        getII(n,m);
        for(int i=0;i<3*n;i++)
            CLR(tree[i].a);
        for(int i=1;i<=n;i++)
            getI(arr[i]);
        init(1,1,n);
        for(int i=1;i<=m;i++)
        {
            int v,x,y;
            getIII(v,x,y);
            printf("%d\n",query(1,1,n,x,y,v));
        }
        if(ci<t) printf("\n");
    }

    return 0;
}


//int main()
//{
//	READ("in");
//	int n;
//	cin>>n;
//	repl(i,n)
//		cin>>arr[i];
//	init(1,1,n);
//
//	update(1,1,n,2,0);
//	cout<<query(1,1,n,1,3)<<endl;
//	update(1,1,n,2,2);
//	cout<<query(1,1,n,2,2)<<endl;
//	return 0;
//}
