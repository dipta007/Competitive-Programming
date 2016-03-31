#pragma comment(linker, "/stack:640000000")

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

#define    rep(i,n)          for(i=1;i<=n;i++)
#define    repI(i,n)         for(i=0;i<n;i++)
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
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
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


template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }

//******************DELETE****************
#define shubhashis
#ifdef shubhashis
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

int bitOn(int N,int pos)
{
    return N=N | (1<<pos);
}
int bitOff(int N,int pos)
{
    return N=N & ~(1<<pos);
}
bool bitCheck(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

string Day[]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
int Days[]={31,28,31,30,31,30,31,31,30,31,30,31};

string bangla[]={"Baishakh", "Jaishtha", "Ashar", "Sraban", "Bhadra", "Ashwin", "Kartik" ,"Agrahayan", "Poush", "Magh", "Falgun", "Chaitra"};
int bDays[]={31,31,31,31,31,30,30,30,30,30,30,30};

bool leap(int y)
{
    if(y%4!=0) return 0;
    else if(y%100!=0) return 1;
    else if(y%400!=0) return 0;
    return 1;
}

string res[32][13][304];

void preCal()
{
    int d=1,m=0,y=0;
    int bd=18,bm=8,by=1378;
    int leapNakiNa=leap(y+1972);
    while(1)
    {
        if(d==1 && m==0)
        {
            bd=18;
            bm=8;
        }

        if(leapNakiNa) bDays[10]=31;
        else bDays[10]=30;

        string st="";
        int x=bd;
        while(x)
        {
            st =  (char)(x%10+48) + st;
            x /= 10;
        }
        st += ", ";
        st += bangla[bm];
        st += ", ";
        x=by;
        string year="";
        while(x)
        {
            year = (char)(x%10+48) + year;
            x /= 10;
        }
        st += year;
        res[d][m][y]=st;

        d++;
        if(m==1 && leapNakiNa)
        {
            if(d>29)
            {
                d=1;
                m++;
            }
        }
        else if(d>Days[m])
        {
            d=1;
            m++;
            if(m>=12)
            {
                m=0;
                y++;
                leapNakiNa=leap(y+1972);
            }
        }

        bd++;
        if(bd>bDays[bm])
        {
            bd=1;
            bm++;
            if(bm>=12)
            {
                bm=0;
                by++;
            }
        }
        if(y>299) break;
    }
}

int main() {
//    READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    preCal();
    for(int ci=1;ci<=t;ci++)
    {
        int d,m,y;
        getIII(d,m,y);
//        int flg=1;
//        int bd=18,bm=
//        while(flg)
//        {
//
//        }
        printf("Case %d: %s\n",ci,res[d][m-1][y-1972].c_str());
//        debug(res[d][m-1][y-1972]);
    }

    return 0;
}



