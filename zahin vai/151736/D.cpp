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

#define dipta00
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
/// Check SZ, mod, base
/// makeHashTableForForward / Backward after each input
/// for query call getForwardHashingQuery / Backward

const int SZ = 1e6+4;
ll forwardHashTable[SZ];
ll backwardHashTable[SZ];
ll power[SZ];

class Hashing
{
    const ll mod = 1e9+7;
    const ll base = 10007;
public:
    Hashing()
    {
        power[0]=1;
        for(int i=1;i<SZ;i++)
        {
            power[i] = (power[i-1] * base) % mod;
        }
    }
    
    ll MOD(ll x)
    {
        return (x%mod+mod)%mod;
    }
    
    void makeForwardHashTable(string st)
    {
        CLR(forwardHashTable);
        int len = st.size();
        for(int i=0;i<len;i++)
        {
            int kk = st[i] - ' ';
            if(i)
            {
                forwardHashTable[i] = ((forwardHashTable[i-1]*base)%mod + kk)%mod;
                continue;
            }
            forwardHashTable[i] = kk;
        }
    }
    
    void makeBackwardHashTable(string st)
    {
        CLR(backwardHashTable);
        int len = st.size();
        for(int i=len-1;i>=0;i--)
        {
            int kk = st[i] - ' ';
            if(i!=len-1)
            {
                backwardHashTable[i] = ((backwardHashTable[i+1]*base)%mod + kk)%mod;
                continue;
            }
            backwardHashTable[i] = kk;
        }
    }
    
    ll getForwardHashingQuery(int left, int right)
    {
        if(left==0)
        {
            return forwardHashTable[right];
        }
        ll ret = MOD(forwardHashTable[right] - (forwardHashTable[left-1] * power[right-left+1])%mod );
        return ret;
    }
    
    ll getBackwardHashingQuery(int left, int right)
    {
        ll ret = MOD(backwardHashTable[left] - (backwardHashTable[right+1] * power[right-left+1])%mod );
        return ret;
    }
};




int main() {
#ifdef dipta007
    READ("/Users/dipta007/CLionProjects/untitled/in.txt");
    //WRITE("out.txt");
#endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int t;
    cin >> t;
    Hashing helper;
    FOR(ci,1,t)
    {
        string st;
        cin >> st;
        helper.makeForwardHashTable(st);
        helper.makeBackwardHashTable(st);
        
        int len = st.size()-1;
        int low = 0, high = st.size()-1;
        int resStrt, resSz;
        
        while (low <= high)
        {
            int mid = (low + high)/2;
            
            ll now = helper.getForwardHashingQuery(0,mid);
            
            int flg=0;
            FOR(i, 0, (int)len-mid)
            {
                ll ki = helper.getBackwardHashingQuery(i, i+mid);
                if(ki==now)
                {
                    flg=1;
                    resStrt = i;
                }
            }
            //debug(low, high, mid, now, flg)
            if(flg)
            {
                resSz = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        debug(resStrt, resSz)
        string res = "";
        FOR(i,resStrt, resStrt+resSz)
        {
            res += st[i];
        }
        cout << res << endl;
    }
    return 0;
}







