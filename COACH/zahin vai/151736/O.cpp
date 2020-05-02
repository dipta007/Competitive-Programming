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

/// Hashing
/// Check SZ, mod, base, index of (base, mod)
/// makeHashTableForForward / Backward after each input
/// for query call getForwardHashingQuery / Backward

const int SZ = 1e6+4;
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
                power[i][j] = (power[i][j-1] * base[i]) % mod[i];
            }
        }
    }

    ll MOD(ll x, int index)
    {
        return (x%mod[index]+mod[index])%mod[index];
    }

    void makeForwardHashTable(string st)
    {
        CLR(forwardHashTable);
        int len = st.size();

        for(int in=0; in<2; in++)
        {
            for(int i=0;i<len;i++)
            {
                int kk = st[i] - ' ';
                if(i)
                {
                    forwardHashTable[in][i] = ((forwardHashTable[in][i-1]*base[in])%mod[in] + kk)%mod[in];
                    continue;
                }
                forwardHashTable[in][i] = kk;
            }
        }
    }

    void makeBackwardHashTable(string st)
    {
        CLR(backwardHashTable);
        int len = st.size();
        for(int in=0; in<2; in++)
        {
            for(int i=len-1;i>=0;i--)
            {
                int kk = st[i] - ' ';
                if(i!=len-1)
                {
                    backwardHashTable[in][i] = ((backwardHashTable[in][i+1]*base[in])%mod[in] + kk)%mod[in];
                    continue;
                }
                backwardHashTable[in][i] = kk;
            }
        }
    }

    ll getForwardHashingQuery(int left, int right)
    {
        if(left==0)
        {
            return (forwardHashTable[0][right] << 31) | forwardHashTable[1][right];
        }
        ll ret1 = MOD(forwardHashTable[0][right] - (forwardHashTable[0][left-1] * power[0][right-left+1])%mod[0] , 0);
        ll ret2 = MOD(forwardHashTable[1][right] - (forwardHashTable[1][left-1] * power[1][right-left+1])%mod[1] , 1);
        ll ret = (ret1 << 31) | ret2;
        return ret;
    }

    ll getBackwardHashingQuery(int left, int right)
    {
        ll ret1 = MOD(backwardHashTable[0][left] - (backwardHashTable[0][right+1] * power[0][right-left+1])%mod[0] , 0);
        ll ret2 = MOD(backwardHashTable[1][left] - (backwardHashTable[1][right+1] * power[1][right-left+1])%mod[1] , 1);
        ll ret = (ret1 << 31) | ret2;
        return ret;
    }

    ll get(string st)
    {
        int len = st.size();

        ll a[2];
        for(int in=0; in<2; in++)
        {
            for(int i=0;i<len;i++)
            {
                int kk = st[i] - ' ';
                if(i)
                {
                    a[in] = ((a[in]*base[in])%mod[in] + kk)%mod[in];
                    continue;
                }
                a[in] = kk;
            }
        }

        return (a[0] << 31) | a[1] ;
    }
};



int main() {
    #ifdef dipta007
        //READ("in.txt");
        //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    Hashing helper;
    while(cin >> n)
    {
        if(n==0) break;

        vector < string > vs[74];
        unordered_map < string, int> pos;
        FOR(i,0,n-1)
        {
            string st;
            cin >> st;
            vs[st.size()].PB(st);
            pos[st]=0;
        }

        string mst;
        cin >> mst;
        int len = mst.size();
        helper.makeForwardHashTable(mst);

        int maxy = 0;
        vi v;
        unordered_map < string, int> koiber;
        FOR(i,1,70)
        {
            if(vs[i].size()==0) continue;
            vector < ll > hashVal;
            map < ll, string > rev;
            FOR(j,0,(int)vs[i].size()-1)
            {
                string st = vs[i][j];
                ll now = helper.get(st);
                hashVal.PB(now);
                rev[now] = st;
            }
            int cnt=0;
            FOR(j,0,len - i)
            {
                ll val = helper.getForwardHashingQuery(j, j+i-1);
                if(rev.find(val)!=rev.end())
                {
                    string stt = rev[val];
                    //debug("ase",stt)
                    koiber[stt]++;

                    maxy = max(maxy, koiber[stt]);
                }
            }
        }

        cout << maxy << endl;
        vector < pair < int, string > > ans;
        FOR(i,1,70)
        {
            FOR(j,0,(int)vs[i].size()-1)
            {
                if(koiber[vs[i][j]]==maxy)
                {
                    //debug(vs[i][j])
                    ans.PB( MP(pos[vs[i][j]] , vs[i][j]));
                }
            }
        }
        sort(ALL(ans));
        FOR(i,0,(int)ans.size()-1)
        {
            cout << ans[i].ss << endl;
        }
    }

    return 0;
}



