#pragma comment(linker, "/stack:640000000")

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
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(N,in)    ((bool)(N&(1<<(in))))
#define    bitOff(N,in)      (N&(~(1<<(in))))
#define    bitOn(N,in)       (N|(1<<(in)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n) { return ((n) < 0 ? -(n) : (n)); }
template< class T > inline T _max(T a, T b) { return (!((a)<(b))?(a):(b)); }
template< class T > inline T _min(T a, T b) { return (((a)<(b))?(a):(b)); }
template< class T > inline T _swap(T &a, T &b) { a=a^b;b=a^b;a=a^b;}
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007

    int n;
    while(~getI(n))
    {
        int len = n*2;
        getchar();
        string st;
        getline(cin,st);
        map <char,int> mp,koto;
        map <char,char> res;
        FOR(i,0,len-1)
        {
            mp[st[i]]++;
        }
        FOR(i,0,3)
        {
            char c = i+'A';
            koto[c]=n-mp[c];
        }

        char ch;
        FOR(i,0,len-1)
        {
            if(i==0)
            {
                FOR(j,0,3)
                {
                    if(koto[j+65] && st[i]!=j+65)
                    {
                        printf("%c",j+65);
                        koto[j+65]--;
                        ch=j+65;
                        break;
                    }
                }
            }
            else
            {
                FOR(j,0,3)
                {
                    if(ch!=j+65 && koto[j+65] && st[i]!=j+65)
                    {
                        printf("%c",j+65);
                        koto[j+65]--;
                        ch = j+65;
                        break;
                    }
                }
            }
        }
//
//        FOR(i,0,3)
//        {
//            FOR(j,0,3)
//            {
//                if(i==j) continue;
//                char c1 = i+'A';
//                char c2 = j+'A';
//                debug(c1,c2,mp[c1],koto[c2])
//                if(mp[c1]==koto[c2])
//                {
//                    mp[c1]=-1;
//                    koto[c2]=-2;
//                    res[c1]=c2;
//                    res[c2]=c1;
//                }
//            }
//        }
//        FOR(i,0,len-1)
//        {
//            printf("%c",res[st[i]]);
//        }
        printf("\n");
    }

    return 0;
}



