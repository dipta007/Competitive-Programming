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

bool leap(int y)
{
    if(y%4==0 && y%100!=0) return 1;
    if(y%100==0 && y%400==0) return 1;
    return 0;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    getchar();
    for(int ci=1;ci<=t;ci++)
    {
        char m1[20],m2[20];
        int d1,d2,y1,y2;
        scanf("%s %d%*c %d",m1,&d1,&y1);
        scanf("%s %d%*c %d",m2,&d2,&y2);
//        debug(m1,d1,y1);
//        debug(m2,d2,y2);
        int cnt=0;
        if(y1%4==0)
        {
            if(strcmp(m1,"January")==0 || strcmp(m1,"February")==0)
            {
                cnt++;
            }
            cnt+=((y2-y1)/4);
        }
        else
        {
//            cnt++;
            int k=y1%4;
            k=4-k;
            int yy1=y1;
            yy1+=k;
            if(yy1<=y2){cnt++;
            cnt+=((y2-yy1)/4);}
        }

        if(y1%100==0)
        {
            if(strcmp(m1,"January")==0 || strcmp(m1,"February")==0)
            {
                cnt--;
            }
            cnt-=((y2-y1)/100);
        }
        else
        {
//            cnt--;
            int k=y1%100;
            k=100-k;
            int yy1=y1;
            yy1+=k;
            if(yy1<=y2){cnt--;
            cnt-=((y2-yy1)/100);}
        }

        if(y1%400==0)
        {
            if(strcmp(m1,"January")==0 || strcmp(m1,"February")==0)
            {
                cnt++;
            }
            cnt+=((y2-y1)/400);
        }
        else
        {

            int k=y1%400;
            k=400-k;
            int yy1=y1;
            yy1+=k;
            if(yy1<=y2){cnt++;
            cnt+=((y2-yy1)/400);}
        }

        if(strcmp(m2,"January")==0 || (strcmp(m2,"February")==0 && d2!=29))
        {
            if(leap(y2))
                cnt--;
        }
        printf("Case %d: %d\n",ci,cnt);
    }
    return 0;
}

