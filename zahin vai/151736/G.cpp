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
#include <unordered_map>
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
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 unsigned long long
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

/// Hashing
/// Check SZ, mod, base, index of (base, mod)
/// makeHashTableForForward / Backward after each input
/// for query call getForwardHashingQuery / Backward

const int SZ = 1e5+4;
ll forwardHashTable[2][SZ];
ll backwardHashTable[2][SZ];
ll power[2][SZ];

class Hashing
{
    const long long mod[2] = {1000000007LL, 2117566807LL};
    const long long base[2] = {1572872831LL, 1971536491LL};
public:
    Hashing()
    {
        power[0][0]=1;
        power[1][0]=1;
        for(int i=0;i<2;i++)
        {
            for(int j=1;j<SZ;j++)
            {
                power[i][j] = (power[i][j-1] * base[i]);
            }
        }
    }

    ll MOD(ll x, int index)
    {
        return (x%mod[index]+mod[index])%mod[index];
    }

    void makeForwardHashTable(string st)
    {
        int len = st.size();

        for(int in=0; in<1; in++)
        {
            for(int i=0;i<len;i++)
            {
                int kk = st[i] - ' ';
                if(i)
                {
                    forwardHashTable[in][i] = ((forwardHashTable[in][i-1]*base[in]) + kk);
                    continue;
                }
                forwardHashTable[in][i] = kk;
            }
        }
    }

    ll getForwardHashingQuery(int left, int right)
    {
        if(left==0)
        {
            return forwardHashTable[0][right];
            return (forwardHashTable[0][right] << 31) | forwardHashTable[1][right];
        }
        ll ret1 = (forwardHashTable[0][right] - (forwardHashTable[0][left-1] * power[0][right-left+1]));
//        ll ret2 = (forwardHashTable[1][right] - (forwardHashTable[1][left-1] * power[1][right-left+1]));
//        ll ret = (ret1 << 31) | ret2;
        return ret1;
    }
};


int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    getI(t);
    Hashing helper;
    FOR(ci,1,t)
    {
        string st;
        cin >> st;
        int len = st.size();
        unordered_map < ll, int> mp;
        int cnt=0;
        for(int ik=1;ik<=len;ik++)
        {
            FOR(i,0,len-ik)
            {
                string stt = st.substr(i, ik);
                stt = stt + stt;
                helper.makeForwardHashTable(stt);
                int flg=1;
                ll now;
                FOR(j,0,ik-1)
                {
                    now = helper.getForwardHashingQuery(j, j+ik-1);
                    if(mp[now]==1)
                    {
                        flg=0;
                        break;
                    }
                }
                if(flg)
                {
                    mp[now]=1;
                    //debug(stt.substr(0,ik),stt)
                    cnt++;
                }
//                FOR(j,0,ik-1)
//                {
//                    ll now = helper.getForwardHashingQuery(j, j+ik-1);
//                    mp[now]=1;
//                }
            }
        }
        cout << cnt <<endl;
    }

    return 0;
}



