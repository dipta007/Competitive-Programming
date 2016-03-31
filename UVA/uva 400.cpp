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

char mirrorl[]="A000300HIL0JM0O0002TUVWXY5";
char mirrord[]="1SE0Z0080";

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    char st[24];
    while(gets(st))
    {
        int len=strlen(st);
        char cp[24];
        strcpy(cp,st);
        int paf=1,mif=1;
        for(int i=0,j=len-1;i<=len/2;i++,j--)
        {
            if(st[i]!=st[j])
            {
                paf=0;
                break;
            }
        }
        for(int i=0;i<len;i++)
        {
            if(st[i]=='0') {
                    mif=0;
            }
        }

        for(int i=0,j=len-1;i<=len/2 && mif==1;i++,j--)
        {
            int k;
            if(st[i]>'0' && st[i]<='9')
            {
                k=st[i]-'1';
                st[i]=mirrord[k];
            }
            else
            {
                k=st[i]-'A';
                st[i]=mirrorl[k];
            }
            if(i<len/2 && st[i]!=st[j])
            {
                mif=0;
                break;
            }
            if(i==len/2 && len%2==1)
            {
                if(cp[len/2]!=st[len/2])
                    mif=0;
            }
        }
        //debug(st);
        if(mif==0 && paf==0) printf("%s -- is not a palindrome.\n\n",cp);
        else if(paf==1 && mif==0) printf("%s -- is a regular palindrome.\n\n",cp);
        else if(paf==0 && mif==1) printf("%s -- is a mirrored string.\n\n",cp);
        else printf("%s -- is a mirrored palindrome.\n\n",cp);

    }

    return 0;
}

