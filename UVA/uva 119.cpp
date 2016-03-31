#include <algorithm>
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
const int MaxMatrixSize=40;
template< class T > inline void showMatrix(int n,T A[MaxMatrixSize][MaxMatrixSize])
  {for (int i=0;i<n;i++){for (int j=0;j<n;j++)cout<<A[i][j]<<" ";cout<<endl;}}

int main() {
    //READ("uva 119.txt");
    //WRITE("out.txt");

    int n;
    int v=0;
    while(~getI(n))
    {
        if(v!=0)
            printf("\n");
        v++;
        char a[16][16];
        map <string,int> mp;
        getchar();
        for(int i=0;i<n;i++)
        {
            scanf("%s",a[i]);
            mp[a[i]]=0;
        }
        getchar();
        for(int i=0;i<n;i++)
        {
            char b[200];
            gets(b);
            char *token;
            char c[]=" ";
            token=strtok(b,c);
            int coun=0;
            char cc[16][16];
            while(token!=NULL)
            {
                strcpy(cc[coun],token);
                coun++;
                token=strtok(NULL,c);
            }
            int n,k;
            n=atoi(cc[1]);
            k=atoi(cc[2]);
            if(k!=0)
            {
                int l=n/k;
                mp[cc[0]]-=(l*k);
                for(int j=1;j<=k;j++)
                {
                    mp[cc[j+2]]+=l;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            printf("%s %d\n",a[i],mp[a[i]]);
        }


    }
    return 0;
}

