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

int a[]={0,1,2,3,4,5,6,7,8,9};
int v[10];
int n;

void call(string s1,string s2)
{
    if(s1.size()==5 && s2.size()==5)
    {
        //debug(s1,s2);
        stringstream ss1,ss2;
        ss1<<s1;
        ss2<<s2;
        int a,b;
        ss1>>a;
        ss2>>b;
        int k=a/b;
        if(k*b==a && k==n)
        {
            printf("%d / %d = %d\n",a,b,n);
            return;
        }
        return;
    }
    for(int i=0;i<10;i++)
    {
        if(v[i]==0)
        {
            char ch=a[i]+48;
            v[i]=1;
            if(s1.size()<5) call(s1+ch,s2);
            if(s2.size()<5) call(s1,s2+ch);
            v[i]=0;
        }
    }
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");
    int ci=1;
    while(~getI(n))
    {
        int flg=0;
        if(n==0) break;
        if(ci!=1) printf("\n");
        ci++;
        for(int i=01234;i<=98765;i++)
        {
            int j=i*n;
            int x=i,y=j;
            int cnt=0;
            int c=5;
            int f=1;
            CLR(v);
            while(c-- && f)
            {
                int k=x%10;
                x=x/10;
                if(v[k]==0) cnt++;
                else f=0;
                v[k]=1;
            }
            c=5;
            while(c-- && f)
            {
                int k=y%10;
                y=y/10;
                if(v[k]==0) cnt++;
                else f=0;
                v[k]=1;
            }
            if(x>0 || y>0) f=0;
            if(cnt==10 && f)
            {
                flg=1;
                printf("%0.5d / %0.5d = %d\n",j,i,n);
            }
        }
        if(!flg) printf("There are no solutions for %d.\n",n);
    }

    return 0;
}

