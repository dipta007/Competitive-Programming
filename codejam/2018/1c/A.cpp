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
#define    sf scanf
#define    pf printf
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

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

const int MS = 1000004;
const int MN = 30;

bitset < 30 > b[12];

struct trie
{
    struct node
    {
        int c, child;
        int a[MN];
    };

    node tree[MS];
    void clear()
    {
        tree[nodes].c = 0;
        tree[nodes].child = 0;
        memset(tree[nodes].a, -1, sizeof tree[nodes].a);
        nodes++;
    }

    int gid(char ch)
    {
        return (int)(ch - 'A');
    }

    int nodes;

    void init()
    {
        nodes = 0;
        clear();
    }

    void add(const string &s, bool query = 0)
    {
        int cur_node = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            int id = gid(s[i]);
            if(tree[cur_node].a[id] == -1)
            {
                tree[cur_node].a[id] = nodes;
                clear();
            }
            cur_node = tree[cur_node].a[id];
        }
        tree[cur_node].c++;
    }

    int dfs(int now)
    {
        int ret = 0;
        FOR(i,0,25) if(tree[now].a[i] != -1) ret++;

        FOR(i,0,25)
        {
            if(tree[now].a[i] != -1)
            {
                ret += dfs(tree[now].a[i]);
            }
        }
        tree[now].child = ret;
        return ret;
    }

    string query(int l)
    {
        int cur_node = 0;
        string st = "";
        int flg = 0;
        FOR(i,0,l-1)
        {
            int mn = INF, in;

            FOR(j,0,25)
            {
                    debug(i, j, b[i].test(j))
                if(tree[cur_node].a[j] == -1 && b[i].test(j) == 1)
                {

                    flg = 1;
                    in = j;
                    break;
                }
                if(tree[cur_node].a[j] != -1)
                {
                    int now = tree[cur_node].a[j];
                    debug(tree[now].child)
                    if(tree[now].child < mn)
                    {
                        mn = tree[now].child;
                        in = j;
                    }
                }
            }

//            debug(i, mn, in)
            char ch = in+'A';
            st += ch;

            if(flg) return st;
            cur_node = tree[cur_node].a[in];

        }
        return "-";
    }
} helper;



int main() {
    #ifdef dipta007
        //READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        helper.init();
        int r,c;
        cin >> r >> c;

        FOR(i,0,c-1) b[i].reset();

        string mst = "";
        FOR(i,1,r)
        {
            string st;
            cin >> st;
            mst = st;
            helper.add(st);

            FOR(j,0,c-1)
            {
                int kk = st[j] - 'A';
                b[j].set(kk);
            }
        }

        helper.dfs(0);

        string res = helper.query(c);
        cout << "Case #" << ci << ": ";
        if(res == "-") cout << "-" << endl;
        else
        {
            int now = res.size();
            FOR(j,(int)now, c-1)
            {
                res += mst[j];
            }
            cout << res << endl;
        }
    }

    return 0;
}


