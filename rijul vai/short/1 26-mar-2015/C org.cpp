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

string stmain[5]={"aabb","abab","abba","aaaa","NO"};

int main() {
    //READ("in.txt");
    //WRITE("out.txt");

    int n,k;
    while(~getII(n,k))
    {
        getchar();
        int real=0;
        vector <string> vs;
        int flg=1;
        n=n*4;
        for(int i=0;i<n;i++)
        {
            string st;
            getline(cin,st);
            int len=st.size();
            int x=k;
            string nst="";
            for(int j=len-1;j>=0 && flg;j--)
            {
                if(st[j]=='a' || st[j]=='e' || st[j]=='i' || st[j]=='o' || st[j]=='u')
                {
                    nst+=st[j];
                    x--;
                }
                else nst+=st[j];
                if(!x) break;
            }
            if(x>0)
            {
                real=5;
                flg=0;
            }
            vs.PB(nst);
            if(vs.size()%4==0 && real==0 && real!=5)
            {
                if(vs[0].compare(vs[1])==0 && vs[1].compare(vs[2])==0 && vs[2].compare(vs[3])==0)
                    real=4;
                else if(vs[0].compare(vs[1])==0 && vs[2].compare(vs[3])==0)
                    real=1;
                else if(vs[0].compare(vs[2])==0 && vs[1].compare(vs[3])==0)
                    real=2;
                else if(vs[0].compare(vs[3])==0 && vs[1].compare(vs[2])==0)
                    real=3;
                else real=5;
                vs.clear();
            }
            else if(vs.size()%4==0 && real!=5)
            {
                int zero,one,two,three,reals;
                zero=vs.size()-4;
                one=zero+1;
                two=zero+2;
                three=zero+3;
                if(vs[zero].compare(vs[one])==0 && vs[one].compare(vs[two])==0 && vs[two].compare(vs[three])==0)
                    reals=4;
                else if(vs[zero].compare(vs[one])==0 && vs[two].compare(vs[three])==0)
                    reals=1;
                else if(vs[zero].compare(vs[two])==0 && vs[one].compare(vs[three])==0)
                    reals=2;
                else if(vs[zero].compare(vs[three])==0 && vs[one].compare(vs[two])==0)
                    reals=3;
                else reals=5;


                if(real==4 && reals!=real)
                {
                    real=reals;
                }
                else if(reals==4)
                {
                    ;
                }
                else if(reals!=real)
                {
                    flg=0;
                    real=5;
                }
                vs.clear();
            }
            //debug(i);
        }
//        debug("assa",real);
        printf("%s\n",stmain[real-1].c_str());
    }

    return 0;
}

