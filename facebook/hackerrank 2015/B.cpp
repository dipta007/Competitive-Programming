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


template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}

//******************DELETE****************
#define shubhashis
#ifdef shubhashis
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

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


string st[2];

void checkSingle(int n)
{
    for(int i=1; i<n-1; i++)
    {
        if(st[0][i-1]=='X' && st[0][i]=='.' && st[0][i+1]=='X')
        {
            st[0][i]='S';
        }
        if(st[1][i-1]=='X' && st[1][i]=='.' && st[1][i+1]=='X')
        {
            st[1][i]='S';
        }
    }
    if(st[0][0]=='.' && st[0][1]=='X')
    {
        st[0][0]='S';
    }
    if(st[1][0]=='.' && st[1][1]=='X')
    {
        st[1][0]='S';
    }
    if(st[0][n-1]=='.' && st[0][n-2]=='X')
    {
        st[0][n-1]='S';
    }
    if(st[1][n-1]=='.' && st[1][n-2]=='X')
    {
        st[1][n-1]='S';
    }
}

int main()
{
    READ("in.txt");
    WRITE("finalB.txt");

    int t;
    getI(t);
    for(int ci=1; ci<=t; ci++)
    {
        int n;
        getI(n);
        getchar();
        getline(cin,st[0]);
        getline(cin,st[1]);
        if(n==1)
        {
            printf("Case #%d: 1\n",ci);
            continue;
        }

        checkSingle(n);
//
//        for(int i=0;i<2;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                cout << st[i][j];
//            }
//            cout << endl;
//        }
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            int cnt1,cnt2;
            cnt1=cnt2=0;
            int flg=0;

            for(int j=i; j<n; j++)
            {
                if(st[0][j]=='X' || st[0][j]=='G') break;
                if(st[0][j]=='S' && (st[1][j]=='S' || st[1][j]=='.'))
                    continue;
                st[0][j]='G';
                cnt1++;
                if(st[1][j]=='S' && flg==0)
                {
                    flg=1;
                    st[1][j]='G';
                    cnt1++;
                }
            }
            flg=0;
            for(int j=i; j<n; j++)
            {
                if(st[1][j]=='X' || st[1][j]=='G') break;
                st[1][j]='G';
                cnt2++;
                if(st[0][j]=='S' && flg==0)
                {
                    flg=1;
                    st[0][j]='G';
                    cnt2++;
                }
            }
            //debug(i,cnt1,cnt2)
            if(cnt1>0) cnt++;
            if(cnt2>0) cnt++;
        }

//        for(int i=0;i<2;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                cout << st[i][j];
//            }
//            cout << endl;
//        }

        //debug(cnt);

        for(int i=0;i<n;i++)
        {
            if(st[0][i]!='G' && st[0][i]!='X') cnt++;
            if(st[1][i]!='G' && st[1][i]!='X') cnt++;
        }
        printf("Case #%d: %d\n",ci,cnt);
    }

    return 0;
}


