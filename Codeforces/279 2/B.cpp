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
#define    getL(n)           scanf("%I64d",&n)
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

struct data
{
    int x,y;
};

bool cmp1(const data &a,const data &b)
{
    if(a.x<b.x) return true;
    if(a.x==b.x) return a.y<b.y;
    return false;
}
bool cmp2(const data &a,const data &b)
{
    if(a.y<b.y) return true;
    if(a.y==b.y) return a.x<b.x;
    return false;
}



data a[300000];

int bin_src1(int low,int high,int key)
{

    while(low<=high)
    {
        int mid=(low+high)/2;
        if(key>a[mid].x)
            low=mid+1;
        else if(key<a[mid].x)
            high=mid-1;
        else
            return mid;
    }
    return -1;

}

int bin_src2(int low,int high,int key)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        //debugIII();
        if(key>a[mid].y)
            low=mid+1;
        else if(key<a[mid].y)
            high=mid-1;
        else
            return mid;
    }
    return -1;

}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n;
    while(~getI(n))
    {
        for(int i=0;i<n;i++)
        {
            getII(a[i].x,a[i].y);
        }

        int sorted[n+1];
        if(n%2==0)
        {
            sort(a,a+n,cmp1);
            //debugI();
            int cnt=1,prev=0;
            //CLR(sorted);
            for(int i=1;i<=n/2;i++)
            {
                //debugIII();
                if(i==1) sorted[cnt]=a[prev].y;
                else
                {
                    prev=bin_src1(0,n-1,a[prev].y);
                    sorted[cnt]=a[prev].y;
                }
                cnt+=2;
            }
            //debugII();
            cnt=n-2;
            prev=0;
            sort(a,a+n,cmp2);
            //debugIII();
            for(int i=1;i<=n/2;i++)
            {
//                debugI();
                if(i==1) sorted[cnt]=a[prev].x;
                else
                {
                    prev=bin_src2(0,n-1,a[prev].x);
                    sorted[cnt]=a[prev].x;
                }
                cnt-=2;
            }
            for(int i=0;i<n;i++)
            {
                if(i>0) printf(" ");
                printf("%d",sorted[i]);
            }
            printf("\n");
        }
        else
        {
            sort(a,a+n,cmp1);
            int cnt=1,prev=0;
            SET(sorted);
            for(int i=1;i<=(int)n/2;i++)
            {
                //debugIII();
                if(i==1) sorted[cnt]=a[prev].y;
                else
                {
                    prev=bin_src1(0,n-1,a[prev].y);
                    sorted[cnt]=a[prev].y;
                }
                cnt+=2;
            }
            cnt=n-1;
            for(int i=0;i<n;i++)
            {
                if(bin_src1(0,n-1,a[i].y)==-1)
                {
                    prev=a[i].y;
                    break;
                }
            }
            int k=n/2+1;
            sort(a,a+n,cmp2);
            for(int i=1;i<=k;i++)
            {
                if(i==1) sorted[cnt]=prev;
                else
                {
                    int l=bin_src2(0,n-1,prev);
                    prev=a[l].x;
                    sorted[cnt]=prev;
                }
                cnt-=2;
            }
            for(int i=0;i<n;i++)
            {
                if(i>0) printf(" ");
                printf("%d",sorted[i]);
            }
            printf("\n");
        }

    }
    return 0;
}
