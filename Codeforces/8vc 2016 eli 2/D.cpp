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
#include <iterator>ac
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


ll bit[1000004];
ll bit1[1000004];
void update ( int x, int v )
{
    while ( x < 1000002 )
    {
        bit[x] += v;
        x += x & (-x);
    }
}
ll query ( int x )
{
    ll res = 0;
    while ( x )
    {
        res += bit[x];
        x -= x & (-x);
    }
    return res;
}
void update1 ( int x, int v )
{
    while ( x < 1000002 )
    {
        bit1[x] += v;
        x += x & (-x);
    }
}
ll query1 ( int x )
{
    ll res = 0;
    while ( x )
    {
        res += bit1[x];
        x -= x & (-x);
    }
    return res;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007
//    ios_base::sync_with_stdio(0);cin.tie(0);

    int n,k;
    while(~getII(n,k))
    {
        CLR(bit);
        CLR(bit1);
        int now = 1;
        ll cnt=1;
        FOR(i,1,n)
        {
            int nxt;
            if(now+k<=n) nxt = now+k;
            else nxt = now+k-n;

            int a = now;
            int b = nxt;
            if(a>b) swap(a,b);

            ll bam = query(n)-query(b) + query(a-1);
            ll dan = query1(b-1) - query1(a);
            //debug(i,bam,dan)
            ll nowRes = min(bam,dan);

            ll bam1 = query1(n)-query1(b) + query1(a-1);
            ll dan1 = query(b-1) - query(a);
            nowRes += min(bam1,dan1);

//            debug(i,bam,dan,bam1,dan1,nowRes, query1(n), query1(b), query1(a-1))

            cnt += (nowRes+1);

            ll u1 = (query(a)-query(a-1))+1;
            update(a, 1);
            ll u2 = (query1(b)-query1(b-1))+1;
            update1(b, 1);

//            cout << " small ";
//            FOR(i,1,n)
//            {
//                cout << query(i) - query(i-1) << " ";
//            }
//            cout << endl << " big ";
//            FOR(i,1,n)
//            {
//                cout << query1(i) - query1(i-1) << " ";
//            }
//            cout << endl;

            now = nxt;

            if(i!=1) printf(" ");
            printf("%lld",cnt);
        }
//        debug(cnt)
        printf("\n");

    }

    return 0;
}



