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

template< class T > inline T _abs(T n)
{
    return (n < 0 ? -n : n);
}
template< class T > inline T _max(T a, T b)
{
    return (!(a < b) ? a : b);
}
template< class T > inline T _min(T a, T b)
{
    return (a < b ? a : b);
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b == 0 ? a : gcd(b, a % b));
}
template< class T > inline T lcm(T a, T b)
{
    return (a / gcd(a, b) * b);
}

struct data
{
    int a,ind,sn;
    data()
    {
        sn=2;
    }
};



int bin_src(int low,int high,int val,data *arr)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid].a<val)
            low=mid+1;
        else if(arr[mid].a==val && arr[mid].sn==2)
        {
            return mid;
        }
        else if(arr[mid].a==val && arr[mid].sn!=2)
        {
            return -1;
        }
        else
            high=mid-1;
    }
    return -1;
}

bool cmp1(const data &a,const data &b)
{
    if(a.a<b.a) return true;
    return false;
}

bool cmp2(const data &a,const data &b)
{
    if(a.ind<b.ind) return true;
    return false;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int n,a,b;
    while(~getIII(n,a,b))
    {
//        bool mark[n+4];
//        CLR(mark);
        data arr[n+4];
        int flg=1;
        for(int i=0; i<n; i++)
        {
            getI(arr[i].a);
            arr[i].ind=i;
        }
        int kk=0;
//        if(n%2!=0)
//        {
//            printf("NO\n");
//            continue;
//        }
        for(int i=0; i<n; i++)
        {
            if(arr[i].sn!=2)
            {
                continue;
            }
            int ka=a-arr[i].a;
            int kb=b-arr[i].a;
            int posa=-1,posb=-1;
            if(ka>0)
                posa=bin_src(kk,n-1,ka,arr);
            if(posa!=-1)
            {
                arr[posa].sn=0;
                arr[i].sn=0;
            }
            else
            {
                if(kb>0)
                    posb=bin_src(kk,n-1,kb,arr);
                if(posb!=-1)
                {
                    arr[posb].sn=1;
                    arr[i].sn=1;
                    //sort(arr,arr+n,cmp1);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i].sn==2)
                flg=0;
        }
        if(flg==0)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(int i=0;i<n;i++)
        {
            printf("%d",arr[i].sn);
            if(i<n-1)
                printf(" ");
            else
                printf("\n");
        }
    }

    return 0;
}

