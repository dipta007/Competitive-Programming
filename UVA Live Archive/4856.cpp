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

/// ********* debug template bt Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;
//******************DELETE****************

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N=N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

string leftOut[7]={ "........||.../\\...",
                    "........||../..\\..",
                    ".../\\...||./....\\.",
                    "../..\\..||/G.....\\",
                    "./....\\.||\\______/",
                    "/YQYFU.\\||........",
                    "\\______/||........"
                    };
string rightOut[7]={".../\\...||........",
                    "../..\\..||........",
                    "./....\\.||.../\\...",
                    "/WCGQG.\\||../..\\..",
                    "\\______/||./....\\.",
                    "........||/OYA...\\",
                    "........||\\______/"
                    };
string equalOut[7]={"........||........",
                    ".../\\...||.../\\...",
                    "../..\\..||../..\\..",
                    "./....\\.||./....\\.",
                    "/NQ....\\||/FG....\\",
                    "\\______/||\\______/",
                    "........||........"
                    };

pii call(int k)
{
    int zero=0,one=0;
    while(k)
    {
        int l=k%2;
        if(l) one++;
        else zero++;
        k=k/2;
    }
    return pii(zero,one);
}


int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int t;
    getI(t);
    getchar();
    for(int ci=1;ci<=t;ci++)
    {
        string st[7];
        for(int i=0;i<7;i++)
        {
            getline(cin,st[i]);
        }
        int in,out;
        if(st[6][2]=='_') in=1;
        else if(st[6][16]=='_') in=3;
        else in=2;

        int left=0,right=0;
        vector <char> vl,vr;
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(isalpha(st[i][j]))
                {
                    pii p = call((int)(st[i][j]));
                    //debug(p.ff,p.ss);
                    left+=p.ff*250+p.ss*500;
                    vl.PB(st[i][j]);
                }
            }
        }
        for(int i=0;i<6;i++)
        {
            for(int j=10;j<18;j++)
            {
                if(isalpha(st[i][j]))
                {
                    pii p = call((int)(st[i][j]));
                    right+=p.ff*250+p.ss*500;
                    vr.PB(st[i][j]);
                }
            }
        }
        //debug(left,right)
        string tmp;
        getline(cin,tmp);
        printf("Case %d:\n",ci);
        while(vl.size()<6)
            vl.PB('.');
        while(vr.size()<6)
            vr.PB('.');
        if((left>right && in==1) || (left==right && in==2) || (left<right && in==3))
        {
            printf("The figure is correct.\n");
            continue;
        }
        if(left>right)
        {
            int l=0,r=0;
            for(int i=0;i<7;i++)
            {
                for(int j=0;j<18;j++)
                {
                    if(i==3 && j>=11 && j<=16) cout << vr[r++];
                    else if(i==5 && j>=1 && j<=6) cout << vl[l++];
                    else cout << leftOut[i][j];
                }
                cout <<endl;
            }
        }
        else if(right>left)
        {
            int l=0,r=0;
            for(int i=0;i<7;i++)
            {
                for(int j=0;j<18;j++)
                {
                    if(i==3 && j>=1 && j<=6) cout << vl[l++];
                    else if(i==5 && j>=11 && j<=16) cout << vr[r++];
                    else cout << rightOut[i][j];
                }
                cout <<endl;
            }
        }
        else
        {
            int l=0,r=0;
            for(int i=0;i<7;i++)
            {
                for(int j=0;j<18;j++)
                {
                    if(i==4 && j>=1 && j<=6) cout << vl[l++];
                    else if(i==4 && j>=11 && j<=16) cout << vr[r++];
                    else cout << equalOut[i][j];
                }
                cout <<endl;
            }
        }
    }

    return 0;
}



