/*
ID: iamdipt1
PROG: beads
LANG: C++
*/

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

template< class T > inline T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > inline T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > inline T _min(T a, T b) { return (a < b ? a : b); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template< class T > inline T lcm(T a, T b) { return (a / gcd(a, b) * b); }

int month[]={31,28,31,30,31,30,31,31,30,31,30,31};

int leap_year(int n)
{
    if((n%100 != 0 && n%4==0) || (n%400==0))
        return 1;
    return 0;
}

int m_len(int m,int y)
{
    if(m==1)
        return month[m]+leap_year(y);
    return month[m];
}

int main() {
    ofstream fout ("out.out");
    ifstream fin ("in.in");
    int a;
    fin >> a;
    char st[2*a+4],sl[2*a+1];
    fin >> st;
    for(int i=0;i<a;i++)
    {
        sl[i]=st[i];
    }
    for(int i=a,j=0;i<2*a;j++,i++)
    {
        sl[i]=st[j];
    }
    sl[2*a]='\0';
    int count[2*a];
    CLR(count);
    int flg=0;
    int cnt=0;
    int len;
    for(int i=0;i<2*a;i++)
    {
        if(sl[i]=='w')
        {
            cnt++;
            count[i]=cnt;
        }
        else if((sl[i]==sl[i-1] || sl[i-1]=='w')&&flg==0)
        {
            cnt++;
            sl[i-1]=sl[i];
            count[i]=cnt;
        }
        else if((sl[i]==sl[i-1] || sl[i-1]=='w')&&flg==1)
        {
            cnt++;
            sl[i-1]=sl[i];
            count[i]=cnt;
        }
        else if(sl[i]!=sl[i-1] && flg==0)
        {
            flg=1;
            len=cnt;
            cnt++;
            count[i]=cnt;
        }
        else if(sl[i]!=sl[i-1] && flg==1)
        {
            cnt=cnt-len;
            len=cnt;
            cnt++;
            count[i]=cnt;
        }

    }
    for(int i=0;i<2*a;i++)
        fout << sl[i] << " ";
    fout <<endl;
    for(int i=0;i<2*a;i++)
    {
        fout << count[i] <<" ";
    }


    return 0;
}

