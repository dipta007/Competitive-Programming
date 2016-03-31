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

    int n;
    while(~getI(n))
    {
        int flg=0;
        int aa[n];
        for(int i=0;i<n;i++)
        {
            getI(aa[i]);
        }
        sort(aa,aa+n);
        int x1,x2,x3,x4;

        if(n==1)
        {
            int man=aa[0];

            flg=1;
            x1=man;
            x2=x1;
            x3=3*x2;
            x4=3*x2;
            printf("YES\n%d\n%d\n%d\n",x2,x3,x4);
        }
        if(n==2)
        {
            int m1=aa[0];
            int m2=aa[1];
            if(m1==m2)
            {
                flg=1;
                x1=m1;
                x2=m2;
                x3=3*x2;
                x4=3*x2;
                printf("YES\n%d\n%d\n",x3,x4);
            }
            else
            {
                if(m2==3*m1)
                {
                    flg=1;
                    x1=m1;
                    x2=x1;
                    x3=m2;
                    x4=3*x2;
                    printf("YES\n%d\n%d\n",x2,x4);
                }
                else if(m2/3==x1 && m2%3==0)
                {
                    x1=m1;
                    x4=m2;
                    x2=2*x1;
                    x3=2*x1;
                    flg=1;
                    printf("YES\n%d\n%d\n",x2,x3);
                }
            }
        }
        if(n==3)
        {
            int m1=aa[0],m2=aa[1],m3=aa[2];
            if(m1==m2)
            {
                flg=1;
                x1=m1;
                x2=m2;
                x3=3*x2;

                x4=3*x2;
                if(x3==m3)
                {
                    printf("YES\n%d\n",x4);
                }
                else flg=0;
            }
            else if(m2==m3)
            {
                x2=m2;
                x3=m2;
                if(x2%2==0 && x2/2==m1)
                {
                    x1=m1;
                    x4=3*x1;
                    printf("YES\n%d\n",x4);
                    flg=1;
                }
            }

        }
        if(n==4)
        {
            flg=1;
            x1=aa[0];
            x2=aa[1];
            x3=aa[2];
            x4=aa[3];

            int a=-INF,b=-INF;
            if((x1+x2+x3+x4)%4==0) a=(x1+x2+x3+x4)/4;
            if((x2+x3)%2==0) b=(x2+x3)/2;
            int c=x4-x1;
            if(a==b && b==c && c==a) printf("YES\n");
            else flg=0;
        }
        if(n==0)
        {
            flg=1;
            x1=1;x2=1;x3=3;x3=3;
            printf("YES\n1\n1\n3\n3\n");
        }
        if(flg==0) printf("NO\n");
        //else printf("%d %d %d %d",x1,x2,x3,x4);
    }

    return 0;
}






