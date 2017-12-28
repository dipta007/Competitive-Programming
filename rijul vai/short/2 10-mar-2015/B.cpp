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
#define    getII(a,b) 	     scanf("%d %d", &a, &b)
#define    getIII(a,b,c)     scanf("%d %d %d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld %lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
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


template< class T > inline T _abs(T n) { return ( (n) < 0 ? -(n) : (n) ); }
template< class T > inline T _max(T a, T b) { return ( ! ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _min(T a, T b) { return ( ( (a) < (b) ) ? (a) : (b) ) ; }
template< class T > inline T _swap(T &a, T &b) { T temp=a;a=b;b=temp;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd( (b), ( (a) % (b) ) ) ; }
template< class T > inline T lcm(T a, T b) { return ( (a) / gcd( (a), (b) ) * (b) ); }


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
//******************DELETE****************

string chord[]={"C","C#","D","D#","E","F","F#","G","G#","A","B","H"};

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    string st;
    while(getline(cin,st))
    {
        stringstream ss(st);
        string tmp;
        vector <string> vs;
        while(ss >> tmp) vs.PB(tmp);
        int a,b,c;
        for(int i=0;i<12;i++)
        {
            if(vs[0].compare(chord[i])==0)
            {
                a=i;
                break;
            }
        }
        for(int i=0;i<12;i++)
        {
            if(vs[1].compare(chord[i])==0)
            {
                b=i;
                break;
            }
        }
        for(int i=0;i<12;i++)
        {
            if(vs[2].compare(chord[i])==0)
            {
                c=i;
                break;
            }
        }
        int d1,d2;
        int aa[3];
        aa[0]=a,aa[1]=b,aa[2]=c;
        sort(aa,aa+3);
        a=aa[0],b=aa[1],c=aa[2];
        for(int i=a,j=0;;i=(i+1)%12,j++)
        {
            if(i==b)
            {
                d1=j;
                j=0;
            }
            if(i==c)
            {
                d2=j;
                break;
            }
        }
        if(d1==4 && d2==3) printf("major\n");
        else if(d1==3 && d2==4) printf("minor\n");
        else
        {
            for(int i=b,j=0;;i=(i+1)%12,j++)
            {
                if(i==c)
                {
                    d1=j;
                    j=0;
                }
                if(i==a)
                {
                    d2=j;
                    break;
                }
            }
            if(d1==4 && d2==3) printf("major\n");
            else if(d1==3 && d2==4) printf("minor\n");
            else
            {
                for(int i=c,j=0;;i=(i+1)%12,j++)
                {
                    if(i==a)
                    {
                        d1=j;
                        j=0;
                    }
                    if(i==b)
                    {
                        d2=j;
                        break;
                    }
                }
                if(d1==4 && d2==3) printf("major\n");
                else if(d1==3 && d2==4) printf("minor\n");
                else printf("strange\n");
            }
        }
    }

    return 0;
}

