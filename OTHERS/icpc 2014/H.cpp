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


int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        int n;
        getI(n);
        int a[n];
        int mark[162];
        CLR(mark);
        double diff=(double)n/4.0;
        for(int i=0;i<n;i++)
        {
            getI(a[i]);
            mark[a[i]]++;
        }
        if(n==1)
        {
            printf("Case %d: 0 0 %d\n",ci,a[0]);
            continue;
        }
        if(n==2)
        {
            printf("Case %d: 0 %d %d\n",ci,a[0],a[1]);
            continue;
        }
        if(n==3)
        {
            printf("Case %d: %d %d %d\n",a[0],a[1],a[2]);
            continue;
        }
        sort(a,a+n);
        for(int i=1;i<=160;i++)
        {
            mark[i]=mark[i]+mark[i-1];
        }
        double mini=1000000.0;
        int r1,r2,r3,r4;
        for(int i=0;i<=160;i++)
        {
            for(int j=i+1;j<=160;j++)
            {
                for(int k=j+1;k<=160;k++)
                {
                    int c1=mark[i];
                    int c2=mark[j]-c1;
                    int c3=mark[k]-c1-c2;
                    int c4=n-c1-c2-c3;
                    double res=_abs(diff-(double)c1)+_abs(diff-(double)c2)+_abs(diff-(double)c3)+_abs(diff-(double)c4);
                    if(res+EPS<mini)
                    {
                        r1=c1;r2=c2;r3=c3;r4=c4;
                        mini=res;
                    }
                }
            }
        }
        printf("Case %d: %d %d %d\n",ci,a[r1-1],a[r1+r2-1],a[r1+r2+r3-1]);

    }

    return 0;
}

