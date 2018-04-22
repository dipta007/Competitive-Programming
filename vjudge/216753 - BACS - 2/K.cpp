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

#define dipta0
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

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

const int NX = 1016 ;

ll dp[2][NX][2][NX];
int vis[2][NX][2][NX];
int lim, tt,k ;
vector < int > inp ;
ll mod = 1e9 + 7;

ll DP( int pos, int isSmall, int value, int last)
{
    if( pos >= lim ) return value ;

    ll &ret = dp[isSmall][pos][value][last];
    int &v = vis[isSmall][pos][value][last];
     if(isSmall && v == tt ) return ret ;
    v = tt ;

    int ses = isSmall ? 9 : inp[pos];
    ret = 0 ;
    for (int i = 0 ; i <= ses ; i++ )
    {
        if( i==4 || i==7 )
        {
            if(value > 0) ret += DP(pos+1, isSmall | (i < inp[pos]), 1, 0);
            else
            {
                if(last != 0)
                {
                    int dis = pos - last;
                    if(dis <= k) ret += DP(pos+1, isSmall | (i < inp[pos]), 1, pos);
                    else ret += DP(pos+1, isSmall | (i < inp[pos]), value, pos);
                }
                else ret += DP(pos+1, isSmall | (i < inp[pos]), value, pos);

            }
        }
        else ret += DP( pos + 1, isSmall | (i < inp[pos]), value, last);

        ret %= mod;
    }
    return ret ;
}

string normalize(string &st) {
    string tmp = "";
    int flg = 0;
    FOR(i,0,(int)st.size()-1)
    {
        if(flg)
        {
            tmp += st[i];
            continue;
        }
        if(st[i] > '0')
        {
            flg = 1;
            tmp += st[i];
        }
    }
    return tmp;
}

string dec(string &st) {
    ROF(i, st.size()-1, 0)
    {
        if(st[i] == '0') st[i] = '9';
        else
        {
            st[i] = st[i] - 1;
            return normalize(st);
        }
    }
}

ll Cal( string &x )
{
    if(x.size() == 0) return 0;

    int kk = 1004 - x.size();
    string tmp = "";
    FOR(i,1,kk) tmp += "0";

    x = tmp + x;
    // debug("sz", x.size())
    inp.clear();
    inp.PB(0);
    FOR(i,0,(int)x.size()-1)
    {
        int kk = x[i] - '0';
        inp.PB(kk);
    }
//    tt++;
    // reverse(inp.begin(),inp.end());
    lim = inp.size();
    return DP( 1, 0, 0, 0 );
}

ll MOD(ll x)
{
    return (x%mod + mod ) %mod;
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);

   // debug(Cal("77"))
    int t;
    getII(t,k);
    CLR(vis);
    tt = 0;
    tt = 1;
    FOR(ci,1,t)
    {
        string l,r;
        cin >> l >> r;

        l = dec(l);
        // debug(l, r, Cal(l), Cal(r))

        printf("%lld\n", MOD(Cal(r) - Cal(l)));
    }


    return 0;
}
