#pragma comment(linker, "/stack:640000000")
#include <bits/stdc++.h>
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
#define    bitFlip(a,k)      (a^(1<<(k)))
#define    bitCount(a)        __builtin_popcount(a)
#define    bitCountLL(a)      __builtin_popcountll(a)
#define    bitLeftMost(a)     (63-__builtin_clzll((a)))
#define    bitRightMost(a)    (__builtin_ctzll(a))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    POPCOUNT           __builtin_popcount
#define    POPCOUNTLL         __builtin_popcountll
#define    RIGHTMOST          __builtin_ctzll
#define    LEFTMOST(x)        (63-__builtin_clzll((x)))

template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }

#ifdef dipta007
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
     #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cerr << name << " : " << arg1 << std::endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
#else
    #define debug(args...)  /// Just strip off all debug tokens
    #define trace(...) ///yeeeee
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///****************** template ends here ****************
int t,n,m;

int bit[102];
int r,c;
ull dp[104][(1<<8)+4];
int vis[104][(1<<8)+4];
int tt;

ull call(int in, int mask);
ull gen(int rr, int cc, int now, int fut)
{
    if(cc >= c) return call(rr+1, fut);
    if(bitCheck(now, cc) == 1) return gen(rr, cc+1, now, fut);

    ull ret = 0;
    int fstIn = cc;
//    FOR(i,0,c-1) if(bitCheck(now, i) == 0) { fstIn = i; break; }
    if(fstIn < c && fstIn+1 < c)
    {
        /// **
        if(bitCheck(now, fstIn)==0 && bitCheck(now, fstIn+1)==0)
        {
            int tmp = now;
            tmp = bitOn(tmp, fstIn);
            tmp = bitOn(tmp, fstIn+1);
            ret += gen(rr, fstIn+2, tmp, fut);
        }
        /// *
        /// **
        if(bitCheck(now, fstIn)==0 && bitCheck(fut, fstIn)==0 && bitCheck(fut, fstIn+1)==0)
        {
            int tmp = fut;
            tmp = bitOn(tmp, fstIn);
            tmp = bitOn(tmp, fstIn+1);
            ret += gen(rr, fstIn+1, bitOn(now, fstIn), tmp);
        }

        /// **
        /// *
        if(bitCheck(now, fstIn)==0 && bitCheck(now, fstIn+1)==0 && bitCheck(fut, fstIn)==0)
        {
            int tmp = now;
            tmp = bitOn(tmp, fstIn);
            tmp = bitOn(tmp, fstIn+1);
            ret += gen(rr, fstIn+2, tmp, bitOn(fut, fstIn));
        }

        /// **
        ///  *
        if(bitCheck(now, fstIn)==0 && bitCheck(now, fstIn+1)==0 && bitCheck(fut, fstIn+1)==0)
        {
            int tmp = now;
            tmp = bitOn(tmp, fstIn);
            tmp = bitOn(tmp, fstIn+1);
            ret += gen(rr, fstIn+2, tmp, bitOn(fut, fstIn+1));
        }
    }

    if(fstIn < c && rr<r-1)
    {
        ///  *
        /// **
        if(fstIn-1 >= 0 && bitCheck(now, fstIn)==0 && bitCheck(fut, fstIn-1)==0 && bitCheck(fut, fstIn)==0)
        {
            int tmp = fut;
            tmp = bitOn(tmp, fstIn);
            tmp = bitOn(tmp, fstIn-1);
            ret += gen(rr, fstIn+1, bitOn(now, fstIn), tmp);
        }
    }

    /// *
    /// *
    if(rr < r-1 && fstIn < c && bitCheck(now, fstIn)==0 && bitCheck(fut,fstIn)==0)
    {
        ret += gen(rr, fstIn+1, bitOn(now, fstIn), bitOn(fut, fstIn));
    }

    return ret;
}

ull call(int in, int mask)
{
    if(in >= r)
    {
        trace(mask);
        return mask == 0;
    }
    ull &ret = dp[in][mask];

    if(vis[in][mask] == tt) return ret;
    vis[in][mask] = tt;

    ret = gen(in, 0, mask, bit[in+1]);

    return ret;
}

int main() {
    #ifdef dipta007
//        READ("in.txt");
//        WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    tt = 0;
    CLR(vis);
    FOR(ci,1,t)
    {
        tt = ci;
        cin >> r >> c;

        CLR(bit);
        if(r < c)
        {
            string st[r];
            FOR(i,0,r-1)
            {
                cin >> st[i];
            }

            FOR(i,0,c-1)
            {
                FOR(j,0,r-1)
                {
                    if(st[j][i] == '#') bit[i] = bitOn(bit[i], j);
                }
            }
            swap(r,c);
        }
        else
        {
            FOR(i,0,r-1)
            {
                string st;
                cin >> st;
                FOR(j,0,c-1)
                {
                    if(st[j]=='#') bit[i] = bitOn(bit[i], j);
                }
            }
        }

        trace(bit[r], bitCount(bit[r]));

        cout << "Case " << ci << ": " << call(0, bit[0]) << endl;
    }

    return 0;
}



