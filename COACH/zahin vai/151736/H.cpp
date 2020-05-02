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

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef dipta00
#define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;

/// Hashing
/// Check SZ, modd, baseee
/// makeHashTableForForward / Backward after each input
/// for query call getForwardHashingQuery / Backward
/// Hashing
/// Check SZ, mod, base
/// makeHashTableForForward / Backward after each input
/// for query call getForwardHashingQuery / Backward

const int SZ = 2e3+4;
ll forwardHashTable[SZ][SZ];
ll power[SZ];

class Hashing
{
    const ll mod = 1000000007LL;
    const ll base = 1572872831LL;
public:
    Hashing()
    {
        power[0]=1;
        for(int i=1; i<SZ; i++)
        {
            power[i] = (power[i-1] * base) % mod;
        }
    }

    ll MOD(ll x)
    {
        return (x%mod+mod)%mod;
    }

    void makeForwardHashTable(int in, string st)
    {
        int len = st.size();
        for(int i=0; i<len; i++)
        {
            int kk = st[i] - 'o';
            if(i)
            {
                forwardHashTable[in][i] = ((forwardHashTable[in][i-1]*base)%mod + kk)%mod;
                //debug(forwardHashTable[in][i-1], base, forwardHashTable[in][i-1]*base, kk)
                continue;
            }
            forwardHashTable[in][i] = kk;
        }
    }

    ll getForwardHashingQuery(int in, int left, int right)
    {
        if(left==0)
        {
            return (forwardHashTable[in][right])%mod;
        }
        ll ret = MOD(forwardHashTable[in][right] - (forwardHashTable[in][left-1] * power[right-left+1])%mod);
        return ret;
    }

};

void computeLPSArray(ll *pat, int M, ll *lps);
ll *lpss;
int cnt=0;

void KMPSearch(ll *pat, int M, ll *txt, int N)
{

    // create lps[] that will hold the longest prefix suffix values for pattern
    int j  = 0;  // index for pat[]

    // Preprocess the pattern (calculate lps[] array)
//    computeLPSArray(pat, M, lps);

    int i = 0;  // index for txt[]
    while(i < N)
    {
        debug("*",i,j)
        if(pat[j] == txt[i])
        {
            debug("*1")
            j++;
            i++;
        }

        if (j == M)
        {
            debug("*2")
            //printf("Found pattern at index %d \n", j);
            debug(j,lpss[j-1])
            cnt++;
            j = lpss[j-1];
        }

        // mismatch after j matches
        else if(pat[j] != txt[i])
        {
            debug("*3",j, lpss[j-1])
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if(j != 0)
                j = lpss[j-1];
            else
                i = i+1;
        }
    }
    //free(lps); // to avoid memory leak
}

void computeLPSArray(ll *pat, int M, ll *lps)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;

    lps[0] = 0; // lps[0] is always 0
    i = 1;

    // the loop calculates lps[i] for i = 1 to M-1
    while(i < M)
    {
        if(pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            if( len != 0 )
            {
                // This is tricky. Consider the example AAACAAAA and i = 7.
                len = lps[len-1];

                // Also, note that we do not increment i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    debug("lps",lps[0])
}




int main()
{
#ifdef dipta007
    //READ("/Users/dipta007/CLionProjects/untitled/in.txt");
    //WRITE("out.txt");
#endif // dipta007
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Hashing helper;
    int l,r,row,col;
    while(cin >> l >> r)
    {
        cin >> row >> col;
        FOR(i,0,l-1)
        {
            string st;
            cin >> st;
            helper.makeForwardHashTable(i, st);
        }
        ll pat[l];
        FOR(i,0,l-1)
        {
            pat[i] = helper.getForwardHashingQuery(i, 0, r-1);
            //debug(pat[i])
        }
        //continue;
        lpss = (ll *)malloc(sizeof(ll)*l);
        debug(lpss[0])
        computeLPSArray(pat, l, lpss);

        FOR(i,0,row-1)
        {
            string st;
            cin >> st;
            helper.makeForwardHashTable(i, st);
        }

        cnt=0;
        FOR(i,r-1,col-1)
        {
            ll txt[row];
            FOR(j,0,row-1)
            {
                txt[j] = helper.getForwardHashingQuery(j, i-r+1, i);
            }
//            FOR(j,0,row-1)
//            {
//                printf("%lld ",txt[j]);
//            }
//            FOR(j,0,l-1)
//            {
//                printf("%lld ",pat[j]);
//            }
//            printf("\n");
            KMPSearch(pat, l, txt, row);
            debug(i,cnt,"*")
        }
        cout << cnt << endl;

    }
    return 0;
}
