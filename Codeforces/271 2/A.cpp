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


int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    char c,st[104];
    scanf("%c",&c);
    scanf("%s",st);
    int len=strlen(st);
    if(c=='R')
    {
        for(int i=0;i<len;i++)
        {
            if(st[i]=='w')
            {
                st[i]='q';
            }
            else if(st[i]=='e')
            {
                st[i]='w';
            }
            else if(st[i]=='r')
            {
                st[i]='e';
            }
            else if(st[i]=='t')
            {
                st[i]='r';
            }
            else if(st[i]=='y')
            {
                st[i]='t';
            }
            else if(st[i]=='u')
            {
                st[i]='y';
            }
            else if(st[i]=='i')
            {
                st[i]='u';
            }
            else if(st[i]=='o')
            {
                st[i]='i';
            }
            else if(st[i]=='p')
            {
                st[i]='o';
            }
            else if(st[i]=='s')
            {
                st[i]='a';
            }
            else if(st[i]=='d')
            {
                st[i]='s';
            }
            else if(st[i]=='f')
            {
                st[i]='d';
            }
            else if(st[i]=='g')
            {
                st[i]='f';
            }
            else if(st[i]=='h')
            {
                st[i]='g';
            }
            else if(st[i]=='j')
            {
                st[i]='h';
            }
            else if(st[i]=='k')
            {
                st[i]='j';
            }
            else if(st[i]=='l')
            {
                st[i]='k';
            }
            else if(st[i]==';')
            {
                st[i]='l';
            }
            else if(st[i]=='x')
            {
                st[i]='z';
            }
            else if(st[i]=='c')
            {
                st[i]='x';
            }
            else if(st[i]=='v')
            {
                st[i]='c';
            }
            else if(st[i]=='b')
            {
                st[i]='v';
            }
            else if(st[i]=='n')
            {
                st[i]='b';
            }
            else if(st[i]=='m')
            {
                st[i]='n';
            }
            else if(st[i]==',')
            {
                st[i]='m';
            }
            else if(st[i]=='.')
            {
                st[i]=',';
            }
            else if(st[i]=='/')
            {
                st[i]='.';
            }
        }
    }
    else if(c=='L')
    {
        for(int i=0;i<len;i++)
        {
            if(st[i]=='q')
            {
                st[i]='w';
            }
            else if(st[i]=='w')
            {
                st[i]='e';
            }
            else if(st[i]=='e')
            {
                st[i]='r';
            }
            else if(st[i]=='r')
            {
                st[i]='t';
            }
            else if(st[i]=='t')
            {
                st[i]='y';
            }
            else if(st[i]=='y')
            {
                st[i]='u';
            }
            else if(st[i]=='u')
            {
                st[i]='i';
            }
            else if(st[i]=='i')
            {
                st[i]='o';
            }
            else if(st[i]=='o')
            {
                st[i]='p';
            }
            else if(st[i]=='a')
            {
                st[i]='s';
            }
            else if(st[i]=='s')
            {
                st[i]='d';
            }
            else if(st[i]=='d')
            {
                st[i]='f';
            }
            else if(st[i]=='f')
            {
                st[i]='g';
            }
            else if(st[i]=='g')
            {
                st[i]='h';
            }
            else if(st[i]=='h')
            {
                st[i]='j';
            }
            else if(st[i]=='j')
            {
                st[i]='k';
            }
            else if(st[i]=='k')
            {
                st[i]='l';
            }
            else if(st[i]=='l')
            {
                st[i]=';';
            }
            else if(st[i]=='z')
            {
                st[i]='x';
            }
            else if(st[i]=='x')
            {
                st[i]='c';
            }
            else if(st[i]=='c')
            {
                st[i]='v';
            }
            else if(st[i]=='v')
            {
                st[i]='b';
            }
            else if(st[i]=='b')
            {
                st[i]='n';
            }
            else if(st[i]=='n')
            {
                st[i]='m';
            }
            else if(st[i]=='m')
            {
                st[i]=',';
            }
            else if(st[i]==',')
            {
                st[i]='.';
            }
            else if(st[i]=='.')
            {
                st[i]='/';
            }
        }
    }
    printf("%s\n",st);

    return 0;
}

