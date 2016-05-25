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
#define    getL(a)           scanf("%I64d",&a)
#define    getLL(a,b)        scanf("%I64d%I64d",&a,&b)
#define    getLLL(a,b,c)     scanf("%I64d%I64d%I64d",&a,&b,&c)
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


template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }



struct kadane //Structure for 1D-Kadane Algorithm
{
    int u,d,sum;
    kadane()
    {
        u=-1,d=-1,sum=0;
    }
};

int a[104][104];

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int r,c,n;
    while(~getI(n))
    {
        r=n;
        c=n;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                getI(a[i][j]);
            }
        }

        int maxSum=-INF,maxL,maxR,maxU,maxD;
        int kad[104];

        for(int left=0;left<c;left++)
        {
            CLR(kad);
            for(int right=left;right<c;right++)
            {
                for(int i=0;i<r;i++)
                {
                    kad[i]=kad[i]+a[i][right];
                }

                kadane curr,maxy;

                for(int i=0;i<r;i++) //This FOR for 1D-Kadane Algorithm
                {
                    if(curr.sum<0)
                    {
                        curr.sum = kad[i];
                        curr.u=i;
                        curr.d=i;
                    }
                    else
                    {
                        curr.sum = curr.sum + kad[i];
                        curr.d=i;
                    }
                    if(curr.sum > maxy.sum)
                    {
                        maxy=curr;
                    }
                }

                if(maxy.sum>maxSum)
                {
                    maxSum=maxy.sum;
                    maxL=left;
                    maxR=right;
                    maxU=maxy.u;
                    maxD=maxy.d;
                }

            }
        }
        printf("%d\n",maxSum);

    }

    return 0;
}

///Time Complexity = O(col * col * row)
///Space Complexity = O(row)
/// MUST HAVE AT LEAST ONE POSITIVE NUMBER


