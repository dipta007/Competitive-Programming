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
#define    getII(a,b) 	     scanf("%d %d", &a, &b)
#define    getIII(a,b,c)     scanf("%d %d %d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld %lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
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


template< class T > inline T _abs(T n) { return ( (n) < 0 ? -(n) : (n) ); }
template< class T > inline T _max(T a, T b) { return ( ! ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _min(T a, T b) { return ( ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _swap(T &a, T &b) { T temp=a;a=b;b=temp;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd( (b), ( (a) % (b) ) ) ; }
template< class T > inline T lcm(T a, T b) { return ( (a) / gcd( (a), (b) ) * (b) ); }


//******************DELETE****************
#define shubhashis
#ifdef shubhashis
     #define debug(args...) {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
//******************DELETE****************

int a[100004][4];
bool dp[100004][4];
int n;

int call(int r,int c)
{
    if(r>=n-1) return 0;
    if(c>=3) return 0;
    if(dp[r][c]!=0) return a[r][c];

    int p1=INF,p2=INF,p3=INF,p4=INF;
    if(c==0)
    {
        p1=a[r][c]+call(r,c+1);
        p2=a[r][c]+call(r+1,c);
        p3=a[r][c]+call(r+1,c+1);
    }
    else if(c==1)
    {
        p1=a[r][c]+call(r+1,c-1);
        p2=a[r][c]+call(r+1,c);
        p3=a[r][c]+call(r+1,c+1);
        p4=a[r][c]+call(r,c+1);
    }
    else
    {
        p1=a[r][c]+call(r+1,c-1);
        p2=a[r][c]+call(r+1,c);
    }
    dp[r][c]=1;
    return (a[r][c]=min(p1,min(p2,min(p3,p4))));
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int ci=1;
    while(~getI(n))
    {
        if(n==0) break;
        CLR(dp);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                getI(a[i][j]);
            }
        }
        a[n-1][0]+=a[n-1][1];
        a[n-1][2]=INF;
//        a[n-1][0]=a[n-1][2]=INF;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=2;j>=0;j--)
            {
                if(j==2)
                {
                    a[i][j]+=min(a[i+1][j-1],a[i+1][j]);
                }
                else if(j==1)
                {
                    a[i][j]+=min(a[i+1][j],min(a[i+1][j+1],min(a[i+1][j-1],a[i][j+1])));
                }
                else
                {
                    a[i][j]+=min(a[i+1][j],min(a[i+1][j+1],a[i][j+1]));
                }
            }
        }
//        int x=a[0][1];
//        int m=x+a[1][0];
//        int n=x+a[1][1];
//        int o=x+a[1][2];
//        int res=min(m,min(n,o));
//        int res=a[n-1][1]+call(0,1);
        printf("%d. %d\n",ci++,a[0][1]);
    }
    return 0;
}
