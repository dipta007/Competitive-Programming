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
#define    getL(a)           scanf("%I64d",&a)
#define    getLL(a,b)        scanf("%I64d%I64d",&a,&b)
#define    getLLL(a,b,c)     scanf("%I64d%I64d%I64d",&a,&b,&c)
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


template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

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


void call(int res)
{
    if(res==2) printf("twenty");
    if(res==3) printf("thirty");
    if(res==4) printf("forty");
    if(res==5) printf("fifty");
    if(res==6) printf("sixty");
    if(res==7) printf("seventy");
    if(res==8) printf("eighty");
    if(res==9) printf("ninety");
}

void call1(int res)
{
    if(res==0) printf("zero");
    if(res==1) printf("one");
    if(res==2) printf("two");
    if(res==3) printf("three");
    if(res==4) printf("four");
    if(res==5) printf("five");
    if(res==6) printf("six");
    if(res==7) printf("seven");
    if(res==8) printf("eight");
    if(res==9) printf("nine");
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n;
    while(~getI(n))
    {
        int a[2];
        int cnt=0;
        while(n!=0)
        {
            int k=n%10;
            n=n/10;
            a[cnt]=k;
            cnt++;
        }
        //debug("c",cnt,a[0],a[1]);
        if(cnt==2)
        {
            swap(a[0],a[1]);
            if(a[0]==1)
            {
                if(a[1]==0) printf("ten");
                if(a[1]==1) printf("eleven");
                if(a[1]==2) printf("twelve");
                if(a[1]==3) printf("thirteen");
                if(a[1]==4) printf("fourteen");
                if(a[1]==5) printf("fifteen");
                if(a[1]==6) printf("sixteen");
                if(a[1]==7) printf("seventeen");
                if(a[1]==8) printf("eighteen");
                if(a[1]==9) printf("nineteen");
                printf("\n");
                continue;
            }
            else
            {
                call(a[0]);
                if(a[1]!=0)
                {
                    printf("-");
                    call1(a[1]);
                }
                printf("\n");
            }
        }
        else if(cnt==1)
        {
            call1(a[0]);
            printf("\n");
        }
        else
        {
            call1(0);
            printf("\n");
        }
    }

    return 0;
}

