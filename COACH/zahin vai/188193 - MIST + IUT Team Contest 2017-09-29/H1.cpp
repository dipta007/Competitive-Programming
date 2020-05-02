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
#define    bitCount(a)        __builtin_popcount(a)
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
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

int n,m,k;
//pii arr[2004];
int tot;
int dp[2004][2004];
string st;

int call(int in, int baki)
{
    if(in >= n+n) return 0;
    if(baki<=0) return 0;
    if(baki <= k) return 1;

    int &ret = dp[in][baki];
    if(ret!=-1) return ret;

    ROF(i,min(k,baki), 1)
    {
        if(baki - i >= 0)
        {
            if(st[in] == st[in+1] && call(in+1, baki-i) == 1) return ret = 1;
            else if(st[in] != st[in+1] && call(in+1, baki-i) == 0) return ret = 1;
        }
        else break;
    }
    return ret = 0;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        cin >> n >> m >> k;
//        string st;
        cin >> st;
        st += "#";

//        int in = 0;
//        arr[0].ff = 1;
//        arr[0].ss = k;
        char ch = st[0];
//        FOR(i,1,n+n-1)
//        {
//            if(st[i]==st[i-1])
//            {
//                arr[in].ff++;
//                arr[in].ss += k;
//            }
//            else
//            {
//                in++;
//                arr[in].ff = 1;
//                arr[in].ss = k;
//            }
//        }

//        FOR(i,0,in)
//        {
//            debug(i, arr[i].ff, arr[i].ss);
//        }

//        tot = in+1;
        SET(dp);
        int kk = call(0,m);

        cout << "Case #" << ci << ": ";
        if(kk==0)
        {
            if(ch == 'A') cout << "B";
            else cout << "A";
        }
        else
        {
            if(ch == 'B') cout << "B";
            else cout << "A";
        }
        cout << endl;

    }

    return 0;
}




