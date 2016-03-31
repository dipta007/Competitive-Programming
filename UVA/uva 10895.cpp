
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

struct data
{
    int val;
    int ind;
};

bool cmp(const data &a,const data &b)
{
    if(a.ind < b.ind) return true;
    return false;
}

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n,m;
    while(~getII(n,m))
    {
        int a[n+1][m+1];
        int b[m+1][n+1];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                a[i][j]=0;

        for(int i=1;i<=n;i++)
        {
            int r;
            getI(r);
            int c[r+1];
            for(int j=1;j<=r;j++)
                getI(c[j]);
            for(int j=1;j<=r;j++)
            {
                int k;
                getI(k);
                a[i][c[j]]=k;
            }
        }

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
                b[i][j]=a[j][i];
        }
        int row[m+1];
        vector <data > v[n+4];
        for(int i=1;i<=m;i++)
        {
            int cnt=0;
            for(int j=1;j<=n;j++)
            {
                if(b[i][j]!=0)
                {
                    cnt++;
                    data gh;
                    gh.ind=j;
                    gh.val=b[i][j];
                    v[i].PB(gh);
                }
            }
            row[i]=cnt;
            //sort(ALL(v[i]),cmp);
        }

        printf("%d %d\n",m,n);
        for(int i=1;i<=m;i++)
        {
            printf("%d",row[i]);
            if(row[i]==0)
            {
                printf("\n\n");
                continue;
            }
            for(int j=0;j<row[i];j++)
            {
                printf(" %d",v[i][j].ind);
            }
            printf("\n");
            for(int j=0;j<row[i];j++)
            {
                if(j>0) printf(" ");
                printf("%d", v[i][j].val );
            }
            printf("\n");
        }
    }

    return 0;
}
