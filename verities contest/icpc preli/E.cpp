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

int month[]={31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    for(int ci=1;ci<=t;ci++)
    {
        int a,b,c,d;
        getIII(a,b,c);
        getI(d);
        int m1,m2,d1,d2;

        if(a<=0 || b<=0 || c<=0 || d<=0)
        {
            printf("Case %d: I am sure there is some kinda mistake!\n",ci);
        }
        else if(a==b && b==c && c==d)
        {
            printf("Case %d: I am sure there is some kinda mistake!\n",ci);
        }
        else if(a==b && c==d && a<=12 && c<=12)
        {
            if(a<c)
                printf("Case %d: Okay got it!\n",ci);
            else printf("Case %d: I am sure there is some kinda mistake!\n",ci);
        }
        else if(a>12 || b>12 || c>12 || d>12)
        {
            if(a>12)
            {
                d1=a;
                d2=c;
                m1=b;
                m2=d;
            }
            else if(b>12)
            {
                d1=b;
                d2=d;
                m1=a;
                m2=c;
            }
            else if(c>12)
            {
                d1=a;
                d2=c;
                m1=b;
                m2=d;
            }
            else if(d>12)
            {
                d1=b;
                d2=d;
                m1=a;
                m2=c;
            }
            if(m1>12 || m2>12)
            {
                printf("Case %d: I am sure there is some kinda mistake!\n",ci);
                continue;
            }
            int k1=month[m1-1];
            int k2=month[m2-1];
            if(d1>k1 || d2>k2)
                printf("Case %d: I am sure there is some kinda mistake!\n",ci);
            else
            {
                int y1=m1*30+d1;
                int y2=m2*30+d2;
                if(y1<y2) printf("Case %d: Okay got it!\n",ci);
                else printf("Case %d: I am sure there is some kinda mistake!\n",ci);
            }

        }
        else if(a<=12 && b<=12 && c<=12 && d<=12)
        {
            int y1=a*30+b;
            int y2=c*30+d;
            int py1=b*30+a;
            int py2=d*30+c;
//            debug(y1);
//            debug(y2);
//            debug(py1);
//            debug(py2);
            if((y1>=y2 && py1<py2) || (y1<y2 && py1>=py2))
                printf("Case %d: Okay got it!\n",ci);
            else if(y1<y2 && py1<py2)
                printf("Case %d: Oh no it is ambiguous!\n",ci);
            else if(y1>=y2 && py1>=py2)
                printf("Case %d: I am sure there is some kinda mistake!\n",ci);

//            else
//            {
//                y1=b*30+a;
//                y2=d*30+c;
//                if(y1<y2)
//                    printf("Case %d: Oh no it is ambiguous!\n",ci);
//                else
//                    printf("Case %d: I am sure there is some kinda mistake!\n",ci);
//            }
            //printf("ambi\n");
        }
        else
        {
            printf("Case %d: Okay got it!\n",ci);
        }
    }

    return 0;
}

