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
/// Check SZ, modd, baseee
/// makeHashTableForForward / Backward after each input
/// for query call getForwardHashingQuery / Backward

const int SZ = 1e5+4;
ll forwardHashTable[SZ];
ll backwardHashTable[SZ];
ll power[SZ];
const ll modd = 1e9+7;
const ll baseee = 10007;

class Hashing
{
    
public:
    Hashing()
    {
        power[0]=1;
        for(int i=1;i<SZ;i++)
        {
            power[i] = (power[i-1] * baseee) % modd;
        }
    }
    
    ll MOD(ll x)
    {
        return (x%modd+modd)%modd;
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
                forwardHashTable[i] = ((forwardHashTable[i-1]*baseee)%modd + kk)%modd;
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
                backwardHashTable[i] = ((backwardHashTable[i+1]*baseee)%modd + kk)%modd;
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
        ll ret = MOD(forwardHashTable[right] - (forwardHashTable[left-1] * power[right-left+1])%modd );
        return ret;
    }
    
    ll getBackwardHashingQuery(int left, int right)
    {
        ll ret = MOD(backwardHashTable[left] - (backwardHashTable[right+1] * power[right-left+1])%modd );
        return ret;
    }
};




int main() {
#ifdef dipta007
    READ("/Users/dipta007/CLionProjects/untitled/in.txt");
    //WRITE("out.txt");
#endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n;
    Hashing helper;
    while(cin >> n)
    {
        string st;
        cin >> st;
        helper.makeForwardHashTable(st);
        helper.makeBackwardHashTable(st);
        
        int len = st.size()-1;
        
        int res = 1;
        FOR(i,0,len)
        {
            int low = 0, high = min(i, len-i);
            while(low <= high)
            {
                int mid = ( low + high ) / 2;
                ll left = helper.getForwardHashingQuery(i - mid, i + mid);
                ll right = helper.getBackwardHashingQuery(i - mid, i + mid);
                if( left == right )
                {
                    res = max(res, mid + mid + 1);
                    low = mid + 1;
                } else high = mid - 1;
            }
        }
        
        FOR(i,0,len-1)
        {
            if(st[i]==st[i+1])
            {
                int low = 0, high = min(i, len-i-1);
                while(low <= high)
                {
                    int mid = ( low + high ) / 2;
                    ll left = helper.getForwardHashingQuery(i - mid, i + mid + 1);
                    ll right = helper.getBackwardHashingQuery(i - mid, i + mid + 1);
                    if( left == right )
                    {
                        res = max(res, mid + mid + 2);
                        low = mid + 1;
                    } else high = mid - 1;
                }
            }
        }
        
        cout << res << endl;
    }
    return 0;
}
