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

string s1, s2;
ll dp[3004][3004][2];
int pp[3004][3004][2];
ll b, ins, del, cpy;

ll call(int i, int j, int flg)
{
    ll &ret = dp[i][j][flg];
    if(i >= s1.size())
    {
        /// sb insert;
        ll kk = s2.size() - j;
        return ret = kk*ins;
    }
    if(j >= s2.size())
    {
        /// sb delete;
        ll kk = s1.size() - i;
        return ret = min(kk*del, b);
    }

    if(ret != -1) return ret;

    ret = INF;
    if(flg)
    {
        ll o1 = call(i+1, j, flg);
        ll o2 = call(i, j, 0);

        if(o1 < o2) pp[i][j][flg] = 1;
        else pp[i][j][flg] = 2;

        return ret = min(o1, o2);
    }
    else
    {
        ll o1 = b + call(i+1, j, 1);
        ll o2 = INF;
        if(s1[i] == s2[j])
        {
            o2 = cpy + call(i+1, j+1, flg);
        }
        ll o3 = del + call(i+1, j, flg);
        ll o4 = ins + call(i, j+1, flg);

        if(o2<=o1 && o2<=o3 && o2<=o4)
        {
            pp[i][j][flg] = 2;
            return ret = o2;
        }
        if(o3<=o1 && o3<=o2 && o3<=o4)
        {
            pp[i][j][flg] = 3;
            return ret = o3;
        }
        if(o4<=o1 && o4<=o3 && o4<=o2)
        {
            pp[i][j][flg] = 4;
            return ret = o4;
        }
        if(o1<=o2 && o1<=o3 && o1<=o4)
        {
            pp[i][j][flg] = 1;
            return ret = o1;
        }
    }

    return ret;
}

vector < pii > vp;
string res;

void path(int i, int j, int flg, int prev)
{
    if(i >= s1.size())
    {
        if(flg)
        {
            vp.push_back(MP(prev, i-1));
        }
        /// sb insert;
        int kk = s2.size() - j;
        FOR(k,1,kk) res += "I";
        return;
    }
    if(j >= s2.size())
    {
        /// sb delete;
        ll kk = s1.size() - i;
        if( b<kk*del)
        {
            vp.PB(MP(i, s1.size()-1));
            return;
        }
        FOR(k,1,kk) res += "D";
        return;
    }

    if(flg)
    {
        int kk = pp[i][j][flg];
        if(kk==1)
        {
            path(i+1, j, flg, prev);
        }
        else
        {
            pii p = MP(prev, i-1);
            vp.PB(p);
            path(i, j, 0, -1);
        }
    }
    else
    {
        int kk = pp[i][j][flg];

        if(kk == 1)
        {
            path(i+1, j, 1, i);
        }
        else if(kk == 2)
        {
            res += "C";
            path(i+1, j+1, flg, prev);
        }
        else if(kk == 3)
        {
            res += "D";
            path(i+1, j, flg, prev);
        }
        else if(kk == 4)
        {
            res += "I";
            path(i, j+1, flg, prev);
        }
    }

    return;
}

int main() {
//    #ifdef dipta007
        READ("block.in");
       WRITE("block.out");
//    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    while( cin >> b >> ins >> del >> cpy )
    {
        cin >> s1 >> s2;
        SET(dp);
        cout << call(0, 0, 0) << endl;

        res = "";
        vp.clear();
        path(0,0,0,-1);
        cout << vp.size() << endl;
        FOR(i,0,(int)vp.size()-1)
        {
            cout << vp[i].ff+1 << " " << vp[i].ss+1 << endl;
        }
        cout << res << endl;
    }

    return 0;
}

