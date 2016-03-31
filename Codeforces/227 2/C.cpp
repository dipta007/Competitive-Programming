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

#define    debug(a)     { cout << a <<endl; }
#define    debugI()     { cout << "*" <<endl; }
#define    debugII()    { cout << "**" <<endl; }
#define    debugIII()   { cout << "***" <<endl; }

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

int brk[]= {1,6,1,2,2,3,1,4,0,1};
int cnt=0;

void call(string st)
{
    int f=0;

    int len=st.size();
    for(int i=0;i<len;i++)
    {
        if(st[i]=='0') ;
        else f++;
        if(f==2) break;
    }
    if(f==1)
    {cnt++;return;}

    string maxy="",res;
    for(int i=0; i<len; i++)
    {
        if(st[i]=='0')
        {
            res.PB(st[i]);
            if(maxy.size()<res.size() || (maxy.size()==res.size() && res[0]>maxy[0]))
            {
                maxy=res;
            }
            if(st[i+1]!='0') res.clear();
        }
        else
        {
            res.PB(st[i]);
            if(maxy.size()<res.size() || (maxy.size()==res.size() && res[0]>maxy[0]))
            {
                maxy=res;
            }
            if(st[i+1]!='0') res.clear();
        }
    }
//    debug(maxy);
    res.clear();
    int index;
    for(int i=0; i<len; i++)
    {
        res.PB(st[i]);
        if((st[i+1]!='0'|| i==len-1) && (maxy.size()<res.size() || (maxy.size()==res.size() && res[0]>=maxy[0])))
        {
            index=i;
            break;
        }
    }
    int flg=0;
//    debug(res);
//    puts("");
    //int cnt=1;
    for(int i=index+1; i<len; i++)
    {
        flg=1;
        if(st[i]=='0' )
        {
            if(st[i+1]!='0' || i==len-1)
            {
                cnt++;
            }
        }
        else
        {
            if(st[i+1]!='0' || i==len-1)
            {
                cnt++;
            }
        }
        //cnt++;
    }
    //debug(cnt);
    if(flg==1) call(res);
    else cnt++;
    return;
}
//10000000000000000000000000000000000000400500000000000000000000000000000000030020010300000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    string st;
    while(getline(cin,st))
    {
        cnt=0;
        call(st);
        debug(cnt);
    }

    return 0;
}
