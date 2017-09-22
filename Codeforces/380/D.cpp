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
#define    FOR(i,L,R) 	     for (int i = (int)(L); i <= (int)(R); i++)
#define    ROF(i,L,R) 	     for (int i = (int)(L); i >= (int)(R); i--)
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
//    #ifdef dipta007
//        READ("aplusb.in");
//        WRITE("aplusb.out");
//    #endif // dipta007

    int n,a,b,k;
    while(~getII(n,a))
    {
        getII(b,k);
        getchar();
        string st;
        getline(cin,st);

        int ship = b;
        int totShip = a*b;

//        int a[n];
//        FOR(i,0,n-1)
//        {
//            if(!i)
//            {
//                a[i] = st[i] - '0';
//            }
//            else
//            {
//                a[i] = a[i-1] + (st[i]-'0');
//            }
//        }
        int last = 0;
        int totLen = 0;
        vector < pair < pii , pii > > vpp,kom;
        FOR(i,0,(int)st.size()-1)
        {
            if(st[i]=='1')
            {
                int len = i-last;
                if(len>=ship)
                {
                    totLen += (len/b);
                    vpp.PB( MP(MP(len,len/b), MP(last, i-1)));
                }
                last=i+1;
            }
            debug(totLen)
        }
        if(last!=n)
        {
            int len = n-last;
            debug(totLen,len)
            if(len>=ship)
            {
                totLen+=len/b;
                vpp.PB( MP(MP(len,len/b), MP(last, n-1)));
            }
        }

        sort(ALL(vpp));
        vi res;

        FOR(i,0,(int)vpp.size()-1)
        {
            debug(totLen,totShip)
            if(totLen<a) break;
            pair <pii, pii> p = vpp[i];
//            if(p.ff < totShip*2)
//            {
//                kom.PB(p);
//                continue;
//            }
            debug("*",p.ss.ff,p.ss.ss)
            int tmpLen = totLen;
            for(int j = p.ss.ff+ship-1; j<=p.ss.ss; j+= ship)
            {
                debug(j)
                res.PB(j+1);
                tmpLen --;
                if(tmpLen<a) break;
            }
            totLen -= p.ff.ss;
        }

//        FOR(i,0,(int)kom.size()-2)
//        {
//            pair <int, pii> p = kom[i];
//            for(int j = p.ss.ff+ship-1; j<=p.ss.ss; j+= ship)
//            {
//                res.PB(j+1);
//            }
//        }
//        if(kom.size()>0)

////        if(totLen>=totShip)
////        {
////            pair <int, pii> p = vpp[vpp.size()-1];
////            if(p.ff>=totShip)
////            {
////                int bosha = ship * (a-1);
////                p.ss.ff = p.ss.ff + bosha ;
////                int tmpLen = totLen;
////                for(int j=p.ss.ff+ship-1;j<=p.ss.ss;j+=ship)
////                {
////                    res.PB(j+1);
////                    tmpLen -= ship;
////                    if(tmpLen<totShip) break;
////                }
////            }
////            totLen -= p.ff;
//////            res.PB(p.ss.ff+ship-1+1);
////        }

        printf("%d\n",res.size());
        FOR(i,0,(int)res.size()-1)
        {
            if(i) printf(" ");
            printf("%d",res[i]);
        }
        printf("\n");
    }

    return 0;
}




