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

#define dipta00
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

int r,c,k;
string grid[504];
int dp[504][504];

int cls[504][504];
int tot[504];

int call(int i, int kk)
{
    if(i >= r) return 0;

    int &ret = dp[i][kk];
    if(ret != -1) return ret;

    ret = INF;
    FOR(j,0,kk)
    {
        int baki = tot[i] - j;
        if(baki < 0) ret = min(ret, call(i+1, kk-j));
        else ret = min(ret, call(i+1, kk - j) + cls[i][baki]);
    }

    return ret;
}


int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    while(cin >> r >> c >> k)
    {
        CLR(tot);
        FOR(i,0,r-1)
        {
            cin >> grid[i];

            FOR(j,0,c-1)
            {
                tot[i] += (grid[i][j] == '1');
            }
        }

        CLR(cls);
        FOR(i,0,r-1)
        {
            FOR(j,1,c)
            {
                cls[i][j] = INF;
            }
        }
        repI(i,r)
        {
            repI(j,c)
            {
                int clshoise = 0;
                FOR(k,j,c-1)
                {
                    if(grid[i][k] == '1')clshoise++;
                    cls[i][clshoise] = min(cls[i][clshoise], k - j + 1);
                }
            }
        }


//        FOR(i,0,r-1) /// oi din
//        {
//            FOR(kk, 0, c) /// kk ta cls korbo
//            {
//                int o1 = 0;
//                int cnt = 0;
//                for(int j=0; j<c && cnt < kk; j++)
//                {
//                    if(grid[i][j] == '1') cnt++;
//
//                    if(cnt > 0) o1++;
//                }
//
//                int o2 = 0;
//                cnt = 0;
//                for(int j=c-1; j>=0 && cnt < kk; j--)
//                {
//                    if(grid[i][j] == '1') cnt++;
//
//                    if(cnt > 0) o2++;
//                }
//
//                cls[i][kk] = min(o1, o2);
//            }
//        }

//        FOR(i,0,r-1)
//        {
//            FOR(j,0,4)
//            {
//                debug(i, j, cls[i][j])
//            }
//        }

//        CLR(dp);
//        FOR(i,0,r-1) /// oi din
//        {
//            FOR(kk, 0, k) /// kk ta bad dibo
//            {
//                int baki = tot[i] - kk;
//                if(baki < 0)
//                {
//                    dp[i][kk] = dp[i][kk-1];
//                    continue;
//                }
//
//                if(i==0) dp[i][kk] = cls[i][baki];
//                else if(kk==0) dp[i][kk] = cls[i][baki] + dp[i-1][k];
//                else dp[i][kk] = min(cls[i][baki] + dp[i-1][k - kk], dp[i][kk-1]);
//
//                debug(i, kk, baki, dp[i][kk], cls[i][baki])
//            }
//        }

        SET(dp);
        cout << call(0, k) << endl;
    }


    return 0;
}


