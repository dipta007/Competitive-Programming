#include <bits/stdc++.h>
using namespace std;

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
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
#define    UNIQUE(V)          (V).erase(unique((V).begin(),(V).end()),(V).end())
#define    vi 	              vector < int >
#define    vii 	              vector < vector < int > >
#define    pii 	              pair< int, int >
#define    ff 	              first
#define    ss 	              second
#define    ll	              long long
#define    ull 	              unsigned long long
#define    sf scanf
#define    pf printf
#define    FMT(...)           (sprintf(CRTBUFF, __VA_ARGS__)?CRTBUFF:0)
char CRTBUFF[30000];

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

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

// g++ -g -O2 -std=gnu++11 A.cpp
// ./a.out

///****************** template ends here ****************

int t, n, m;

struct board {
    int x[16], y[16];
} brd[1000];

int brdIn = 0;

bool check(int n, int x, int y, board &tmp)
{
    FOR(i,0,n-1)
    {
        if(tmp.y[i] == y || abs(x-tmp.x[i]) == abs(y-tmp.y[i])) return false;
    }
    return true;
}

void pre(int q, board &tmp)
{
    if(q == 8)
    {
        brd[brdIn++] = tmp;
//        brdIn++;
        return;
    }

    FOR(c, 0, 7)
    {
        if(check(q, q, c, tmp) == true)
        {
            tmp.x[q] = q;
            tmp.y[q] = c;
            pre(q+1, tmp);
        }
    }
}

int distance(int x, int y, int idx, board &tmp)
{
    int r = tmp.x[idx];
    int c = tmp.y[idx];
    if(r == x && c == y) return 0;
    if(r == x || c == y || abs(r-x) == abs(c-y)) return 1;
    return 2;
}

board given;
int dp[10][(1<<9)+4];

int call(int in, int mask, int id)
{
    int &ret = dp[in][mask];
    if(bitCount(mask) == 8) return ret = 0;
    if(ret != -1) return ret;

    ret = INF;
    FOR(i,0,7)
    {
        if(bitCheck(mask, i) == 0)
        {
            int dd = distance(given.x[in], given.y[in], i, brd[id]);
            ret = min(ret, dd + call(in+1, bitOn(mask, i), id) );
        }
    }
    return ret;
}

int main() {
    #ifdef dipta007
        READ("in.txt");
       //WRITE("out.txt");
    #endif // dipta007
    ios_base::sync_with_stdio(0);cin.tie(0);

    board tmp;
    brdIn = 0;
    pre(0, tmp);

    trace(brdIn);
    int t;
    cin >> t;
    FOR(ci,1,t)
    {
        int id = 0;
        FOR(i,0,7)
        {
            string st;
            cin >> st;
            FOR(j,0,7) if(st[j] == 'q') given.x[id] = i, given.y[id] = j, id++;
        }

        SET(dp);
        int res = INF;
        FOR(i,0,brdIn-1)
        {
            SET(dp);
            res = min(res, call(0, 0, i));
        }
        cout << "Case " << ci << ": " << res << endl;
    }

    return 0;
}


