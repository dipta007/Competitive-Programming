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

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }


int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n,m,x,y;
    while(~getII(n,m))
    {
        getII(x,y);
        int cnt=0,cnt1=0,cnt2=0;
        int i;
        if(m>n){
        for( i=1;cnt1<n || cnt2<m;i++)
        {
            if(i%x==0 && i%y==0) ;
            else if(i%x==0 && i%y!=0 && cnt2<m) cnt2++;
            else if(i%x!=0 && i%y==0 && cnt1<n) cnt1++;
            else if(i%x!=0 && i%y!=0)
            {
                int f1=n-cnt1;
                int f2=m-cnt2;
                if(f1<f2) cnt2++;
                else if(f2<=f1) cnt1++;
//                if(m>n && cnt2<m) cnt2++;
//                else if(n>=m && cnt1<n) cnt1++;
            }
        }
        }
        else
        {
        for( i=1;cnt1<n || cnt2<m;i++)
        {
            if(i%x==0 && i%y==0) ;
            else if(i%x!=0 && i%y==0 && cnt1<n) cnt1++;
            else if(i%x==0 && i%y!=0 && cnt2<m) cnt2++;
            else if(i%x!=0 && i%y!=0)
            {
                int f1=n-cnt1;
                int f2=m-cnt2;
                if(f1<f2) cnt2++;
                else if(f2<=f1) cnt1++;
//                if(m>n && cnt2<m) cnt2++;
//                else if(n>=m && cnt1<n) cnt1++;
            }
        }
        }
        debug(i-1);
    }

    return 0;
}



