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

vector < string > vs[104];
int n;
string no;
map <string, vi > mp;
int segTot;
int dp[104][600004]
int dp2[104][104]

int matchIt(int seg, int in, int ni, int num)
{
    if(in < 0) return ni;

    vi v = mp[vs[seg][in]];

    int ret = -1;
    for(auto val: v)
    {
        int in = ni;
        int flg = 1;
        FOR(i,1,val)
        {
            int kk = st[in] - '0';
            if(kk == num) in++;
            else
            {
                flg = 0;
                break;
            }
        }
        if(flg) ret =
    }
}


int call(int in, int ni)
{
    if(ni >= n) return 1;
    if(in >= segTot) return 0;

    int &ret = dp[in];
    if(ret != -1) return ret;

    ret = 0;
    ret = ret || call(in+1, ni);

    vi v = mp[vs[in].back()];
    int kk = no[ni] - '0';
    for(auto val: v)
    {
        if(val == kk)
        {
            int index = matchIt(in, vs[in].size()-2, ni+1, kk);
            if(index < 0) continue;
            ret = ret || call(in+1, index+1);
        }
    }
    return ret;
}



void tockenizer(string st)
{
    vs.clear();
    string tmp = "";
    int len = st.size();
    segTot = 0;
    FOR(i,0,len-1)
    {
        if(st[i] == '.' || st[i] == ',')
        {
//            if(tmp.size() != 0) vs.PB(tmp);
            segTot++;
            tmp = "";
        }
        else if(st[i] == ' ')
        {
            vs[segTot].PB(tmp);
            tmp = "";
        }
        else tmp += st[i];
    }
    if(tmp.size()!=0) vs[segTot].PB(tmp);
}

int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
   // ios_base::sync_with_stdio(0);cin.tie(0);


    int t;
    cin >> t;

    mp["zero"].PB(0);
    mp["one"].PB(1);
    mp["two"].PB(2);
    mp["three"].PB(3);
    mp["four"].PB(4);
    mp["five"].PB(5);
    mp["six"].PB(6);
    mp["seven"].PB(7);
    mp["eight"].PB(8);
    mp["nine"].PB(9);

    mp["odd"].PB(1);
    mp["odd"].PB(3);
    mp["odd"].PB(5);
    mp["odd"].PB(7);
    mp["odd"].PB(9);

    mp["even"].PB(0);
    mp["even"].PB(2);
    mp["even"].PB(4);
    mp["even"].PB(6);
    mp["even"].PB(8);

    FOR(ci,1,t)
    {
        string tmp;
        getline(cin, tmp);

        tockenizer(tmp);

        cin >> n;
        cin >> no;


    }

    return 0;
}

